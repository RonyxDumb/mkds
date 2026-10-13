/* Decompiled C draft; module arm9; ROM address 021000d0. No matching claim. */
#include "types.h"
#include "deps/021000d0_func_021000d0.h"

uint func_021000d0(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = func_020d2c20();
  iVar4 = 0;
  uVar3 = uRam02100130;
  if (0 < iVar2) {
    do {
      if (param_1 ==
          (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20)) {
        uVar3 = iRam02100134 + iVar4 * 0xc;
        uVar1 = uVar3 & 3;
        uVar3 = *(uint *)(uVar3 & 0xfffffffc);
        uVar3 = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x24;
        uVar1 = uVar3 & 3;
        uVar3 = *(uint *)(uVar3 & 0xfffffffc);
        return uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
      }
      iVar4 = iVar4 + 1;
      uVar3 = uVar3 + 0xc;
    } while (iVar4 < iVar2);
  }
  return 0;
}

