/* Decompiled C draft; module arm9; ROM address 020d4f34. No matching claim. */
#include "types.h"
#include "deps/020d4f34_func_020d4f34.h"

uint func_020d4f34(uint param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = param_1 + 8 & 3;
  uVar6 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar4 = iRam020d4f8c + 0x10U & 3;
  uVar5 = *(uint *)(iRam020d4f8c + 0x10U & 0xfffffffc);
  iVar1 = (int)((uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) -
               (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20)) >> 0xc;
  uVar3 = iRam020d4f8c + 8U & 3;
  uVar4 = *(uint *)(iRam020d4f8c + 8U & 0xfffffffc);
  iVar2 = (int)((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) -
               (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20)) >> 0xc;
  uVar3 = iVar2 * iVar2 + iVar1 * iVar1;
  uVar4 = uVar3 & 0x3fffffe0;
  if (param_4 < (int)uVar3) {
    uVar4 = uVar4 | *(uint *)(uRam020d4f90 & 0xfffffffc) >> (uRam020d4f90 & 3) * 8 |
                    *(uint *)(uRam020d4f90 & 0xfffffffc) << (uRam020d4f90 & 3) * -8 + 0x20;
  }
  return uVar4 | 3;
}

