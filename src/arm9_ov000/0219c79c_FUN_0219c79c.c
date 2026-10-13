/* Decompiled C draft; module arm9_ov000; ROM address 0219c79c. No matching claim. */
#include "types.h"
#include "deps/0219c79c_FUN_0219c79c.h"

void FUN_0219c79c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined8 uVar3;
  
  func_0x0213a2d0((uint *)(uintptr_t)(*DAT_0219c804 + 0x4c),param_1);
  func_0x0213a2d0((uint *)(uintptr_t)(*DAT_0219c804 + DAT_0219c808),param_2);
  iVar2 = *DAT_0219c804;
  uVar3 = func_0x0200f5ac();
  *(undefined8 *)(iVar2 + 0x38) = uVar3;
  *(undefined4 *)(iVar2 + 0x34) = 1;
  puVar1 = (undefined4 *)*DAT_0219c804;
  FUN_0218f15c((int *)(uintptr_t)(*puVar1),(char *)(void *)(puVar1 + 0x13),(char *)(uintptr_t)((int)puVar1 + DAT_0219c808),1,0,param_3,0);
  iVar2 = FUN_0219c8dc();
  if (iVar2 == 0) {
    *(undefined4 *)(*DAT_0219c804 + 4) = param_4;
  }
  return;
}

