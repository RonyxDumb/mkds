/* Decompiled C draft; module arm9_ov000; ROM address 021a158c. No matching claim. */
#include "types.h"
#include "deps/021a158c_FUN_021a158c.h"

int FUN_021a158c(int *param_1)

{
  int *piVar1;
  
  piVar1 = DAT_021a15a8;
  if (*DAT_021a15a8 == 0) {
    return 0;
  }
  *param_1 = *DAT_021a15a8 + DAT_021a15ac;
  return *(byte *)(*piVar1 + 0xd) + 1;
}

