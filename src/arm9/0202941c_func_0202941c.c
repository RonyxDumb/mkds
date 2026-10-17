/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
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
#define state (*(CharacterSelectState **)0x2174e18u)
extern void func_0202b7c0(int);
void func_0202941c(int value){if(*(int *)((unsigned char *)state+0x104))func_0202b7c0(value);}