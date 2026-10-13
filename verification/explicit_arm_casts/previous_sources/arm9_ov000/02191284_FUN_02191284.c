/* Decompiled C draft; module arm9_ov000; ROM address 02191284. No matching claim. */
#include "types.h"
#include "deps/02191284_FUN_02191284.h"

int FUN_02191284(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_29c [33];
  undefined1 local_27b [21];
  undefined1 auStack_266 [512];
  undefined1 auStack_66 [82];
  
  iVar5 = *param_1;
  iVar1 = FUN_02196870(param_1,param_3,0);
  if (iVar1 != 0) {
    if ((*(int *)(iVar5 + DAT_02191624) == DAT_02191628) && (*(int *)(iVar5 + DAT_0219162c) != 0)) {
      FUN_0219490c(param_1);
      *(undefined4 *)(iVar5 + DAT_02191630) = 0;
      *(undefined4 *)(iVar5 + DAT_0219162c) = 0;
    }
    else if ((*(int *)(iVar5 + DAT_02191624) == DAT_02191634) &&
            (iVar1 = FUN_021967b4(param_3,DAT_02191638,auStack_266,DAT_0219163c), iVar1 != 0)) {
      uVar2 = func_0x0213bf90(auStack_266);
      *(undefined4 *)(iVar5 + DAT_0219162c) = uVar2;
    }
    iVar1 = func_0x02139f70(param_3,DAT_02191640);
    if (iVar1 != 0) {
      FUN_021965a0(param_1,*(undefined4 *)(iVar5 + DAT_02191624),iVar5);
      FUN_02190f4c(param_1,4,1);
      return 4;
    }
    FUN_021965a0(param_1,*(undefined4 *)(iVar5 + DAT_02191624),iVar5);
    FUN_02190f4c(param_1,4,0);
    return 4;
  }
  iVar6 = *(int *)(param_2 + 4);
  iVar1 = *(int *)(param_2 + 0x14);
  if (iVar1 == 1) {
    iVar1 = func_0x0213a038(param_3,DAT_02191644,5);
    if (iVar1 != 0) {
      FUN_021965a0(param_1,1,DAT_02191648);
      FUN_02190f4c(param_1,3,1);
      return 3;
    }
    iVar1 = FUN_021967b4(param_3,DAT_0219164c,iVar6,0x80);
    if (iVar1 == 0) {
      FUN_021965a0(param_1,1,DAT_02191648);
      FUN_02190f4c(param_1,3,1);
      return 3;
    }
    if (*(int *)(iVar6 + DAT_02191650) == 0) {
      iVar1 = FUN_021919ac(param_1,iVar6);
      if (iVar1 != 0) {
        return iVar1;
      }
      *(undefined4 *)(param_2 + 0x14) = 2;
    }
    else {
      iVar1 = FUN_021917b0(param_1,iVar6);
      if (iVar1 != 0) {
        return iVar1;
      }
      *(undefined4 *)(param_2 + 0x14) = 3;
    }
  }
  else if (iVar1 == 2) {
    iVar1 = func_0x0213a038(param_3,DAT_02191664,5);
    if (iVar1 != 0) {
      FUN_021965a0(param_1,1,DAT_02191648);
      FUN_02190f4c(param_1,3,1);
      return 3;
    }
    iVar1 = FUN_021967b4(param_3,DAT_02191668,auStack_266,DAT_0219163c);
    if (iVar1 == 0) {
      FUN_021965a0(param_1,1,DAT_0219165c);
      FUN_02190f4c(param_1,3,1);
      return 3;
    }
    uVar2 = func_0x0213bf90(auStack_266);
    *(undefined4 *)(iVar5 + DAT_0219166c) = uVar2;
    iVar1 = FUN_021967b4(param_3,DAT_02191658,auStack_266,DAT_0219163c);
    if (iVar1 == 0) {
      FUN_021965a0(param_1,1,DAT_0219165c);
      FUN_02190f4c(param_1,3,1);
      return 3;
    }
    uVar2 = func_0x0213bf90(auStack_266);
    *(undefined4 *)(iVar5 + DAT_02191630) = uVar2;
    iVar1 = FUN_021967b4(param_3,DAT_02191660,auStack_266,DAT_0219163c);
    if (iVar1 == 0) {
      FUN_021965a0(param_1,1,DAT_0219165c);
      FUN_02190f4c(param_1,3,1);
      return 3;
    }
    uVar2 = func_0x0213bf90(auStack_266);
    *(undefined4 *)(iVar5 + DAT_0219162c) = uVar2;
    iVar1 = FUN_021967b4(param_3,DAT_02191670,local_27b,0x15);
    if (iVar1 == 0) {
      local_27b[0] = 0;
    }
    iVar1 = FUN_021967b4(param_3,DAT_02191674,iVar5 + DAT_02191678,0x19);
    if (iVar1 == 0) {
      *(undefined1 *)(iVar5 + DAT_02191678) = 0;
    }
    if (*(char *)(iVar6 + 0xc2) == '\0') {
      if (*(char *)(iVar5 + DAT_0219167c) == '\0') {
        func_0x02135014(auStack_66,DAT_02191680,iVar5 + DAT_02191684,iVar5 + DAT_02191688);
        puVar3 = auStack_66;
      }
      else {
        puVar3 = (undefined1 *)(iVar5 + DAT_0219167c);
      }
    }
    else {
      puVar3 = (undefined1 *)(iVar6 + 0xc2);
    }
    func_0x02135014(auStack_266,DAT_0219168c,iVar6 + 0xa1,DAT_02191690,puVar3,iVar6,iVar6 + 0x80,
                    iVar6 + 0xa1);
    uVar2 = func_0x0213a434(auStack_266);
    FUN_0218e0fc(auStack_266,uVar2,auStack_29c);
    iVar1 = FUN_021967b4(param_3,DAT_02191694,auStack_266,DAT_0219163c);
    if (iVar1 == 0) {
      FUN_021965a0(param_1,1,DAT_02191790);
      FUN_02190f4c(param_1,3,1);
      return 3;
    }
    iVar1 = func_0x02134d30(auStack_29c,auStack_266,0x20);
    if (iVar1 != 0) {
      FUN_021965a0(param_1,DAT_02191794,DAT_02191798);
      FUN_02190f4c(param_1,3,1);
      return 3;
    }
    if (*(int *)(iVar5 + DAT_0219179c) != 0) {
      puVar4 = (undefined4 *)FUN_0219496c(param_1,*(undefined4 *)(iVar5 + DAT_021917a0));
      *puVar4 = *(undefined4 *)(iVar5 + DAT_021917a0);
      puVar4[1] = *(undefined4 *)(iVar5 + DAT_021917a4);
    }
    *(undefined4 *)(iVar5 + DAT_021917a8) = 3;
    iVar1 = *(int *)(param_2 + 0xc);
    uVar2 = *(undefined4 *)(param_2 + 0x10);
    if (iVar1 != 0) {
      puVar4 = (undefined4 *)FUN_021a3690(0x20);
      if (puVar4 == (undefined4 *)0x0) {
        FUN_02196590(param_1,DAT_021917ac);
        return 1;
      }
      func_0x02134de0(puVar4,0,0x20);
      puVar4[1] = *(undefined4 *)(iVar5 + DAT_021917a0);
      *puVar4 = 0;
      FUN_02196914(puVar4 + 2,local_27b,0x15);
      iVar1 = FUN_02190ed4(param_1,iVar1,uVar2,puVar4,param_2,0);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
    FUN_02193818(param_1,param_2);
  }
  else if (iVar1 == 3) {
    iVar1 = func_0x0213a038(param_3,DAT_02191654,5);
    if (iVar1 != 0) {
      FUN_021965a0(param_1,1,DAT_02191648);
      FUN_02190f4c(param_1,3,1);
      return 3;
    }
    iVar1 = FUN_021967b4(param_3,DAT_02191658,auStack_266,DAT_0219163c);
    if (iVar1 == 0) {
      FUN_021965a0(param_1,1,DAT_0219165c);
      FUN_02190f4c(param_1,3,1);
      return 3;
    }
    uVar2 = func_0x0213bf90(auStack_266);
    *(undefined4 *)(iVar5 + DAT_02191630) = uVar2;
    iVar1 = FUN_021967b4(param_3,DAT_02191660,auStack_266,DAT_0219163c);
    if (iVar1 == 0) {
      FUN_021965a0(param_1,1,DAT_0219165c);
      FUN_02190f4c(param_1,3,1);
      return 3;
    }
    uVar2 = func_0x0213bf90(auStack_266);
    *(undefined4 *)(iVar5 + DAT_0219162c) = uVar2;
    iVar1 = FUN_021919ac(param_1,iVar6);
    if (iVar1 != 0) {
      return iVar1;
    }
    *(undefined4 *)(param_2 + 0x14) = 2;
  }
  return 0;
}

