/* Decompiled C draft; module arm9_ov000; ROM address 02186430. No matching claim. */
#include "types.h"
#include "deps/02186430_FUN_02186430.h"

void FUN_02186430(void)

{
  if (*DAT_02186464 != 0) {
    if (*(int *)(*DAT_02186464 + DAT_02186468) != 0) {
      FUN_02186d04();
    }
    (**(code **)(*DAT_02186464 + DAT_02186470))(DAT_0218646c,*DAT_02186464,0);
    *DAT_02186464 = 0;
  }
  return;
}

