/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
typedef struct CharacterSelectState {
 unsigned char reserved00[0x60];
 int cursor, previous_cursor, timer, phase, alpha;
 unsigned short render_value;
 unsigned char reserved76[6];
 int character_count, mode;
 short neighbors[4];
 unsigned char reserved8c[4];
 struct {int character;short cell,unused;} entries[12];
 int current_character,current_value;
} CharacterSelectState;
#define state (*(CharacterSelectState **)0x2174e14u)
#define system_mode (*(unsigned short *)0x27ffc40u)
extern void *GetGlobalCA_from_thumb(void);extern void func_0211f498(void);extern void Mem_DestroyHeap(int);
void func_020260e4(void){if(system_mode==2){if(*(int *)((unsigned char *)GetGlobalCA_from_thumb()+200)==2)func_0211f498();}Mem_DestroyHeap(*(int *)((unsigned char *)state+0x5c));state=0;}