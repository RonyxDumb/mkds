/* Decompiled C draft; module arm9_ov000; ROM address 0218d818. No matching claim. */
#include "types.h"
#include "deps/0218d818_FUN_0218d818.h"

int FUN_0218d818(undefined4 param_1,int param_2,int param_3,int param_4,code *param_5,
                undefined4 *param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  param_3 = param_3 + -1;
  *param_6 = 0;
  if (-1 < param_3) {
    do {
      iVar3 = iVar2 + param_3 >> 1;
      iVar1 = (*param_5)(param_2 + param_4 * iVar3,param_1);
      if (iVar1 == 0) {
        *param_6 = 1;
      }
      if (iVar1 < 0) {
        iVar2 = iVar3 + 1;
      }
      else {
        param_3 = iVar3 + -1;
      }
    } while (iVar2 <= param_3);
  }
  return param_2 + param_4 * iVar2;
}

