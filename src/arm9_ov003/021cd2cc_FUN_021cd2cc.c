/* Decompiled C draft; module arm9_ov003; ROM address 021cd2cc. No matching claim. */
#include "types.h"
#include "deps/021cd2cc_FUN_021cd2cc.h"

int FUN_021cd2cc(uint param_1)

{
  if (param_1 < 0x3a) {
    return param_1 - 0x30;
  }
  if (param_1 < 0x47) {
    return param_1 - 0x37;
  }
  return param_1 - 0x57;
}

