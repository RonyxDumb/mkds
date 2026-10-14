/* Decompiled C draft; module arm9; ROM address 020b2c24. No matching claim. */
#include "types.h"
#include "deps/020b2c24_SaveDataIoManagerIsBusy12.h"

uint SaveDataIoManagerIsBusy12(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = SaveDataIoManagerIsBusy();
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = (*(uint *)(uRam020b2c50 & 0xfffffffc) >> (uRam020b2c50 & 3) * 8 |
            *(uint *)(uRam020b2c50 & 0xfffffffc) << (uRam020b2c50 & 3) * -8 + 0x20) + 0x10;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  }
  return uVar3;
}

