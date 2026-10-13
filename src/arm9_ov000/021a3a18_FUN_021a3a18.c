/* Decompiled C draft; module arm9_ov000; ROM address 021a3a18. No matching claim. */
#include "types.h"
#include "deps/021a3a18_FUN_021a3a18.h"

void FUN_021a3a18(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int aiStack_82c [5];
  undefined1 auStack_818 [2052];
  
  *(undefined4 *)((int)aiStack_82c + DAT_021a3b80) = 0;
  FUN_021a4480(auStack_818,3,(undefined1 *)(void *)(param_1 + 0x21));
  iVar3 = 0;
  if (0 < *DAT_021a3b84) {
    puVar2 = DAT_021a3b88;
    do {
      func_0x02135014(aiStack_82c,DAT_021a3b8c,iVar3);
      FUN_021a471c((int)(uintptr_t)(auStack_818),(undefined4)(uintptr_t)(aiStack_82c));
      uVar1 = FUN_021a8c6c(*puVar2,puVar2 + 1);
      FUN_021a471c((int)(uintptr_t)(auStack_818),uVar1);
      puVar2 = puVar2 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < *DAT_021a3b84);
  }
  FUN_021a471c((int)(uintptr_t)(auStack_818),DAT_021a3b90);
  FUN_021a4760((undefined4)(uintptr_t)(auStack_818),param_1[0x30]);
  FUN_021a471c((int)(uintptr_t)(auStack_818),DAT_021a3b94);
  uVar1 = DAT_021a3b9c;
  if (param_1[0x32] != 0) {
    uVar1 = DAT_021a3b98;
  }
  FUN_021a471c((int)(uintptr_t)(auStack_818),uVar1);
  if (param_2 != 0) {
    FUN_021a471c((int)(uintptr_t)(auStack_818),DAT_021a3ba0);
    FUN_021a4760((undefined4)(uintptr_t)(auStack_818),param_2);
  }
  FUN_021a471c((int)(uintptr_t)(auStack_818),DAT_021a3ba4);
  FUN_021a471c((int)(uintptr_t)(auStack_818),(undefined4)(uintptr_t)(param_1 + 1));
  if (param_1[0x2a] != 0) {
    FUN_021a471c((int)(uintptr_t)(auStack_818),DAT_021a3ba8);
    FUN_021a4760((undefined4)(uintptr_t)(auStack_818),*(undefined4 *)((int)param_1 + DAT_021a3bac));
    FUN_021a471c((int)(uintptr_t)(auStack_818),DAT_021a3bb0);
    FUN_021a4760((undefined4)(uintptr_t)(auStack_818),*(undefined2 *)((int)param_1 + DAT_021a3bb4));
  }
  if (param_2 == 2) {
    iVar3 = *(int *)((int)aiStack_82c + DAT_021a3b80);
    if (0 < DAT_021a3bb8 - iVar3) {
      *(int *)((int)aiStack_82c + DAT_021a3b80) = iVar3 + 1;
      auStack_818[iVar3] = 0;
    }
  }
  else {
    FUN_021a41a0(param_1,auStack_818,0xff,0,0xff,0,0xff,0);
  }
  FUN_0218e3e4(*param_1,auStack_818,*(undefined4 *)((int)aiStack_82c + DAT_021a3b80),0,
               param_1 + 0x33,8);
  uVar1 = FUN_0218e8c4();
  param_1[0x2b] = uVar1;
  param_1[0x2c] = param_1[0x2b];
  if (param_2 != 0) {
    param_1[0x2d] = 0;
  }
  return;
}

