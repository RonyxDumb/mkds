/* Decompiled C draft; module arm9; ROM address 0212497c. No matching claim. */
#include "types.h"
#include "deps/0212497c_func_0212497c.h"

uint func_0212497c(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = CellBank_GetMetatileEntry(param_2,*(uint *)(param_3 + param_1 * 8 + 0xc) & 0xffff);
  return *(ushort *)(*(int *)(iVar1 + 4) + 4) & uRam021249a4;
}

