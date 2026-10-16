/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
typedef struct Context{unsigned char pad[1500];void (*callback)(int,void *);} Context;extern Context *data_0216fde8;
void func_0200b820(unsigned short a,unsigned short b){unsigned short args[2];if(data_0216fde8->callback){args[0]=a;args[1]=b;data_0216fde8->callback(2,args);}}