/* Decompiled C draft; module arm9_ov000; ROM address 0218ebe8. No matching claim. */
#include "types.h"
#include "deps/0218ebe8_FUN_0218ebe8.h"

undefined4 FUN_0218ebe8(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int local_10 [2];
  
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    if (*(int *)(*param_1 + DAT_0218ec40) != 0) {
      *param_3 = 0;
      return 0;
    }
    iVar1 = FUN_02194934(param_1,param_2,local_10);
    if ((iVar1 == 0) || (*(undefined4 **)(local_10[0] + 8) == (undefined4 *)0x0)) {
      *param_3 = 0xffffffff;
    }
    else {
      *param_3 = **(undefined4 **)(local_10[0] + 8);
    }
    return 0;
  }
  return 2;
}

