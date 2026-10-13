/* Decompiled C draft; module arm9_ov001; ROM address 02187024. No matching claim. */
#include "types.h"
#include "deps/02187024_FUN_02187024.h"

uint FUN_02187024(int *param_1,int *param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = func_0x02148714(*param_1 - *param_2,param_1[2] - param_2[2]);
  uVar3 = iVar1 - param_4 & 0xffff;
  if ((int)param_3 < 0) {
    param_3 = -param_3;
  }
  if (DAT_0218706c < (int)uVar3) {
    uVar3 = uVar3 - DAT_02187070;
  }
  uVar2 = -param_3;
  if (((int)(uVar3 + param_3) < 0 == SBORROW4(uVar3,-param_3)) &&
     (uVar2 = param_3, (int)uVar3 <= (int)param_3)) {
    uVar2 = uVar3;
  }
  return param_4 + uVar2 & 0xffff;
}

