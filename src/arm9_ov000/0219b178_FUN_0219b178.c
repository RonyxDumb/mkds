/* Decompiled C draft; module arm9_ov000; ROM address 0219b178. No matching claim. */
#include "types.h"
#include "deps/0219b178_FUN_0219b178.h"

void FUN_0219b178(void)

{
  int iVar1;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_48 = 0;
  uStack_44 = 0;
  local_40 = 0;
  uStack_3c = 0;
  local_38 = 0;
  uStack_34 = 0;
  local_30 = 0;
  uStack_2c = 0;
  local_28 = 0;
  uStack_24 = 0;
  local_20 = 0;
  uStack_1c = 0;
  local_18 = 0;
  uStack_14 = 0;
  local_10 = 0;
  uStack_c = 0;
  if (*DAT_0219b1cc == 0) {
    iVar1 = FUN_0218dc94(0x40,4,DAT_0219b1d0);
    *DAT_0219b1cc = iVar1;
  }
  FUN_0218dbc0((undefined4 *)(uintptr_t)(*DAT_0219b1cc),(undefined4)(uintptr_t)(&local_48));
  iVar1 = FUN_0218dc44((undefined4 *)(uintptr_t)(*DAT_0219b1cc));
  FUN_0218dbf8((int *)(uintptr_t)(*DAT_0219b1cc),iVar1 + -1);
  return;
}

