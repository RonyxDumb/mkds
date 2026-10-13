/* Decompiled C draft; module arm9_ov000; ROM address 021a9610. No matching claim. */
#include "types.h"
#include "deps/021a9610_FUN_021a9610.h"

undefined4 FUN_021a9610(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_021a9d68();
  if (iVar1 != 7) {
    return 1;
  }
  iVar1 = FUN_021a9d68(param_1);
  if (iVar1 != 6) {
    return 1;
  }
  return 0;
}

