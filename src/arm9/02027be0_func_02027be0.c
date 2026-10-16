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
extern const unsigned short data_0215377c[4];
extern const unsigned short data_02153784[4];
extern const unsigned short data_0215378c[4];
extern const unsigned short data_02153794[4];
extern const unsigned short data_0215379c[4];
extern const unsigned short data_021537a4[4];
extern const unsigned short data_021537ac[4];
extern const unsigned short data_021537b4[4];
extern const unsigned short data_021537bc[4];
extern const unsigned short data_021537c4[4];
extern const unsigned short data_021537cc[4];
extern const unsigned short data_021537d4[4];
void func_02027be0(void){CharacterSelectState *s=state;switch(s->cursor){case 0:s->neighbors[0]=data_0215377c[0];s->neighbors[1]=data_0215377c[1];s->neighbors[2]=data_0215377c[2];s->neighbors[3]=data_0215377c[3];return;case 1:if(s->previous_cursor==4){s->neighbors[0]=data_02153784[0];s->neighbors[1]=data_02153784[1];s->neighbors[2]=data_02153784[2];s->neighbors[3]=data_02153784[3];return;}s->neighbors[0]=data_0215378c[0];s->neighbors[1]=data_0215378c[1];s->neighbors[2]=data_0215378c[2];s->neighbors[3]=data_0215378c[3];return;case 2:s->neighbors[0]=data_02153794[0];s->neighbors[1]=data_02153794[1];s->neighbors[2]=data_02153794[2];s->neighbors[3]=data_02153794[3];return;case 3:if(s->previous_cursor==1 || s->previous_cursor==6){s->neighbors[0]=data_0215379c[0];s->neighbors[1]=data_0215379c[1];s->neighbors[2]=data_0215379c[2];s->neighbors[3]=data_0215379c[3];return;}s->neighbors[0]=data_021537a4[0];s->neighbors[1]=data_021537a4[1];s->neighbors[2]=data_021537a4[2];s->neighbors[3]=data_021537a4[3];return;case 4:if(s->previous_cursor==2 || s->previous_cursor==7){s->neighbors[0]=data_021537ac[0];s->neighbors[1]=data_021537ac[1];s->neighbors[2]=data_021537ac[2];s->neighbors[3]=data_021537ac[3];return;}s->neighbors[0]=data_021537b4[0];s->neighbors[1]=data_021537b4[1];s->neighbors[2]=data_021537b4[2];s->neighbors[3]=data_021537b4[3];return;case 5:s->neighbors[0]=data_021537bc[0];s->neighbors[1]=data_021537bc[1];s->neighbors[2]=data_021537bc[2];s->neighbors[3]=data_021537bc[3];return;case 6:if(s->previous_cursor==4){s->neighbors[0]=data_021537c4[0];s->neighbors[1]=data_021537c4[1];s->neighbors[2]=data_021537c4[2];s->neighbors[3]=data_021537c4[3];return;}s->neighbors[0]=data_021537cc[0];s->neighbors[1]=data_021537cc[1];s->neighbors[2]=data_021537cc[2];s->neighbors[3]=data_021537cc[3];return;case 7:s->neighbors[0]=data_021537d4[0];s->neighbors[1]=data_021537d4[1];s->neighbors[2]=data_021537d4[2];s->neighbors[3]=data_021537d4[3];return;default:return;}}