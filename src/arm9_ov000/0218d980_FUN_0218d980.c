/* Decompiled C draft; module arm9_ov000; ROM address 0218d980. No matching claim. */
#include "types.h"
#include "deps/0218d980_FUN_0218d980.h"

undefined4 FUN_0218d980(int *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  int local_1c [2];
  
  local_1c[0] = 1;
  if ((param_1 == (int *)0x0) || (iVar2 = *param_1, iVar2 == 0)) {
    return 0xffffffff;
  }
  if (param_5 == 0) {
    uVar1 = FUN_0218dbf8(param_1,param_4);
    iVar2 = FUN_0218d86c(param_2,uVar1,iVar2 - param_4,param_1[2],param_3);
  }
  else {
    uVar1 = FUN_0218dbf8(param_1,param_4);
    iVar2 = FUN_0218d818(param_2,uVar1,iVar2 - param_4,param_1[2],param_3,local_1c);
  }
  if ((iVar2 != 0) && (local_1c[0] != 0)) {
    uVar1 = func_0x02133068(iVar2 - param_1[5],param_1[2]);
    return uVar1;
  }
  return 0xffffffff;
}

