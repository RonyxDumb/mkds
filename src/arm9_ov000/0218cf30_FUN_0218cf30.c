/* Decompiled C draft; module arm9_ov000; ROM address 0218cf30. No matching claim. */
#include "types.h"
#include "deps/0218cf30_FUN_0218cf30.h"

void FUN_0218cf30(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  uVar4 = *(uint *)(param_1 + 0x80);
  if (0 < (int)uVar4) {
    uVar7 = *DAT_0218cfa8;
    uVar1 = func_0x0213a434(uVar7);
    if (uVar1 < uVar4) {
      iVar5 = *(int *)(param_1 + 0x7c);
      uVar6 = *DAT_0218cfa8;
      uVar2 = func_0x0213a434(uVar6);
      iVar3 = func_0x0213a038(iVar5,uVar6,uVar2);
      if (iVar3 == 0) {
        iVar3 = func_0x0213a434(uVar7);
        FUN_0218c45c(param_1,iVar5 + iVar3);
        (**(code **)(param_1 + DAT_0218cfb4))
                  (param_1,5,*DAT_0218cfac,*(undefined4 *)(param_1 + DAT_0218cfb0));
      }
    }
  }
  (**(code **)(param_1 + DAT_0218cfb4))
            (param_1,4,*DAT_0218cfac,*(undefined4 *)(param_1 + DAT_0218cfb0));
  FUN_0218c980((undefined4 *)(uintptr_t)(param_1));
  return;
}

