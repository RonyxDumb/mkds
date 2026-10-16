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
void func_020272c0(unsigned short a,unsigned short b){if(system_mode!=2){CharacterSelectState *s=state;if(*(int *)((unsigned char *)s+296)==0){*(unsigned short *)(*(unsigned char **)((unsigned char *)s+0x18)+6)=a;*(unsigned short *)(*(unsigned char **)((unsigned char *)s+0x18)+0xc6)=b;}}}