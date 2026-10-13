/* Decompiled C draft; module arm9; ROM address 020f4090. No matching claim. */
#include "types.h"
#include "deps/020f4090_func_020f4090.h"

uint func_020f4090(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = iRam020f409c + param_1 * 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

