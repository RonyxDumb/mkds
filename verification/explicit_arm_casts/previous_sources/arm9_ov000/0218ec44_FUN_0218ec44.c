/* Decompiled C draft; module arm9_ov000; ROM address 0218ec44. No matching claim. */
#include "types.h"
#include "deps/0218ec44_FUN_0218ec44.h"

undefined4 FUN_0218ec44(int *param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  if ((param_1 == (int *)0x0) || (iVar2 = *param_1, iVar2 == 0)) {
    return 2;
  }
  if (*(int *)(iVar2 + DAT_0218ed18) != 0) {
    func_0x02134de0(param_3,0,DAT_0218ed1c);
    return 0;
  }
  if (param_3 == (undefined4 *)0x0) {
    FUN_02196590(param_1,DAT_0218ed20);
    return 2;
  }
  if ((-1 < param_2) && (param_2 < *(int *)(iVar2 + DAT_0218ed24))) {
    puVar1 = (undefined4 *)FUN_02194808();
    if (puVar1 == (undefined4 *)0x0) {
      FUN_02196590(param_1,DAT_0218ed28);
      return 2;
    }
    iVar2 = puVar1[2];
    if (iVar2 == 0) {
      func_0x0213442c(DAT_0218ed2c,DAT_0218ed30,0,DAT_0218ed34);
    }
    *param_3 = *puVar1;
    param_3[1] = *(undefined4 *)(iVar2 + 4);
    if (*(int *)(iVar2 + 8) == 0) {
      Reset = 0;
    }
    else {
      FUN_02196914(param_3 + 2,*(int *)(iVar2 + 8),DAT_0218ed38);
    }
    if (*(int *)(iVar2 + 0xc) == 0) {
      Reset = 0;
    }
    else {
      FUN_02196914((int)param_3 + DAT_0218ed18,*(int *)(iVar2 + 0xc),DAT_0218ed38);
    }
    *(undefined4 *)((int)param_3 + DAT_0218ed3c) = *(undefined4 *)(iVar2 + 0x10);
    *(undefined4 *)((int)param_3 + DAT_0218ed40) = *(undefined4 *)(iVar2 + 0x14);
    return 0;
  }
  FUN_02196590(param_1,DAT_0218ed28);
  return 2;
}

