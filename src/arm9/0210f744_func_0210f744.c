/* Decompiled C draft; module arm9; ROM address 0210f744. No matching claim. */
#include "types.h"
#include "deps/0210f744_func_0210f744.h"

uint func_0210f744(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = iRam0210f758 + param_1 * 0xc;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

