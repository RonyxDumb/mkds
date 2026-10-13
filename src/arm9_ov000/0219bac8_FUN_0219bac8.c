/* Decompiled C draft; module arm9_ov000; ROM address 0219bac8. No matching claim. */
#include "types.h"
#include "deps/0219bac8_FUN_0219bac8.h"

undefined4 FUN_0219bac8(uint param_1)

{
  undefined4 uVar1;
  
  if (*DAT_0219bafc == 0) {
    return 0;
  }
  if ((*(uint *)(*DAT_0219bafc + DAT_0219bb00) & 1 << (param_1 & 0xff)) != 0) {
    uVar1 = FUN_0219b8bc();
    return uVar1;
  }
  return 0;
}

