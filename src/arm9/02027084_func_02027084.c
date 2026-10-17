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
extern void func_02124b1c(void *,unsigned short,int);
#define system_mode (*(unsigned short *)0x27ffc40u)
void func_02027084(void){CharacterSelectState *s=state;unsigned char *gfx=(unsigned char *)s+0x1c;if(system_mode!=2){int count=*(unsigned short *)(*(unsigned char **)(gfx+12)+6),i,off;i=0;if(count>0){off=0;do{func_02124b1c(*(unsigned char **)(gfx+24)+off,state->render_value,state->alpha);off+=64;i++;}while(i<count);}}}