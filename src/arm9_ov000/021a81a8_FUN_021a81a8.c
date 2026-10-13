/* Decompiled C draft; module arm9_ov000; ROM address 021a81a8. No matching claim. */
#include "types.h"
#include "deps/021a81a8_FUN_021a81a8.h"

int FUN_021a81a8(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                int param_6)

{
  int iVar1;
  int iVar2;
  int local_24;
  int local_20;
  undefined4 local_1c [2];
  
  local_20 = 0;
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x68) + DAT_021a8264) + 0x48);
  if (*(char *)(param_1 + 0x73) == '\x01') {
    local_24 = param_3;
    if (iVar1 + -0x2a < param_3) {
      return -0x23;
    }
  }
  else {
    local_24 = iVar1 + -0x36;
    if (param_3 <= local_24) {
      local_24 = param_3;
    }
  }
  if (0 < param_3) {
    do {
      iVar1 = FUN_021a813c(param_1,param_3,local_24,local_1c,param_6);
      if (0 < iVar1) {
        iVar2 = FUN_021a8014(param_1,param_2,iVar1,local_1c[0],param_4,param_5,param_6);
        if (iVar2 < 1) {
          return -6;
        }
        param_2 = param_2 + iVar1;
        param_3 = param_3 - iVar1;
        local_20 = local_20 + iVar1;
      }
      if (param_6 == 0) {
        if (0 < iVar1) {
          return local_20;
        }
        return -6;
      }
    } while (0 < param_3);
  }
  return local_20;
}

