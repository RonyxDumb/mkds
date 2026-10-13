/* Decompiled C draft; module arm9_ov000; ROM address 0218f21c. No matching claim. */
#include "types.h"
#include "deps/0218f21c_FUN_0218f21c.h"

undefined4 FUN_0218f21c(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((param_1 == (int *)0x0) || (*param_1 == 0)) {
    return 2;
  }
  if ((-1 < param_2) && (param_2 < 6)) {
    iVar1 = *param_1 + param_2 * 8;
    *(undefined4 *)(iVar1 + DAT_0218f260) = param_3;
    *(undefined4 *)(iVar1 + DAT_0218f264) = param_4;
    return 0;
  }
  FUN_02196590(param_1,DAT_0218f25c);
  return 2;
}

