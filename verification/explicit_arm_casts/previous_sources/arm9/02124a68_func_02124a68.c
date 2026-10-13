/* Decompiled C draft; module arm9; ROM address 02124a68. No matching claim. */
#include "types.h"
#include "deps/02124a68_func_02124a68.h"

int func_02124a68(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = CellBank_GetMetatileEntry(param_2,*(uint *)(param_3 + param_1 * 8 + 0xc) & 0xffff);
  return (int)(*(ushort *)(*(int *)(iVar1 + 4) + 4) & uRam02124a94) >> 0xc;
}

