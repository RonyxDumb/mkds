/* Decompiled C draft; module arm9_ov000; ROM address 0218d86c. No matching claim. */
#include "types.h"
#include "deps/0218d86c_FUN_0218d86c.h"

int FUN_0218d86c(undefined4 param_1,int param_2,int param_3,int param_4,code *param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_3) {
    iVar2 = 0;
    do {
      iVar1 = (*param_5)(param_1,param_2 + iVar2);
      if (iVar1 == 0) {
        return param_2 + iVar3 * param_4;
      }
      iVar2 = iVar2 + param_4;
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_3);
  }
  return 0;
}

