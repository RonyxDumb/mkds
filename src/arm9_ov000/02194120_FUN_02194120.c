/* Decompiled C draft; module arm9_ov000; ROM address 02194120. No matching claim. */
#include "types.h"
#include "deps/02194120_FUN_02194120.h"

void FUN_02194120(undefined4 param_1,int param_2)

{
  FUN_0218e524(*(undefined4 *)(param_2 + 8),2);
  FUN_0218e53c(*(undefined4 *)(param_2 + 8));
  FUN_021a3668(*(undefined4 *)(param_2 + 0x18));
  *(undefined4 *)(param_2 + 0x18) = 0;
  FUN_021a3668(*(undefined4 *)(param_2 + 0x28));
  *(undefined4 *)(param_2 + 0x28) = 0;
  if (*(int *)(param_2 + 0x38) != 0) {
    FUN_0218dc48();
    *(undefined4 *)(param_2 + 0x38) = 0;
  }
  FUN_021a3668(param_2);
  return;
}

