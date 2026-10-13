/* Decompiled C draft; module arm9_ov000; ROM address 0218de28. No matching claim. */
#include "types.h"
#include "deps/0218de28_FUN_0218de28.h"

undefined4 FUN_0218de28(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 != (int *)0x0) {
    iVar1 = (*(code *)param_1[3])(param_2,param_1[1]);
    iVar2 = FUN_0218d980((int *)(uintptr_t)(*(undefined4 *)(*param_1 + iVar1 * 4)),param_2,param_1[4],0,0);
    uVar3 = 0;
    if (iVar2 != -1) {
      uVar3 = FUN_0218dbf8(*(undefined4 *)(*param_1 + iVar1 * 4));
    }
    return uVar3;
  }
  func_0x0213442c(DAT_0218de84,DAT_0218de88,0,0x94);
  return 0;
}

