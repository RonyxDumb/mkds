/* Decompiled C draft; module arm9_ov000; ROM address 02193d64. No matching claim. */
#include "types.h"
#include "deps/02193d64_FUN_02193d64.h"

undefined4 FUN_02193d64(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 local_18;
  undefined2 uStack_16;
  undefined4 local_14;
  int local_10;
  
  iVar1 = FUN_02194934(param_1,param_2[3],&local_10);
  if (iVar1 == 0) {
    FUN_02196590(param_1,DAT_02193e60);
    return 3;
  }
  uVar2 = FUN_0218e554(2,1,0);
  param_2[2] = uVar2;
  if (param_2[2] == -1) {
    FUN_021965a0(param_1,5,DAT_02193e64);
    FUN_02190f4c(param_1,3,0);
    return 3;
  }
  iVar1 = FUN_0218e80c();
  if (iVar1 == 0) {
    FUN_021965a0(param_1,5,DAT_02193e68);
    FUN_02190f4c(param_1,3,0);
    return 3;
  }
  FUN_02193ff4(param_2[2]);
  local_14 = *(undefined4 *)(*(int *)(local_10 + 8) + 0x10);
  _local_18 = CONCAT22((short)*(undefined4 *)(*(int *)(local_10 + 8) + 0x14),0x200);
  iVar1 = FUN_0218e4b4(param_2[2],&local_18,8);
  if ((((iVar1 == -1) && (iVar1 = FUN_0218e368(param_2[2]), iVar1 != -6)) && (iVar1 != -0x1a)) &&
     (iVar1 != -0x4c)) {
    FUN_021965a0(param_1,5,DAT_02193e6c);
    FUN_02190f4c(param_1,3,1);
    return 3;
  }
  *param_2 = 0x67;
  return 0;
}

