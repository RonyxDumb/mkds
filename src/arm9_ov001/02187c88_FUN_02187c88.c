/* Decompiled C draft; module arm9_ov001; ROM address 02187c88. No matching claim. */
#include "types.h"
#include "deps/02187c88_FUN_02187c88.h"

void FUN_02187c88(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  *(undefined4 *)(param_1 + DAT_02187cc4) = param_2;
  puVar3 = (undefined4 *)(param_1 + DAT_02187cc8);
  uVar2 = param_3[1];
  *puVar3 = *param_3;
  puVar3[1] = uVar2;
  puVar3[2] = param_3[2];
  piVar1 = (int *)(param_1 + DAT_02187ccc);
  *(int *)(*(int *)(*piVar1 + 0x10) + 0x2c) = param_1;
  func_0x020109c4(*(undefined4 *)(*piVar1 + 0x10),DAT_02187cd0,0,6,3);
  return;
}

