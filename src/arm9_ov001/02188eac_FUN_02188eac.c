/* Decompiled C draft; module arm9_ov001; ROM address 02188eac. No matching claim. */
#include "types.h"
#include "deps/02188eac_FUN_02188eac.h"

undefined4 FUN_02188eac(int param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  
  if (param_3 == (int *)0x0) {
    return 0;
  }
  iVar1 = func_0x02148714(*param_3 - *(int *)(param_1 + 4),param_3[2] - *(int *)(param_1 + 0xc));
  uVar2 = iVar1 - param_2 & 0xffff;
  if (DAT_02188efc < (int)uVar2) {
    uVar2 = uVar2 - DAT_02188f00;
  }
  if ((-uVar2 == param_4 || -param_4 < (int)uVar2) && ((int)uVar2 <= param_4)) {
    return 1;
  }
  return 0;
}

