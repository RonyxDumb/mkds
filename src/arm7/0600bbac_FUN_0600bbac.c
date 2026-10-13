/* Decompiled C draft; module arm7; ROM address 0600bbac. No matching claim. */
#include "types.h"
#include "deps/0600bbac_FUN_0600bbac.h"

undefined4 FUN_0600bbac(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 3) {
    *(short *)((*(uint *)(DAT_0600bbe4 & 0xfffffffc) >> (DAT_0600bbe4 & 3) * 8 |
               *(uint *)(DAT_0600bbe4 & 0xfffffffc) << (DAT_0600bbe4 & 3) * -8 + 0x20) + 0x330) =
         (short)param_1;
    FUN_0600aea0();
    uVar1 = 0;
  }
  else {
    uVar1 = 5;
  }
  return uVar1;
}

