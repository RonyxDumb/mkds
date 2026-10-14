/* Decompiled C draft; module arm7; ROM address 037fc8ac. No matching claim. */
#include "types.h"
#include "deps/037fc8ac_FUN_037fc8ac.h"

uint FUN_037fc8ac(uint param_1)

{
  uint uVar1;
  
  if ((param_1 & 1) == 0) {
    uVar1 = *(uint *)(DAT_037fc8c8 & 0xfffffffc) >> (DAT_037fc8c8 & 3) * 8 |
            *(uint *)(DAT_037fc8c8 & 0xfffffffc) << (DAT_037fc8c8 & 3) * -8 + 0x20;
  }
  else {
    uVar1 = *(uint *)(DAT_037fc8c4 & 0xfffffffc) >> (DAT_037fc8c4 & 3) * 8 |
            *(uint *)(DAT_037fc8c4 & 0xfffffffc) << (DAT_037fc8c4 & 3) * -8 + 0x20;
  }
  return uVar1;
}

