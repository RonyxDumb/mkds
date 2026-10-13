/* Decompiled C draft; module arm9_ov000; ROM address 0218dd74. No matching claim. */
#include "types.h"
#include "deps/0218dd74_FUN_0218dd74.h"

void FUN_0218dd74(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_0218dbf8();
    (**(code **)(param_1 + 0x10))();
  }
  return;
}

