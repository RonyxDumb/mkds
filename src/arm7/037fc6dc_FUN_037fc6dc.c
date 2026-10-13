/* Decompiled C draft; module arm7; ROM address 037fc6dc. No matching claim. */
#include "types.h"
#include "deps/037fc6dc_FUN_037fc6dc.h"

uint FUN_037fc6dc(int param_1)

{
  uint uVar1;
  
  uVar1 = DAT_037fc738;
  if (param_1 != 0x7f) {
    if (param_1 == 0x7e) {
      uVar1 = 0x3c00;
    }
    else if (param_1 < 0x32) {
      uVar1 = param_1 * 2 + 1U & 0xffff;
    }
    else {
      uVar1 = FUN_03806b2c(0x1e00,0x7e - param_1);
      uVar1 = uVar1 & 0xffff;
    }
  }
  return uVar1;
}

