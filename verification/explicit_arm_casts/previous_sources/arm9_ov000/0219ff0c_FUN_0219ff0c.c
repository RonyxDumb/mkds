/* Decompiled C draft; module arm9_ov000; ROM address 0219ff0c. No matching claim. */
#include "types.h"
#include "deps/0219ff0c_FUN_0219ff0c.h"

void FUN_0219ff0c(undefined4 param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *param_2;
  if (2 < iVar2 + 2U) {
    func_0x0214d02c(param_2 + 1,*DAT_0219ff44 + DAT_0219ff48,iVar2 * 4);
  }
  piVar1 = DAT_0219ff44;
  *(int *)(*DAT_0219ff44 + DAT_0219ff4c) = iVar2 + 1;
  *(undefined4 *)(*piVar1 + DAT_0219ff50) = param_1;
  return;
}

