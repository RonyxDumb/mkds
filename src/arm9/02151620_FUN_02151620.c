/* Decompiled C draft; module arm9; ROM address 02151620. No matching claim. */
#include "types.h"
#include "deps/02151620_FUN_02151620.h"

undefined4 FUN_02151620(byte *param_1)

{
  byte bVar1;
  
  bVar1 = *param_1;
  if (bVar1 == 0x7f) {
    return 0;
  }
  if (bVar1 == 0) {
    return 0;
  }
  if (bVar1 < 0xe0) {
    return 1;
  }
  return 0;
}

