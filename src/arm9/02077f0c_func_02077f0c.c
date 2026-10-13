/* Decompiled C draft; module arm9; ROM address 02077f0c. No matching claim. */
#include "types.h"
#include "deps/02077f0c_func_02077f0c.h"

void func_02077f0c(ushort *param_1,int param_2,undefined4 param_3)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  
  uVar1 = *param_1;
  iVar3 = param_2 - (uint)uVar1;
  if (iVar3 < 0) {
    iVar3 = iRam02077f44 - iVar3;
  }
  sVar2 = func_021488e8(iVar3,param_3);
  *param_1 = *param_1 + sVar2;
  if ((int)((*param_1 + 100) - param_2) < 0) {
    *param_1 = (ushort)(*param_1 + 100);
    return;
  }
  *param_1 = uVar1;
  return;
}

