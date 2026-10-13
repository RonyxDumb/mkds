/* Decompiled C draft; module arm9; ROM address 0204dcf0. No matching claim. */
#include "types.h"
#include "deps/0204dcf0_func_0204dcf0.h"

uint func_0204dcf0(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = 1;
  uVar2 = param_1 & 1;
  uVar3 = 1;
  do {
    if ((1 << (uVar1 & 0xff) & param_1) != 0) {
      uVar2 = uVar2 | 1 << (uVar3 & 0xff) & 0xffU;
      uVar3 = uVar3 + 1;
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 8);
  return uVar2;
}

