/* Decompiled C draft; module arm9_ov001; ROM address 02191888. No matching claim. */
#include "types.h"
#include "deps/02191888_FUN_02191888.h"

undefined4 FUN_02191888(int param_1)

{
  if (*(int *)(param_1 + DAT_021918b8) < 1) {
    FUN_02187af4();
    FUN_02188200(param_1,DAT_021918c0);
    *(undefined4 *)(param_1 + DAT_021918c4) = 0;
  }
  else {
    func_0x020d275c(param_1,DAT_021918bc);
  }
  return 0;
}

