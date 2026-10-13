/* Decompiled C draft; module arm9_ov000; ROM address 0218e2a4. No matching claim. */
#include "types.h"
#include "deps/0218e2a4_FUN_0218e2a4.h"

void FUN_0218e2a4(uint param_1)

{
  if (param_1 == 0) {
    param_1 = 1;
  }
  else {
    param_1 = param_1 & DAT_0218e2b8;
  }
  *DAT_0218e2bc = param_1;
  return;
}

