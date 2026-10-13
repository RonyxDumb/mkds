/* Decompiled C draft; module arm9_ov000; ROM address 02194b4c. No matching claim. */
#include "types.h"
#include "deps/02194b4c_FUN_02194b4c.h"

void FUN_02194b4c(int param_1)

{
  if (*(int *)(param_1 + 8) != 0) {
    FUN_021a3668(*(undefined4 *)(*(int *)(param_1 + 8) + 8));
    *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
    FUN_021a3668(*(undefined4 *)(*(int *)(param_1 + 8) + 0xc));
    *(undefined4 *)(*(int *)(param_1 + 8) + 0xc) = 0;
    FUN_021a3668(*(undefined4 *)(param_1 + 8));
    *(undefined4 *)(param_1 + 8) = 0;
  }
  FUN_0219210c(param_1);
  FUN_021a3668(*(undefined4 *)(param_1 + 0x10));
  *(undefined4 *)(param_1 + 0x10) = 0;
  FUN_021a3668(*(undefined4 *)(param_1 + 0x18));
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}

