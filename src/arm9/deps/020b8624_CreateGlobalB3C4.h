#pragma once
/* Function-specific inferred declarations. */
void Arm_FlushRange(uint param_1,int param_2);
int Bmg_GetRawStringPointer_from_thumb(undefined4 param_1,undefined4 param_2);
int CellBank_GetMetatileEntry(ushort *param_1,uint param_2);
undefined4 ComputeSomeInterCharacterWidth(undefined4 param_1);
void CopyMemory16(int param_1,int param_2,int param_3);
void CreateGlobalB3C4(void);
uint ExecutionContext_GetHeapHandle(int param_1);
void FormatRacerNameString_from_thumb(undefined4 param_1,int param_2,int param_3);
void FormatTimeTrialRecordRacerNameString(int param_1,int param_2,int param_3);
void G2d_Sprite_CreateFromTiles(void);
void G2d_Text_PrintString(int param_1,int param_2,int param_3,undefined4 param_4,uint param_5,undefined4 param_6);
uint GetActiveExecutionContext(void);
undefined4 GetBmgIndexFromCircuitIndex_from_thumb(int param_1);
ushort GetCurrentPlayerRacerId(void);
undefined4 GetLoadedFont_from_thumb(int param_1);
undefined4 GetSomeInterCharacterWidth(undefined4 param_1);
void Gfx_ReadCharGraphics(int *param_1,int param_2);
void Gfx_ReadPalette(int *param_1,int param_2);
void LoadCellBankFrom(int *param_1,int param_2);
undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2);
void func_020b46d0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,int param_8);
void func_020b47c0(void);
void func_020b47cc(void);
#define DAT_020b95c0 (*(undefined4 *)(uintptr_t)0x20b95c0u)
#define DAT_020b95c4 (*(undefined4 **)(uintptr_t)0x20b95c4u)
#define DAT_020b95c8 (*(undefined4 *)(uintptr_t)0x20b95c8u)
#define DAT_020b95cc (*(int *)(uintptr_t)0x20b95ccu)
#define DAT_020b95d0 (*(undefined4 *)(uintptr_t)0x20b95d0u)
#define DAT_020b95d4 (*(int *)(uintptr_t)0x20b95d4u)
#define DAT_020b95d8 (*(uint *)(uintptr_t)0x20b95d8u)
#define DAT_020b95dc (*(undefined4 *)(uintptr_t)0x20b95dcu)
#define DAT_020b95e0 (*(int *)(uintptr_t)0x20b95e0u)
#define DAT_020b95e4 (*(undefined4 *)(uintptr_t)0x20b95e4u)
#define DAT_020b95e8 (*(int *)(uintptr_t)0x20b95e8u)
#define DAT_020b95ec (*(undefined4 *)(uintptr_t)0x20b95ecu)
#define DAT_020b95f0 (*(int *)(uintptr_t)0x20b95f0u)
#define DAT_020b95f4 (*(undefined4 *)(uintptr_t)0x20b95f4u)
#define DAT_020b95f8 (*(int *)(uintptr_t)0x20b95f8u)
#define DAT_020b95fc (*(undefined4 *)(uintptr_t)0x20b95fcu)
#define DAT_020b9600 (*(undefined4 *)(uintptr_t)0x20b9600u)
#define DAT_020b9604 (*(undefined4 *)(uintptr_t)0x20b9604u)
#define DAT_020b9608 (*(undefined4 *)(uintptr_t)0x20b9608u)
#define DAT_020b960c (*(undefined4 *)(uintptr_t)0x20b960cu)
#define DAT_020b9610 (*(undefined4 *)(uintptr_t)0x20b9610u)
#define DAT_020b9614 (*(undefined4 *)(uintptr_t)0x20b9614u)
#define DAT_020b9618 (*(undefined4 *)(uintptr_t)0x20b9618u)
#define DAT_020b961c (*(undefined4 *)(uintptr_t)0x20b961cu)
#define DAT_020b9620 (*(undefined4 *)(uintptr_t)0x20b9620u)
#define DAT_020b9628 (*(undefined4 *)(uintptr_t)0x20b9628u)
#define DAT_020b962c (*(undefined4 *)(uintptr_t)0x20b962cu)
#define DAT_020b9630 (*(undefined4 *)(uintptr_t)0x20b9630u)
#define DAT_020b9634 (*(undefined4 *)(uintptr_t)0x20b9634u)
#define DAT_020b9638 (*(undefined4 *)(uintptr_t)0x20b9638u)
#define DAT_020b9640 (*(undefined4 *)(uintptr_t)0x20b9640u)
#define DAT_020b9644 (*(undefined4 *)(uintptr_t)0x20b9644u)
#define DAT_020b9648 (*(undefined4 *)(uintptr_t)0x20b9648u)
#define DAT_020b964c (*(undefined4 *)(uintptr_t)0x20b964cu)
#define DAT_020b9650 (*(undefined4 *)(uintptr_t)0x20b9650u)
#define DAT_020b9654 (*(undefined4 *)(uintptr_t)0x20b9654u)
#define DAT_020b9658 (*(undefined4 *)(uintptr_t)0x20b9658u)
#define DAT_020b965c (*(int *)(uintptr_t)0x20b965cu)
#define DAT_020b9660 (*(undefined4 *)(uintptr_t)0x20b9660u)
#define DAT_020b9664 (*(int *)(uintptr_t)0x20b9664u)
#define DAT_020b9668 (*(undefined4 *)(uintptr_t)0x20b9668u)
#define DAT_020b966c (*(int *)(uintptr_t)0x20b966cu)
#define DAT_020b9670 (*(undefined4 *)(uintptr_t)0x20b9670u)
#define DAT_020b9674 (*(undefined4 *)(uintptr_t)0x20b9674u)
#define DAT_020b9678 (*(undefined4 *)(uintptr_t)0x20b9678u)
#define DAT_020b967c (*(undefined4 *)(uintptr_t)0x20b967cu)
#define DAT_020b9680 (*(undefined4 *)(uintptr_t)0x20b9680u)
#define DAT_020b9684 (*(undefined4 *)(uintptr_t)0x20b9684u)
#define DAT_020b997c (*(undefined4 *)(uintptr_t)0x20b997cu)
#define DAT_020b9980 (*(undefined4 *)(uintptr_t)0x20b9980u)
#define DAT_020b9984 (*(undefined4 *)(uintptr_t)0x20b9984u)
#define DAT_020b9988 (*(int *)(uintptr_t)0x20b9988u)
#define DAT_020b998c (*(undefined4 *)(uintptr_t)0x20b998cu)
#define DAT_020b9990 (*(undefined4 *)(uintptr_t)0x20b9990u)
