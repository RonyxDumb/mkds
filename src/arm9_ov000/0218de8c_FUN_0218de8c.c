/* Decompiled C draft; module arm9_ov000; ROM address 0218de8c. No matching claim. */
#include "types.h"
#include "deps/0218de8c_FUN_0218de8c.h"

bool FUN_0218de8c(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != (int *)0x0) {
    iVar1 = (*(code *)param_1[3])(param_2,param_1[1]);
    iVar2 = FUN_0218d980((int *)(uintptr_t)(*(undefined4 *)(*param_1 + iVar1 * 4)),param_2,param_1[4],0,0);
    if (iVar2 != -1) {
      FUN_0218da5c(*(undefined4 *)(*param_1 + iVar1 * 4));
    }
    return iVar2 != -1;
  }
  func_0x0213442c(DAT_0218dee8,DAT_0218deec,0,0x82);
  return false;
}

