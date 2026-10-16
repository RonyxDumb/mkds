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
extern const unsigned short data_021536d4[4];
extern const unsigned short data_021536dc[4];
extern const unsigned short data_021536e4[4];
extern const unsigned short data_021536ec[4];
extern const unsigned short data_021536f4[4];
extern const unsigned short data_021536fc[4];
extern const unsigned short data_02153704[4];
extern const unsigned short data_0215370c[4];
extern const unsigned short data_02153714[4];
extern const unsigned short data_0215371c[4];
extern const unsigned short data_02153724[4];
extern const unsigned short data_0215372c[4];
void func_02027850(void){CharacterSelectState *s=state;switch(s->cursor){case 0:s->neighbors[0]=data_021536d4[0];s->neighbors[1]=data_021536d4[1];s->neighbors[2]=data_021536d4[2];s->neighbors[3]=data_021536d4[3];return;case 1:if(s->previous_cursor==5){s->neighbors[0]=data_021536dc[0];s->neighbors[1]=data_021536dc[1];s->neighbors[2]=data_021536dc[2];s->neighbors[3]=data_021536dc[3];return;}s->neighbors[0]=data_021536e4[0];s->neighbors[1]=data_021536e4[1];s->neighbors[2]=data_021536e4[2];s->neighbors[3]=data_021536e4[3];return;case 2:s->neighbors[0]=data_021536ec[0];s->neighbors[1]=data_021536ec[1];s->neighbors[2]=data_021536ec[2];s->neighbors[3]=data_021536ec[3];return;case 3:s->neighbors[0]=data_021536f4[0];s->neighbors[1]=data_021536f4[1];s->neighbors[2]=data_021536f4[2];s->neighbors[3]=data_021536f4[3];return;case 4:s->neighbors[0]=data_021536fc[0];s->neighbors[1]=data_021536fc[1];s->neighbors[2]=data_021536fc[2];s->neighbors[3]=data_021536fc[3];return;case 5:s->neighbors[0]=data_02153704[0];s->neighbors[1]=data_02153704[1];s->neighbors[2]=data_02153704[2];s->neighbors[3]=data_02153704[3];return;case 6:s->neighbors[0]=data_0215370c[0];s->neighbors[1]=data_0215370c[1];s->neighbors[2]=data_0215370c[2];s->neighbors[3]=data_0215370c[3];return;case 7:s->neighbors[0]=data_02153714[0];s->neighbors[1]=data_02153714[1];s->neighbors[2]=data_02153714[2];s->neighbors[3]=data_02153714[3];return;case 8:if(s->previous_cursor==5){s->neighbors[0]=data_0215371c[0];s->neighbors[1]=data_0215371c[1];s->neighbors[2]=data_0215371c[2];s->neighbors[3]=data_0215371c[3];return;}s->neighbors[0]=data_02153724[0];s->neighbors[1]=data_02153724[1];s->neighbors[2]=data_02153724[2];s->neighbors[3]=data_02153724[3];return;case 9:s->neighbors[0]=data_0215372c[0];s->neighbors[1]=data_0215372c[1];s->neighbors[2]=data_0215372c[2];s->neighbors[3]=data_0215372c[3];return;default:return;}}