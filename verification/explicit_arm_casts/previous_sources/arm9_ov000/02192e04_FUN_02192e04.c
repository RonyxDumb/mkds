/* Decompiled C draft; module arm9_ov000; ROM address 02192e04. No matching claim. */
#include "types.h"
#include "deps/02192e04_FUN_02192e04.h"

int FUN_02192e04(int *param_1,int param_2,undefined4 param_3)

{
  undefined1 **ppuVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  int local_280;
  undefined1 **local_27c;
  int local_278;
  int local_274;
  undefined4 local_270;
  char acStack_26c [64];
  undefined1 local_22c [31];
  undefined1 local_20d [21];
  undefined1 local_1f8 [51];
  undefined1 local_1c5 [31];
  undefined1 local_1a6 [31];
  undefined1 local_187 [51];
  undefined1 *local_154 [7];
  undefined1 *local_138 [2];
  undefined1 local_12d;
  undefined1 *apuStack_12c [3];
  undefined1 local_120 [128];
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined1 *local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined1 local_64 [80];
  
  iVar6 = *param_1;
  iVar2 = FUN_02196870(param_1,param_3,1);
  if (iVar2 != 0) {
    return 4;
  }
  iVar2 = func_0x0213a038(param_3,DAT_02193190,4);
  if (iVar2 != 0) {
    FUN_021965a0(param_1,1,DAT_02193194);
    FUN_02190f4c(param_1,3,1);
    return 3;
  }
  iVar2 = FUN_021967b4(param_3,DAT_02193198,acStack_26c,0x40);
  if (iVar2 == 0) {
    FUN_021965a0(param_1,1,DAT_02193194);
    FUN_02190f4c(param_1,3,1);
    return 3;
  }
  iVar2 = func_0x0213bf90(acStack_26c);
  if (iVar2 < 1) {
    func_0x0213442c(DAT_0219319c,DAT_021931a0,0,DAT_021931a4);
  }
  FUN_02194934(param_1,iVar2,&local_278);
  local_280 = 7;
  ppuVar1 = local_154;
  do {
    local_27c = ppuVar1;
    *local_27c = (undefined1 *)0x0;
    local_27c[1] = (undefined1 *)0x0;
    local_27c[2] = (undefined1 *)0x0;
    local_27c[3] = (undefined1 *)0x0;
    local_27c[4] = (undefined1 *)0x0;
    local_27c[5] = (undefined1 *)0x0;
    local_27c[6] = (undefined1 *)0x0;
    local_27c[7] = (undefined1 *)0x0;
    local_280 = local_280 + -1;
    ppuVar1 = local_27c + 8;
  } while (local_280 != 0);
  local_27c[8] = (undefined1 *)0x0;
  local_27c[9] = (undefined1 *)0x0;
  local_27c[10] = (undefined1 *)0x0;
  local_27c[0xb] = (undefined1 *)0x0;
  local_154[0] = local_22c;
  local_154[1] = local_20d;
  local_154[2] = local_1f8;
  local_154[3] = local_1c5;
  local_154[4] = local_1a6;
  local_154[5] = local_64;
  local_8c = local_187;
  iVar3 = FUN_021967b4(param_3,DAT_021931a8,local_154[0],0x1f);
  if (iVar3 == 0) {
    *local_154[0] = 0;
  }
  iVar3 = FUN_021967b4(param_3,DAT_021931ac,local_154[1],0x15);
  if (iVar3 == 0) {
    *local_154[1] = 0;
  }
  iVar3 = FUN_021967b4(param_3,DAT_021931b0,local_154[2],0x33);
  if (iVar3 == 0) {
    *local_154[2] = 0;
  }
  iVar3 = FUN_021967b4(param_3,DAT_021931b4,local_154[3],0x1f);
  if (iVar3 == 0) {
    *local_154[3] = 0;
  }
  iVar3 = FUN_021967b4(param_3,DAT_021931b8,local_154[4],0x1f);
  if (iVar3 == 0) {
    *local_154[4] = 0;
  }
  iVar3 = FUN_021967b4(param_3,DAT_021931bc,acStack_26c,0x40);
  if (iVar3 == 0) {
    local_154[6] = (undefined1 *)0xffffffff;
  }
  else {
    local_154[6] = (undefined1 *)func_0x0213bf90(acStack_26c);
  }
  iVar3 = FUN_021967b4(param_3,DAT_021931c0,local_154[5],0x4c);
  if (iVar3 == 0) {
    *local_154[5] = 0;
  }
  iVar3 = FUN_021967b4(param_3,DAT_021931c4,local_138,0xb);
  if (iVar3 == 0) {
    local_138[0]._0_1_ = 0;
  }
  iVar3 = FUN_021967b4(param_3,DAT_021931c8,&local_12d,3);
  if (iVar3 == 0) {
    local_12d = 0;
  }
  iVar3 = FUN_021967b4(param_3,DAT_021931cc,acStack_26c,0x40);
  if (iVar3 == 0) {
    apuStack_12c[1] = (undefined1 *)0x0;
  }
  else {
    func_0x0213a450(acStack_26c);
    apuStack_12c[1] = (undefined1 *)func_0x0212fe20();
  }
  iVar3 = FUN_021967b4(param_3,DAT_021931d0,acStack_26c,0x40);
  if (iVar3 == 0) {
    apuStack_12c[2] = (undefined1 *)0x0;
  }
  else {
    func_0x0213a450(acStack_26c);
    apuStack_12c[2] = (undefined1 *)func_0x0212fe20();
  }
  iVar3 = FUN_021967b4(param_3,DAT_021931d4,local_120,0x80);
  if (iVar3 == 0) {
    local_120[0] = 0;
  }
  iVar3 = FUN_021967b4(param_3,DAT_021931d8,acStack_26c,0x40);
  if (iVar3 == 0) {
    local_a0 = 0;
    local_9c = 0;
    local_98 = 0;
  }
  else {
    uVar4 = func_0x0213bf90(acStack_26c);
    iVar3 = FUN_021935bc(param_1,uVar4,&local_a0,&local_9c,&local_98);
    if (iVar3 != 0) {
      return iVar3;
    }
  }
  iVar3 = FUN_021967b4(param_3,DAT_021931dc,acStack_26c,0x40);
  if (iVar3 == 0) {
    local_94 = DAT_021931e0;
  }
  else if (acStack_26c[0] == '0') {
    local_94 = DAT_021931e4;
  }
  else if (acStack_26c[0] == '1') {
    local_94 = DAT_021931e8;
  }
  else {
    local_94 = DAT_021931e0;
  }
  iVar3 = FUN_021967b4(param_3,DAT_021931ec,acStack_26c,0x40);
  if (iVar3 == 0) {
    local_90 = 0xffffffff;
  }
  else {
    local_90 = func_0x0213bf90(acStack_26c);
  }
  iVar3 = FUN_021967b4(param_3,DAT_021931f0,local_8c,0x33);
  if (iVar3 == 0) {
    *local_8c = 0;
  }
  iVar3 = FUN_021967b4(param_3,DAT_021931f4,acStack_26c,0x40);
  if (iVar3 == 0) {
    local_88 = 0;
  }
  else {
    local_88 = func_0x0213bf90(acStack_26c);
  }
  iVar3 = FUN_021967b4(param_3,DAT_021931f8,acStack_26c,0x40);
  if (iVar3 == 0) {
    local_84 = 0;
  }
  else {
    local_84 = func_0x0213bf90(acStack_26c);
  }
  iVar3 = FUN_021967b4(param_3,DAT_021931fc,acStack_26c,0x40);
  if (iVar3 == 0) {
    local_80 = 0;
  }
  else {
    local_80 = func_0x0213bf90(acStack_26c);
  }
  iVar3 = FUN_021967b4(param_3,DAT_02193200,acStack_26c,0x40);
  if (iVar3 == 0) {
    local_7c = 0;
  }
  else {
    local_7c = func_0x0213bf90(acStack_26c);
  }
  iVar3 = FUN_021967b4(param_3,DAT_02193204,acStack_26c,0x40);
  if (iVar3 == 0) {
    local_78 = 0;
  }
  else {
    local_78 = func_0x0213bf90(acStack_26c);
  }
  iVar3 = FUN_021967b4(param_3,DAT_02193208,acStack_26c,0x40);
  if (iVar3 == 0) {
    local_74 = 0;
  }
  else {
    local_74 = func_0x0213bf90(acStack_26c);
  }
  iVar3 = FUN_021967b4(param_3,DAT_0219320c,acStack_26c,0x40);
  if (iVar3 == 0) {
    local_70 = 0;
  }
  else {
    local_70 = func_0x0213bf90(acStack_26c);
  }
  iVar3 = FUN_021967b4(param_3,DAT_0219336c,acStack_26c,0x40);
  if (iVar3 == 0) {
    local_6c = 0;
  }
  else {
    local_6c = func_0x0213bf90(acStack_26c);
  }
  iVar3 = FUN_021967b4(param_3,DAT_02193370,acStack_26c,0x40);
  if (iVar3 == 0) {
    local_68 = 0;
  }
  else {
    local_68 = func_0x0213bf90(acStack_26c);
  }
  iVar3 = FUN_021967b4(param_3,DAT_02193374,acStack_26c,0x40);
  if (iVar3 != 0) {
    iVar3 = *(int *)(iVar6 + DAT_0219337c);
    for (piVar7 = *(int **)(iVar6 + DAT_02193380); piVar7 != (int *)0x0; piVar7 = (int *)piVar7[0xf]
        ) {
      if ((piVar7[3] == iVar2) && (*piVar7 == 0x65)) {
        if (local_278 == 0) {
          local_278 = FUN_0219496c(param_1,iVar2);
        }
        *piVar7 = 0x66;
        iVar3 = 1;
      }
    }
    if ((local_278 == 0) && (*(int *)(iVar6 + DAT_0219337c) != 0)) {
      local_278 = FUN_0219496c(param_1,iVar2);
    }
    if (iVar3 != 0) {
      FUN_021a3668(*(undefined4 *)(local_278 + 0x18));
      *(undefined4 *)(local_278 + 0x18) = 0;
      uVar4 = FUN_0218e880(acStack_26c);
      *(undefined4 *)(local_278 + 0x18) = uVar4;
    }
    if (*(int *)(iVar6 + DAT_0219337c) != 0) {
      FUN_0219218c(param_1,local_278,local_154);
    }
    local_274 = *(int *)(param_2 + 0xc);
    local_270 = *(undefined4 *)(param_2 + 0x10);
    if (local_274 != 0) {
      puVar5 = (undefined4 *)FUN_021a3690(DAT_02193384);
      if (puVar5 == (undefined4 *)0x0) {
        FUN_02196590(param_1,DAT_02193388);
        return 1;
      }
      FUN_0219338c(local_154,puVar5);
      *puVar5 = 0;
      puVar5[1] = iVar2;
      iVar2 = FUN_02190ed4(param_1,local_274,local_270,puVar5,param_2,0);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    FUN_02193818(param_1,param_2);
    return 0;
  }
  FUN_021965a0(param_1,1,DAT_02193378);
  FUN_02190f4c(param_1,3,1);
  return 3;
}

