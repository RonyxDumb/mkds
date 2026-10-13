/* Decompiled C draft; module arm9_ov001; ROM address 02183d94. No matching claim. */
#include "types.h"
#include "deps/02183d94_FUN_02183d94.h"

undefined4 FUN_02183d94(int param_1)

{
  int iVar1;
  
  iVar1 = func_0x0207a974((short)*(char *)(*DAT_02183ddc + 0x62));
  FUN_02188998(param_1,iVar1 + 0x80);
  if (*(int *)(param_1 + DAT_02183de0) < *(int *)(*(int *)(param_1 + 0xa0) + DAT_02183de4)) {
    FUN_02188200(param_1,DAT_02183de8);
    FUN_02184e6c(param_1);
  }
  return 0;
}

