/* Decompiled C draft; module arm9; ROM address 020136f0. No matching claim. */
#include "types.h"
#include "deps/020136f0_Nsbtx_GetTEX0Block.h"

int Nsbtx_GetTEX0Block(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = param_1 + *(ushort *)(param_1 + 0xc);
  if (*(short *)(param_1 + 0xe) != 1) {
    uVar1 = uVar3 + 4 & 3;
    uVar3 = *(uint *)(uVar3 + 4 & 0xfffffffc);
    return param_1 + (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  }
  if ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
      *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) == uRam0201372c) {
    iVar2 = param_1 + (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                      *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20);
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}

