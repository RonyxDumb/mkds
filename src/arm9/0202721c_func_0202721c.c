/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
typedef struct State {unsigned char pad[0x60]; int cursor,previous,timer,phase,alpha; unsigned short value; unsigned char pad76[6]; int count,mode; short neighbors[4]; int transition; struct {int character;short cell,pad;} entries[12];} State;
extern State *data_02174e14;
#define state data_02174e14
#define system_mode (*(unsigned short *)0x27ffc40u)
extern short data_02153554[];
extern void func_02124748(int,void*,void*,void*,int,int,int,int);
void func_0202721c(void){State *s=state;if(*(int *)((unsigned char *)s+296)==0){unsigned char *gfx=(unsigned char *)s+0x38;func_02124748(s->entries[s->cursor].cell,*(void **)(gfx+8),*(void **)(gfx+0),*(void **)(gfx+12),0,2,*(int *)((unsigned char *)s+8),*(int *)((unsigned char *)s+12));func_02124748(state->entries[state->cursor].cell,*(void **)(gfx+8),*(void **)(gfx+0),*(void **)(gfx+12),0,1,*(int *)((unsigned char *)s+8),*(int *)((unsigned char *)s+12));}}