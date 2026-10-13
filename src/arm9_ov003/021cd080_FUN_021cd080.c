/* Decompiled C draft; module arm9_ov003; ROM address 021cd080. No matching claim. */
#include "types.h"
#include "deps/021cd080_FUN_021cd080.h"

void FUN_021cd080(short *param_1)

{
  if (((param_1[1] == 0) && (*(char *)(*DAT_021cd0c8 + DAT_021cd0cc) == '\0')) && (*param_1 == 0x26)
     ) {
    if (param_1[4] == 4) {
      FUN_021cd190();
      return;
    }
    if (param_1[4] == 5) {
      FUN_021ccf30();
      FUN_021cd190();
      return;
    }
    func_0x0200fd1c();
  }
  return;
}

