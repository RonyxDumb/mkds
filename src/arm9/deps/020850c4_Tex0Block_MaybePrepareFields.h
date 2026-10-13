#pragma once
/* Function-specific inferred declarations. */
int Tex0Block_GetCompressedTextureDataSize(int param_1);
int Tex0Block_GetPaletteDataSize(int param_1);
int Tex0Block_GetTextureDataSize(int param_1);
void Tex0Block_MaybeCopyPaletteToMem(int param_1,int param_2);
void Tex0Block_MaybeCopyTexturesToMem(int param_1,int param_2);
undefined4 Tex0Block_MaybePrepareFields(int param_1);
void Tex0Block_SetPaletteVramKey(int param_1,undefined4 param_2);
void Tex0Block_SetTexturesVramKeys(int param_1,int param_2,int param_3);
#define uRam0208525c (*(uint *)(uintptr_t)0x208525cu)
#define uRam02085260 (*(uint *)(uintptr_t)0x2085260u)
#define uRam02085264 (*(uint *)(uintptr_t)0x2085264u)
#define uRam02085268 (*(uint *)(uintptr_t)0x2085268u)
