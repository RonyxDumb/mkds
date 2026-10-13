/* Decompiled C draft; module arm9_ov001; ROM address 02186fb4. No matching claim. */
#include "types.h"
#include "deps/02186fb4_FUN_02186fb4.h"

uint FUN_02186fb4(int *param_1,int *param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = func_0x02148714(*param_1 - *param_2,param_1[2] - param_2[2]);
  uVar3 = iVar1 - param_5 & 0xffff;
  iVar1 = param_3;
  if (param_3 < 0) {
    iVar1 = -param_3;
  }
  if (DAT_02187018 < (int)uVar3) {
    uVar3 = uVar3 - DAT_0218701c;
  }
  if (param_3 < 0) {
    iVar2 = (uVar3 + param_4) - DAT_02187020;
  }
  else {
    iVar2 = (uVar3 - param_4) + DAT_02187020;
  }
  iVar4 = -iVar1;
  if ((iVar2 + iVar1 < 0 == SBORROW4(iVar2,-iVar1)) && (iVar4 = iVar1, iVar2 <= iVar1)) {
    iVar4 = iVar2;
  }
  return param_5 + iVar4 & 0xffff;
}

