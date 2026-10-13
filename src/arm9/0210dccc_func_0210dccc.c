/* Decompiled C draft; module arm9; ROM address 0210dccc. No matching claim. */
#include "types.h"
#include "deps/0210dccc_func_0210dccc.h"

undefined4
func_0210dccc(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
             undefined4 param_5)

{
  int iVar1;
  
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  iVar1 = func_0210e3ec(param_5,*param_1,param_1[1],param_1[2]);
  if (iVar1 == 0) {
    func_0210e434((undefined4 *)(uintptr_t)(param_5));
    func_0210e33c((int *)(uintptr_t)(param_5),*param_1,param_1[1],param_1[2]);
  }
  func_0212c6a0(param_1 + 3);
  *piRam0210dd40 = (int)param_1;
  param_1[4] = param_5;
  return 1;
}

