/* Decompiled C draft; module arm9_ov000; ROM address 0219aeb0. No matching claim. */
#include "types.h"
#include "deps/0219aeb0_FUN_0219aeb0.h"

void FUN_0219aeb0(undefined4 *param_1)

{
  byte bVar1;
  undefined1 extraout_var;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined1 local_6c;
  undefined1 local_6b;
  undefined1 local_6a;
  undefined1 local_69;
  undefined1 local_68;
  undefined1 local_67;
  undefined1 local_66;
  undefined1 local_65;
  uint local_64;
  undefined1 local_60;
  undefined1 local_5f;
  char local_5e;
  byte local_5d;
  undefined1 local_5c;
  undefined1 local_5b;
  undefined1 local_5a;
  byte local_59;
  undefined1 local_58;
  undefined1 auStack_57 [67];
  
  local_6c = *DAT_0219b014;
  local_6b = DAT_0219b014[1];
  local_6a = DAT_0219b014[2];
  local_69 = DAT_0219b014[3];
  local_68 = DAT_0219b014[4];
  local_67 = DAT_0219b014[5];
  local_66 = 2;
  local_65 = 0;
  local_5f = (undefined1)param_1[3];
  uVar6 = param_1[2];
  local_64 = uVar6 << 0x18 & DAT_0219b018 |
             uVar6 << 8 & DAT_0219b01c | uVar6 >> 0x18 | uVar6 >> 8 & DAT_0219b020;
  local_5e = param_1[1] != -1;
  bVar1 = FUN_0219b05c();
  iVar2 = FUN_0219b05c();
  uVar6 = FUN_0219b05c();
  uVar3 = FUN_0219b05c();
  uVar5 = iVar2 << 8 & DAT_0219b01c;
  uVar6 = uVar6 >> 0x18 | uVar3 >> 8 & DAT_0219b020;
  uVar3 = uVar5 | uVar6;
  local_5d = bVar1 & (byte)(DAT_0219b018 >> 0x18) | (byte)(uVar5 >> 0x18);
  local_5c = (undefined1)(uVar3 >> 0x10);
  local_5b = (undefined1)(uVar3 >> 8);
  local_5a = (undefined1)uVar6;
  local_59 = 0;
  local_58 = 0;
  func_0x0213a2d0(auStack_57,DAT_0219b024);
  iVar2 = func_0x0213a434(DAT_0219b024);
  iVar2 = iVar2 + 0x16;
  if ((local_5e != '\0') && (param_1[5] == 0)) {
    local_60 = 0;
    FUN_0219b0b0(param_1[1],*DAT_0219b028,DAT_0219b02c,&local_6c,iVar2);
  }
  if (param_1[6] == 0) {
    local_60 = 1;
    FUN_0219b0b0(*param_1,*DAT_0219b028,DAT_0219b02c,&local_6c,iVar2);
  }
  if (local_5e == '\0') {
    uVar7 = *param_1;
    uVar4 = *param_1;
  }
  else {
    uVar7 = param_1[1];
    uVar4 = param_1[1];
  }
  FUN_0219b038(uVar4);
  local_59 = FUN_0219b038(uVar7);
  local_59 = local_59 & (byte)(DAT_0219b020 >> 8);
  local_58 = extraout_var;
  if (param_1[7] == 0) {
    local_60 = 2;
    FUN_0219b0b0(*param_1,*DAT_0219b030,DAT_0219b02c,&local_6c,iVar2);
  }
  iVar2 = FUN_0218e8c4();
  param_1[10] = iVar2 + DAT_0219b034;
  param_1[9] = 0x1e;
  return;
}

