/* Decompiled C draft; module arm9_ov000; ROM address 0219b868. No matching claim. */
#include "types.h"
#include "deps/0219b868_FUN_0219b868.h"

undefined4 FUN_0219b868(uint param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  byte *local_10 [2];
  
  iVar1 = FUN_021a158c(local_10);
  iVar2 = 0;
  if (0 < iVar1) {
    do {
      if (param_1 == *local_10[0]) break;
      local_10[0] = local_10[0] + 1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  if (iVar2 != iVar1) {
    uVar3 = FUN_021a1620();
    return uVar3;
  }
  return 0;
}

