/* Decompiled C draft; module arm9_ov003; ROM address 021b8f68. No matching claim. */
#include "types.h"
#include "deps/021b8f68_func_ov003_021b8f68.h"

int func_ov003_021b8f68(int param_1,int param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 != 0) {
    *param_3 = *param_3 + 1;
    return param_1;
  }
  iVar1 = func_ov003_021b8bf0(param_4,param_2 + 0x1c);
  if (iVar1 < 0) {
    *param_3 = *param_3 + 1;
    return 0;
  }
  iVar1 = func_ov003_021b7c44(*(undefined2 *)(param_2 + 0x26));
  if (iVar1 == 0) {
    *param_3 = *param_3 + 1;
    return 0;
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
  if (*(char *)(param_2 + 0x24) != '\x01') {
    *param_3 = *param_3 + 1;
    return 0;
  }
  iVar1 = func_ov003_021b8b18((undefined1 *)(uintptr_t)(param_2 + 0x28),uRam021b9070);
  if (iVar1 < 0) {
    if (iVar1 == -2) {
      func_ov003_021b94b8(0x16);
      return -1;
    }
    *param_3 = *param_3 + 1;
    return 0;
  }
  func_ov003_021b7c44(*(undefined2 *)(param_2 + 0x18));
  uVar2 = func_ov003_021b8748();
  *puRam021b9074 = uVar2;
  *param_3 = 0;
  return 1;
}

