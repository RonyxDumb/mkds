/* Decompiled C draft; module arm7; ROM address 0600b7f4. No matching claim. */
#include "types.h"
#include "deps/0600b7f4_FUN_0600b7f4.h"

undefined4 FUN_0600b7f4(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 2) {
    *(short *)((*(uint *)(DAT_0600b814 & 0xfffffffc) >> (DAT_0600b814 & 3) * 8 |
               *(uint *)(DAT_0600b814 & 0xfffffffc) << (DAT_0600b814 & 3) * -8 + 0x20) + 0x332) =
         (short)param_1;
    uVar1 = 0;
  }
  else {
    uVar1 = 5;
  }
  return uVar1;
}

