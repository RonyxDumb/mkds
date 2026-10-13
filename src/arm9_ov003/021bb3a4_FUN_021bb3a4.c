/* Decompiled C draft; module arm9_ov003; ROM address 021bb3a4. No matching claim. */
#include "types.h"
#include "deps/021bb3a4_FUN_021bb3a4.h"

void FUN_021bb3a4(undefined1 *param_1,undefined1 param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_3 != 0) {
    do {
      *param_1 = param_2;
      param_1 = param_1 + 1;
      uVar1 = uVar1 + 1;
    } while (uVar1 < param_3);
  }
  return;
}

