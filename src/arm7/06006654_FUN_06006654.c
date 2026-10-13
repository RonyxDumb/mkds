/* Decompiled C draft; module arm7; ROM address 06006654. No matching claim. */
#include "types.h"
#include "deps/06006654_FUN_06006654.h"

void FUN_06006654(uint param_1)

{
  if (param_1 < 0xd2) {
    if (param_1 < 0xd0) {
      if (param_1 == 200) {
        FUN_060063b0();
      }
    }
    else if (param_1 == 0xd0) {
      FUN_06006358();
    }
    else if (param_1 == 0xd1) {
      FUN_060061a0();
    }
  }
  else if (param_1 < 0xf1) {
    if (param_1 == 0xf0) {
      FUN_06006228();
    }
  }
  else if (param_1 == 0x104) {
    FUN_06006144();
  }
  return;
}

