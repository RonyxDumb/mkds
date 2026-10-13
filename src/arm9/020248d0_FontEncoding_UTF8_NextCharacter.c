/* Decompiled C draft; module arm9; ROM address 020248d0. No matching claim. */
#include "types.h"
#include "deps/020248d0_FontEncoding_UTF8_NextCharacter.h"

uint FontEncoding_UTF8_NextCharacter(undefined4 *param_1)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  uint uVar4;
  
  pbVar3 = (byte *)(*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                   *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20);
  uVar4 = (uint)*pbVar3;
  if ((*pbVar3 & 0x80) == 0) {
    *param_1 = pbVar3 + 1;
  }
  else if ((uVar4 & 0xe0) == 0xc0) {
    uVar4 = pbVar3[1] & 0x3f | (uVar4 & 0x1f) << 6;
    *param_1 = pbVar3 + 2;
  }
  else {
    bVar1 = pbVar3[1];
    bVar2 = pbVar3[2];
    *param_1 = pbVar3 + 3;
    uVar4 = bVar2 & 0x3f | (uVar4 & 0xf) << 0xc | (bVar1 & 0x3f) << 6;
  }
  return uVar4;
}

