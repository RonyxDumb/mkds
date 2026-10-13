/* Decompiled C draft; module arm9_ov000; ROM address 02196240. No matching claim. */
#include "types.h"
#include "deps/02196240_FUN_02196240.h"

undefined4 FUN_02196240(undefined4 param_1,int *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)FUN_021a3690(DAT_021962c0);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_02196590((undefined4 *)(uintptr_t)(param_1),DAT_021962c4);
    return 1;
  }
  func_0x02134de0(puVar1,0,DAT_021962c0);
  *puVar1 = param_3;
  puVar1[1] = 0xffffffff;
  puVar1[2] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[3] = 0;
  puVar1[8] = 0;
  puVar1[9] = 0;
  puVar1[7] = DAT_021962c8;
  uVar2 = FUN_021a3690(puVar1[7] + 1);
  puVar1[6] = uVar2;
  if (puVar1[6] == 0) {
    FUN_02196590((undefined4 *)(uintptr_t)(param_1),DAT_021962c4);
    return 1;
  }
  *(undefined4 *)((int)puVar1 + DAT_021962cc) = 0;
  *(undefined4 *)((int)puVar1 + DAT_021962d0) = 0;
  *param_2 = (int)puVar1;
  return 0;
}

