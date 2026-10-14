/* Decompiled C draft; module arm9; ROM address 0203bfc4. No matching claim. */
#include "types.h"
#include "deps/0203bfc4_GetCurrentTime.h"

void GetCurrentTime(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = Rtc_GetTime();
  if (iVar1 != 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}

