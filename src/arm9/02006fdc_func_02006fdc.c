/* Decompiled C draft; module arm9; ROM address 02006fdc. No matching claim. */
#include "types.h"
#include "deps/02006fdc_func_02006fdc.h"

uint func_02006fdc(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if ((param_1 >> (uVar1 & 0xff) & 1U) != 0) {
      return uVar1;
    }
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 0x10);
  return 0xffffffff;
}

