/* Decompiled C draft; module arm9_ov000; ROM address 021ab448. No matching claim. */
#include "types.h"
#include "deps/021ab448_FUN_021ab448.h"

int FUN_021ab448(byte *param_1,int param_2)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = ((uint)param_1[1] + (uint)*param_1 * 10) - DAT_021ab4a4;
  pbVar1 = param_1 + 2;
  if (param_2 == 0x17) {
    if (uVar3 < 0x32) {
      iVar2 = uVar3 + DAT_021ab4a8;
    }
    else {
      iVar2 = uVar3 + DAT_021ab4ac;
    }
  }
  else {
    iVar2 = uVar3 * 100 + (((uint)param_1[3] + (uint)*pbVar1 * 10) - DAT_021ab4a4);
    pbVar1 = param_1 + 4;
  }
  return iVar2 * 0x10000 + ((uint)pbVar1[1] + (uint)*pbVar1 * 10) * 0x100 + DAT_021ab4a4 * -0x101 +
         (uint)pbVar1[3] + (uint)pbVar1[2] * 10;
}

