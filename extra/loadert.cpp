#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <unordered_map>

#include "toml.hpp" 

#include "mesh.h"
#include "csg.h"
#include "octree.h"

//OcTree* rootNode = nullptr;



class OB3MLLevel :public OcTree {
    struct BlockInfo {
        std::string file;
        float scaleX = 1.0f;
        float scaleY = 1.0f;
        float scaleZ = 1.0f;
        float translationX = 0.0f;
        float translationY = 0.0f;
        float translationZ = 0.0f;
        float rotationX = 0.0f;
        float rotationY = 0.0f;
        float rotationZ = 0.0f;
        float alpha = 1.0f;
        bool solid = true;
    };

    // Cache e mappa dei blocchi della legenda
    std::map<std::string, Mesh*> masterCache;    // File path -> Master Mesh pulita
    std::map<std::string, Mesh*> legendBlocks;   // Token (es: "W1", "#") -> Mesh pronta

    int octreeLevel = 0;
    int worldSizeX = 0;
    int worldSizeY = 0;
    int worldSizeZ = 0;

    struct Point3D {
        int x, y, z;

        bool operator==(const Point3D& other) const {
            return x == other.x && y == other.y && z == other.z;
        }
    };

    // Funzione di Hash custom per combinare i tre interi in un unico hash a 64-bit
    struct Point3DHash {
        std::size_t operator()(const Point3D& p) const {
            // Hash combination (tecnica standard per combinare hash in C++)
            std::size_t h1 = std::hash<int>{}(p.x);
            std::size_t h2 = std::hash<int>{}(p.y);
            std::size_t h3 = std::hash<int>{}(p.z);
        
            return h1 ^ (h2 << 1) ^ (h3 << 2); 
        }
    };
    std::unordered_map<Point3D, std::string, Point3DHash> gridMap;

    std::map<std::string, std::vector<Point3D>> logicAnchors;
    std::set<std::string> isAnchor;
    static int anchor_x;
    static int anchor_y;
    static int anchor_z;

