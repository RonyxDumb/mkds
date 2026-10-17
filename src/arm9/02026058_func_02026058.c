/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
typedef struct State {unsigned char pad[0x60]; int cursor,previous,timer,phase,alpha; unsigned short value; unsigned char pad76[6]; int count,mode; short neighbors[4]; int transition; struct {int character;short cell,pad;} entries[12];} State;
extern State *data_02174e14;
#define state data_02174e14
#define system_mode (*(unsigned short *)0x27ffc40u)
extern short data_02153554[];
extern void G2x_SetBlendAlpha_(void*,int,int,int,int);extern void func_0202ba14(void);
void func_02026058(void){int flags=24;G2x_SetBlendAlpha_((void*)0x4001050u,0,63,6,10);if(state->phase!=9||state->transition!=2)flags|=1;(*(unsigned int *)0x4000000u)=((*(unsigned int *)0x4000000u)&0xffffe0ffu)|(flags<<8);(*(unsigned int *)0x4001000u)=((*(unsigned int *)0x4001000u)&0xffffe0ffu)|(0x1600u);(*(unsigned short *)0x4000008u)=((*(unsigned short *)0x4000008u)&~3)|1;if(*(int *)((unsigned char *)state+296))func_0202ba14();}