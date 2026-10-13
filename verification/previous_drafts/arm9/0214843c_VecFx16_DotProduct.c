/* Decompiled C draft; module arm9; ROM address 0214843c. No matching claim. */
#include "types.h"
#include "deps/0214843c_VecFx16_DotProduct.h"

uint VecFx16_DotProduct(short *param_1,short *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (int)*param_1 * (int)*param_2 + (int)param_1[1] * (int)param_2[1];
  uVar1 = (int)param_1[2] * (int)param_2[2] + 0x800;
  return uVar2 + uVar1 >> 0xc |
         (((int)uVar2 >> 0x1f) + ((int)uVar1 >> 0x1f) + (uint)CARRY4(uVar2,uVar1)) * 0x100000;
}

