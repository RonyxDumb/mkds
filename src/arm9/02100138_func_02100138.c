/* Decompiled C draft; module arm9; ROM address 02100138. No matching claim. */
#include "types.h"
#include "deps/02100138_func_02100138.h"

uint func_02100138(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = func_020d2c20();
  iVar4 = 0;
  uVar3 = uRam02100198;
  if (0 < iVar2) {
    do {
      if (param_1 ==
          (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20)) {
        uVar3 = iRam0210019c + iVar4 * 0xc;
        uVar1 = uVar3 & 3;
        uVar3 = *(uint *)(uVar3 & 0xfffffffc);
        uVar3 = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x30;
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

