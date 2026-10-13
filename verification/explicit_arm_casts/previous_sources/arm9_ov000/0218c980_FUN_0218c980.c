/* Decompiled C draft; module arm9_ov000; ROM address 0218c980. No matching claim. */
#include "types.h"
#include "deps/0218c980_FUN_0218c980.h"

void FUN_0218c980(undefined4 *param_1)

{
  if (param_1[0x1f] != 0) {
    FUN_021a3668();
  }
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  if (*(int *)((int)param_1 + DAT_0218c9cc) != -1) {
    FUN_0218e53c();
  }
  *(undefined4 *)((int)param_1 + DAT_0218c9cc) = 0xffffffff;
  *param_1 = 1;
  FUN_0218c9d4(param_1);
  *(undefined4 *)((int)param_1 + DAT_0218c9d0) = 0xffffffff;
  FUN_0218ca1c(param_1);
  return;
}

