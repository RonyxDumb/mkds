/* Decompiled C draft; module arm9_ov000; ROM address 02190da0. No matching claim. */
#include "types.h"
#include "deps/02190da0_FUN_02190da0.h"

void FUN_02190da0(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*param_2 == 0) {
    func_0x0213442c(DAT_02190ec8,DAT_02190ecc,0,0x6e);
  }
  if (param_2[2] == 0) {
    func_0x0213442c(DAT_02190ed0,DAT_02190ecc,0,0x6f);
  }
  (*(code *)*param_2)(param_1,param_2[2],param_2[1]);
  iVar1 = param_2[3];
  if (iVar1 == 2) {
    FUN_021a3668(*(undefined4 *)(param_2[2] + 8));
    *(undefined4 *)(param_2[2] + 8) = 0;
  }
  else if (iVar1 == 3) {
    iVar1 = param_2[2];
    iVar3 = 0;
    if (0 < *(int *)(iVar1 + 0x38)) {
      iVar2 = 0;
      do {
        FUN_021a3668(*(undefined4 *)(*(int *)(iVar1 + 0x3c) + iVar2));
        *(undefined4 *)(*(int *)(iVar1 + 0x3c) + iVar2) = 0;
        FUN_021a3668(*(undefined4 *)(*(int *)(iVar1 + 0x40) + iVar2));
        *(undefined4 *)(*(int *)(iVar1 + 0x40) + iVar2) = 0;
        iVar2 = iVar2 + 4;
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(iVar1 + 0x38));
    }
    FUN_021a3668(*(undefined4 *)(iVar1 + 0x3c));
    *(undefined4 *)(iVar1 + 0x3c) = 0;
    FUN_021a3668(*(undefined4 *)(iVar1 + 0x40));
    *(undefined4 *)(iVar1 + 0x40) = 0;
  }
  else if (iVar1 == 4) {
    iVar1 = param_2[2];
    FUN_021a3668(*(undefined4 *)(iVar1 + 0xc));
    *(undefined4 *)(iVar1 + 0xc) = 0;
  }
  else if (iVar1 == 7) {
    iVar1 = param_2[2];
    if (*(int *)(iVar1 + 0x10) != 0) {
      FUN_021a3668();
      *(undefined4 *)(iVar1 + 0x10) = 0;
    }
  }
  else if (iVar1 == 8) {
    iVar1 = param_2[2];
    if (*(int *)(iVar1 + 8) != 0) {
      FUN_021a3668();
      *(undefined4 *)(iVar1 + 8) = 0;
    }
  }
  else if (iVar1 == 9) {
    iVar1 = param_2[2];
    iVar3 = 0;
    if (0 < *(int *)(iVar1 + 4)) {
      iVar2 = 0;
      do {
        FUN_021a3668(*(undefined4 *)(*(int *)(iVar1 + 8) + iVar2));
        *(undefined4 *)(*(int *)(iVar1 + 8) + iVar2) = 0;
        iVar2 = iVar2 + 4;
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(iVar1 + 4));
    }
    FUN_021a3668(*(undefined4 *)(iVar1 + 8));
    *(undefined4 *)(iVar1 + 8) = 0;
  }
  FUN_021a3668(param_2[2]);
  param_2[2] = 0;
  FUN_021a3668(param_2);
  return;
}

