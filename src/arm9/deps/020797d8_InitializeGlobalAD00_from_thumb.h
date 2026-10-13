#pragma once
/* Function-specific inferred declarations. */
void CharacterKart_PatchRobPalette_from_thumb(int *param_1,int param_2);
void CopyKartCharPhysicalParam(int param_1,uint param_2,uint param_3);
void CreateLoadPhysicalParams(undefined4 param_1,int param_2);
undefined4 DetermineIsP_from_thumb(uint param_1);
void Dispose_KM1_Mount_KM2_from_thumb(void);
void FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb(undefined4 param_1);
int FindFileBuffer_KME_KM1_KM2_KSB_from_thumb(undefined4 param_1);
char * FormatCharacterFaceAnimationNsbtpPath(void);
undefined4 GetKartAPaletteData_from_thumb(void);
void Gfx_ReadPalette(int *param_1,int param_2);
void InitializeGlobalAD00_from_thumb(undefined4 param_1,int param_2);
void LoadAD00KillerItemModel_from_thumb(undefined4 param_1);
void MaybeLoadKartAIData_from_thumb(void);
undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2);
void Mem_CpuCopy8(ushort *param_1,uint *param_2,uint param_3);
void SetCurrentlyInKartModelMenu(int param_1);
void StructAD00Sub_Initialize_from_thumb(undefined4 *param_1);
void StructAD00Sub_SetKartIndex_from_thumb(int param_1,undefined4 param_2);
void StructAD00Sub_SomeFn_from_thumb(int param_1);
void func_02079678(undefined4 param_1,int param_2);
#define piRam02079978 (*(int **)(uintptr_t)0x2079978u)
#define piRam02079980 (*(int **)(uintptr_t)0x2079980u)
#define puRam02079970 (*(undefined4 **)(uintptr_t)0x2079970u)
#define uRam0207996c (*(undefined4 *)(uintptr_t)0x207996cu)
#define uRam02079974 (*(undefined4 *)(uintptr_t)0x2079974u)
#define uRam0207997c (*(undefined4 *)(uintptr_t)0x207997cu)
#define uRam02079984 (*(undefined4 *)(uintptr_t)0x2079984u)
