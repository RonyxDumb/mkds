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
extern const unsigned short data_02153614[4];
extern const unsigned short data_0215361c[4];
extern const unsigned short data_02153624[4];
extern const unsigned short data_0215362c[4];
extern const unsigned short data_02153634[4];
extern const unsigned short data_0215363c[4];
extern const unsigned short data_02153644[4];
extern const unsigned short data_0215364c[4];
extern const unsigned short data_02153654[4];
extern const unsigned short data_0215365c[4];
extern const unsigned short data_02153664[4];
extern const unsigned short data_0215366c[4];
void func_02027448(void){CharacterSelectState *s=state;switch(s->cursor){case 0:s->neighbors[0]=data_02153614[0];s->neighbors[1]=data_02153614[1];s->neighbors[2]=data_02153614[2];s->neighbors[3]=data_02153614[3];return;case 1:s->neighbors[0]=data_0215361c[0];s->neighbors[1]=data_0215361c[1];s->neighbors[2]=data_0215361c[2];s->neighbors[3]=data_0215361c[3];return;case 2:s->neighbors[0]=data_02153624[0];s->neighbors[1]=data_02153624[1];s->neighbors[2]=data_02153624[2];s->neighbors[3]=data_02153624[3];return;case 3:s->neighbors[0]=data_0215362c[0];s->neighbors[1]=data_0215362c[1];s->neighbors[2]=data_0215362c[2];s->neighbors[3]=data_0215362c[3];return;case 4:s->neighbors[0]=data_02153634[0];s->neighbors[1]=data_02153634[1];s->neighbors[2]=data_02153634[2];s->neighbors[3]=data_02153634[3];return;case 5:s->neighbors[0]=data_0215363c[0];s->neighbors[1]=data_0215363c[1];s->neighbors[2]=data_0215363c[2];s->neighbors[3]=data_0215363c[3];return;case 6:s->neighbors[0]=data_02153644[0];s->neighbors[1]=data_02153644[1];s->neighbors[2]=data_02153644[2];s->neighbors[3]=data_02153644[3];return;case 7:s->neighbors[0]=data_0215364c[0];s->neighbors[1]=data_0215364c[1];s->neighbors[2]=data_0215364c[2];s->neighbors[3]=data_0215364c[3];return;case 8:s->neighbors[0]=data_02153654[0];s->neighbors[1]=data_02153654[1];s->neighbors[2]=data_02153654[2];s->neighbors[3]=data_02153654[3];return;case 9:s->neighbors[0]=data_0215365c[0];s->neighbors[1]=data_0215365c[1];s->neighbors[2]=data_0215365c[2];s->neighbors[3]=data_0215365c[3];return;case 10:s->neighbors[0]=data_02153664[0];s->neighbors[1]=data_02153664[1];s->neighbors[2]=data_02153664[2];s->neighbors[3]=data_02153664[3];return;case 11:s->neighbors[0]=data_0215366c[0];s->neighbors[1]=data_0215366c[1];s->neighbors[2]=data_0215366c[2];s->neighbors[3]=data_0215366c[3];return;default:return;}}