/* Decompiled C draft; module arm9_ov000; ROM address 021a47ac. No matching claim. */
#include "types.h"
#include "deps/021a47ac_FUN_021a47ac.h"

void FUN_021a47ac(int *param_1)

{
  if (param_1 == (int *)0x0) {
    param_1 = (int *)*DAT_021a4810;
  }
  if (param_1[0x2f] != 0) {
    FUN_021a3a18(param_1,2);
  }
  if ((*param_1 != -1) && (param_1[0x31] != 0)) {
    FUN_0218e53c();
  }
  *param_1 = -1;
  param_1[0x2b] = 0;
  if (param_1[0x31] != 0) {
    FUN_0218e8b4();
  }
  if (param_1 != DAT_021a4814) {
    FUN_021a3668(param_1);
  }
  return;
}

