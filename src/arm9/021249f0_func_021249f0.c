/* Decompiled C draft; module arm9; ROM address 021249f0. No matching claim. */
#include "types.h"
#include "deps/021249f0_func_021249f0.h"

int func_021249f0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = CellBank_GetMetatileEntry((ushort *)(uintptr_t)(param_2),*(uint *)(param_3 + param_1 * 8 + 0xc) & 0xffff);
  return (int)(*(ushort *)(*(int *)(iVar1 + 4) + 4) & uRam02124a1c) >> 10;
}

