/* Decompiled C draft; module arm7; ROM address 0600bad4. No matching claim. */
#include "types.h"
#include "deps/0600bad4_FUN_0600bad4.h"

undefined4 FUN_0600bad4(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 4) {
    *(short *)((*(uint *)(DAT_0600baf4 & 0xfffffffc) >> (DAT_0600baf4 & 3) * 8 |
               *(uint *)(DAT_0600baf4 & 0xfffffffc) << (DAT_0600baf4 & 3) * -8 + 0x20) + 0x336) =
         (short)param_1;
    uVar1 = 0;
  }
  else {
    uVar1 = 5;
  }
  return uVar1;
}

