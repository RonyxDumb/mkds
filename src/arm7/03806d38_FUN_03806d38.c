/* Decompiled C draft; module arm7; ROM address 03806d38. No matching claim. */
#include "types.h"
#include "deps/03806d38_FUN_03806d38.h"

void FUN_03806d38(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    return;
  }
  if (param_2 <= param_1) {
    uVar1 = 0x1c;
    uVar2 = param_1 >> 4;
    if ((int)param_2 <= (int)(param_1 >> 0x10)) {
      uVar1 = 0xc;
      uVar2 = param_1 >> 0x14;
    }
    if ((int)param_2 <= (int)(uVar2 >> 4)) {
      uVar1 = uVar1 - 8;
      uVar2 = uVar2 >> 8;
    }
    if ((int)param_2 <= (int)uVar2) {
      uVar1 = uVar1 - 4;
      uVar2 = uVar2 >> 4;
    }
                    /* WARNING: Could not recover jumptable at 0x03806d8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&UNK_03806d94 + uVar1 * 0xc))
              ((param_1 << (uVar1 & 0xff)) * 2,-param_2,uVar1 * 3,uVar2);
    return;
  }
  return;
}

