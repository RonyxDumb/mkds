/* Decompiled C draft; module arm9_ov001; ROM address 02183f0c. No matching claim. */
#include "types.h"
#include "deps/02183f0c_FUN_02183f0c.h"

void FUN_02183f0c(ushort *param_1)

{
  undefined4 uVar1;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  ushort *local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 auStack_c [4];
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  FUN_02187218(param_1,8);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0x50) + 0x70),
               *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x74));
  FUN_02188950(param_1,&local_28);
  FUN_0218720c(param_1);
  FUN_02188c90(param_1);
  FUN_02188cec(param_1,0);
  if (*param_1 == DAT_02183fdc) {
    FUN_021874c4(param_1,0,0,0,DAT_02183fe0,0);
    FUN_021874c4(param_1,0,0,0,DAT_02183fe4,0);
  }
  else if (*param_1 == DAT_02183fe8) {
    FUN_021874c4(param_1,0,0,0,DAT_02183fe0,0);
    FUN_021874c4(param_1,0,0,0,DAT_02183fe4,0);
  }
  local_1c = *DAT_02183fec;
  local_14 = DAT_02183fec[2];
  local_10 = DAT_02183fec[3];
  local_18 = param_1 + 2;
  local_10 = func_0x020d4ef4(local_18,local_10,auStack_c,DAT_02183fec + 4);
  uVar1 = func_0x02108e7c();
  func_0x0210b734(&local_1c,uVar1);
  param_1[1] = param_1[1] | *DAT_02183ff0;
  return;
}

