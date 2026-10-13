/* Decompiled C draft; module arm9_ov000; ROM address 0219bd90. No matching claim. */
#include "types.h"
#include "deps/0219bd90_FUN_0219bd90.h"

void FUN_0219bd90(char param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = FUN_0219c39c();
  if ((iVar2 == 0) && (*(int *)(*DAT_0219bde4 + 0x24) == 3)) {
    FUN_0219b964();
    piVar1 = DAT_0219bde4;
    *(undefined4 *)(*DAT_0219bde4 + 0x6c) = param_3;
    *(undefined4 *)(*piVar1 + 0x70) = param_4;
    FUN_0219b8a8(5);
    FUN_021a260c(param_1 + -1,param_2,DAT_0219bde8,0,param_5,param_6);
  }
  return;
}

