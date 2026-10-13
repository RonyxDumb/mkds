/* Decompiled C draft; module arm9_ov003; ROM address 021d06b0. No matching claim. */
#include "types.h"
#include "deps/021d06b0_FUN_021d06b0.h"

undefined4 FUN_021d06b0(void)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_021d07b0(3);
  uVar1 = (**(code **)(*DAT_021d06f8 + DAT_021d0700))(*DAT_021d06f8 + DAT_021d06fc);
  iVar2 = func_0x02145708(DAT_021d0704,uVar1,*DAT_021d06f8 + DAT_021d06fc);
  if (iVar2 != 2) {
    FUN_021d079c();
    FUN_021d07b0(9);
    return 0;
  }
  return 1;
}

