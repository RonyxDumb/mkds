/* Decompiled C draft; module arm9; ROM address 02021834. No matching claim. */
#include "types.h"
#include "deps/02021834_func_02021834.h"

uint func_02021834(void)

{
  uint uVar1;
  uint uVar2;
  
  DC_InvalidateRangeNoClean
            (*(uint *)(uRam02021864 & 0xfffffffc) >> (uRam02021864 & 3) * 8 |
             *(uint *)(uRam02021864 & 0xfffffffc) << (uRam02021864 & 3) * -8 + 0x20,4);
  uVar2 = *(uint *)(uRam02021864 & 0xfffffffc) >> (uRam02021864 & 3) * 8 |
          *(uint *)(uRam02021864 & 0xfffffffc) << (uRam02021864 & 3) * -8 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

