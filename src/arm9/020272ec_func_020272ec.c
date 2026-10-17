/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
typedef struct State {unsigned char pad[0x60]; int cursor,previous,timer,phase,alpha; unsigned short value; unsigned char pad76[6]; int count,mode; short neighbors[4]; int transition; struct {int character;short cell,pad;} entries[12];} State;
extern State *data_02174e14;
#define state data_02174e14
#define system_mode (*(unsigned short *)0x27ffc40u)
extern short data_02153554[];
void func_020272ec(void){if(system_mode!=2){int i;unsigned char *gfx=(unsigned char *)state+0x1c;short *entry;i=0;*(int *)(*(unsigned char **)((unsigned char *)gfx+24)+1536)=0;*(int *)(*(unsigned char **)((unsigned char *)gfx+24)+1600)=1;entry=data_02153554;for(;i<12;i++){*(unsigned short *)(*(unsigned char **)((unsigned char *)gfx+24)+entry[1]*64+4)=0;*(unsigned short *)(*(unsigned char **)((unsigned char *)gfx+24)+entry[1]*64+6)=0;entry+=4;}}}