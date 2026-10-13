/* Decompiled C draft; module arm9; ROM address 020b4b10. No matching claim. */
#include "types.h"
#include "deps/020b4b10_GetSomeInterCharacterWidth2.h"

undefined4 GetSomeInterCharacterWidth2(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(DAT_020b4b50 & 0xfffffffc) >> (DAT_020b4b50 & 3) * 8 |
          *(uint *)(DAT_020b4b50 & 0xfffffffc) << (DAT_020b4b50 & 3) * -8 + 0x20) + 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  switch(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) {
  case 0:
    return 1;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  default:
    return param_1;
  }
  return 0xffffffff;
}

