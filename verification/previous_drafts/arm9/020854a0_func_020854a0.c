/* Decompiled C draft; module arm9; ROM address 020854a0. No matching claim. */
#include "types.h"
#include "deps/020854a0_func_020854a0.h"

uint func_020854a0(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020854bc & 0xfffffffc) >> (uRam020854bc & 3) * 8 |
          *(uint *)(uRam020854bc & 0xfffffffc) << (uRam020854bc & 3) * -8 + 0x20) +
          (param_2 + param_1 + -1) * 4 + 0x40;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

