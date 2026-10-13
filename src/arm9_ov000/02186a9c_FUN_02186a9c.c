/* Decompiled C draft; module arm9_ov000; ROM address 02186a9c. No matching claim. */
#include "types.h"
#include "deps/02186a9c_FUN_02186a9c.h"

undefined4 FUN_02186a9c(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_1 + DAT_02186b04;
  iVar1 = func_0x0213a434(param_2);
  iVar2 = *(int *)(iVar4 + 4);
  iVar3 = *(int *)(iVar4 + 8) - iVar2;
  if (iVar3 < iVar1) {
    iVar2 = FUN_02186998(param_1,(int *)(uintptr_t)(iVar4),(iVar1 - iVar3) + 1);
    if (iVar2 == 0) {
      return 1;
    }
    iVar2 = *(int *)(iVar4 + 4);
    iVar3 = *(int *)(iVar4 + 8) - iVar2;
  }
  iVar2 = func_0x0200d9e0(iVar2,iVar3,DAT_02186b08,param_2);
  if (iVar2 != iVar1) {
    return 1;
  }
  *(int *)(iVar4 + 4) = *(int *)(iVar4 + 4) + iVar2;
  return 0;
}

