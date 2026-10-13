/* Decompiled C draft; module arm9_ov003; ROM address 021cfff8. No matching claim. */
#include "types.h"
#include "deps/021cfff8_FUN_021cfff8.h"

undefined2 FUN_021cfff8(uint param_1)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = func_0x02143280();
  if (uVar2 == DAT_021d0070) {
    FUN_021d079c(3);
    FUN_021d07b0(9);
    return 3;
  }
  if (uVar2 != 0) {
    uVar3 = param_1 - 1;
    while( true ) {
      if ((1 << (uVar3 & 0xff) & uVar2) != 0) {
        uVar1 = FUN_021cff38(DAT_021d0074,param_1);
        return uVar1;
      }
      param_1 = param_1 + 1 & 0xffff;
      if (0x10 < param_1) break;
      uVar3 = param_1 - 1;
    }
    return 0x18;
  }
  FUN_021d079c(0x16);
  FUN_021d07b0(9);
  return 0x18;
}

