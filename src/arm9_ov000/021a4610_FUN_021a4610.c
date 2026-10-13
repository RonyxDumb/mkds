/* Decompiled C draft; module arm9_ov000; ROM address 021a4610. No matching claim. */
#include "types.h"
#include "deps/021a4610_FUN_021a4610.h"

uint FUN_021a4610(uint param_1)

{
  if (param_1 < 0x1a) {
    return param_1 + 0x41 & 0xff;
  }
  if (param_1 < 0x34) {
    return param_1 + 0x47 & 0xff;
  }
  if (param_1 < 0x3e) {
    return param_1 - 4 & 0xff;
  }
  if (param_1 == 0x3e) {
    return 0x2b;
  }
  if (param_1 == 0x3f) {
    return 0x2f;
  }
  return 0;
}

