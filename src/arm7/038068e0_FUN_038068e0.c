/* Decompiled C draft; module arm7; ROM address 038068e0. No matching claim. */
#include "types.h"
#include "deps/038068e0_FUN_038068e0.h"

uint FUN_038068e0(uint param_1)

{
  uint uVar1;
  
  param_1 = param_1 - (DAT_03806918 & param_1 >> 1);
  uVar1 = (param_1 & DAT_0380691c) + (DAT_0380691c & param_1 >> 2);
  uVar1 = uVar1 + (uVar1 >> 4) & DAT_03806920;
  uVar1 = uVar1 + (uVar1 >> 8);
  return uVar1 + (uVar1 >> 0x10) & 0xff;
}

