/* Decompiled C draft; module arm9; ROM address 0204acd0. No matching claim. */
#include "types.h"
#include "deps/0204acd0_SetSomeSceneSseqId.h"

void SetSomeSceneSseqId(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = uRam0204ad20;
  uVar4 = *(uint *)(uRam0204ad20 & 0xfffffffc) >> (uRam0204ad20 & 3) * 8 |
          *(uint *)(uRam0204ad20 & 0xfffffffc) << (uRam0204ad20 & 3) * -8 + 0x20;
  uVar2 = uVar4 + 0x1c;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (-1 < (int)(uVar2 << 0x1e)) {
    *(uint *)(uVar4 + 0x1c) = uVar2 | 2;
    uVar2 = uVar1 & 3;
    uVar3 = *(uint *)(uVar1 & 0xfffffffc);
    LoadSomeSseq((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 8,param_1,0xff);
    return;
  }
  return;
}

