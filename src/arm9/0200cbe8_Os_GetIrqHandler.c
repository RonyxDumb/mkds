/* Decompiled C draft; module arm9; ROM address 0200cbe8. No matching claim. */
#include "types.h"
#include "deps/0200cbe8_Os_GetIrqHandler.h"

uint Os_GetIrqHandler(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = uRam0200cc6c;
  while ((param_1 & 1) == 0) {
    iVar3 = iVar3 + 1;
    param_1 = param_1 >> 1;
    uVar2 = uVar2 + 4;
    if (0x15 < iVar3) {
      return 0;
    }
  }
  if ((7 < iVar3) && (iVar3 < 0xc)) {
    uVar2 = iRam0200cc70 + (iVar3 + -8) * 0xc;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  }
  if ((2 < iVar3) && (iVar3 < 7)) {
    uVar2 = iRam0200cc70 + (iVar3 + 1) * 0xc;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  }
  return *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
         *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
}

