/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
typedef struct Context{unsigned char pad[1308];void (*callback)(int,void *);} Context;extern Context *data_0216fda8;
void func_02009928(unsigned short a,unsigned short b){unsigned short args[2];if(b!=2 && b!=0){args[0]=a;args[1]=b;data_0216fda8->callback(255,args);}}