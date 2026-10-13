/* Decompiled C draft; module arm9; ROM address 0212d300. No matching claim. */
#include "types.h"
#include "deps/0212d300_Sound_GetFileSize.h"

uint Sound_GetFileSize(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (*(uint *)(uRam0212d324 & 0xfffffffc) >> (uRam0212d324 & 3) * 8 |
          *(uint *)(uRam0212d324 & 0xfffffffc) << (uRam0212d324 & 3) * -8 + 0x20) + 0x84;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar2 = uVar3 + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (param_1 < (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)) {
    uVar2 = uVar3 + param_1 * 0x10 + 0x10;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