    void LoadLegend(const toml::table& tbl) {
        auto legend = tbl["legend"].as_table();
        if (!legend) return;

        // Mappa temporanea per la gestione degli alias
        std::map<std::string, std::string> aliasMap;

        // --- PRIMO PASSAGGIO: Blocchi Standard (definizione tramite file) ---
        for (const auto& [key, value] : *legend) {
            std::string token(key.str());
            // Se il token è già presente (override/ridefinizione di un blocco esistente)
            auto it = legendBlocks.find(token);
            if (it != legendBlocks.end()) {
                if (it->second) {
                    it->second->FreeEntity(); // Sicuro al 100%: in questa fase non esistono alias!
                }
                legendBlocks.erase(it);
            }
            if (auto details = value.as_table()) {

                // Se è un alias, lo rimandiamo al secondo passaggio
                if ((*details)["alias"]) {
                    if (auto targetAlias = (*details)["alias"].value<std::string>()) {
                        aliasMap[token] = *targetAlias;
                    }
                    continue;
                }

                if ((*details)["anchor"]) {
                    isAnchor.insert(token);
                }
    
                // Se è un blocco logico, è vuoto
                if ((*details)["logic"]) {
                    legendBlocks[token] = nullptr;
                    continue;
                }

                // Il campo "file" è obbligatorio per i blocchi standard
                if (!(*details)["file"]) continue;
    
                BlockInfo block;
                block.file = (*details)["file"].as_string()->get();

                // 1. Caricamento / Recupero Master Cache
                if (masterCache.find(block.file) == masterCache.end()) {
                    Mesh* master = Mesh::LoadMesh(block.file.c_str());
                    if (!master) {
                        std::cerr << "Error: Could not load mesh file '" << block.file << "'\n";
                        continue;
                    }
                    master->HideEntity();
                    masterCache[block.file] = master;
                }

                Mesh* cleanMaster = masterCache[block.file];
                Mesh* readyBlock = cleanMaster->CopyEntity(0);

                // 2. Scala
                if ((*details)["scale"]) {
                    if (auto scaleArray = (*details)["scale"].as_array()) {
                        block.scaleX = scaleArray->at(0).value<float>().value_or(1.0f);
                        block.scaleY = scaleArray->at(1).value<float>().value_or(1.0f);
                        block.scaleZ = scaleArray->at(2).value<float>().value_or(1.0f);
                        readyBlock->ScaleMesh(block.scaleX, block.scaleY, block.scaleZ);
                    }
                }

                // 3. Traslazione locale
                if ((*details)["translation"]) {
                    if (auto transArray = (*details)["translation"].as_array()) {
                        block.translationX = transArray->at(0).value<float>().value_or(0.0f);
                        block.translationY = transArray->at(1).value<float>().value_or(0.0f);
                        block.translationZ = transArray->at(2).value<float>().value_or(0.0f);
                        readyBlock->PositionMesh(block.translationX, block.translationY, block.translationZ);
                    }
                }

                // 4. Sezionamento CSG (Opzionale)
                if ((*details)["cut"]) {
                    if (auto cutArray = (*details)["cut"].as_array()) {
                        float cutX = 2.0f * cutArray->at(0).value<float>().value_or(0.0f);
                        float cutY = 2.0f * cutArray->at(1).value<float>().value_or(0.0f);
                        float cutZ = 2.0f * cutArray->at(2).value<float>().value_or(0.0f);

                        Mesh* tempCube = Mesh::CreateCube(0);
                        tempCube->PositionMesh(cutX, cutY, cutZ);

                        Mesh* newBlock = CSG::MeshCSG(readyBlock, tempCube, 3);
                        if (newBlock) {
                            newBlock->PositionMesh(-cutX, -cutY, -cutZ);
                            tempCube->FreeEntity();
                            readyBlock->FreeEntity();
                            readyBlock = newBlock;
                        } else {
                            tempCube->FreeEntity();
                        }
                    }
                }

                // 5. Rotazione
                if ((*details)["rotation"]) {
                    if (auto rotArray = (*details)["rotation"].as_array()) {
                        block.rotationX = rotArray->at(0).value<float>().value_or(0.0f);
                        block.rotationY = rotArray->at(1).value<float>().value_or(0.0f);
                        block.rotationZ = rotArray->at(2).value<float>().value_or(0.0f);
                        readyBlock->RotateMesh(block.rotationX, block.rotationY, block.rotationZ);
                    }
                }

                // 6. Trasparenza
                if ((*details)["alpha"]) {
                    block.alpha = (*details)["alpha"].value<float>().value_or(1.0f);
                    readyBlock->EntityAlpha(block.alpha);
                }

                // 7. Solidità (Memorizzata in 'obscurer')
                block.solid = (*details)["solid"].value<bool>().value_or(true);
                readyBlock->obscurer = block.solid ? 1 : 0;
    
                legendBlocks[token] = readyBlock;
            }
        }

        // --- SECONDO PASSAGGIO: Risoluzione degli Alias ---
        for (const auto& [aliasToken, targetToken] : aliasMap) {
            auto it = legendBlocks.find(targetToken);
            if (it != legendBlocks.end()) {
                // Se l'alias va a sovrascrivere un token già esistente in legendBlocks
                auto existingIt = legendBlocks.find(aliasToken);
                if (existingIt != legendBlocks.end()) {
                    if (existingIt->second && existingIt->second != it->second) {
                        existingIt->second->FreeEntity();
                    }
                    legendBlocks.erase(existingIt);
                }
                legendBlocks[aliasToken] = it->second;
            } else {
                std::cerr << "Warning: Alias '" << aliasToken 
                          << "' points to non-existent symbol '" << targetToken << "'\n";
            }
        }
        // 3. Liberiamo la Master Cache
        for (const auto& [path, masterPtr] : masterCache) {
            if (masterPtr) {
                masterPtr->FreeEntity();
            }
        }
        masterCache.clear();
    }

/*    void CreateBlockInEngine(const std::string& blockId, int x, int y, int z) {
        auto it = legendBlocks.find(blockId);
        if (it != legendBlocks.end()) {
            Mesh* blockMesh = it->second;
            if (blockMesh == nullptr) return;
            int solidFlag = blockMesh->obscurer;

            OctreeBlock(
                blockMesh, 
                octreeLevel, 
                x - worldSizeX / 2, 
                y - worldSizeY / 2, 
                worldSizeZ / 2 - 1 - z, 
                solidFlag
            );
        }
    }*/

