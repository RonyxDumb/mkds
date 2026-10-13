/* Decompiled C draft; module arm9_ov000; ROM address 0218f2e8. No matching claim. */
#include "types.h"
#include "deps/0218f2e8_FUN_0218f2e8.h"

int FUN_0218f2e8(int *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_1c [2];
  
  iVar3 = *param_1;
  iVar4 = 0;
  if (4 < *(uint *)(iVar3 + DAT_0218f3e8)) {
    func_0x0213442c(DAT_0218f3ec,DAT_0218f3f0,0,DAT_0218f3f4);
  }
  if (*(int *)(iVar3 + DAT_0218f3e8) == 1) {
    while( true ) {
      iVar4 = FUN_02191200(param_1);
      if (((iVar4 == 0) && (param_2 != 0)) && (*(int *)(iVar3 + DAT_0218f3e8) == 1)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (!bVar1) break;
      thunk_EXT_FUN_0200dc3c(10);
    }
    if (iVar4 != 0) {
      iVar2 = FUN_021937e8(param_1,local_1c,1);
      if (iVar2 == 0) {
        func_0x0213442c(DAT_0218f3f8,DAT_0218f3f0,0,DAT_0218f3fc);
      }
      else {
        *(undefined4 *)(local_1c[0] + 0x1c) = 4;
      }
    }
  }
  if (*(int *)(iVar3 + DAT_0218f3e8) - 2U < 2) {
    if (iVar4 == 0) {
      iVar4 = FUN_0218f408(param_1);
    }
    if (iVar4 == 0) {
      iVar4 = FUN_02193f50(param_1);
    }
  }
  if (iVar4 == 0) {
    iVar4 = FUN_02194bb8(param_1);
  }
  local_1c[0] = *(int *)(iVar3 + DAT_0218f400);
  while (local_1c[0] != 0) {
    if (*(int *)(local_1c[0] + 0x1c) == 0) {
      local_1c[0] = *(int *)(local_1c[0] + 0x20);
    }
    else {
      FUN_02193954(param_1);
      local_1c[0] = *(int *)(local_1c[0] + 0x20);
      FUN_02193818(param_1);
    }
  }
  iVar2 = FUN_02190cd4(param_1,param_2);
  if ((iVar2 == 0) && (iVar2 = iVar4, *(int *)(iVar3 + DAT_0218f404) != 0)) {
    FUN_02190ff8(param_1,0);
  }
  return iVar2;
}

