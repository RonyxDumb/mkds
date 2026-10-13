/* Decompiled C draft; module arm9; ROM address 0202056c. No matching claim. */
#include "types.h"
#include "deps/0202056c_Math_CountPopulation.h"

uint Math_CountPopulation(uint param_1)

{
  uint uVar1;
  
  param_1 = param_1 - (uRam020205a4 & param_1 >> 1);
  uVar1 = (param_1 & uRam020205a8) + (uRam020205a8 & param_1 >> 2);
  uVar1 = uVar1 + (uVar1 >> 4) & uRam020205ac;
  uVar1 = uVar1 + (uVar1 >> 8);
  return uVar1 + (uVar1 >> 0x10) & 0xff;
}

