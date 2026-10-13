/* Decompiled C draft; module arm9_ov000; ROM address 0219ab24. No matching claim. */
#include "types.h"
#include "deps/0219ab24_FUN_0219ab24.h"

void FUN_0219ab24(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_28 [8];
  undefined4 local_20;
  undefined1 uStack_1c;
  undefined1 local_1b;
  ushort local_1a;
  int local_18;
  
  uVar1 = DAT_0219ac44;
  local_20 = 8;
  if (param_1[4] == 4) {
    FUN_0219b130();
    return;
  }
  if (*param_1 != -1) {
    while (iVar2 = FUN_0218e668(), iVar2 != 0) {
      iVar2 = FUN_0218e438(*param_1,uVar1,DAT_0219ac48,0,auStack_28,&local_20);
      if ((iVar2 == -1) || (FUN_0219a7e4(uVar1,iVar2,auStack_28), param_1[4] == 4)) break;
      if (*param_1 == -1) break;
    }
  }
  if ((param_1[4] == 0) || (param_1[4] == 2)) {
    uVar3 = FUN_0218e8c4();
    if ((uint)param_1[10] < uVar3) {
      if (param_1[9] < param_1[8]) {
        (*(code *)param_1[0xe])(2,0xffffffff,0,param_1[0xf]);
        FUN_0219ac50(param_1[2]);
      }
      else {
        param_1[8] = param_1[8] + 1;
        if (param_1[4] == 0) {
          FUN_0219aeb0(param_1);
        }
        else {
          FUN_0219ade4(param_1);
        }
      }
    }
  }
  if (param_1[4] == 3) {
    uVar3 = FUN_0218e8c4();
    if ((uint)param_1[10] < uVar3) {
      if (param_1[1] == -1) {
        local_1b = 2;
        local_1a = *(ushort *)(param_1 + 0xc) >> 8 |
                   *(ushort *)(param_1 + 0xc) << 8 & (ushort)DAT_0219ac4c;
        local_18 = param_1[0xb];
        (*(code *)param_1[0xe])(0,*param_1,&uStack_1c,param_1[0xf]);
        *param_1 = -1;
      }
      FUN_0219ac50(param_1[2]);
    }
  }
  if ((param_1[4] == 1) && (uVar3 = FUN_0218e8c4(), (uint)param_1[10] < uVar3)) {
    (*(code *)param_1[0xe])(1,0xffffffff,0,param_1[0xf]);
    FUN_0219ac50(param_1[2]);
  }
  return;
}

