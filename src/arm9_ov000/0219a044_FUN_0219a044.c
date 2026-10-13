/* Decompiled C draft; module arm9_ov000; ROM address 0219a044. No matching claim. */
#include "types.h"
#include "deps/0219a044_FUN_0219a044.h"

void FUN_0219a044(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    *(undefined4 *)(param_1 + 0x18) = 1;
    FUN_021988e8();
    iVar1 = FUN_02198448(param_1);
    if (iVar1 != 0) {
      FUN_0219a3f8((undefined4 *)(uintptr_t)(param_1));
    }
  }
  return;
}

