/* Decompiled C draft; module arm9_ov003; ROM address 021b91a4. No matching claim. */
#include "types.h"
#include "deps/021b91a4_func_ov003_021b91a4.h"

undefined4 func_ov003_021b91a4(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = func_ov003_021b7c30(uRam021b91e8);
  *param_1 = uVar1;
  func_ov003_021b7d90(param_1 + 1,uRam021b91e8,*param_1);
  param_1[9] = 1;
  uVar1 = func_ov003_021b7c30(uRam021b91ec);
  param_1[10] = uVar1;
  if (0xd < (uint)param_1[10]) {
    return 0xffffffff;
  }
  func_ov003_021b7d90(param_1 + 0xb,uRam021b91ec);
  return 0;
}

