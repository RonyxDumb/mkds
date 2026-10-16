/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
extern int *func_020070b8(void);extern void func_020070c0(int);extern void func_020070cc(int);
int func_02006f14(int x,int y){int *p=func_020070b8();if(*p==4 || *p==6)return 0;func_020070c0(x-14);func_020070cc(y-14);return 1;}