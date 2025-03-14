#include "actions.h"
#include "pivot.h"

list<Action*> Action::action_list;

void Action::Update(){
	list<Action*>::iterator it;

	for(it=Action::action_list.begin();it!=Action::action_list.end();it++){
		Action* act=*it;

		switch (act->act){
		case ACT_COMPLETED:	{
			//completed action
			action_list.splice(action_list.end(),act->nextActions);
			it=action_list.erase(it);
			delete act;
			break;}
		case ACT_DESTROY:{
			//Destroy an action and all the actions after it
			list<Action*>::iterator it2;
			for(it2=act->nextActions.begin();it2!=act->nextActions.end();it2++){
				(*it2)->act=ACT_DESTROY;
			}
			act->act=ACT_COMPLETED;
			break;}
		case ACT_STOP:	{
			act->TargetAction->act=ACT_DESTROY;
			act->act=ACT_COMPLETED;
			break;}
		case ACT_WAIT:	{
			act->rate-=1.0;
			if (act->rate<1.0)
				act->act=ACT_COMPLETED;
			break;}
		case ACT_MOVEBY:	{
			//MoveBy
			float n=sqrt(act->a*act->a+act->b*act->b+act->c*act->c);
			if (n<act->rate) {
				act->act=ACT_COMPLETED;
				break;}
			float dx=(act->a*act->rate)/n;
			float dy=(act->b*act->rate)/n;
			float dz=(act->c*act->rate)/n;

			act->a-=dx;
			act->b-=dy;
			act->c-=dz;

			act->ent->MoveEntity(dx,dy,dz);
			break;}
		case ACT_TURNBY:	{
			//TurnBy
			float n=abs(act->a)+abs(act->b)+abs(act->c);
			if (n<act->rate) {
				act->act=ACT_COMPLETED;
				break;}
			float dp=(act->a*act->rate)/n;
			float dy=(act->b*act->rate)/n;
			float dr=(act->c*act->rate)/n;

			act->a-=dp;
			act->b-=dy;
			act->c-=dr;

			act->ent->TurnEntity(dp,dy,dr);
			break;}
		case ACT_VECTOR:	{
			//Vector
			float dx=act->a+act->ent->EntityX(true);
			float dy=act->b+act->ent->EntityY(true);
			float dz=act->c+act->ent->EntityZ(true);

			act->ent->PositionEntity(dx,dy,dz,true);

			break;}
		case ACT_MOVETO:	{
			//MoveTo
			float dx=act->a-act->ent->EntityX(true);
			float dy=act->b-act->ent->EntityY(true);
			float dz=act->c-act->ent->EntityZ(true);

			float n=sqrt(dx*dx+dy*dy+dz*dz);
			if (n<act->rate) {
				act->act=ACT_COMPLETED;
				break;}

			act->ent->TranslateEntity(dx/n*act->rate,dy/n*act->rate,dz/n*act->rate,true);

			break;}
		case ACT_TURNTO:	{
			//TurnTo
			float dx=act->a-act->ent->EntityPitch(true);
			float dy=act->b-act->ent->EntityYaw(true);
			float dz=act->c-act->ent->EntityRoll(true);

			float n=abs(dx)+abs(dy)+abs(dz);
			if (n<act->rate) {
				act->act=ACT_COMPLETED;
				break;}

			float p=dx/n*act->rate + act->ent->EntityPitch(true);
			float y=dy/n*act->rate + act->ent->EntityYaw(true);
			float r=dz/n*act->rate + act->ent->EntityRoll(true);

			act->ent->RotateEntity(p,y,r,true);

			break;}
		case ACT_SCALETO:	{
			//ScaleTo
			float dx=act->a-act->ent->sx;
			float dy=act->b-act->ent->sy;
			float dz=act->c-act->ent->sz;

			float n=abs(dx)+abs(dy)+abs(dz);
			if (n<act->rate) {
				act->act=ACT_COMPLETED;
				break;}

			float sx=dx/n*act->rate + act->ent->sx;
			float sy=dy/n*act->rate + act->ent->sy;
			float sz=dz/n*act->rate + act->ent->sz;

			act->ent->ScaleEntity(sx,sy,sz);


			break;}
		case ACT_FADETO:	{
			//FadeTo
			float d=act->a-act->ent->brush.alpha;

			float n=abs(d);
			if (n<act->rate) {
				act->act=ACT_COMPLETED;
				break;}

			float a=d/n*act->rate + act->ent->brush.alpha;

			act->ent->EntityAlpha(a);

			break;}
		case ACT_TINTTO:{
			//TintTo
			float dr=act->a-act->ent->brush.red*255.0;
			float dg=act->b-act->ent->brush.green*255.0;
			float db=act->c-act->ent->brush.blue*255.0;

			float n=abs(dr)+abs(dg)+abs(db);
			if (n<act->rate) {
				act->act=ACT_COMPLETED;
				break;}

			float r=dr/n*act->rate + act->ent->brush.red*255.0;
			float g=dg/n*act->rate + act->ent->brush.green*255.0;
			float b=db/n*act->rate + act->ent->brush.blue*255.0;

			act->ent->EntityColor(r,g,b);


			break;}
		case ACT_TRACK_BY_POINT:{
			//TrackByPoint
			float px=act->a;
			float py=act->b;
			float pz=act->c;
			
			act->target->mat.TransformVec(px, py, pz, 1);

			float dx=px-act->ent->EntityX(true);
			float dy=py-act->ent->EntityY(true);
			float dz=pz-act->ent->EntityZ(true);

			float n=sqrt(dx*dx+dy*dy+dz*dz);
			if (n>=act->rate) {
				act->ent->TranslateEntity(dx/n*act->rate,dy/n*act->rate,dz/n*act->rate,true);
			}
			
			dx=act->target->mat.GetPitch()-act->ent->EntityPitch(true);
			dy=act->target->mat.GetYaw()-act->ent->EntityYaw(true);
			dz=act->target->mat.GetRoll()-act->ent->EntityRoll(true);

			n=abs(dx)+abs(dy)+abs(dz);
			if (n>=act->rate) {

				float p=dx/n*act->rate + act->ent->EntityPitch(true);
				float y=dy/n*act->rate + act->ent->EntityYaw(true);
				float r=dz/n*act->rate + act->ent->EntityRoll(true);

				act->ent->RotateEntity(p,y,r,true);
			}

			break;}
		case ACT_TRACK_BY_DISTANCE:{
			//TrackByDistance
			float d=act->ent->EntityDistance(act->target)-act->a;

			float n=abs(d);

			act->ent->PointEntity(act->target);
			if (n<act->rate) {
				break;}
			act->ent->MoveEntity(0,0,act->rate*d/n);

			break;}
		case ACT_NEWTONIAN:{
			
			float dx=act->ent->EntityX(true)-act->a;
			float dy=act->ent->EntityY(true)-act->b;
			float dz=act->ent->EntityZ(true)-act->c;

			act->a=act->ent->EntityX(true);
			act->b=act->ent->EntityY(true);
			act->c=act->ent->EntityZ(true);

			act->ent->TranslateEntity(dx*act->rate,dy*act->rate,dz*act->rate,true);

			break;}
		case ACT_CALLFUNCTION:{
			act->Execute();
			act->act=ACT_COMPLETED;
			break;}
		case ACT_ITERATE:{
			list<Action*>::iterator it2;
			Action* o=0;
			for(it2=act->nextActions.begin();it2!=act->nextActions.end();it2++){
				Action* n=new Action;
				n->ent=(*it2)->ent;
				n->act=(*it2)->act;
				n->target=(*it2)->target;
				n->a=(*it2)->a;
				n->b=(*it2)->b;
				n->c=(*it2)->c;
				n->rate=(*it2)->rate;
				if (o==0){
					action_list.push_back(n);
				}else{
					o->nextActions.push_back(n);
				}
				o=n;
			}
			if (o==0){
				act->act=ACT_COMPLETED;
			}else{
				o->nextActions.push_back(act);
				it=action_list.erase(it);
			}


			break;}
		case TRIGGER_CLOSETO:	{
			//MoveTo
			float dx=act->a-act->ent->EntityX(true);
			float dy=act->b-act->ent->EntityY(true);
			float dz=act->c-act->ent->EntityZ(true);

			float n=sqrt(dx*dx+dy*dy+dz*dz);
			if (n<act->rate)
				act->act=ACT_COMPLETED;
			break;}
		case TRIGGER_ENTITYDISTANCE:{
			//TrackByDistance
			float d=act->ent->EntityDistance(act->target);

			if (d<act->rate) 
				act->act=ACT_COMPLETED;
			break;}
		case TRIGGER_COLLISION:{
			if (act->ent->EntityCollided((int)act->rate)!=0)
				act->act=ACT_COMPLETED;
			break;}
		}
	}
}

Action* Action::AddAction(Entity* ent, int action, Entity* t, float a, float b, float c, float rate){
	Action* act=new Action;
	act->ent=ent;
	act->act=action;
	act->target=t;
	act->a=a;
	act->b=b;
	act->c=c;
	act->rate=rate;

	action_list.push_back(act);
	
	return act;
}

void Action::AppendAction(Action* a){
	action_list.remove(a);
	nextActions.push_back(a);
}

void Action::FreeAction(int glob){
	//The action will be removed at the first update; it cannot be erased immediately, because other actions might point at it
	if (glob==0){
		act=ACT_COMPLETED;
	}else{
		act=ACT_DESTROY;}
}

