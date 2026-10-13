/* Decompiled C draft; module arm9_ov000; ROM address 021996b8. No matching claim. */
#include "types.h"
#include "deps/021996b8_FUN_021996b8.h"

undefined4 FUN_021996b8(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_3 == 2) {
    uVar2 = FUN_0219a028(param_2,0);
    iVar1 = FUN_02199ec8(param_1,uVar2);
    if (iVar1 != 0) {
      return 1;
    }
    return 0;
  }
  iVar1 = FUN_02199fa4();
  if (iVar1 != 0) {
    return 1;
  }
  return 0;
}

