/* Decompiled C draft; module arm7; ROM address 037fba94. No matching claim. */
#include "types.h"
#include "deps/037fba94_FUN_037fba94.h"

int FUN_037fba94(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 < 0x18) {
    uVar1 = *(uint *)(DAT_037fbaf8 & 0xfffffffc) >> (DAT_037fbaf8 & 3) * 8 |
            *(uint *)(DAT_037fbaf8 & 0xfffffffc) << (DAT_037fbaf8 & 3) * -8 + 0x20;
    return (int)(param_1 * (uVar1 * (param_2 + 0x28) + (DAT_037fbafc - uVar1) * 0x40)) >> 0x15;
  }
  if (param_2 < 0x69) {
    return param_1;
  }
  uVar1 = *(uint *)(DAT_037fbaf8 & 0xfffffffc) >> (DAT_037fbaf8 & 3) * 8 |
          *(uint *)(DAT_037fbaf8 & 0xfffffffc) << (DAT_037fbaf8 & 3) * -8 + 0x20;
  return (int)(param_1 * (-uVar1 * (param_2 + -0x28) + (uVar1 + DAT_037fbafc) * 0x40)) >> 0x15;
}

