/* Decompiled C draft; module arm9; ROM address 0208c178. No matching claim. */
#include "types.h"
#include "deps/0208c178_func_0208c178.h"

uint func_0208c178(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x114U & 3;
  uVar2 = *(uint *)(param_1 + 0x114U & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

