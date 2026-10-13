/* Decompiled C draft; module arm9; ROM address 02150dc8. No matching claim. */
#include "types.h"
#include "deps/02150dc8_func_02150dc8.h"

uint func_02150dc8(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)piRam02150df8 & 3;
  uVar2 = *(uint *)((uint)piRam02150df8 & 0xfffffffc);
  *piRam02150df8 = param_1;
  if (param_1 == 0) {
    *puRam02150e00 = uRam02150e04;
  }
  else {
    *puRam02150e00 = uRam02150dfc;
  }
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

