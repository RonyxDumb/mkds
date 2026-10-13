/* Decompiled C draft; module arm9_ov000; ROM address 02197d84. No matching claim. */
#include "types.h"
#include "deps/02197d84_FUN_02197d84.h"

void FUN_02197d84(int *param_1,int param_2,int param_3)

{
  if ((param_2 != 0) && (param_3 != 0)) {
    if (param_3 == -1) {
      param_3 = func_0x0213a434(param_2);
    }
    if (param_1[1] < param_1[2] + param_3) {
      func_0x0213442c(DAT_02197dd4,DAT_02197dd8,0,0x40);
    }
    func_0x02134eb8((uint *)(uintptr_t)(*param_1 + param_1[2]),param_2,param_3);
    param_1[2] = param_1[2] + param_3;
  }
  return;
}

