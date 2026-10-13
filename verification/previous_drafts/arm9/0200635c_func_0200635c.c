/* Decompiled C draft; module arm9; ROM address 0200635c. No matching claim. */
#include "types.h"
#include "deps/0200635c_func_0200635c.h"

void func_0200635c(int param_1,uint param_2)

{
  int iVar1;
  
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  *(uint *)(param_1 + 0xc) = param_2;
  iVar1 = ((int)param_2 >> 5) * 4;
  *(uint *)(*(int *)(param_1 + 0x14) + iVar1) =
       *(uint *)(*(int *)(param_1 + 0x14) + iVar1) | 1 << (param_2 & 0x1f);
  return;
}

