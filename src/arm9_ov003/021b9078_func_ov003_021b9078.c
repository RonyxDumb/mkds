/* Decompiled C draft; module arm9_ov003; ROM address 021b9078. No matching claim. */
#include "types.h"
#include "deps/021b9078_func_ov003_021b9078.h"

undefined4 func_ov003_021b9078(undefined4 param_1,int param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = func_ov003_021b7c44(*(undefined2 *)(param_2 + 0xc));
  if (iVar1 == 0) {
    *param_3 = *param_3 + 1;
    return param_1;
  }
  if (*(char *)(param_2 + 0x1b) == '\x11') {
    iVar1 = func_ov003_021b8c8c(param_2 + 0xc);
    if (iVar1 < 1) {
      iVar1 = func_ov003_021b7c44(*(undefined2 *)(param_2 + 0x12));
      if (iVar1 == iRam021b9128) {
        param_1 = func_ov003_021b8f68(param_1,param_2,param_3,param_4);
      }
      else if (iVar1 == iRam021b912c) {
        param_1 = func_ov003_021b8e60(param_1,param_2,param_3,param_4);
      }
      else if (iVar1 == iRam021b9130) {
        param_1 = func_ov003_021b8d9c(param_1,param_2,param_3,param_4);
      }
      return param_1;
    }
    *param_3 = *param_3 + 1;
    return param_1;
  }
  *param_3 = *param_3 + 1;
  return param_1;
}

