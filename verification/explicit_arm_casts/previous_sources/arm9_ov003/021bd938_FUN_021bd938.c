/* Decompiled C draft; module arm9_ov003; ROM address 021bd938. No matching claim. */
#include "types.h"
#include "deps/021bd938_FUN_021bd938.h"

int FUN_021bd938(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int local_1c;
  int local_18 [2];
  
  iVar1 = FUN_021bdc5c(param_1,&local_1c,local_18);
  if (iVar1 == 0) {
    return 0;
  }
  if (local_1c != param_2) {
    return 0;
  }
  if (param_4 == 0) {
    func_0x02134eb8(param_3,iVar1,local_18[0]);
  }
  else {
    FUN_021bcadc(param_3,iVar1,local_18[0],param_4,0x10);
    local_18[0] = local_18[0] + -8;
  }
  return local_18[0];
}

