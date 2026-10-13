/* Decompiled C draft; module arm9_ov003; ROM address 021b8340. No matching claim. */
#include "types.h"
#include "deps/021b8340_func_ov003_021b8340.h"

void func_ov003_021b8340(int param_1,undefined2 *param_2,undefined4 param_3,short *param_4,
                        undefined2 *param_5,undefined4 param_6)

{
  undefined2 uVar1;
  
  if (param_1 == 1) {
    *param_5 = 1;
    func_ov003_021b81f4(param_3,(undefined4)(uintptr_t)(param_2 + 2),(int)*param_4,(undefined1 *)(uintptr_t)(param_6),(undefined4)(uintptr_t)(param_2 + 1),uRam021b8398,8);
    uVar1 = func_ov003_021b7c94(*param_4);
    *param_2 = uVar1;
    *param_4 = *param_4 + 4;
    return;
  }
  func_ov003_021b7d90(param_2,param_3,(int)*param_4);
  return;
}

