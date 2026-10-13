/* Decompiled C draft; module arm9_ov000; ROM address 0218ed44. No matching claim. */
#include "types.h"
#include "deps/0218ed44_FUN_0218ed44.h"

undefined4 FUN_0218ed44(int *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if ((param_1 != (int *)0x0) && (iVar1 = *param_1, iVar1 != 0)) {
    if (*(int *)(iVar1 + DAT_0218ed6c) != 0) {
      *param_2 = 0;
      return 0;
    }
    *param_2 = *(undefined4 *)(iVar1 + DAT_0218ed70);
    return 0;
  }
  return 2;
}

