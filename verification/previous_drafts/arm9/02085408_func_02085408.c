/* Decompiled C draft; module arm9; ROM address 02085408. No matching claim. */
#include "types.h"
#include "deps/02085408_func_02085408.h"

uint func_02085408(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam02085420 & 0xfffffffc) >> (uRam02085420 & 3) * 8 |
          *(uint *)(uRam02085420 & 0xfffffffc) << (uRam02085420 & 3) * -8 + 0x20) +
          (param_1 + -1) * 4 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

