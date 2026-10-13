/* Decompiled C draft; module arm9_ov000; ROM address 02198ba8. No matching claim. */
#include "types.h"
#include "deps/02198ba8_FUN_02198ba8.h"

undefined4 FUN_02198ba8(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  
  local_20 = *DAT_02198c04;
  local_1f = DAT_02198c04[1];
  local_1e = 0x65;
  FUN_0219a01c((int)(uintptr_t)(&local_20),3,param_2);
  uVar2 = 5;
  if (param_2 != param_3) {
    FUN_0219a01c((int)(uintptr_t)(&local_20),5,param_3);
    uVar2 = 7;
  }
  iVar1 = FUN_02198714((undefined4 *)(uintptr_t)(param_1),(undefined4)(uintptr_t)(&local_20),uVar2);
  if (iVar1 == 0) {
    return 0;
  }
  return 1;
}

