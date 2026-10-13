/* Decompiled C draft; module arm9_ov000; ROM address 021aa7f8. No matching claim. */
#include "types.h"
#include "deps/021aa7f8_FUN_021aa7f8.h"

void FUN_021aa7f8(undefined4 param_1,undefined4 param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_28 [20];
  
  iVar2 = (int)param_3 + DAT_021aa878;
  FUN_021abd2c((undefined4 *)(uintptr_t)(iVar2));
  uVar1 = func_0x0213a434(param_2);
  FUN_021abca0(iVar2,param_2,uVar1);
  FUN_021abca0(iVar2,*param_3 + 0x20,0x30);
  FUN_021abca0(iVar2,(int)(uintptr_t)(param_3 + 2),0x20);
  FUN_021abca0(iVar2,(int)(uintptr_t)(param_3 + 10),0x20);
  FUN_021abc4c(iVar2,(undefined4)(uintptr_t)(auStack_28));
  iVar2 = (int)param_3 + DAT_021aa87c;
  FUN_021ab7b4((undefined4 *)(uintptr_t)(iVar2));
  FUN_021ab728(iVar2,*param_3 + 0x20,0x30);
  FUN_021ab728(iVar2,(int)(uintptr_t)(auStack_28),0x14);
  FUN_021ab6d4(iVar2,param_1);
  return;
}

