/* Decompiled C draft; module arm9_ov000; ROM address 021a88e4. No matching claim. */
#include "types.h"
#include "deps/021a88e4_FUN_021a88e4.h"

undefined4 FUN_021a88e4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_70 [60];
  int local_34;
  int local_30;
  undefined4 local_28;
  int local_24;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar1 = (**(code **)(*DAT_021a8954 + 0x18))(DAT_021a8950);
  if (iVar1 == 0) {
    return 0;
  }
  func_0x0214d168((uint *)(void *)(auStack_70),0,100);
  local_34 = DAT_021a8958;
  local_24 = iVar1 + DAT_021a8958;
  local_28 = DAT_021a895c;
  local_30 = iVar1;
  FUN_021ae304((undefined4)(uintptr_t)(auStack_70));
  uVar2 = FUN_021acef8(param_1);
  FUN_021ae2f4();
  (**(code **)(*DAT_021a8954 + 0x1c))(iVar1);
  return uVar2;
}

