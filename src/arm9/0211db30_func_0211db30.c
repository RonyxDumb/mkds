/* Decompiled C draft; module arm9; ROM address 0211db30. No matching claim. */
#include "types.h"
#include "deps/0211db30_func_0211db30.h"

void func_0211db30(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 local_8;
  
  if (*(int *)(*piRam0211db84 + 0x2c) == 3) {
    puVar1 = (undefined4 *)(iRam0211db88 + param_2 * 0x14);
    local_18 = *puVar1;
    uStack_14 = puVar1[1];
    local_10 = puVar1[2];
    uStack_c = puVar1[3];
    local_8 = puVar1[4];
  }
  else {
    puVar1 = (undefined4 *)(iRam0211db8c + param_2 * 0x14);
    local_18 = *puVar1;
    uStack_14 = puVar1[1];
    local_10 = puVar1[2];
    uStack_c = puVar1[3];
    local_8 = puVar1[4];
  }
  *param_1 = local_18;
  param_1[1] = uStack_14;
  param_1[2] = local_10;
  param_1[3] = uStack_c;
  param_1[4] = local_8;
  return;
}

