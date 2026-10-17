/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
extern void func_02025904(void *,int,int,int,int,void *(*)(int));
extern void func_02025954(int,void *,int);
void func_020258d4(int sub,void *out,int characters,int palette,int screen,int layer,void *(*load)(int)){func_02025904(out,characters,palette,screen,layer,load);func_02025954(sub,out,layer);}