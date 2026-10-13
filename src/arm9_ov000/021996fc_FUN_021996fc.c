/* Decompiled C draft; module arm9_ov000; ROM address 021996fc. No matching claim. */
#include "types.h"
#include "deps/021996fc_FUN_021996fc.h"

undefined4 FUN_021996fc(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int local_1c [2];
  
  if (param_4 < 7) {
    iVar1 = FUN_02199fa4();
    if (iVar1 != 0) {
      return 1;
    }
    return 0;
  }
  uVar2 = FUN_0219a028(param_3,3);
  uVar3 = FUN_0219a028(param_3,5);
  iVar1 = FUN_02199ec8(param_1,uVar3);
  if (iVar1 == 0) {
    return 0;
  }
  if (uVar2 == *(ushort *)(param_1 + 0x66)) {
    FUN_021997f8(param_1);
    iVar1 = FUN_02199a0c(param_1,param_2,param_3 + 7,param_4 + -7);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = FUN_0219981c(param_1);
    if (iVar1 != 0) {
      return 1;
    }
    return 0;
  }
  iVar1 = FUN_0219a014(uVar2);
  if (iVar1 < 0) {
    FUN_021997f8(param_1);
    return 1;
  }
  iVar1 = FUN_021998d8(param_1,param_2,uVar2,param_3 + 7,param_4 + -7,local_1c);
  if (iVar1 == 0) {
    return 0;
  }
  if ((local_1c[0] != 0) && (iVar1 = FUN_02199f80(param_1), iVar1 == 0)) {
    return 0;
  }
  return 1;
}

