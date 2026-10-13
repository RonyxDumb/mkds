/* Decompiled C draft; module arm9; ROM address 02110590. No matching claim. */
#include "types.h"
#include "deps/02110590_func_02110590.h"

uint func_02110590(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = iRam0211059c + param_1 * 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

