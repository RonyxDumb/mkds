/* Decompiled C draft; module arm9_ov000; ROM address 0218dc94. No matching claim. */
#include "types.h"
#include "deps/0218dc94_FUN_0218dc94.h"

undefined4 * FUN_0218dc94(int param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)FUN_021a3690(0x18);
  if (puVar1 == (undefined4 *)0x0) {
    func_0x0213442c(DAT_0218dd08,DAT_0218dd0c,0,0x52);
  }
  if (param_1 == 0) {
    func_0x0213442c(DAT_0218dd10,DAT_0218dd0c,0,0x53);
  }
  if (param_2 == 0) {
    param_2 = 8;
  }
  *puVar1 = 0;
  puVar1[1] = param_2;
  puVar1[2] = param_1;
  puVar1[3] = param_2;
  puVar1[4] = param_3;
  if (puVar1[1] == 0) {
    puVar1[5] = 0;
  }
  else {
    uVar2 = FUN_021a3690(puVar1[2] * puVar1[1]);
    puVar1[5] = uVar2;
    if (puVar1[5] == 0) {
      func_0x0213442c(DAT_0218dd14,DAT_0218dd0c,0,0x5e);
    }
  }
  return puVar1;
}

