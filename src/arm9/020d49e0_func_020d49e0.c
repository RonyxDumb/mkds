/* Decompiled C draft; module arm9; ROM address 020d49e0. No matching claim. */
#include "types.h"
#include "deps/020d49e0_func_020d49e0.h"

void func_020d49e0(int *param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(param_1 + 1);
  *(ushort *)(param_1 + 1) = uVar1 + 1;
  *(undefined4 *)(*param_1 + (uint)uVar1 * 4) = param_2;
  return;
}

