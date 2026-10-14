/* Decompiled C draft; module arm9; ROM address 02148908. No matching claim. */
#include "types.h"
#include "deps/02148908_SetBrightness.h"

void SetBrightness(ushort *param_1,int param_2)

{
  if (param_2 == 0) {
    *param_1 = 0;
    return;
  }
  if (param_2 < 1) {
    *param_1 = -(ushort)param_2 | 0x8000;
  }
  else {
    *param_1 = (ushort)param_2 | 0x4000;
  }
  return;
}

