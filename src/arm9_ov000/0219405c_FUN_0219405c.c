/* Decompiled C draft; module arm9_ov000; ROM address 0219405c. No matching claim. */
#include "types.h"
#include "deps/0219405c_FUN_0219405c.h"

void FUN_0219405c(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *param_1;
  if (param_2 == 0) {
    func_0x0213442c(DAT_02194104,DAT_02194108,0,DAT_0219410c);
  }
  iVar2 = *(int *)(iVar3 + DAT_02194110);
  if (iVar2 == param_2) {
    *(int *)(iVar3 + DAT_02194110) = *(int *)(param_2 + 0x3c);
  }
  else {
    for (iVar3 = *(int *)(iVar2 + 0x3c); iVar3 != param_2; iVar3 = *(int *)(iVar3 + 0x3c)) {
      if (iVar3 == 0) {
        func_0x0213442c(DAT_02194114,DAT_02194108,0,DAT_02194118);
        FUN_0219690c(param_1,DAT_0219411c);
        return;
      }
      iVar2 = iVar3;
    }
    *(undefined4 *)(iVar2 + 0x3c) = *(undefined4 *)(param_2 + 0x3c);
  }
  iVar3 = FUN_0218dc44((undefined4 *)(uintptr_t)(*(undefined4 *)(param_2 + 0x38)));
  while (iVar3 != 0) {
    piVar1 = (int *)FUN_0218dbf8((int *)(uintptr_t)(*(undefined4 *)(param_2 + 0x38)),0);
    if (piVar1[4] < 100) {
      FUN_0218fbe0(param_1,*(undefined4 *)(param_2 + 0xc),piVar1[4],*piVar1 + piVar1[5]);
    }
    FUN_0218da5c((int *)(uintptr_t)(*(undefined4 *)(param_2 + 0x38)),0);
    iVar3 = FUN_0218dc44((undefined4 *)(uintptr_t)(*(undefined4 *)(param_2 + 0x38)));
  }
  FUN_02194120((undefined4)(uintptr_t)(param_1),param_2);
  return;
}

