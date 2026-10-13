/* Decompiled C draft; module arm9; ROM address 020d3df4. No matching claim. */
#include "types.h"
#include "deps/020d3df4_func_020d3df4.h"

int func_020d3df4(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(uRam020d3e10 & 0xfffffffc) >> (uRam020d3e10 & 3) * 8 |
          *(uint *)(uRam020d3e10 & 0xfffffffc) << (uRam020d3e10 & 3) * -8 + 0x20;
  iVar2 = iRam020d3e14;
  if (uVar3 != 0) {
    uVar3 = uVar3 + 4;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    iVar2 = param_1 - (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  }
  return iVar2;
}

