/* Decompiled C draft; module arm9_ov000; ROM address 021a6614. No matching claim. */
#include "types.h"
#include "deps/021a6614_FUN_021a6614.h"

int FUN_021a6614(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_021a5b30();
  iVar2 = 0;
  if (param_1 != 0) {
    if ((*(int *)(iVar1 + DAT_021a6664) != 0) && (0xc < *(uint *)(iVar1 + DAT_021a6668))) {
      iVar2 = *(int *)(*(int *)(iVar1 + DAT_021a6664) + 4);
      while ((iVar2 != 0 && (iVar1 = FUN_021a6d1c(iVar2 + 0x14,param_1), iVar1 == 0))) {
        iVar2 = *(int *)(iVar2 + 0xc);
      }
    }
    return iVar2;
  }
  return 0;
}

