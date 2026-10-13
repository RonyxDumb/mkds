/* Decompiled C draft; module arm9_ov001; ROM address 0218d520. No matching claim. */
#include "types.h"
#include "deps/0218d520_FUN_0218d520.h"

undefined4 FUN_0218d520(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  undefined8 uVar6;
  
  uVar1 = FUN_02187fc0();
  iVar2 = FUN_021881a8(param_1,uVar1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xa0),0);
  if (iVar2 != 0) {
    uVar3 = func_0x020a1154((short)*(char *)(*DAT_0218d7a0 + 0x62));
    if (uVar3 < 2) {
      iVar5 = DAT_0218d7a4 - *(int *)(*(int *)(param_1 + 0xa0) + 0xac);
      iVar2 = FUN_02187f38(param_1);
      uVar6 = func_0x02133048(iVar2,iVar2 >> 0x1f,iVar5,iVar5 >> 0x1f);
      uVar3 = (uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14;
    }
    else {
      uVar3 = func_0x020a1154((short)*(char *)(*DAT_0218d7a0 + 0x62));
      if (uVar3 < 3) {
        iVar5 = DAT_0218d7a4 - *(int *)(*(int *)(param_1 + 0xa0) + 0xa8);
        iVar2 = FUN_02187f38(param_1);
        uVar6 = func_0x02133048(iVar2,iVar2 >> 0x1f,iVar5,iVar5 >> 0x1f);
        uVar3 = (uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14;
      }
      else {
        uVar3 = FUN_02187f38(param_1);
      }
    }
    iVar2 = FUN_02187f7c(param_1);
    if (0 < iVar2) {
      FUN_0218d9cc(param_1);
    }
    if (*(int *)(*DAT_0218d7a0 + 8) == 4) {
      iVar2 = func_0x020a126c();
    }
    else {
      iVar2 = 0;
    }
    if (((iVar2 == 0) && (*(int *)(param_1 + 0xa8) == 0)) &&
       (iVar2 = FUN_021871f8(param_1,3), iVar2 != 0)) {
      iVar2 = *(int *)(param_1 + 0xa0);
      iVar2 = FUN_02188084(param_1,*(undefined4 *)(iVar2 + DAT_0218d7a8),
                           *(undefined4 *)(iVar2 + DAT_0218d7ac),
                           *(undefined4 *)(iVar2 + DAT_0218d7b0));
      if (iVar2 == 0) {
        iVar2 = *(int *)(param_1 + 0xa0);
        iVar2 = FUN_02188084(param_1,*(undefined4 *)(iVar2 + DAT_0218d7d0),
                             *(undefined4 *)(iVar2 + DAT_0218d7d4),
                             *(undefined4 *)(iVar2 + DAT_0218d7d8));
        if (iVar2 != 0) {
          *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218d7b4)
          ;
          *(undefined4 *)(param_1 + DAT_0218d7b8) = 3;
          FUN_02188d30(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218d7dc),
                       *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218d7e0),DAT_0218d7c4);
          uVar3 = uVar3 - *(int *)(*(int *)(param_1 + 0xa0) + DAT_0218d7c8);
          func_0x020d2774(param_1,DAT_0218d7cc);
        }
      }
      else {
        *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218d7b4);
        *(undefined4 *)(param_1 + DAT_0218d7b8) = 3;
        FUN_02188d30(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218d7bc),
                     *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218d7c0),DAT_0218d7c4);
        uVar3 = uVar3 - *(int *)(*(int *)(param_1 + 0xa0) + DAT_0218d7c8);
        func_0x020d2774(param_1,DAT_0218d7cc);
      }
    }
    FUN_0218d824(param_1,uVar3);
    FUN_0218d87c(param_1,uVar3);
    FUN_02187e78(param_1);
    if (*(int *)(param_1 + DAT_0218d7e4) == 0) {
      FUN_02187e48(param_1,4);
    }
  }
  if (0 < *(int *)(param_1 + 0xa8)) {
    *(int *)(param_1 + 0xa8) = *(int *)(param_1 + 0xa8) + -1;
  }
  iVar2 = FUN_021871f8(param_1,5);
  if (iVar2 != 0) {
    iVar2 = FUN_02188220(param_1);
    if (iVar2 == 2) {
      iVar2 = *(int *)(param_1 + DAT_0218d7e8) + 1;
      if (5 < iVar2) {
        iVar2 = 0;
      }
      piVar4 = (int *)(param_1 + DAT_0218d7e8);
      *piVar4 = iVar2;
      if (*piVar4 == 0) {
        FUN_021875c0(param_1,0,0,0,DAT_0218d7ec,0x1c);
      }
      iVar2 = *(int *)(param_1 + DAT_0218d7f0) + 1;
      if (0x11 < iVar2) {
        iVar2 = 0;
      }
      piVar4 = (int *)(param_1 + DAT_0218d7f0);
      *piVar4 = iVar2;
      if (*piVar4 == 0) {
        func_0x020d2774(param_1,DAT_0218d7f4);
      }
    }
    else {
      iVar2 = FUN_02188220(param_1);
      if (iVar2 == 1) {
        iVar2 = *(int *)(param_1 + DAT_0218d7e8) + 1;
        if (0x11 < iVar2) {
          iVar2 = 0;
        }
        piVar4 = (int *)(param_1 + DAT_0218d7e8);
        *piVar4 = iVar2;
        if (*piVar4 == 0) {
          FUN_021875c0(param_1,0,0,0,DAT_0218d7f8,0x1c);
          func_0x020d2774(param_1,DAT_0218d7fc);
        }
      }
    }
  }
  return 0;
}

