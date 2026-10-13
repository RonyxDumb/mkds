/* Decompiled C draft; module arm9_ov000; ROM address 021a4818. No matching claim. */
#include "types.h"
#include "deps/021a4818_FUN_021a4818.h"

void FUN_021a4818(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    param_1 = *DAT_021a4860;
  }
  if (*(int *)(param_1 + 0xbc) != 0) {
    iVar1 = FUN_0218e8c4();
    if ((uint)(iVar1 - *(int *)(param_1 + 0xac)) < DAT_021a4864) {
      *(undefined4 *)(param_1 + 0xb4) = 1;
      return;
    }
    FUN_021a3a18((undefined4 *)(uintptr_t)(param_1),1);
    *(undefined4 *)(param_1 + 0xb4) = 0;
  }
  return;
}

