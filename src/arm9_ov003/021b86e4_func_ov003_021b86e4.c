/* Decompiled C draft; module arm9_ov003; ROM address 021b86e4. No matching claim. */
#include "types.h"
#include "deps/021b86e4_func_ov003_021b86e4.h"

undefined4 func_ov003_021b86e4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    func_ov003_021b9134(2);
    uVar1 = func_ov003_021b858c(param_2,param_3,param_4);
    return uVar1;
  }
  if (param_1 != 1) {
    if (param_1 != 2) {
      return 0xffffffff;
    }
    func_ov003_021b9134(5);
    uVar1 = func_ov003_021b8428(param_2,param_3,param_4);
    return uVar1;
  }
  func_ov003_021b9134(3);
  uVar1 = func_ov003_021b8498(param_2,param_3,param_4);
  return uVar1;
}

