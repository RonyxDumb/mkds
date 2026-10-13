/* Decompiled C draft; module arm9; ROM address 020360a0. No matching claim. */
#include "types.h"
#include "deps/020360a0_func_020360a0.h"

uint func_020360a0(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = SaveDataIoManager_IsBusy();
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = (*(uint *)(uRam020360cc & 0xfffffffc) >> (uRam020360cc & 3) * 8 |
            *(uint *)(uRam020360cc & 0xfffffffc) << (uRam020360cc & 3) * -8 + 0x20) + 0x10;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  }
  return uVar3;
}

