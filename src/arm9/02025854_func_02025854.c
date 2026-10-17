/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
extern void func_02025884(void *,int,int,int,int,void *(*)(int));
extern void func_02025954(int,void *,int);
void func_02025854(int sub,void *out,int characters,int palette,int screen,int layer,void *(*load)(int)){func_02025884(out,characters,palette,screen,layer,load);func_02025954(sub,out,layer);}