    void ParseASCIILayer(const std::string& rawMap, int layerY, int charStep) {
        std::stringstream ss(rawMap);
        std::string line;
        int z = 0;

        while (std::getline(ss, line)) {
            if (!line.empty() && line.back() == '\r') {
                line.pop_back();
            }
    
            if (line.empty()) continue;
    
            int x = 0;
            for (size_t i = 0; i < line.length(); i += charStep) {
                std::string blockId = line.substr(i, charStep);
    
                if (blockId.length() < static_cast<size_t>(charStep)) break;
    
                //CreateBlockInEngine(blockId, x, layerY, z);
                auto it = legendBlocks.find(blockId);
                if (it != legendBlocks.end()) {
                    // Se it->second è un Mesh*, lo inserisce nel motore OcTree
                    if (it->second != nullptr) {
                        int solidFlag = it->second->obscurer;
                        OctreeBlock(
                            it->second, 
                            octreeLevel, 
                            x - worldSizeX / 2, 
                            layerY - worldSizeY / 2, 
                            worldSizeZ / 2 - 1 - z, 
                            solidFlag
                        );
                    }
                    if (isAnchor.count(blockId) > 0){
                        logicAnchors[blockId].push_back({x - worldSizeX / 2, layerY - worldSizeY / 2, worldSizeZ / 2 - 1 - z, });
                    }
                    gridMap[{x, layerY, z}] = blockId;
                }
                x++;
            }
            z++;
        }
    }

public:
    static OB3MLLevel* LoadTOMLMap(const std::string& filePath, Entity* parent) {
        try {
            toml::table tbl = toml::parse_file(filePath);

            // 1. Inclusione Legende Esterne ("include_legend")
            std::vector<std::string> includeFiles;
            if (auto includeArray = tbl["include_legend"].as_array()) {
                for (auto&& el : *includeArray) {
                    if (auto path = el.value<std::string>()) {
                        includeFiles.push_back(*path);
                    }
                }
            } else if (auto singlePath = tbl["include_legend"].value<std::string>()) {
                includeFiles.push_back(*singlePath);
            }

            if (!includeFiles.empty() && !tbl["legend"]) {
                tbl.insert("legend", toml::table{});
            }

            for (const auto& externalPath : includeFiles) {
                try {
                    auto extLegend = toml::parse_file(externalPath);
                    if (auto extTable = extLegend["legend"].as_table()) {
                        tbl["legend"].as_table()->insert(
                            extTable->begin(),
                            extTable->end(),
                            toml::value_flags::none
                        );
                    }
                } catch (const toml::parse_error& err) {
                    std::cerr << "Error including legend '" << externalPath << "': " << err.what() << "\n";
                }
            }

            // 2. Caricamento Legenda
            OB3MLLevel* oct=new OB3MLLevel;

            oct->LoadLegend(tbl);

            // 3. Parametri del Mondo
            oct->worldSizeX = tbl["world"]["size_xyz"][0].as_integer()->get();
            oct->worldSizeY = tbl["world"]["size_xyz"][1].as_integer()->get();
            oct->worldSizeZ = tbl["world"]["size_xyz"][2].as_integer()->get();
    
            int charStep = tbl["world"]["char_step"].value<int>().value_or(1);

            int maxDimension = std::ceil(std::max({oct->worldSizeX, oct->worldSizeY, oct->worldSizeZ}) / 2.0f);
            int levelX = std::ceil(std::log2(oct->worldSizeX));
            int levelY = std::ceil(std::log2(oct->worldSizeY));
            int levelZ = std::ceil(std::log2(oct->worldSizeZ));
            oct->octreeLevel = std::max({levelX, levelY, levelZ});

            //rootNode = OcTree::CreateOcTree(maxDimension, maxDimension, maxDimension, parentEntity);
            oct->class_name="OcTree";

            oct->AddParent(parent);
            entity_list.push_back(oct);
            mesh_info=C_NewMeshInfo();
            oct->c_col_tree=C_CreateColTree(mesh_info);
            C_DeleteMeshInfo(mesh_info);

            //terrain_list.push_back(oct);

            oct->child.width=maxDimension;
            oct->child.height=maxDimension;
            oct->child.depth=maxDimension;

            oct->child.x=0;
            oct->child.y=0;
            oct->child.z=0;

            oct->child.child[0]=0;
            oct->child.mesh=0;
            oct->child.far=1000000;
    
            // 4. Parsing Sezione Layout
            auto layoutTable = tbl["layout"].as_table();
            if (!layoutTable) {
                std::cerr << "Error: [layout] section missing!\n";
                return oct;
            }

            for (const auto& [key, value] : *layoutTable) {
                std::string layerName(key.str());
                size_t posUnderscore = layerName.find_last_of('_');
            
                if (posUnderscore == std::string::npos) continue;
    
                int layerY = std::stoi(layerName.substr(posUnderscore + 1));

                if (layerY < 0 || layerY >= oct->worldSizeY) continue;
    
                if (auto rawMapPtr = value.as_string()) {
                    oct->ParseASCIILayer(rawMapPtr->get(), layerY, charStep);
                }
            }
            oct->isAnchor.clear();

            std::cout << "Map loaded successfully!\n";
            return oct;

        } catch (const toml::parse_error& err) {
            std::cerr << "TOML parse error: " << err.description()
                      << " [Line " << err.source().begin.line
                      << ", Column " << err.source().begin.column << "]\n";
            return 0;
        }
    }



