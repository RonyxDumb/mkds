/* Decompiled C draft; module arm9; ROM address 0208b484. No matching claim. */
#include "types.h"
#include "deps/0208b484_func_0208b484.h"

uint func_0208b484(undefined4 *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = uRam0208b494;
  *param_1 = param_2;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

