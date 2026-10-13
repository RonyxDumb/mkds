/* Decompiled C draft; module arm9_ov000; ROM address 0219a3f8. No matching claim. */
#include "types.h"
#include "deps/0219a3f8_FUN_0219a3f8.h"

void FUN_0219a3f8(undefined4 *param_1)

{
  if (param_1[7] != 0) {
    param_1[5] = 1;
    return;
  }
  FUN_0218e53c(*param_1);
  FUN_0218dfb4((int *)(uintptr_t)(param_1[3]));
  FUN_0218dc48((int *)(uintptr_t)(param_1[4]));
  FUN_021a3668((undefined4)(uintptr_t)(param_1));
  FUN_0218e8b4();
  return;
}

