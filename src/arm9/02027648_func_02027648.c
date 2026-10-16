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
extern const unsigned short data_02153674[4];
extern const unsigned short data_0215367c[4];
extern const unsigned short data_02153684[4];
extern const unsigned short data_0215368c[4];
extern const unsigned short data_02153694[4];
extern const unsigned short data_0215369c[4];
extern const unsigned short data_021536a4[4];
extern const unsigned short data_021536ac[4];
extern const unsigned short data_021536b4[4];
extern const unsigned short data_021536bc[4];
extern const unsigned short data_021536c4[4];
extern const unsigned short data_021536cc[4];
void func_02027648(void){CharacterSelectState *s=state;switch(s->cursor){case 0:s->neighbors[0]=data_02153674[0];s->neighbors[1]=data_02153674[1];s->neighbors[2]=data_02153674[2];s->neighbors[3]=data_02153674[3];return;case 1:s->neighbors[0]=data_0215367c[0];s->neighbors[1]=data_0215367c[1];s->neighbors[2]=data_0215367c[2];s->neighbors[3]=data_0215367c[3];return;case 2:s->neighbors[0]=data_02153684[0];s->neighbors[1]=data_02153684[1];s->neighbors[2]=data_02153684[2];s->neighbors[3]=data_02153684[3];return;case 3:s->neighbors[0]=data_0215368c[0];s->neighbors[1]=data_0215368c[1];s->neighbors[2]=data_0215368c[2];s->neighbors[3]=data_0215368c[3];return;case 4:s->neighbors[0]=data_02153694[0];s->neighbors[1]=data_02153694[1];s->neighbors[2]=data_02153694[2];s->neighbors[3]=data_02153694[3];return;case 5:if(s->previous_cursor==2 || s->previous_cursor==9){s->neighbors[0]=data_0215369c[0];s->neighbors[1]=data_0215369c[1];s->neighbors[2]=data_0215369c[2];s->neighbors[3]=data_0215369c[3];return;}s->neighbors[0]=data_021536a4[0];s->neighbors[1]=data_021536a4[1];s->neighbors[2]=data_021536a4[2];s->neighbors[3]=data_021536a4[3];return;case 6:s->neighbors[0]=data_021536ac[0];s->neighbors[1]=data_021536ac[1];s->neighbors[2]=data_021536ac[2];s->neighbors[3]=data_021536ac[3];return;case 7:s->neighbors[0]=data_021536b4[0];s->neighbors[1]=data_021536b4[1];s->neighbors[2]=data_021536b4[2];s->neighbors[3]=data_021536b4[3];return;case 8:s->neighbors[0]=data_021536bc[0];s->neighbors[1]=data_021536bc[1];s->neighbors[2]=data_021536bc[2];s->neighbors[3]=data_021536bc[3];return;case 9:s->neighbors[0]=data_021536c4[0];s->neighbors[1]=data_021536c4[1];s->neighbors[2]=data_021536c4[2];s->neighbors[3]=data_021536c4[3];return;case 10:s->neighbors[0]=data_021536cc[0];s->neighbors[1]=data_021536cc[1];s->neighbors[2]=data_021536cc[2];s->neighbors[3]=data_021536cc[3];return;default:return;}}