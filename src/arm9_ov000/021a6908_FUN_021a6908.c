/* Decompiled C draft; module arm9_ov000; ROM address 021a6908. No matching claim. */
#include "types.h"
#include "deps/021a6908_FUN_021a6908.h"

undefined4 FUN_021a6908(int param_1)

{
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = DAT_021a6930;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    return 1;
  }
  if (*(int *)(param_1 + 8) == DAT_021a6930) {
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    return 1;
  }
  return 0;
}

