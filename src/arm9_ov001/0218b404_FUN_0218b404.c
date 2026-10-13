/* Decompiled C draft; module arm9_ov001; ROM address 0218b404. No matching claim. */
#include "types.h"
#include "deps/0218b404_FUN_0218b404.h"

void FUN_0218b404(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  uint uVar4;
  
  if (*(int *)(*DAT_0218b5b4 + 8) == 4) {
    iVar1 = func_0x020a126c();
  }
  else {
    iVar1 = 0;
  }
  if (iVar1 == 0) {
    uVar2 = FUN_02187fc0(param_2);
    iVar1 = FUN_021881a8(param_2,uVar2,*(undefined4 *)(*(int *)(param_2 + 0xa0) + 0xb4),0);
    if (iVar1 != 0) {
      iVar1 = FUN_02187f7c(param_2);
      if (iVar1 < 200) {
        if (iVar1 < 100) {
          if ((0 < iVar1) && (iVar1 = FUN_021871f8(param_2,1), iVar1 != 0)) {
            FUN_0218bde8(param_2);
            FUN_02188200(param_2,DAT_0218b5b8);
          }
        }
        else {
          iVar1 = FUN_021871f8(param_2,7);
          if (iVar1 != 0) {
            FUN_0218bbac(param_2);
            FUN_02188200(param_2,DAT_0218b5b8);
          }
        }
      }
      else {
        iVar1 = FUN_021871f8(param_2,8);
        if (iVar1 != 0) {
          FUN_0218ba34(param_2);
          FUN_02188200(param_2,DAT_0218b5b8);
        }
      }
      FUN_02187e78(param_2);
      if (*(int *)(param_2 + DAT_0218b5bc) == 0) {
        FUN_02187e48(param_2,3);
      }
    }
    iVar1 = FUN_021871f8(param_2,2);
    if ((iVar1 != 0) &&
       (iVar1 = FUN_02188104(param_2,*(undefined4 *)(*(int *)(param_2 + 0xa0) + DAT_0218b5c0),
                             *(undefined4 *)(*(int *)(param_2 + 0xa0) + DAT_0218b5c4)), iVar1 != 0))
    {
      FUN_0218c490(param_2);
      FUN_02188200(param_2,DAT_0218b5c8);
    }
    iVar1 = FUN_021871f8(param_2,1);
    if (iVar1 != 0) {
      FUN_0218c354(param_2);
      FUN_02188200(param_2,DAT_0218b5c8);
    }
    *(undefined4 *)(param_2 + DAT_0218b5cc) = 1;
  }
  else {
    iVar1 = FUN_021871f8(param_2,1);
    if (iVar1 != 0) {
      if (*(int *)(*DAT_0218b5b4 + 8) == 4) {
        iVar1 = func_0x020a1084((short)*(char *)(*DAT_0218b5b4 + 0x62));
      }
      else {
        iVar1 = 0;
      }
      if (iVar1 == 0) {
        FUN_0218b8f8(param_2);
      }
      else {
        FUN_0218b9b4(param_2);
      }
    }
  }
  FUN_021864ac(param_1,param_2);
  FUN_0219b1fc(*(undefined4 *)(param_2 + DAT_0218b5d0));
  uVar4 = *(int *)(param_2 + DAT_0218b5d4) + 1;
  iVar1 = FUN_02188220(param_2);
  if ((int)(uVar4 + iVar1 * -0x1e) < 0 == SBORROW4(uVar4,iVar1 * 0x1e)) {
    iVar1 = FUN_02188220(param_2);
    uVar4 = iVar1 * 0x1e;
  }
  puVar3 = (uint *)(param_2 + DAT_0218b5d4);
  *puVar3 = uVar4;
  uVar4 = *puVar3;
  iVar1 = func_0x0209b710(*(undefined4 *)(param_2 + DAT_0218b5d0));
  if (iVar1 + -1 <= (int)uVar4) {
    iVar1 = func_0x0209b710(*(undefined4 *)(param_2 + DAT_0218b5d0));
    uVar4 = iVar1 - 1;
  }
  puVar3 = (uint *)(param_2 + DAT_0218b5d4);
  *puVar3 = uVar4;
  func_0x0209b734(*(undefined4 *)(param_2 + DAT_0218b5d0),*puVar3 & 0xffff);
  return;
}

