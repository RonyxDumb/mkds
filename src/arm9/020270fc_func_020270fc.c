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
extern CharacterSelectState *data_02174e14;
#define state data_02174e14
extern void func_02027be0(void);
extern void func_02027a58(void);
extern void func_02027850(void);
extern void func_02027648(void);
extern void func_02027448(void);
extern void func_02027188(void);
extern void func_0202721c(void);
extern void func_02025f54(void *,int);extern int func_02025e60(int);
void func_020270fc(int previous_cursor){state->previous_cursor=previous_cursor;switch(state->character_count){case 8:func_02027be0();break;case 9:func_02027a58();break;case 10:func_02027850();break;case 11:func_02027648();break;case 12:func_02027448();break;}func_02027188();func_0202721c();func_02025f54((unsigned char *)state+0xf8,0);state->current_character=state->entries[state->cursor].character;state->current_value=func_02025e60(state->current_character);}