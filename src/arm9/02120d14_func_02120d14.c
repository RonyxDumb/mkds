/* Decompiled C draft; module arm9; ROM address 02120d14. No matching claim. */
#include "types.h"
#include "deps/02120d14_func_02120d14.h"

undefined4 func_02120d14(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam02120d4c & 0xfffffffc) >> (uRam02120d4c & 3) * 8 |
          *(uint *)(uRam02120d4c & 0xfffffffc) << (uRam02120d4c & 3) * -8 + 0x20) + 0x18e8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if ((uVar2 != 1) && (uVar2 == 3)) {
    return 1;
  }
  return 0;
}

