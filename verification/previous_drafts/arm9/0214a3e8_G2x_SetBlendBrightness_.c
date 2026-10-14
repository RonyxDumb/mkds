/* Decompiled C draft; module arm9; ROM address 0214a3e8. No matching claim. */
#include "types.h"
#include "deps/0214a3e8_G2x_SetBlendBrightness_.h"

void G2x_SetBlendBrightness_(ushort *param_1,ushort param_2,int param_3)

{
  if (param_3 < 0) {
    *param_1 = param_2 | 0xc0;
    param_1[2] = -(ushort)param_3;
  }
  else {
    *param_1 = param_2 | 0x80;
    param_1[2] = (ushort)param_3;
  }
  return;
}

