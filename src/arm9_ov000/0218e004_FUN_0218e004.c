/* Decompiled C draft; module arm9_ov000; ROM address 0218e004. No matching claim. */
#include "types.h"
#include "deps/0218e004_FUN_0218e004.h"

int * FUN_0218e004(int param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_4 == 0) {
    func_0x0213442c(DAT_0218e0c4,DAT_0218e0c8,0,0x38);
  }
  if (param_5 == 0) {
    func_0x0213442c(DAT_0218e0cc,DAT_0218e0c8,0,0x39);
  }
  if (param_1 == 0) {
    func_0x0213442c(DAT_0218e0d0,DAT_0218e0c8,0,0x3a);
  }
  if (param_2 == 0) {
    func_0x0213442c(DAT_0218e0d4,DAT_0218e0c8,0,0x3b);
  }
  piVar1 = (int *)FUN_021a3690(0x14);
  if (piVar1 == (int *)0x0) {
    func_0x0213442c(DAT_0218e0d8,DAT_0218e0c8,0,0x3e);
  }
  iVar2 = FUN_021a3690(param_2 << 2);
  *piVar1 = iVar2;
  if (*piVar1 == 0) {
    func_0x0213442c(DAT_0218e0dc,DAT_0218e0c8,0,0x41);
  }
  iVar2 = 0;
  if (0 < param_2) {
    iVar4 = 0;
    do {
      uVar3 = FUN_0218dc94(param_1,param_3,param_6);
      *(undefined4 *)(*piVar1 + iVar4) = uVar3;
      iVar4 = iVar4 + 4;
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_2);
  }
  piVar1[1] = param_2;
  piVar1[2] = param_6;
  piVar1[4] = param_5;
  piVar1[3] = param_4;
  return piVar1;
}

