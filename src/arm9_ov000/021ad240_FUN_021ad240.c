/* Decompiled C draft; module arm9_ov000; ROM address 021ad240. No matching claim. */
#include "types.h"
#include "deps/021ad240_FUN_021ad240.h"

byte * FUN_021ad240(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  
  bVar1 = *param_1;
  param_1 = param_1 + 1;
  while( true ) {
    uVar2 = (uint)bVar1;
    if (uVar2 == 0) {
      return param_1;
    }
    if ((uVar2 & 0xc0) == 0xc0) break;
    pbVar3 = param_1 + uVar2;
    param_1 = pbVar3 + 1;
    bVar1 = *pbVar3;
  }
  return param_1 + 1;
}

