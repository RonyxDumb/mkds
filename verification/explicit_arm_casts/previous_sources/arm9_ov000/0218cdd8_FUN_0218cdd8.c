/* Decompiled C draft; module arm9_ov000; ROM address 0218cdd8. No matching claim. */
#include "types.h"
#include "deps/0218cdd8_FUN_0218cdd8.h"

void FUN_0218cdd8(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  
  if (param_2 == 0) {
    param_2 = DAT_0218ce10;
  }
  iVar1 = func_0x0213a434(param_2);
  iVar1 = iVar1 + 1;
  func_0x02134eb8(*param_1,param_2,iVar1);
  *param_3 = *param_3 + iVar1;
  *param_1 = *param_1 + iVar1;
  return;
}

