/* Decompiled C draft; module arm9_ov000; ROM address 02191e58. No matching claim. */
#include "types.h"
#include "deps/02191e58_FUN_02191e58.h"

undefined4 FUN_02191e58(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18 [2];
  
  iVar3 = *param_1;
  if (*(int *)(iVar3 + DAT_02192098) == 0) {
    iVar1 = FUN_0218e554(2,1,0);
    piVar2 = (int *)(iVar3 + DAT_0219209c);
    *piVar2 = iVar1;
    if (*piVar2 == -1) {
      FUN_021965a0(param_1,5,DAT_021920a0);
      FUN_02190f4c(param_1,3,1);
      return 3;
    }
    iVar1 = FUN_0218e80c();
    if (iVar1 == 0) {
      FUN_021965a0(param_1,5,DAT_021920a4);
      FUN_02190f4c(param_1,3,1);
      return 3;
    }
    local_1c = 0;
    local_20 = 0x200;
    iVar1 = FUN_0218e4e4(*(undefined4 *)(iVar3 + DAT_0219209c),(undefined1 *)(void *)(&local_20),8);
    if (iVar1 == -1) {
      FUN_021965a0(param_1,5,DAT_021920a8);
      FUN_02190f4c(param_1,3,1);
      return 3;
    }
    iVar1 = FUN_0218e49c(*(undefined4 *)(iVar3 + DAT_0219209c),5);
    if (iVar1 == -1) {
      FUN_021965a0(param_1,5,DAT_021920ac);
      FUN_02190f4c(param_1,3,1);
      return 3;
    }
    local_18[0] = 8;
    iVar1 = FUN_0218e394(*(undefined4 *)(iVar3 + DAT_0219209c),(byte *)(void *)(&local_20),local_18);
    if (iVar1 == -1) {
      FUN_021965a0(param_1,5,DAT_021920b0);
      FUN_02190f4c(param_1,3,1);
      return 3;
    }
    *(uint *)(iVar3 + DAT_021920b4) = local_20 >> 0x10;
  }
  else {
    *(undefined4 *)(iVar3 + DAT_0219209c) = 0xffffffff;
    *(undefined4 *)(iVar3 + DAT_021920b4) = 0;
  }
  iVar1 = FUN_0218e554(2,1,0);
  piVar2 = (int *)(iVar3 + DAT_021920b8);
  *piVar2 = iVar1;
  if (*piVar2 == -1) {
    FUN_021965a0(param_1,5,DAT_021920a0);
    FUN_02190f4c(param_1,3,1);
    return 3;
  }
  iVar1 = FUN_0218e80c();
  if (iVar1 == 0) {
    FUN_021965a0(param_1,5,DAT_021920a4);
    FUN_02190f4c(param_1,3,1);
    return 3;
  }
  iVar1 = FUN_021a8f84(DAT_021920bc);
  if (iVar1 == 0) {
    FUN_021965a0(param_1,5,DAT_021920c0);
    FUN_02190f4c(param_1,3,1);
    return 3;
  }
  local_20 = 0x200;
  local_1c = *(int *)**(undefined4 **)(iVar1 + 0xc);
  if (local_1c == 0) {
    func_0x0213442c(DAT_021920c4,DAT_021920c8,0,0x90);
  }
  local_20 = CONCAT22((short)DAT_021920cc,(undefined2)local_20);
  iVar1 = FUN_0218e4b4(*(undefined4 *)(iVar3 + DAT_021920b8),(undefined1 *)(void *)(&local_20),8);
  if ((((iVar1 == -1) && (iVar1 = FUN_0218e368(*(undefined4 *)(iVar3 + DAT_021920b8)), iVar1 != -6))
      && (iVar1 != -0x1a)) && (iVar1 != -0x4c)) {
    FUN_021965a0(param_1,5,DAT_021920d0);
    FUN_02190f4c(param_1,3,1);
    return 3;
  }
  *(undefined4 *)(param_2 + 0x14) = 1;
  *(undefined4 *)(iVar3 + DAT_021920d4) = 1;
  return 0;
}

