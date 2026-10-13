#pragma once
/* Function-specific inferred declarations. */
void Arm_FlushRange(uint param_1,int param_2);
int Bmg_GetRawStringPointer_from_thumb(undefined4 param_1,undefined4 param_2);
int CellBank_GetMetatileEntry(ushort *param_1,uint param_2);
void CopySomePaletteData(undefined4 param_1,int param_2,uint param_3);
void CopyTileDataTop_0(undefined4 param_1,int param_2,uint param_3);
uint ExecutionContext_GetHeapHandle(int param_1);
void G2d_Sprite_CreateFromTiles(void);
void G2d_Text_PrintString(int param_1,int param_2,int param_3,undefined4 param_4,uint param_5,undefined4 param_6);
uint GetActiveExecutionContext(void);
undefined4 GetBmgIndexFromCircuitIndex_from_thumb(int param_1);
undefined4 GetLoadedFont_from_thumb(int param_1);
undefined4 GetSomeInterCharacterWidth(undefined4 param_1);
undefined4 GetSomeInterCharacterWidth2(undefined4 param_1);
void Gfx_ReadCharGraphics(int *param_1,int param_2);
void Gfx_ReadPalette(int *param_1,int param_2);
void InitializeRaceIntroData(void);
void LoadCellBankFrom(int *param_1,int param_2);
undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2);
void func_020b47c0(void);
void func_020b47cc(void);
#define puRam020c4e28 (*(undefined4 **)(uintptr_t)0x20c4e28u)
#define uRam020c4e24 (*(undefined4 *)(uintptr_t)0x20c4e24u)
#define uRam020c4e2c (*(undefined4 *)(uintptr_t)0x20c4e2cu)
#define uRam020c4e30 (*(undefined4 *)(uintptr_t)0x20c4e30u)
#define uRam020c4e34 (*(undefined4 *)(uintptr_t)0x20c4e34u)
#define uRam020c4e38 (*(uint *)(uintptr_t)0x20c4e38u)
#define uRam020c4e3c (*(undefined4 *)(uintptr_t)0x20c4e3cu)
#define uRam020c4e40 (*(undefined4 *)(uintptr_t)0x20c4e40u)
#define uRam020c4e44 (*(undefined4 *)(uintptr_t)0x20c4e44u)
