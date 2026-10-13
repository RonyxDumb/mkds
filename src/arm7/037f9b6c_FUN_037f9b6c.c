/* Decompiled C draft; module arm7; ROM address 037f9b6c. No matching claim. */
#include "types.h"
#include "deps/037f9b6c_FUN_037f9b6c.h"

int FUN_037f9b6c(int param_1)

{
  int iVar1;
  
  if (param_1 == 1) {
    return DAT_037f9bcc;
  }
  if (param_1 == 7) {
    return 0x3800000;
  }
  if (param_1 != 8) {
    return 0;
  }
  if (DAT_037f9bd8 != 0) {
    if (DAT_037f9bd8 < 0) {
      iVar1 = 0x3800000 - DAT_037f9bd8;
    }
    else {
      iVar1 = (DAT_037f9bd4 - DAT_037f9bd0) - DAT_037f9bd8;
    }
    return iVar1;
  }
  return 0x3800000;
}

