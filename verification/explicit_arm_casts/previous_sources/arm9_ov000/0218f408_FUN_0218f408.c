/* Decompiled C draft; module arm9_ov000; ROM address 0218f408. No matching claim. */
#include "types.h"
#include "deps/0218f408_FUN_0218f408.h"

int FUN_0218f408(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_20;
  int local_1c;
  int local_18;
  
  iVar1 = DAT_0218f608;
  local_18 = 0;
  iVar4 = *param_1;
  while( true ) {
    FUN_02192d64(param_1,iVar4 + DAT_0218f60c);
    iVar2 = FUN_021906e4(param_1,*(undefined4 *)(iVar4 + DAT_0218f614),iVar4 + DAT_0218f60c,
                         &local_18,1,DAT_0218f610);
    if (iVar2 != 0) {
      return iVar2;
    }
    iVar2 = FUN_021907e8(param_1,*(undefined4 *)(iVar4 + DAT_0218f614),iVar4 + iVar1,&local_1c,
                         &local_18,DAT_0218f610);
    if (iVar2 != 0) {
      if (iVar2 != 3) {
        return iVar2;
      }
      FUN_021965a0(param_1,5,DAT_0218f618);
      FUN_02190f4c(param_1,3,1);
      return 3;
    }
    puVar3 = (undefined1 *)func_0x02139f70(*(undefined4 *)(iVar4 + iVar1),DAT_0218f61c);
    while (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 0;
      FUN_0219690c(param_1,DAT_0218f620,*(undefined4 *)(iVar4 + iVar1));
      local_1c = (int)puVar3 - *(int *)(iVar4 + iVar1);
      if (*(int *)(iVar4 + DAT_0218f624) < local_1c) {
        iVar2 = local_1c;
        if (local_1c < DAT_0218f628) {
          iVar2 = DAT_0218f628;
        }
        *(int *)(iVar4 + DAT_0218f624) = *(int *)(iVar4 + DAT_0218f624) + iVar2;
        iVar2 = FUN_021a3678(*(undefined4 *)(iVar4 + DAT_0218f62c),
                             *(int *)(iVar4 + DAT_0218f624) + 1);
        if (iVar2 == 0) {
          FUN_02196590(param_1,DAT_0218f630);
          return 1;
        }
        *(int *)(iVar4 + DAT_0218f62c) = iVar2;
      }
      func_0x02134eb8(*(undefined4 *)(iVar4 + DAT_0218f62c),*(undefined4 *)(iVar4 + iVar1),
                      local_1c + 1);
      *(int *)(iVar4 + DAT_0218f634) =
           *(int *)(iVar4 + DAT_0218f634) - ((int)(puVar3 + 7) - *(int *)(iVar4 + iVar1));
      func_0x02134df8(*(undefined4 *)(iVar4 + iVar1),puVar3 + 7,*(int *)(iVar4 + DAT_0218f634) + 1);
      uVar5 = *(undefined4 *)(iVar4 + DAT_0218f62c);
      iVar2 = func_0x02139f70(uVar5,DAT_0218f638);
      if (iVar2 == 0) {
        iVar2 = FUN_02196870(param_1,uVar5,1);
        if (iVar2 != 0) {
          return 4;
        }
        uVar5 = *(undefined4 *)(iVar4 + DAT_0218f62c);
        iVar2 = func_0x0213a038(uVar5,DAT_0218f640,4);
        if (iVar2 == 0) {
          iVar2 = FUN_0218fca8(param_1,uVar5);
          if (iVar2 != 0) {
            return iVar2;
          }
        }
        else {
          iVar2 = func_0x0213a038(uVar5,DAT_0218f644,10);
          if (iVar2 != 0) {
            FUN_0219690c(param_1,DAT_0218f648);
          }
        }
      }
      else {
        uVar5 = func_0x0213bf90(iVar2 + 4);
        iVar2 = FUN_021937e8(param_1,&local_20,uVar5);
        if (iVar2 == 0) {
          FUN_0219690c(param_1,DAT_0218f63c,uVar5);
        }
        else {
          iVar2 = FUN_02193748(param_1,local_20,*(undefined4 *)(iVar4 + DAT_0218f62c));
          if (iVar2 != 0) {
            return iVar2;
          }
        }
      }
      puVar3 = (undefined1 *)func_0x02139f70(*(undefined4 *)(iVar4 + iVar1),DAT_0218f61c);
    }
    if (local_18 != 0) {
      *(undefined4 *)(iVar4 + DAT_0218f64c) = 4;
      FUN_021965a0(param_1,7,DAT_0218f650);
      FUN_02190f4c(param_1,3,1);
      return 0;
    }
    iVar2 = FUN_021937c0(param_1);
    if (iVar2 == 0) break;
    thunk_EXT_FUN_0200dc3c(10);
  }
  return 0;
}

