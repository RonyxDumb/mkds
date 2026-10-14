/* Decompiled C draft; module arm9; ROM address 0203bfec. No matching claim. */
#include "types.h"
#include "deps/0203bfec_GetCurrentDate.h"

void GetCurrentDate(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = Rtc_GetDate();
  if (iVar1 != 0) {
    *param_1 = 5;
    param_1[1] = 1;
    param_1[2] = 1;
  }
  return;
}

