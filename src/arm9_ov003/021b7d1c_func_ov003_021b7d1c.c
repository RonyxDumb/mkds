/* Decompiled C draft; module arm9_ov003; ROM address 021b7d1c. No matching claim. */
#include "types.h"
#include "deps/021b7d1c_func_ov003_021b7d1c.h"

void func_ov003_021b7d1c(undefined4 param_1,undefined4 *param_2,undefined4 param_3,
                        undefined4 param_4,int *param_5)

{
  uint uVar1;
  uint uVar2;
  undefined4 local_18;
  undefined4 local_14;
  
  local_18 = *param_2;
  local_14 = param_2[1];
  uVar1 = func_0x02133068(iRam021b7d64 * *param_5,0x40);
  uVar2 = func_0x02133068(iRam021b7d64 * param_5[1],0x40);
  func_0x021a8b20(&local_18,1,uVar1 + uVar2,
                  ((int)uVar1 >> 0x1f) + ((int)uVar2 >> 0x1f) + (uint)CARRY4(uVar1,uVar2));
  return;
}

