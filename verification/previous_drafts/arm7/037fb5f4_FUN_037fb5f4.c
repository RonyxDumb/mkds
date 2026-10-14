/* Decompiled C draft; module arm7; ROM address 037fb5f4. No matching claim. */
#include "types.h"
#include "deps/037fb5f4_FUN_037fb5f4.h"

undefined4 FUN_037fb5f4(uint param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  
  if ((*DAT_037fb690 & 0x4000) == 0) {
    FUN_037faf70(*DAT_037fb690 & 0x4000);
    if ((*DAT_037fb690 & 2) == 0) {
      *DAT_037fb694 = param_1 & 0x1f | (param_3 & 1) << 5 | param_2 << 6;
      FUN_037faf84();
      uVar1 = 0;
    }
    else {
      FUN_037faf84();
      uVar1 = 0xfffffffe;
    }
  }
  else {
    *DAT_037fb690 = *DAT_037fb690 | 0xc000;
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

