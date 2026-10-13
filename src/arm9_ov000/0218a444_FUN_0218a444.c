/* Decompiled C draft; module arm9_ov000; ROM address 0218a444. No matching claim. */
#include "types.h"
#include "deps/0218a444_FUN_0218a444.h"

int FUN_0218a444(uint param_1)

{
  if ((0x40 < param_1) && (param_1 < 0x5b)) {
    return param_1 - 0x41;
  }
  if ((0x60 < param_1) && (param_1 < 0x7b)) {
    return param_1 - 0x47;
  }
  if ((0x2f < param_1) && (param_1 < 0x3a)) {
    return param_1 + 4;
  }
  if (param_1 == 0x2b) {
    return 0x3e;
  }
  if (param_1 == 0x2f) {
    return 0x3f;
  }
  return -(uint)(param_1 != 0x3d);
}

