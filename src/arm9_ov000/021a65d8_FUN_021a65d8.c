/* Decompiled C draft; module arm9_ov000; ROM address 021a65d8. No matching claim. */
#include "types.h"
#include "deps/021a65d8_FUN_021a65d8.h"

int FUN_021a65d8(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_021a5b30();
  iVar2 = 0;
  if ((*(int *)(iVar1 + DAT_021a660c) != 0) && (0xc < *(uint *)(iVar1 + DAT_021a6610))) {
    for (iVar2 = *(int *)(*(int *)(iVar1 + DAT_021a660c) + 4);
        (iVar2 != 0 && (*(int *)(iVar2 + 4) != param_1)); iVar2 = *(int *)(iVar2 + 0xc)) {
    }
  }
  return iVar2;
}

