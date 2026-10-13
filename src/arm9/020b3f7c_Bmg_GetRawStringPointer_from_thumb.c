/* Decompiled C draft; module arm9; ROM address 020b3f7c. No matching claim. */
#include "types.h"
#include "deps/020b3f7c_Bmg_GetRawStringPointer_from_thumb.h"

int Bmg_GetRawStringPointer_from_thumb(undefined4 param_1,undefined4 param_2)

{
  int extraout_r1;
  
  Bmg_Load_from_thumb();
  _s32_div_f(param_2,uRam020b3fa4);
  return *piRam020b3fa8 + 8 + *(int *)(*piRam020b3fac + extraout_r1 * 4 + 0x10);
}

