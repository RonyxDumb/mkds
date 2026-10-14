/* Decompiled C draft; module arm9; ROM address 0212d254. No matching claim. */
#include "types.h"
#include "deps/0212d254_Sound_MaybeGetRawFilePointer.h"

uint Sound_MaybeGetRawFilePointer(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (*(uint *)(uRam0212d278 & 0xfffffffc) >> (uRam0212d278 & 3) * 8 |
          *(uint *)(uRam0212d278 & 0xfffffffc) << (uRam0212d278 & 3) * -8 + 0x20) + 0x84;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar2 = uVar3 + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (param_1 < (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)) {
    uVar2 = uVar3 + param_1 * 0x10 + 0x14;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

