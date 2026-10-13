/* Decompiled C draft; module arm9; ROM address 020b2c54. No matching claim. */
#include "types.h"
#include "deps/020b2c54_SaveDataIoManagerIsBusy.h"

uint SaveDataIoManagerIsBusy(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020b2c64 & 0xfffffffc) >> (uRam020b2c64 & 3) * 8 |
          *(uint *)(uRam020b2c64 & 0xfffffffc) << (uRam020b2c64 & 3) * -8 + 0x20) + 0xc;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

