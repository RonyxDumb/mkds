/* Decompiled C draft; module arm9_ov000; ROM address 0218daf8. No matching claim. */
#include "types.h"
#include "deps/0218daf8_FUN_0218daf8.h"

void FUN_0218daf8(undefined4 *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_18 [8];
  
  if (param_3 == 0) {
    func_0x0213442c(DAT_0218db40,DAT_0218db44,0,0xb7);
  }
  iVar1 = FUN_0218d818(param_2,param_1[5],*param_1,param_1[2],param_3,auStack_18);
  uVar2 = func_0x02133068(iVar1 - param_1[5],param_1[2]);
  FUN_0218db48(param_1,param_2,uVar2);
  return;
}

