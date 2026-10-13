/* Decompiled C draft; module arm9_ov000; ROM address 0218aea4. No matching claim. */
#include "types.h"
#include "deps/0218aea4_FUN_0218aea4.h"

int FUN_0218aea4(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    *param_1 = *(int *)(iVar1 + 0x20);
    if (*param_1 == 0) {
      param_1[1] = 0;
    }
    param_1[2] = param_1[2] + -1;
  }
  return iVar1;
}

