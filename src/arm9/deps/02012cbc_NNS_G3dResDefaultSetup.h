#pragma once
/* Function-specific inferred declarations. */
undefined4 NNS_G3dResDefaultSetup(uint param_1);
int Nsbmd_GetMDL0Block(int param_1);
int Nsbtx_GetTEX0Block(uint param_1);
int Tex0Block_GetCompressedTextureDataSize(int param_1);
int Tex0Block_GetPaletteDataSize(int param_1);
int Tex0Block_GetTextureDataSize(int param_1);
void Tex0Block_MaybeCopyPaletteToMem(int param_1,int param_2);
void Tex0Block_MaybeCopyTexturesToMem(int param_1,int param_2);
void Tex0Block_SetPaletteVramKey(int param_1,undefined4 param_2);
void Tex0Block_SetTexturesVramKeys(int param_1,int param_2,int param_3);
uint func_02010168(int param_1,undefined4 param_2);
#define uRam02012ef8 (*(uint *)(uintptr_t)0x2012ef8u)
#define uRam02012efc (*(uint *)(uintptr_t)0x2012efcu)
#define uRam02012f00 (*(uint *)(uintptr_t)0x2012f00u)
#define uRam02012f04 (*(uint *)(uintptr_t)0x2012f04u)
#define uRam02012f08 (*(uint *)(uintptr_t)0x2012f08u)
#define uRam02012f0c (*(uint *)(uintptr_t)0x2012f0cu)
#define uRam02012f10 (*(uint *)(uintptr_t)0x2012f10u)
#define uRam02012f14 (*(uint *)(uintptr_t)0x2012f14u)
#define uRam02012f18 (*(uint *)(uintptr_t)0x2012f18u)
#define uRam02012f1c (*(uint *)(uintptr_t)0x2012f1cu)
#define uRam02012f20 (*(uint *)(uintptr_t)0x2012f20u)
