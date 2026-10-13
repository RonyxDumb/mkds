/* Decompiled C draft; module arm9_ov000; ROM address 02189280. No matching claim. */
#include "types.h"
#include "deps/02189280_FUN_02189280.h"

undefined4 FUN_02189280(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_021a5bfc();
  switch(uVar1) {
  case 0:
    return 1;
  case 1:
    FUN_021a6428();
    break;
  case 3:
    FUN_021a61e4();
    break;
  case 6:
    FUN_021a6024();
    break;
  case 9:
    FUN_021a5db0();
    break;
  case 0xb:
    FUN_02188508(0);
    return 0xffffffff;
  case 0xc:
    FUN_021a5c24();
  }
  return 0;
}

