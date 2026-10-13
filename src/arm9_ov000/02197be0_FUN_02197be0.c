/* Decompiled C draft; module arm9_ov000; ROM address 02197be0. No matching claim. */
#include "types.h"
#include "deps/02197be0_FUN_02197be0.h"

byte * FUN_02197be0(byte *param_1)

{
  undefined4 uVar1;
  char extraout_r1;
  char extraout_r1_00;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  
  if (param_1 == (byte *)0x0) {
    func_0x0213442c(DAT_02197c98,DAT_02197c9c,0,0x2b);
  }
  FUN_0218e8c4();
  func_0x021384cc();
  uVar1 = func_0x021384dc();
  func_0x02133068(uVar1,0x5d);
  *param_1 = extraout_r1 + 0x21;
  uVar3 = 0;
  uVar4 = 1;
  do {
    uVar2 = (uint)*param_1;
    uVar3 = uVar2 & 1 ^ uVar3 ^ (uVar4 ^ param_1[uVar4 - 1]) & 1 ^ (uint)(uVar2 < 0x4f) ^
            (uint)(param_1[uVar4 - 1] < uVar2);
    pbVar5 = param_1 + uVar4;
    uVar1 = func_0x021384dc();
    func_0x02133068(uVar1,0x5d);
    param_1[uVar4] = extraout_r1_00 + 0x21;
    if (((uVar3 != 0) && ((*pbVar5 & 1) == 0)) || ((uVar3 == 0 && ((*pbVar5 & 1) == 1)))) {
      *pbVar5 = *pbVar5 + 1;
    }
    uVar4 = uVar4 + 1;
  } while ((int)uVar4 < 0x20);
  return param_1;
}

