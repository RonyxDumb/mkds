/* Decompiled C draft; module arm9_ov000; ROM address 02197020. No matching claim. */
#include "types.h"
#include "deps/02197020_FUN_02197020.h"

void FUN_02197020(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_10 = param_6;
  local_14 = param_7;
  local_18 = param_5;
  local_28 = param_1;
  local_24 = param_2;
  local_20 = param_3;
  local_1c = param_4;
  if (*DAT_02197060 == 0) {
    iVar1 = FUN_0218dc94(0x1c,2,0);
    *DAT_02197060 = iVar1;
  }
  FUN_0218dbc0((undefined4 *)(uintptr_t)(*DAT_02197060),(undefined4)(uintptr_t)(&local_28));
  return;
}

