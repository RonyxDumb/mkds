/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
typedef struct CharacterSelectState {
 unsigned char reserved00[0x1c]; struct { unsigned char pad[12]; void *cellbank; void *a,*b; unsigned char *icons; unsigned char tail[40]; } render;
 int cursor, previous_cursor, timer, phase, alpha;
 unsigned short render_value;
 unsigned char reserved76[6];
 int character_count, mode;
 short neighbors[4];
 unsigned char reserved8c[4];
 struct {int character;short cell,unused;} entries[12];
 int current_character,current_value;
} CharacterSelectState;
extern CharacterSelectState *data_02174e14;
#define state data_02174e14
extern void func_02128310(int);extern void func_02027424(int);extern void func_02025f14(void *,int);extern void func_020789d4(void);
void func_020273c0(void){state->timer=0;*(int *)((unsigned char *)state+0x8c)=2;state->phase=8;func_02128310(0);func_02027424(3);func_02025f14((unsigned char *)state+0xf8,2);func_02025f14((unsigned char *)state+264,2);func_02025f14((unsigned char *)state+280,2);func_020789d4();}