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
#define state (*(CharacterSelectState **)0x2174e14u)
extern short data_02153554[];
extern void func_02025c6c(int,int,void *);
void func_020271e8(void){CharacterSelectState *s=state;void *gfx=(unsigned char *)s+0x1c;int off=s->cursor*4;func_02025c6c(24,data_02153554[off],*(void **)((unsigned char *)gfx+0xc));func_02025c6c(25,data_02153554[off],*(void **)((unsigned char *)gfx+0xc));}