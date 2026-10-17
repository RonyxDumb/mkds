/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
typedef struct State {unsigned char pad[0x60]; int cursor,previous,timer,phase,alpha; unsigned short value; unsigned char pad76[6]; int count,mode; short neighbors[4]; int transition; struct {int character;short cell,pad;} entries[12];} State;
extern State *data_02174e14;
#define state data_02174e14
#define system_mode (*(unsigned short *)0x27ffc40u)
extern short data_02153554[];
void func_0202734c(int visible){State *s=state;int i;unsigned char *gfx=(unsigned char *)s+0x1c;if(system_mode!=2){i=0;short *entry;if(s->count>0){entry=data_02153554;do{*(int *)(*(unsigned char **)((unsigned char *)gfx+24)+entry[2]*64)=visible;*(int *)(*(unsigned char **)((unsigned char *)gfx+24)+entry[1]*64)=*(int *)(*(unsigned char **)((unsigned char *)gfx+24)+entry[2]*64);*(int *)(*(unsigned char **)((unsigned char *)gfx+24)+entry[0]*64)=*(int *)(*(unsigned char **)((unsigned char *)gfx+24)+entry[1]*64);entry+=4;i++;}while(i<state->count);}*(int *)(*(unsigned char **)((unsigned char *)gfx+24)+1600)=visible;}}