/* Decompiled C draft; module arm9_ov000; ROM address 02194934. No matching claim. */
#include "types.h"
#include "deps/02194934_FUN_02194934.h"

undefined4 FUN_02194934(int *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  undefined4 local_28 [8];
  
  local_28[0] = param_2;
  iVar1 = FUN_0218de28(*(undefined4 *)(*param_1 + DAT_02194968),local_28);
  if (param_3 != (int *)0x0) {
    *param_3 = iVar1;
  }
  if (iVar1 != 0) {
    return 1;
  }
  return 0;
}

