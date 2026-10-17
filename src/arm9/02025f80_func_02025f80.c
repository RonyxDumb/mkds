/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
typedef struct Transition {int a,b,value;short x,y;} Transition;
extern void func_02025f14(Transition *,int);
void func_02025f80(Transition *transition,int mode,int value,int x,int y){
transition->value=value;transition->x=x;transition->y=y;func_02025f14(transition,mode);}
