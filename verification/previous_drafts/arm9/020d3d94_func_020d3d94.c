/* Decompiled C draft; module arm9; ROM address 020d3d94. No matching claim. */
#include "types.h"
#include "deps/020d3d94_func_020d3d94.h"

bool func_020d3d94(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(uRam020d3db8 & 0xfffffffc) >> (uRam020d3db8 & 3) * 8 |
          *(uint *)(uRam020d3db8 & 0xfffffffc) << (uRam020d3db8 & 3) * -8 + 0x20;
  if (uVar2 == 0) {
    return false;
  }
  uVar2 = uVar2 + 0x170;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0;
}

