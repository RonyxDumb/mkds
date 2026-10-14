/* Decompiled C draft; module arm7; ROM address 037ff8b4. No matching claim. */
#include "types.h"
#include "deps/037ff8b4_FUN_037ff8b4.h"

void FUN_037ff8b4(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_037faf70();
  if (param_2 < 0x2000000) {
    if (param_2 == 0) {
      FUN_037fc29c();
    }
  }
  else {
    FUN_037f9854(DAT_037ff904,param_2,0);
  }
  FUN_037faf84(uVar1);
  return;
}

