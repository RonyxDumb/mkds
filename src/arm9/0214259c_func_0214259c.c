/* Decompiled C draft; module arm9; ROM address 0214259c. No matching claim. */
#include "types.h"
#include "deps/0214259c_func_0214259c.h"

uint func_0214259c(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = Wm_CheckInitialized();
  if (iVar2 == 0) {
    uVar3 = (*(uint *)(uRam021425c8 & 0xfffffffc) >> (uRam021425c8 & 3) * 8 |
            *(uint *)(uRam021425c8 & 0xfffffffc) << (uRam021425c8 & 3) * -8 + 0x20) + 4;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

