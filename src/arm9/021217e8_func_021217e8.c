/* Decompiled C draft; module arm9; ROM address 021217e8. No matching claim. */
#include "types.h"
#include "deps/021217e8_func_021217e8.h"

undefined4 func_021217e8(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  
  switch(param_1) {
  case 0:
    uVar2 = (*(uint *)(DAT_0212198c & 0xfffffffc) >> (DAT_0212198c & 3) * 8 |
            *(uint *)(DAT_0212198c & 0xfffffffc) << (DAT_0212198c & 3) * -8 + 0x20) + 0x1950;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) < 2) {
      return 1;
    }
    break;
  case 1:
    uVar2 = (*(uint *)(DAT_0212198c & 0xfffffffc) >> (DAT_0212198c & 3) * 8 |
            *(uint *)(DAT_0212198c & 0xfffffffc) << (DAT_0212198c & 3) * -8 + 0x20) + 0x1950;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
      return 1;
    }
    break;
  case 2:
    uVar2 = (*(uint *)(DAT_0212198c & 0xfffffffc) >> (DAT_0212198c & 3) * 8 |
            *(uint *)(DAT_0212198c & 0xfffffffc) << (DAT_0212198c & 3) * -8 + 0x20) + 0x1950;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) < 2) {
      return 1;
    }
    break;
  case 3:
    uVar2 = (*(uint *)(DAT_0212198c & 0xfffffffc) >> (DAT_0212198c & 3) * 8 |
            *(uint *)(DAT_0212198c & 0xfffffffc) << (DAT_0212198c & 3) * -8 + 0x20) + 0x1950;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    if ((uVar2 == 1) || (uVar2 - 4 < 3)) {
      return 1;
    }
    break;
  case 4:
    uVar2 = (*(uint *)(DAT_0212198c & 0xfffffffc) >> (DAT_0212198c & 3) * 8 |
            *(uint *)(DAT_0212198c & 0xfffffffc) << (DAT_0212198c & 3) * -8 + 0x20) + 0x1950;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) - 5 < 2) {
      return 1;
    }
    break;
  case 5:
    uVar2 = (*(uint *)(DAT_0212198c & 0xfffffffc) >> (DAT_0212198c & 3) * 8 |
            *(uint *)(DAT_0212198c & 0xfffffffc) << (DAT_0212198c & 3) * -8 + 0x20) + 0x1950;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) - 6 < 2) {
      return 1;
    }
    break;
  case 6:
    uVar2 = (*(uint *)(DAT_0212198c & 0xfffffffc) >> (DAT_0212198c & 3) * 8 |
            *(uint *)(DAT_0212198c & 0xfffffffc) << (DAT_0212198c & 3) * -8 + 0x20) + 0x1950;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) - 7 < 2) {
      return 1;
    }
    break;
  case 7:
    uVar2 = (*(uint *)(DAT_0212198c & 0xfffffffc) >> (DAT_0212198c & 3) * 8 |
            *(uint *)(DAT_0212198c & 0xfffffffc) << (DAT_0212198c & 3) * -8 + 0x20) + 0x1950;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) - 8 < 2) {
      return 1;
    }
    break;
  case 8:
    uVar2 = (*(uint *)(DAT_0212198c & 0xfffffffc) >> (DAT_0212198c & 3) * 8 |
            *(uint *)(DAT_0212198c & 0xfffffffc) << (DAT_0212198c & 3) * -8 + 0x20) + 0x1950;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) - 3 < 2) {
      return 1;
    }
    break;
  case 9:
    uVar2 = (*(uint *)(DAT_0212198c & 0xfffffffc) >> (DAT_0212198c & 3) * 8 |
            *(uint *)(DAT_0212198c & 0xfffffffc) << (DAT_0212198c & 3) * -8 + 0x20) + 0x1950;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) - 3 < 3) {
      return 1;
    }
  }
  return 0;
}

