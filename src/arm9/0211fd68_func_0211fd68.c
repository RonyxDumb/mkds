/* Decompiled C draft; module arm9; ROM address 0211fd68. No matching claim. */
#include "types.h"
#include "deps/0211fd68_func_0211fd68.h"

undefined4 func_0211fd68(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam0211fda4 & 0xfffffffc) >> (uRam0211fda4 & 3) * 8 |
          *(uint *)(uRam0211fda4 & 0xfffffffc) << (uRam0211fda4 & 3) * -8 + 0x20) + 0x1f2c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if (uVar2 == 5) {
    return 1;
  }
  if (uVar2 != 7) {
    return 0;
  }
  return 0xffffffff;
}

