/* Decompiled C draft; module arm9_ov000; ROM address 0219a61c. No matching claim. */
#include "types.h"
#include "deps/0219a61c_FUN_0219a61c.h"

void FUN_0219a61c(int *param_1,int *param_2)

{
  int iVar1;
  
  if (*param_1 == 0) {
    *param_1 = DAT_0219a650;
    *param_2 = 0;
    return;
  }
  if (*param_2 == -1) {
    iVar1 = func_0x0213a434(*param_1);
    *param_2 = iVar1 + 1;
  }
  return;
}

