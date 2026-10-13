/* Decompiled C draft; module arm9; ROM address 0214a40c. No matching claim. */
#include "types.h"
#include "deps/0214a40c_G2x_SetBlendAlpha_.h"

void G2x_SetBlendAlpha_(uint *param_1,uint param_2,int param_3,uint param_4,int param_5)

{
  *param_1 = param_2 | 0x40 | param_3 << 8 | (param_4 | param_5 << 8) << 0x10;
  return;
}

