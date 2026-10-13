/* Decompiled C draft; module arm9_ov000; ROM address 0219edb0. No matching claim. */
#include "types.h"
#include "deps/0219edb0_FUN_0219edb0.h"

undefined4 FUN_0219edb0(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 local_8 [2];
  
  if (param_2 == 0xd) {
    local_8[0] = *(undefined4 *)(*DAT_0219ee04 + DAT_0219ee08);
  }
  FUN_021a0ae8(param_2,param_1,0,0,local_8,param_2 == 0xd);
  iVar1 = FUN_0219fee4();
  if (iVar1 == 0) {
    uVar2 = FUN_021a350c();
    iVar1 = *DAT_0219ee04;
    *(int *)(iVar1 + DAT_0219ee0c) = (int)uVar2;
    *(int *)(iVar1 + DAT_0219ee10) = (int)((ulonglong)uVar2 >> 0x20);
    return 1;
  }
  return 0;
}

