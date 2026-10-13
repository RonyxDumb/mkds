/* Decompiled C draft; module arm9; ROM address 02147e8c. No matching claim. */
#include "types.h"
#include "deps/02147e8c_FX_Sqrt.h"

void FX_Sqrt(int param_1)

{
  undefined4 *puVar1;
  
  if (0 < param_1) {
    *puRam02147ed4 = 1;
    puVar1 = puRam02147ed8;
    *puRam02147ed8 = 0;
    puVar1[1] = param_1;
    FX_GetSqrtResult();
    return;
  }
  return;
}

