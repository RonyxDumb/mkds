/* Decompiled C draft; module arm9_ov000; ROM address 0219adb4. No matching claim. */
#include "types.h"
#include "deps/0219adb4_FUN_0219adb4.h"

int FUN_0219adb4(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_0218e374();
  if (iVar1 == -1) {
    iVar1 = FUN_021a8f84(param_1);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = *(int *)**(undefined4 **)(iVar1 + 0xc);
  }
  return iVar1;
}

