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
extern void *FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(const void *);extern void Gfx_ReadCharGraphics(void *,void *);extern void Gfx_ReadPalette(void *,void *);extern void LoadCellBankFrom(void *,void *);
void VerifySelectCharacterFiles_from_thumb(void){void *characters=0,*palette=0,*cells=0;Gfx_ReadCharGraphics(&characters,FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb((const void *)0x2161b3cu));LoadCellBankFrom(&cells,FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb((const void *)0x2161b5cu));Gfx_ReadPalette(&palette,FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb((const void *)0x2161b7cu));Gfx_ReadCharGraphics(&characters,FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb((const void *)0x2161b9cu));LoadCellBankFrom(&cells,FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb((const void *)0x2161bb8u));Gfx_ReadPalette(&palette,FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb((const void *)0x2161bd4u));Gfx_ReadCharGraphics(&characters,FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb((const void *)0x2161bf0u));LoadCellBankFrom(&cells,FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb((const void *)0x2161c14u));Gfx_ReadCharGraphics(&characters,FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb((const void *)0x2161c38u));LoadCellBankFrom(&cells,FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb((const void *)0x2161c60u));}