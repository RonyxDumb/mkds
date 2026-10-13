/* Decompiled C draft; module arm9_ov000; ROM address 021a9358. No matching claim. */
#include "types.h"
#include "deps/021a9358_FUN_021a9358.h"

int FUN_021a9358(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (*(int *)(iVar1 + DAT_021a9388) == 0) {
    if (*(int *)(param_1 + 0x44) == 0) {
      return 0;
    }
    FUN_021a9d68();
  }
  return *(int *)(iVar1 + DAT_021a938c) - *(int *)(iVar1 + DAT_021a9390);
}

