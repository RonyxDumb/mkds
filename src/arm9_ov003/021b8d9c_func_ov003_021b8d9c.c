/* Decompiled C draft; module arm9_ov003; ROM address 021b8d9c. No matching claim. */
#include "types.h"
#include "deps/021b8d9c_func_ov003_021b8d9c.h"

int func_ov003_021b8d9c(int param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  
  if (param_1 != 2) {
    *param_3 = *param_3 + 1;
    return param_1;
  }
  iVar1 = func_ov003_021b8bf0(param_4 + 0x10,param_2 + 0x1c);
  if (iVar1 < 0) {
    *param_3 = *param_3 + 1;
    return 2;
  }
  if (*(char *)(param_2 + 0x24) != '\a') {
    *param_3 = *param_3 + 1;
    return 2;
  }
  iVar1 = func_ov003_021b7c44(*(undefined2 *)(param_2 + 0x26));
  if (iVar1 == 0) {
    *param_3 = *param_3 + 1;
    return 2;
  }
  iVar1 = func_ov003_021b7c5c(*(undefined4 *)(param_2 + 0x28));
  if (iVar1 == 0) {
    return 100;
  }
  iVar1 = func_ov003_021b7c5c(*(undefined4 *)(param_2 + 0x28));
  if (iVar1 == -2) {
    func_ov003_021b94b8(0x14);
    return -1;
  }
  iVar1 = func_ov003_021b7c5c(*(undefined4 *)(param_2 + 0x28));
  if (iVar1 == -3) {
    func_ov003_021b94b8(0x15);
    return -1;
  }
  func_ov003_021b94b8(0x18);
  return -1;
}

