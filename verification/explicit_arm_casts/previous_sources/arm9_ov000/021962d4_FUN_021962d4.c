/* Decompiled C draft; module arm9_ov000; ROM address 021962d4. No matching claim. */
#include "types.h"
#include "deps/021962d4_FUN_021962d4.h"

undefined4 FUN_021962d4(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_18;
  int local_14;
  
  iVar3 = *(int *)(param_2 + 4);
  *(undefined4 *)(iVar3 + 0xc) = DAT_0219640c;
  uVar1 = FUN_021a3690(*(int *)(iVar3 + 0xc) + 1);
  *(undefined4 *)(iVar3 + 8) = uVar1;
  if (*(int *)(iVar3 + 8) == 0) {
    FUN_02196590(param_1,DAT_02196410);
    return 1;
  }
  uVar1 = FUN_0218e554(2,1,0);
  *(undefined4 *)(iVar3 + 4) = uVar1;
  if (*(int *)(iVar3 + 4) == -1) {
    FUN_021965a0(param_1,5,DAT_02196414);
    FUN_02190f4c(param_1,3,1);
    return 3;
  }
  iVar2 = FUN_0218e80c();
  if (iVar2 == 0) {
    FUN_021965a0(param_1,5,DAT_02196418);
    FUN_02190f4c(param_1,3,1);
    return 3;
  }
  iVar2 = FUN_021a8f84(DAT_0219641c);
  if (iVar2 == 0) {
    FUN_021965a0(param_1,5,DAT_02196420);
    FUN_02190f4c(param_1,3,1);
    return 3;
  }
  local_18 = 0x200;
  local_14 = *(int *)**(undefined4 **)(iVar2 + 0xc);
  if (local_14 == 0) {
    func_0x0213442c(DAT_02196424,DAT_02196428,0,0x59);
  }
  local_18 = CONCAT22((short)DAT_0219642c,(undefined2)local_18);
  iVar2 = FUN_0218e4b4(*(undefined4 *)(iVar3 + 4),&local_18,8);
  if ((((iVar2 == -1) && (iVar3 = FUN_0218e368(*(undefined4 *)(iVar3 + 4)), iVar3 != -6)) &&
      (iVar3 != -0x1a)) && (iVar3 != -0x4c)) {
    FUN_021965a0(param_1,5,DAT_02196430);
    FUN_02190f4c(param_1,3,1);
    return 3;
  }
  *(undefined4 *)(param_2 + 0x14) = 1;
  return 0;
}

