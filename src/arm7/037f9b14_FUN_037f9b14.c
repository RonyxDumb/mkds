/* Decompiled C draft; module arm7; ROM address 037f9b14. No matching claim. */
#include "types.h"
#include "deps/037f9b14_FUN_037f9b14.h"

uint FUN_037f9b14(int param_1)

{
  uint uVar1;
  
  if (param_1 == 1) {
    return DAT_037f9b64;
  }
  if (param_1 != 7) {
    if (param_1 != 8) {
      return 0;
    }
    uVar1 = 0x3800000;
    if (0x3800000 < DAT_037f9b68) {
      uVar1 = DAT_037f9b68;
    }
    return uVar1;
  }
  uVar1 = DAT_037f9b68;
  if (0x3800000 < DAT_037f9b68) {
    uVar1 = 0x3800000;
  }
  return uVar1;
}

