/* Decompiled C draft; module arm9_ov000; ROM address 0218db48. No matching claim. */
#include "types.h"
#include "deps/0218db48_FUN_0218db48.h"

void FUN_0218db48(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((param_3 < 0) || (*param_1 < param_3)) {
    func_0x0213442c(DAT_0218dbb8,DAT_0218dbbc,0,0xa7);
  }
  if (*param_1 == param_1[1]) {
    FUN_0218dd38(param_1);
  }
  *param_1 = *param_1 + 1;
  iVar1 = *param_1;
  if (param_3 < iVar1 + -1) {
    uVar2 = FUN_0218dbf8(param_1,param_3 + 1);
    uVar3 = FUN_0218dbf8(param_1,param_3);
    func_0x02134df8(uVar2,uVar3,((iVar1 + -1) - param_3) * param_1[2]);
  }
  FUN_0218dd18(param_1,param_2,param_3);
  return;
}

