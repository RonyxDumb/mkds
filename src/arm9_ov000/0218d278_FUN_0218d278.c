/* Decompiled C draft; module arm9_ov000; ROM address 0218d278. No matching claim. */
#include "types.h"
#include "deps/0218d278_FUN_0218d278.h"

void FUN_0218d278(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + DAT_0218d2a4) == 0) {
    FUN_0218b224(param_2,0);
  }
  else {
    FUN_0218b224(param_2);
  }
  *(undefined4 *)(param_1 + DAT_0218d2a4) = param_2;
  return;
}

