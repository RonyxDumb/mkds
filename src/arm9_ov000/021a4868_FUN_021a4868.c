/* Decompiled C draft; module arm9_ov000; ROM address 021a4868. No matching claim. */
#include "types.h"
#include "deps/021a4868_FUN_021a4868.h"

void FUN_021a4868(int *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_0218e8c4();
  if (*param_1 == -1) {
    return;
  }
  if ((param_1[0x2e] < 1) || (uVar1 - param_1[0x2b] <= DAT_021a492c)) {
    if ((param_1[0x2d] == 0) || (uVar1 - param_1[0x2b] <= DAT_021a492c)) {
      uVar2 = param_1[0x2b];
      if (((DAT_021a4938 < uVar1 - uVar2) || (uVar2 == 0)) || (uVar1 < uVar2)) {
        FUN_021a3a18(param_1,0);
      }
    }
    else {
      FUN_021a3a18(param_1,1);
    }
  }
  else {
    if (3 < param_1[0x2e]) {
      param_1[0x2e] = 0;
      (*(code *)param_1[0x27])(5,DAT_021a4930,*(undefined4 *)((int)param_1 + DAT_021a4934));
      return;
    }
    FUN_021a3a18(param_1,3);
    param_1[0x2e] = param_1[0x2e] + 1;
  }
  if (DAT_021a493c < uVar1 - param_1[0x2c]) {
    FUN_021a3bbc(param_1);
  }
  return;
}

