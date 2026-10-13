/* Decompiled C draft; module arm9_ov003; ROM address 021b8e60. No matching claim. */
#include "types.h"
#include "deps/021b8e60_func_ov003_021b8e60.h"

int func_ov003_021b8e60(int param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 != 1) {
    *param_3 = *param_3 + 1;
    return param_1;
  }
  iVar1 = func_ov003_021b8bf0(param_4 + 8,param_2 + 0x1c);
  if (iVar1 < 0) {
    *param_3 = *param_3 + 1;
    return 1;
  }
  iVar1 = func_ov003_021b7c44(*(undefined2 *)(param_2 + 0x26));
  if (iVar1 == 0) {
    *param_3 = *param_3 + 1;
    return 1;
  }
  if (*(char *)(param_2 + 0x24) == '\a') {
    iVar1 = func_ov003_021b7c5c(*(undefined4 *)(param_2 + 0x28));
    if (iVar1 == -2) {
      func_ov003_021b94b8(0x14);
    }
    else {
      iVar1 = func_ov003_021b7c5c(*(undefined4 *)(param_2 + 0x28));
      if (iVar1 == -3) {
        func_ov003_021b94b8(0x15);
      }
      else {
        func_ov003_021b94b8(0x18);
      }
    }
    return -1;
  }
  func_ov003_021b7d84(uRam021b8f58,0,uRam021b8f5c);
  uVar2 = func_ov003_021b7c44(*(undefined2 *)(param_2 + 0x16));
  iVar1 = func_ov003_021b8758(0,(char *)(param_2 + 0x24),uVar2,uRam021b8f58,uRam021b8f60);
  if (iVar1 < 0) {
    *param_3 = *param_3 + 1;
    return 1;
  }
  if ((*(uint *)(iRam021b8f64 + 0xc) & *(uint *)(iRam021b8f64 + 8)) == 0) {
    return 1;
  }
  *param_3 = 0;
  return 2;
}

