/* Decompiled C draft; module arm9; ROM address 020b4b98. No matching claim. */
#include "types.h"
#include "deps/020b4b98_SomeCheckLangFrench.h"

bool SomeCheckLangFrench(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(DAT_020b4bf4 & 0xfffffffc) >> (DAT_020b4bf4 & 3) * 8 |
          *(uint *)(DAT_020b4bf4 & 0xfffffffc) << (DAT_020b4bf4 & 3) * -8 + 0x20) + 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  switch(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    if ((param_1 != 1) && (param_1 != 0)) {
      return true;
    }
    return false;
  case 3:
    break;
  case 4:
    break;
  case 5:
  }
  return param_1 != 1;
}

