/* Decompiled C draft; module arm9; ROM address 0208b458. No matching claim. */
#include "types.h"
#include "deps/0208b458_func_0208b458.h"

uint func_0208b458(int *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = uRam0208b480;
  uVar1 = uRam0208b47c;
  if (param_2 < 1000) {
    *param_1 = param_2;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar1 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  }
  else {
    *param_1 = param_2 + -1000;
    uVar2 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    uVar1 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  }
  return uVar1;
}

