/* Decompiled C draft; module arm9_ov000; ROM address 021a3c14. No matching claim. */
#include "types.h"
#include "deps/021a3c14_FUN_021a3c14.h"

void FUN_021a3c14(undefined4 *param_1,char *param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  int local_82c [4];
  char local_81c [2056];
  
  local_82c[1] = param_4;
  *(undefined4 *)((int)local_82c + DAT_021a3e50) = 0;
  if (param_1 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)*DAT_021a3e54;
  }
  cVar1 = *param_2;
  if (cVar1 == ';') {
    if ((code *)param_1[0x35] == (code *)0x0) {
      return;
    }
    (*(code *)param_1[0x35])(param_2,param_3,local_82c[1]);
    return;
  }
  if (cVar1 == '\\') {
    FUN_021a3f78((undefined4)(uintptr_t)(param_1),local_81c);
    local_82c[0] = 8;
    FUN_0218e3e4(*param_1,local_81c,*(undefined4 *)((int)local_82c + DAT_021a3e50),0,local_82c[1]);
    return;
  }
  if (param_3 < 7) {
    return;
  }
  if (cVar1 != -2) {
    return;
  }
  if (param_2[1] != -3) {
    return;
  }
  if (0 < (int)param_1[0x2e]) {
    param_1[0x2e] = 0;
  }
  local_82c[2] = (int)param_2[2];
  pcVar2 = param_2 + 3;
  pcVar3 = param_2 + 7;
  iVar4 = param_3 + -7;
  FUN_021a4480(local_81c,local_82c[2],pcVar2);
  switch(local_82c[2]) {
  case 0:
    FUN_021a412c((undefined4)(uintptr_t)(param_1),(undefined4)(uintptr_t)(local_81c),pcVar3,iVar4);
    break;
  case 1:
    if ((0xc < iVar4) && (param_1[0x2a] != 0)) {
      FUN_021a438c((int)(uintptr_t)(param_1),(undefined4)(uintptr_t)(pcVar3 + param_3 + -0x14));
    }
    FUN_021a4418((int)(uintptr_t)(param_1),(int)(uintptr_t)(local_81c),(int)(uintptr_t)(pcVar3),iVar4);
    break;
  case 2:
    if (0x20 < iVar4) {
      iVar4 = 0x20;
    }
    local_81c[0] = '\x05';
    func_0x02134eb8((uint *)(void *)(local_81c + *(int *)((int)local_82c + DAT_021a3e50)),(uint)(uintptr_t)(pcVar3),iVar4);
    *(int *)((int)local_82c + DAT_021a3e50) = *(int *)((int)local_82c + DAT_021a3e50) + iVar4;
    break;
  case 3:
  case 5:
  case 7:
  case 8:
    return;
  case 4:
    if (param_1[0x2e] == -1) {
      return;
    }
    local_82c[3] = 0;
    do {
      if (pcVar2[local_82c[3]] != *(char *)((int)param_1 + local_82c[3] + 0x84)) {
        return;
      }
      local_82c[3] = local_82c[3] + 1;
    } while (local_82c[3] < 4);
    if (iVar4 < 2) {
      return;
    }
    param_1[0x2e] = 0xffffffff;
    (*(code *)param_1[0x27])((int)*pcVar3,param_2 + 8,*(undefined4 *)((int)param_1 + DAT_021a3e58));
    return;
  case 6:
    local_82c[3] = 0;
    do {
      if (pcVar2[local_82c[3]] != *(char *)((int)param_1 + local_82c[3] + 0x84)) {
        return;
      }
      local_82c[3] = local_82c[3] + 1;
    } while (local_82c[3] < 4);
    if (iVar4 < 4) {
      return;
    }
    local_81c[0] = '\a';
    iVar4 = *(int *)((int)local_82c + DAT_021a3e50);
    local_81c[iVar4] = *pcVar3;
    local_81c[iVar4 + 1] = param_2[8];
    local_81c[iVar4 + 2] = param_2[9];
    local_81c[iVar4 + 3] = param_2[10];
    *(int *)((int)local_82c + DAT_021a3e50) = *(int *)((int)local_82c + DAT_021a3e50) + 4;
    local_82c[3] = *(int *)pcVar3;
    iVar4 = FUN_021a3e5c((int)(uintptr_t)(param_1),local_82c[3]);
    if (iVar4 == 0) {
      FUN_021a3eb0((int)(uintptr_t)(param_1),(int)(uintptr_t)(param_2 + 0xb),param_3 + -0xb);
    }
    break;
  default:
    goto switchD_021a3ce4_default;
  }
  local_82c[0] = 8;
  FUN_0218e3e4(*param_1,local_81c,*(undefined4 *)((int)local_82c + DAT_021a3e50),0,local_82c[1]);
switchD_021a3ce4_default:
  return;
}

