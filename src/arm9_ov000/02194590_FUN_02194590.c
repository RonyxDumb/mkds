/* Decompiled C draft; module arm9_ov000; ROM address 02194590. No matching claim. */
#include "types.h"
#include "deps/02194590_FUN_02194590.h"

int FUN_02194590(int *param_1,int *param_2)

{
  bool bVar1;
  undefined1 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int local_28;
  undefined1 auStack_24 [4];
  int local_20;
  int local_1c [2];
  
  iVar5 = *param_1;
  switch(*param_2) {
  case 0x65:
    break;
  case 0x66:
    iVar5 = FUN_02193d64();
    if (iVar5 != 0) {
      return iVar5;
    }
    break;
  case 0x67:
    iVar4 = FUN_02196714((undefined4)(uintptr_t)(param_1),param_2[2],&local_28);
    if (iVar4 != 0) {
      return iVar4;
    }
    if (local_28 == 4) {
      FUN_02196590(param_1,DAT_021947a4);
      return 3;
    }
    if (local_28 == 3) {
      bVar1 = true;
      iVar4 = FUN_02194934(param_1,param_2[3],local_1c);
      if (iVar4 == 0) {
        FUN_02196590(param_1,DAT_021947a4);
        return 3;
      }
      FUN_02190b80((undefined4)(uintptr_t)(param_1),(undefined4)(uintptr_t)(param_2 + 10),DAT_021947a8);
      FUN_02190b80((undefined4)(uintptr_t)(param_1),(undefined4)(uintptr_t)(param_2 + 10),DAT_021947ac);
      FUN_02190b58(param_1,param_2 + 10,*(undefined4 *)(iVar5 + DAT_021947b0));
      FUN_02190b80((undefined4)(uintptr_t)(param_1),(undefined4)(uintptr_t)(param_2 + 10),DAT_021947b4);
      FUN_02190b80((undefined4)(uintptr_t)(param_1),(undefined4)(uintptr_t)(param_2 + 10),iVar5 + DAT_021947b8);
      FUN_02190b80((undefined4)(uintptr_t)(param_1),(undefined4)(uintptr_t)(param_2 + 10),DAT_021947bc);
      FUN_02190b80((undefined4)(uintptr_t)(param_1),(undefined4)(uintptr_t)(param_2 + 10),*(undefined4 *)(local_1c[0] + 0x18));
      FUN_02190b80((undefined4)(uintptr_t)(param_1),(undefined4)(uintptr_t)(param_2 + 10),DAT_021947c0);
      piVar3 = *(int **)(iVar5 + DAT_021947c4);
      if (piVar3 != (int *)0x0) {
        do {
          if (((piVar3[3] == param_2[3]) && (piVar3 != param_2)) && (*piVar3 < 0x68)) {
            bVar1 = false;
          }
          piVar3 = (int *)piVar3[0xf];
        } while (piVar3 != (int *)0x0);
      }
      if (bVar1) {
        FUN_021a3668(*(undefined4 *)(local_1c[0] + 0x18));
        *(undefined4 *)(local_1c[0] + 0x18) = 0;
        iVar5 = FUN_021947e4(local_1c[0]);
        if (iVar5 != 0) {
          FUN_021948f8(param_1,local_1c[0]);
        }
      }
      *param_2 = 0x68;
    }
    break;
  case 0x68:
    iVar5 = FUN_021907e8((undefined4)(uintptr_t)(param_1),param_2[2],param_2 + 6,auStack_24,&local_20,DAT_021947c8);
    if (iVar5 != 0) {
      return iVar5;
    }
    puVar2 = (undefined1 *)func_0x02139f70(param_2[6],DAT_021947c0);
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 0;
      iVar4 = param_2[6];
      iVar5 = func_0x0213a038(iVar4,DAT_021947cc,7);
      if (iVar5 == 0) {
        param_2[5] = param_2[5] + 1;
        if (1 < param_2[5]) {
          FUN_02196590(param_1,DAT_021947d0);
          return 3;
        }
        iVar5 = FUN_02193e70(param_1,param_2);
        if (iVar5 != 0) {
          return iVar5;
        }
      }
      else {
        iVar5 = func_0x0213a038(iVar4,DAT_021947d4,6);
        if (iVar5 != 0) {
          FUN_02196590(param_1,DAT_021947d8);
          return 3;
        }
      }
      *param_2 = 0x69;
      param_2[8] = 0;
    }
    break;
  default:
    func_0x0213442c(DAT_021947dc,DAT_021947e0,0,0x9f);
  }
  if ((0 < param_2[0xc]) &&
     ((iVar5 = FUN_021906e4(param_1,param_2[2],param_2 + 10,&local_20,1,DAT_021947c8), local_20 != 0
      || (iVar5 != 0)))) {
    *param_2 = 0x6a;
  }
  return 0;
}

