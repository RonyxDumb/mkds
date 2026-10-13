/* Decompiled C draft; module arm9_ov003; ROM address 021cca30. No matching claim. */
#include "types.h"
#include "deps/021cca30_FUN_021cca30.h"

void FUN_021cca30(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_021d283c(DAT_021cca64,4);
  *DAT_021cca68 = iVar1;
  func_0x0214d0a8((undefined4 *)(uintptr_t)(param_1),(undefined4 *)(uintptr_t)(iVar1 + 4),DAT_021cca6c);
  uVar2 = FUN_021d3544(1,DAT_021cca70,0,0x78);
  *(undefined4 *)*DAT_021cca68 = uVar2;
  return;
}

