/* Decompiled C draft; module arm9_ov000; ROM address 02198d04. No matching claim. */
#include "types.h"
#include "deps/02198d04_FUN_02198d04.h"

undefined4 FUN_02198d04(undefined4 param_1)

{
  int iVar1;
  int local_10 [2];
  
  iVar1 = FUN_0219903c(param_1,7,7,local_10);
  if (iVar1 == 0) {
    return 0;
  }
  if (local_10[0] != 0) {
    return 1;
  }
  iVar1 = FUN_02198fdc(param_1);
  if (iVar1 != 0) {
    return 1;
  }
  return 0;
}

