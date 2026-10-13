/* Decompiled C draft; module arm9_ov000; ROM address 021ac34c. No matching claim. */
#include "types.h"
#include "deps/021ac34c_FUN_021ac34c.h"

void FUN_021ac34c(uint *param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_3 != 0) {
    do {
      *param_1 = (uint)*(byte *)(param_2 + uVar1 + 3) |
                 (uint)*(byte *)(param_2 + uVar1 + 2) << 8 |
                 (uint)*(byte *)(param_2 + uVar1) << 0x18 |
                 (uint)*(byte *)(param_2 + uVar1 + 1) << 0x10;
      param_1 = param_1 + 1;
      uVar1 = uVar1 + 4;
    } while (uVar1 < param_3);
  }
  return;
}

