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
extern const unsigned short data_02153734[4];
extern const unsigned short data_0215373c[4];
extern const unsigned short data_02153744[4];
extern const unsigned short data_0215374c[4];
extern const unsigned short data_02153754[4];
extern const unsigned short data_0215375c[4];
extern const unsigned short data_02153764[4];
extern const unsigned short data_0215376c[4];
extern const unsigned short data_02153774[4];
void func_02027a58(void){CharacterSelectState *s=state;switch(s->cursor){case 0:s->neighbors[0]=data_02153734[0];s->neighbors[1]=data_02153734[1];s->neighbors[2]=data_02153734[2];s->neighbors[3]=data_02153734[3];return;case 1:s->neighbors[0]=data_0215373c[0];s->neighbors[1]=data_0215373c[1];s->neighbors[2]=data_0215373c[2];s->neighbors[3]=data_0215373c[3];return;case 2:s->neighbors[0]=data_02153744[0];s->neighbors[1]=data_02153744[1];s->neighbors[2]=data_02153744[2];s->neighbors[3]=data_02153744[3];return;case 3:s->neighbors[0]=data_0215374c[0];s->neighbors[1]=data_0215374c[1];s->neighbors[2]=data_0215374c[2];s->neighbors[3]=data_0215374c[3];return;case 4:s->neighbors[0]=data_02153754[0];s->neighbors[1]=data_02153754[1];s->neighbors[2]=data_02153754[2];s->neighbors[3]=data_02153754[3];return;case 5:s->neighbors[0]=data_0215375c[0];s->neighbors[1]=data_0215375c[1];s->neighbors[2]=data_0215375c[2];s->neighbors[3]=data_0215375c[3];return;case 6:s->neighbors[0]=data_02153764[0];s->neighbors[1]=data_02153764[1];s->neighbors[2]=data_02153764[2];s->neighbors[3]=data_02153764[3];return;case 7:s->neighbors[0]=data_0215376c[0];s->neighbors[1]=data_0215376c[1];s->neighbors[2]=data_0215376c[2];s->neighbors[3]=data_0215376c[3];return;case 8:s->neighbors[0]=data_02153774[0];s->neighbors[1]=data_02153774[1];s->neighbors[2]=data_02153774[2];s->neighbors[3]=data_02153774[3];return;default:return;}}