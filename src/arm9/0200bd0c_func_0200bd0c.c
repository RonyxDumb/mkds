/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
typedef struct State{unsigned char pad[26];unsigned short a,b,c,d;} State;extern State *data_0216fdec;
int func_0200bd0c(void){int result=0,ready=0;State *p=data_0216fdec;if(p->a==1 && p->d==0)ready=1;if(ready && p->b==0)result=1;return result;}