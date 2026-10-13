#pragma once
/* Function-specific inferred declarations. */
int CellBank_GetMetatileEntry(ushort *param_1,uint param_2);
void CopySomePaletteData(undefined4 param_1,int param_2,uint param_3);
void CopyTileDataTop_0(undefined4 param_1,int param_2,uint param_3);
uint ExecutionContext_GetHeapHandle(int param_1);
uint GetActiveExecutionContext(void);
void Gfx_ReadCharGraphics(int *param_1,int param_2);
void Gfx_ReadPalette(int *param_1,int param_2);
void LoadCellBankFrom(int *param_1,int param_2);
void LoadSomeEndingStaffRollStuff(void);
undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2);
void func_020b47c0(void);
#define _DAT_04000000 (*(uint *)(uintptr_t)0x4000000u)
#define puRam020d1588 (*(undefined4 **)(uintptr_t)0x20d1588u)
#define uRam020d1584 (*(undefined4 *)(uintptr_t)0x20d1584u)
#define uRam020d158c (*(undefined4 *)(uintptr_t)0x20d158cu)
#define uRam020d1590 (*(undefined4 *)(uintptr_t)0x20d1590u)
#define uRam020d1594 (*(undefined4 *)(uintptr_t)0x20d1594u)
#define uRam020d1598 (*(uint *)(uintptr_t)0x20d1598u)
