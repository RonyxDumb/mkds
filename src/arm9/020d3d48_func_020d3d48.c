/* Decompiled C draft; module arm9; ROM address 020d3d48. No matching claim. */
#include "types.h"
#include "deps/020d3d48_func_020d3d48.h"

int func_020d3d48(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(uRam020d3d88 & 0xfffffffc) >> (uRam020d3d88 & 3) * 8 |
          *(uint *)(uRam020d3d88 & 0xfffffffc) << (uRam020d3d88 & 3) * -8 + 0x20;
  if ((uVar4 != 0) &&
     (uVar1 = uVar4 + 0x170 & 3, uVar3 = *(uint *)(uVar4 + 0x170 & 0xfffffffc),
     uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0)) {
    uVar1 = uVar4 + 4 & 3;
    uVar4 = *(uint *)(uVar4 + 4 & 0xfffffffc);
    return param_1 - (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  }
  uVar4 = *(uint *)(uRam020d3d8c & 0xfffffffc) >> (uRam020d3d8c & 3) * 8 |
          *(uint *)(uRam020d3d8c & 0xfffffffc) << (uRam020d3d8c & 3) * -8 + 0x20;
  iVar2 = iRam020d3d90;
  if (uVar4 != 0) {
    iVar2 = param_1 - (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                      *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20);
  }
  return iVar2;
}

