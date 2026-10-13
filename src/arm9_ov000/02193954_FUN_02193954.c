/* Decompiled C draft; module arm9_ov000; ROM address 02193954. No matching claim. */
#include "types.h"
#include "deps/02193954_FUN_02193954.h"

int FUN_02193954(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar5 = *param_1;
  if (param_1 == (int *)0x0) {
    func_0x0213442c(DAT_02193b60,DAT_02193b64,0,0x22);
  }
  if (*param_1 == 0) {
    func_0x0213442c(DAT_02193b68,DAT_02193b64,0,0x23);
  }
  if (param_2 == (undefined4 *)0x0) {
    func_0x0213442c(DAT_02193b6c,DAT_02193b64,0,0x24);
  }
  iVar3 = param_2[3];
  uVar1 = param_2[4];
  if (iVar3 != 0) {
    switch(*param_2) {
    case 0:
      puVar2 = (undefined4 *)FUN_021a3690(0x20);
      if (puVar2 == (undefined4 *)0x0) {
        FUN_02196590(param_1,DAT_02193b70);
        return 1;
      }
      func_0x02134de0(puVar2,0,0x20);
      *puVar2 = param_2[7];
      if (*(int *)(iVar5 + DAT_02193b74) == DAT_02193b78) {
        puVar4 = (undefined4 *)(iVar5 + DAT_02193b7c);
        puVar2[1] = *puVar4;
        *puVar4 = 0;
      }
      iVar5 = FUN_02190ed4(param_1,iVar3,uVar1,(undefined4)(uintptr_t)(puVar2),(int)(uintptr_t)(param_2),0);
      if (iVar5 != 0) {
        return iVar5;
      }
      break;
    case 1:
      puVar2 = (undefined4 *)FUN_021a3690(8);
      if (puVar2 == (undefined4 *)0x0) {
        FUN_02196590(param_1,DAT_02193b70);
        return 1;
      }
      *(undefined1 *)puVar2 = 0;
      *(undefined1 *)((int)puVar2 + 1) = 0;
      *(undefined1 *)((int)puVar2 + 2) = 0;
      *(undefined1 *)((int)puVar2 + 3) = 0;
      *(undefined1 *)(puVar2 + 1) = 0;
      *(undefined1 *)((int)puVar2 + 5) = 0;
      *(undefined1 *)((int)puVar2 + 6) = 0;
      *(undefined1 *)((int)puVar2 + 7) = 0;
      *puVar2 = param_2[7];
      iVar5 = FUN_02190ed4(param_1,iVar3,uVar1,(undefined4)(uintptr_t)(puVar2),(int)(uintptr_t)(param_2),0);
      if (iVar5 != 0) {
        return iVar5;
      }
      break;
    case 2:
      puVar2 = (undefined4 *)FUN_021a3690(DAT_02193b80);
      if (puVar2 == (undefined4 *)0x0) {
        FUN_02196590(param_1,DAT_02193b70);
        return 1;
      }
      func_0x02134de0(puVar2,0,DAT_02193b80);
      *puVar2 = param_2[7];
      iVar5 = FUN_02190ed4(param_1,iVar3,uVar1,(undefined4)(uintptr_t)(puVar2),(int)(uintptr_t)(param_2),0);
      if (iVar5 != 0) {
        return iVar5;
      }
      break;
    case 3:
      puVar2 = (undefined4 *)FUN_021a3690(0x10);
      if (puVar2 == (undefined4 *)0x0) {
        FUN_02196590(param_1,DAT_02193b70);
        return 1;
      }
      iVar5 = 0x10;
      puVar4 = puVar2;
      do {
        *(undefined1 *)puVar4 = 0;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      *puVar2 = param_2[7];
      puVar2[3] = 0;
      iVar5 = FUN_02190ed4(param_1,iVar3,uVar1,(undefined4)(uintptr_t)(puVar2),(int)(uintptr_t)(param_2),0);
      if (iVar5 != 0) {
        return iVar5;
      }
      break;
    case 4:
      puVar2 = (undefined4 *)FUN_021a3690(4);
      if (puVar2 == (undefined4 *)0x0) {
        FUN_02196590(param_1,DAT_02193b70);
        return 1;
      }
      *(undefined1 *)puVar2 = 0;
      *(undefined1 *)((int)puVar2 + 1) = 0;
      *(undefined1 *)((int)puVar2 + 2) = 0;
      *(undefined1 *)((int)puVar2 + 3) = 0;
      *puVar2 = param_2[7];
      iVar5 = FUN_02190ed4(param_1,iVar3,uVar1,(undefined4)(uintptr_t)(puVar2),(int)(uintptr_t)(param_2),0);
      if (iVar5 != 0) {
        return iVar5;
      }
      break;
    default:
      func_0x0213442c(DAT_02193b84,DAT_02193b64,0,0x6b);
    }
  }
  return 0;
}

