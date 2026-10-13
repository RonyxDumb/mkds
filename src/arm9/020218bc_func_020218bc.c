/* Decompiled C draft; module arm9; ROM address 020218bc. No matching claim. */
#include "types.h"
#include "deps/020218bc_func_020218bc.h"

uint func_020218bc(void)

{
  uint uVar1;
  uint uVar2;
  
  DC_InvalidateRangeNoClean
            ((*(uint *)(uRam020218f0 & 0xfffffffc) >> (uRam020218f0 & 3) * 8 |
             *(uint *)(uRam020218f0 & 0xfffffffc) << (uRam020218f0 & 3) * -8 + 0x20) + 4,4);
  uVar2 = (*(uint *)(uRam020218f0 & 0xfffffffc) >> (uRam020218f0 & 3) * 8 |
          *(uint *)(uRam020218f0 & 0xfffffffc) << (uRam020218f0 & 3) * -8 + 0x20) + 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

