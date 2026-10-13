/* Decompiled C draft; module arm9_ov001; ROM address 0218a590. No matching claim. */
#include "types.h"
#include "deps/0218a590_FUN_0218a590.h"

undefined4 FUN_0218a590(int param_1)

{
  if ((*(uint *)(param_1 + DAT_0218a5f0) & DAT_0218a5f4) != 0) {
    if (DAT_0218a5fc < *(int *)(param_1 + DAT_0218a5f8)) {
      FUN_02187af4();
      FUN_02187518(param_1,0,0,0,DAT_0218a600,0);
      FUN_02187518(param_1,0,0,0,DAT_0218a604,0);
    }
    if (0 < *(int *)(param_1 + DAT_0218a5f8)) {
      func_0x020d2774(param_1,DAT_0218a608);
    }
  }
  return 0;
}

