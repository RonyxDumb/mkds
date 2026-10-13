/* Decompiled C draft; module arm9_ov000; ROM address 0219aa64. No matching claim. */
#include "types.h"
#include "deps/0219aa64_FUN_0219aa64.h"

void FUN_0219aa64(undefined4 *param_1,int param_2)

{
  uint uVar1;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  uint local_24;
  undefined1 local_1f;
  
  local_2c = *DAT_0219aadc;
  local_2b = DAT_0219aadc[1];
  local_2a = DAT_0219aadc[2];
  local_29 = DAT_0219aadc[3];
  local_28 = DAT_0219aadc[4];
  local_27 = DAT_0219aadc[5];
  local_26 = 2;
  local_25 = 6;
  local_1f = (undefined1)param_1[3];
  uVar1 = param_1[2];
  local_24 = uVar1 << 0x18 & DAT_0219aae0 |
             uVar1 << 8 & DAT_0219aae4 | uVar1 >> 0x18 | uVar1 >> 8 & DAT_0219aae8;
  FUN_0219b0b0(*param_1,*(undefined4 *)(param_2 + 4),
               (int)(uint)*(ushort *)(param_2 + 2) >> 8 |
               (uint)*(ushort *)(param_2 + 2) << 8 & DAT_0219aae8 & 0xffff,(undefined4)(uintptr_t)(&local_2c),0x15);
  return;
}

