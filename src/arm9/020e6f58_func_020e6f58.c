/* Decompiled C draft; module arm9; ROM address 020e6f58. No matching claim. */
#include "types.h"
#include "deps/020e6f58_func_020e6f58.h"

void func_020e6f58(int *param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  
  uVar1 = *(ushort *)(param_1 + 1);
  *(ushort *)(param_1 + 1) = uVar1 + 1;
  *(int *)(*param_1 + (uint)uVar1 * 4) = param_2;
  if (param_1[6] == 3) {
    param_1[6] = *(int *)(*(int *)(param_2 + 0x98) + 0x20);
  }
  if (param_1[7] == 0) {
    param_1[7] = *(int *)(*(int *)(param_2 + 0x98) + 4);
  }
  if (param_1[8] == 3) {
    iVar2 = func_020d6910(6);
    param_1[8] = iVar2;
  }
  return;
}

