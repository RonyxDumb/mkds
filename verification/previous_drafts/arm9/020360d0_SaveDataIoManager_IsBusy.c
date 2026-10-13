/* Decompiled C draft; module arm9; ROM address 020360d0. No matching claim. */
#include "types.h"
#include "deps/020360d0_SaveDataIoManager_IsBusy.h"

uint SaveDataIoManager_IsBusy(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020360e0 & 0xfffffffc) >> (uRam020360e0 & 3) * 8 |
          *(uint *)(uRam020360e0 & 0xfffffffc) << (uRam020360e0 & 3) * -8 + 0x20) + 0xc;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

