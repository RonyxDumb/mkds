/* Decompiled C draft; module arm9_ov000; ROM address 0219a220. No matching claim. */
#include "types.h"
#include "deps/0219a220_FUN_0219a220.h"

void FUN_0219a220(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int local_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if ((*(int *)(param_1 + 0x14) == 0) && (*(int *)(param_1 + 0x24) == 0)) {
    local_10 = param_1;
    uStack_c = param_2;
    uStack_8 = param_3;
    uStack_4 = param_4;
    if (*(int *)(param_1 + 0xc) == 7) {
      iVar2 = FUN_0218dc44(*(undefined4 *)(*(int *)(param_1 + 8) + 0x10));
      iVar4 = 0;
      if (0 < iVar2) {
        do {
          iVar1 = local_10;
          piVar3 = (int *)FUN_0218dbf8(*(undefined4 *)(*(int *)(local_10 + 8) + 0x10),iVar4);
          if (iVar1 == *piVar3) {
            FUN_0218da5c(*(undefined4 *)(*(int *)(iVar1 + 8) + 0x10),iVar4);
            return;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar2);
        return;
      }
    }
    else {
      FUN_0218de8c(*(undefined4 *)(*(int *)(param_1 + 8) + 0xc),&local_10);
    }
  }
  return;
}

