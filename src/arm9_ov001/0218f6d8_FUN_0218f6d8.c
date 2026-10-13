/* Decompiled C draft; module arm9_ov001; ROM address 0218f6d8. No matching claim. */
#include "types.h"
#include "deps/0218f6d8_FUN_0218f6d8.h"

void FUN_0218f6d8(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 auStack_18 [4];
  undefined4 local_14;
  
  if (*(int *)(*DAT_0218f720 + 8) == 4) {
    uVar1 = func_ov001_02181a88();
  }
  else {
    uVar1 = 0;
  }
  if (*(int *)(*DAT_0218f720 + 8) == 4) {
    uVar2 = func_ov001_02181a94();
  }
  else {
    uVar2 = 0;
  }
  func_0x021484d0(uVar2,uVar1,(int *)(void *)(auStack_18));
  local_14 = 0;
  FUN_02188950(param_1,(undefined4 *)(void *)(auStack_18));
  return;
}

