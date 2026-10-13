/* Decompiled C draft; module arm9; ROM address 020b4cb0. No matching claim. */
#include "types.h"
#include "deps/020b4cb0_MaybeCreateRotationMatrix.h"

void MaybeCreateRotationMatrix(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)*(short *)(iRam020b4ce8 + (param_2 >> 4) * 4);
  iVar1 = (int)*(short *)(iRam020b4ce8 + ((param_2 >> 4) * 2 + 1) * 2);
  *param_1 = iVar1;
  param_1[1] = iVar2;
  param_1[2] = -iVar2;
  param_1[3] = iVar1;
  return;
}

