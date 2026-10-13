/* Decompiled C draft; module arm9; ROM address 02087c9c. No matching claim. */
#include "types.h"
#include "deps/02087c9c_Animation_SetParameters.h"

void Animation_SetParameters(undefined2 *param_1,undefined4 param_2,int param_3)

{
  undefined2 uVar1;
  bool bVar2;
  
  bVar2 = param_3 == 0;
  if (bVar2) {
    param_3 = 0;
  }
  uVar1 = (undefined2)param_3;
  if (!bVar2) {
    uVar1 = 1;
  }
  *param_1 = uVar1;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 4) = 0x1000;
  *(undefined4 *)(param_1 + 2) = param_2;
  *(undefined4 *)(param_1 + 6) = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  return;
}

