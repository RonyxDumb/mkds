/* Decompiled C draft; module arm9_ov000; ROM address 021a49a0. No matching claim. */
#include "types.h"
#include "deps/021a49a0_FUN_021a49a0.h"

void FUN_021a49a0(int param_1)

{
  if (param_1 == 0) {
    param_1 = *DAT_021a49c8;
  }
  if (*(int *)(param_1 + 0xbc) != 0) {
    FUN_021a4868((int *)(uintptr_t)(param_1));
  }
  FUN_021a4940((undefined4 *)(uintptr_t)(param_1));
  return;
}