    void FreeEntity(){
        // 1. Raccogliamo solo i puntatori MESH unici (elimina gli alias duplicati)
        std::set<Mesh*> uniqueMeshes;
        for (const auto& [token, meshPtr] : legendBlocks) {
            if (meshPtr) {
                uniqueMeshes.insert(meshPtr);
            }
        }

        // 2. Liberiamo ogni mesh unica UNA SOLA VOLTA
        for (Mesh* mesh : uniqueMeshes) {
            mesh->FreeEntity();
        }
        legendBlocks.clear();
        gridMap.clear();
        OcTree::FreeEntity();
    }

    void SetTileID(int wx, int wy, int wz, const std::string& id) {
        int gx = wx + worldSizeX / 2;
        int gy = wy + worldSizeY / 2;
        int gz = worldSizeZ / 2 - 1 - wz;

        if (gx < 0 || gx >= worldSizeX || 
            gy < 0 || gy >= worldSizeY || 
            gz < 0 || gz >= worldSizeZ) {
            return;
        }

        auto it = legendBlocks.find(id);
        if (it == legendBlocks.end() || id.empty()) {
            gridMap.erase({gx, gy, gz});
        } else {
            gridMap[{gx, gy, gz}] = id;
        }
    }

    std::string GetTileID(int wx, int wy, int wz) const {
        int gx = wx + worldSizeX / 2;
        int gy = wy + worldSizeY / 2;
        int gz = worldSizeZ / 2 - 1 - wz;

        auto it = gridMap.find({gx, gy, gz});
        if (it != gridMap.end()) {
            return it->second;
        }
        return "";
    }

    Mesh* GetTileMesh(const std::string& id) const{
        auto it = legendBlocks.find(id);
        if (it != legendBlocks.end()) {
            return it->second;
        }
        return nullptr;
    }

    int GetLOD(){
        return octreeLevel;
    }

    int CountAnchors(const std::string& id){
         auto it = logicAnchors.find(id);
         if (it != logicAnchors.end()) {
             return it->second.size();
         }
         return 0;
    }

    void GetAnchors(const std::string& id, int n){
         auto it = logicAnchors.find(id);
         if (it != logicAnchors.end()) {
             if (n >= 0 && n < static_cast<int>(it->second.size())) {
                 Point3D p=it->second[n];
                 anchor_x= p.x;
                 anchor_y= p.y;
                 anchor_z= p.z;
             }
         }
    }

    static int AnchorX(){
        return anchor_x;
    }

    static int AnchorY(){
        return anchor_y;
    }

    static int AnchorZ(){
        return anchor_z;
    }
};

int OB3MLLevel::anchor_x=0;
int OB3MLLevel::anchor_y=0;
int OB3MLLevel::anchor_z=0;


extern "C" {
    OB3MLLevel* LoadOB3ML(char* pathFile, Entity* parent) {
        return OB3MLLevel::LoadTOMLMap(pathFile, parent);
    }

    const char* GetOB3MLTileID(OB3MLLevel* level, int x, int y, int z) {
        if (!level) return "";
        static std::string lastTile;
        lastTile = level->GetTileID(x, y, z);
        return lastTile.c_str();
    }

    void SetOB3MLTileID(OB3MLLevel* level, int x, int y, int z, char* id) {
        level->SetTileID(x, y, z, id);
    }

    Mesh* GetTileMesh(OB3MLLevel* level, const char* id) {
        return level->GetTileMesh(id);
    }

    int CountAnchors(OB3MLLevel* level, const char* id) {
        return level->CountAnchors(id);
    }

    void GetAnchors(OB3MLLevel* level, const char* id, int n) {
        level->GetAnchors(id,n);
    }

    int AnchorX(){
        return OB3MLLevel::AnchorX();
    }

    int AnchorY(){
        return OB3MLLevel::AnchorY();
    }

    int AnchorZ(){
        return OB3MLLevel::AnchorZ();
    }
}