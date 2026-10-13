/* Decompiled C draft; module arm9_ov000; ROM address 0219a5b0. No matching claim. */
#include "types.h"
#include "deps/0219a5b0_FUN_0219a5b0.h"

undefined4 FUN_0219a5b0(int param_1,undefined4 param_2,undefined2 param_3)

{
  undefined4 *puVar1;
  undefined4 *local_a8;
  undefined4 local_a4;
  undefined2 local_a0;
  
  local_a8 = &local_a4;
  local_a4 = param_2;
  local_a0 = param_3;
  puVar1 = (undefined4 *)FUN_0218de28((int *)(uintptr_t)(*(undefined4 *)(param_1 + 0xc)),(undefined4)(uintptr_t)(&local_a8));
  if (puVar1 != (undefined4 *)0x0) {
    return *puVar1;
  }
  return 0;
}

