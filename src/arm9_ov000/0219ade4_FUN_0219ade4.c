/* Decompiled C draft; module arm9_ov000; ROM address 0219ade4. No matching claim. */
#include "types.h"
#include "deps/0219ade4_FUN_0219ade4.h"

void FUN_0219ade4(int *param_1)

{
  uint uVar1;
  int iVar2;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  uint local_24;
  int local_20;
  ushort local_1c;
  undefined1 local_1a;
  undefined1 local_19;
  
  local_2c = *DAT_0219ae9c;
  local_2b = DAT_0219ae9c[1];
  local_2a = DAT_0219ae9c[2];
  local_29 = DAT_0219ae9c[3];
  local_28 = DAT_0219ae9c[4];
  local_27 = DAT_0219ae9c[5];
  local_26 = 2;
  local_25 = 7;
  uVar1 = param_1[2];
  local_24 = uVar1 << 0x18 & DAT_0219aea0 |
             uVar1 << 8 & DAT_0219aea4 | uVar1 >> 0x18 | uVar1 >> 8 & DAT_0219aea8;
  local_20 = param_1[0xb];
  local_1c = *(ushort *)(param_1 + 0xc) >> 8 |
             *(ushort *)(param_1 + 0xc) << 8 & (ushort)DAT_0219aea8;
  local_1a = *(undefined1 *)((int)param_1 + 0x32);
  local_19 = param_1[4] != 2;
  iVar2 = param_1[1];
  if (iVar2 == -1) {
    iVar2 = *param_1;
  }
  FUN_0219b0b0(iVar2,param_1[0xb],(short)param_1[0xc],(undefined4)(uintptr_t)(&local_2c),0x14);
  iVar2 = FUN_0218e8c4();
  param_1[10] = iVar2 + DAT_0219aeac;
  param_1[9] = 0xc;
  if (*(char *)((int)param_1 + 0x32) != '\0') {
    *(undefined1 *)((int)param_1 + 0x33) = 1;
  }
  return;
}

