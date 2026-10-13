/* Decompiled C draft; module arm9_ov000; ROM address 021a09d0. No matching claim. */
#include "types.h"
#include "deps/021a09d0_FUN_021a09d0.h"

void FUN_021a09d0(undefined4 param_1,undefined1 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_214 [512];
  
  iVar1 = func_0x0200d9e0(auStack_214,DAT_021a0a34,DAT_021a0a38,DAT_021a0a3c,3,DAT_021a0a30);
  auStack_214[iVar1] = param_2;
  auStack_214[iVar1 + 1] = 0;
  if (param_4 != 0) {
    iVar2 = func_0x0213a434(param_4);
    func_0x0214d1fc(param_4,auStack_214 + iVar1 + 1,iVar2);
    (auStack_214 + iVar1 + 1)[iVar2] = 0;
  }
  FUN_0218e908(param_1,param_3,auStack_214);
  return;
}

