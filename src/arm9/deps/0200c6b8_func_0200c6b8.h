#pragma once
/* Function-specific inferred declarations. */
void DC_FlushAll(void);
void DC_InvalidateRangeNoClean(uint param_1,int param_2);
void MI_DmaCopy16(int param_1,undefined4 param_2,undefined4 param_3,uint param_4);
void Mem_CpuCopy32(undefined4 *param_1,undefined4 *param_2,int param_3);
void ReadSomeExmemcntData_from_thumb(int *param_1);
uint SetIE(undefined4 param_1);
void WaitByLoop(void);
void func_0200c46c(undefined4 param_1);
void func_0200c4a4(undefined4 param_1,int *param_2);
void func_0200c4c0(undefined4 param_1,uint *param_2);
void func_0200c508(int *param_1);
void func_0200c6b8(void);
#define iRam0200c7d4 (*(int *)(uintptr_t)0x200c7d4u)
#define iRam0200c7dc (*(int *)(uintptr_t)0x200c7dcu)
#define iRam0200c7e4 (*(int *)(uintptr_t)0x200c7e4u)
#define iRam0200c7f0 (*(int *)(uintptr_t)0x200c7f0u)
#define piRam0200c7b4 (*(int **)(uintptr_t)0x200c7b4u)
#define psRam0200c7c4 (*(short **)(uintptr_t)0x200c7c4u)
#define puRam0200c7b8 (*(ushort **)(uintptr_t)0x200c7b8u)
#define puRam0200c7c0 (*(undefined2 **)(uintptr_t)0x200c7c0u)
#define puRam0200c7c8 (*(ushort **)(uintptr_t)0x200c7c8u)
#define puRam0200c7e0 (*(undefined2 **)(uintptr_t)0x200c7e0u)
#define uRam0200c7bc (*(undefined4 *)(uintptr_t)0x200c7bcu)
#define uRam0200c7cc (*(uint *)(uintptr_t)0x200c7ccu)
#define uRam0200c7d0 (*(undefined4 *)(uintptr_t)0x200c7d0u)
#define uRam0200c7d8 (*(undefined4 *)(uintptr_t)0x200c7d8u)
#define uRam0200c7e8 (*(undefined4 *)(uintptr_t)0x200c7e8u)
#define uRam0200c7ec (*(undefined4 *)(uintptr_t)0x200c7ecu)
