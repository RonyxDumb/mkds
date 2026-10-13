/* Decompiled C draft; module arm9_ov000; ROM address 0219922c. No matching claim. */
#include "types.h"
#include "deps/0219922c_FUN_0219922c.h"

undefined4 FUN_0219922c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0219a5b0();
  if (*(int *)(param_1 + 0x2c) != 0) {
    iVar2 = FUN_02197f28(param_1,iVar1,param_2,param_3,1,0,0,0);
    if (iVar2 == 0) {
      return 0;
    }
  }
  if (iVar1 == 0) {
    return 1;
  }
  if (*(int *)(iVar1 + 0xc) == 0) {
    if ((*(int *)(iVar1 + 0x20) == 0) ||
       (iVar2 = FUN_0218e8c4(), (uint)(iVar2 - *(int *)(iVar1 + 0x1c)) < *(uint *)(iVar1 + 0x20))) {
      return 1;
    }
    iVar1 = FUN_02199fb0(iVar1,6,1);
    if (iVar1 == 0) {
      return 0;
    }
  }
  else {
    iVar1 = FUN_02199fb0(iVar1,2,1);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 1;
}

