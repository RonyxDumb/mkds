/* Decompiled C draft; module arm9_ov000; ROM address 0218def0. No matching claim. */
#include "types.h"
#include "deps/0218def0_FUN_0218def0.h"

void FUN_0218def0(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == (int *)0x0) {
    func_0x0213442c(DAT_0218df54,DAT_0218df58,0,0x71);
  }
  else {
    iVar1 = (*(code *)param_1[3])(param_2,param_1[1]);
    iVar1 = iVar1 * 4;
    iVar2 = FUN_0218d980((int *)(uintptr_t)(*(undefined4 *)(*param_1 + iVar1)),param_2,param_1[4],0,0);
    if (iVar2 == -1) {
      FUN_0218dbc0((undefined4 *)(uintptr_t)(*(undefined4 *)(*param_1 + iVar1)),param_2);
      return;
    }
    FUN_0218da1c(*(undefined4 *)(*param_1 + iVar1),param_2);
  }
  return;
}

