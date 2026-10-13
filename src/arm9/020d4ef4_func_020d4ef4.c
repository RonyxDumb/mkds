/* Decompiled C draft; module arm9; ROM address 020d4ef4. No matching claim. */
#include "types.h"
#include "deps/020d4ef4_func_020d4ef4.h"

int func_020d4ef4(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_1 != 0) {
    uVar3 = param_1 + 8 & 3;
    uVar6 = *(uint *)(param_1 + 8 & 0xfffffffc);
    uVar4 = iRam020d4f30 + 0x10U & 3;
    uVar5 = *(uint *)(iRam020d4f30 + 0x10U & 0xfffffffc);
    iVar1 = (int)((uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) -
                 (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20)) >> 0xc;
    uVar3 = iRam020d4f30 + 8U & 3;
    uVar4 = *(uint *)(iRam020d4f30 + 8U & 0xfffffffc);
    iVar2 = (int)((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                  *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) -
                 (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20)) >> 0xc;
    return iVar2 * iVar2 + iVar1 * iVar1;
  }
  return 0;
}

