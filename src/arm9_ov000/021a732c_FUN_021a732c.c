/* Decompiled C draft; module arm9_ov000; ROM address 021a732c. No matching claim. */
#include "types.h"
#include "deps/021a732c_FUN_021a732c.h"

int FUN_021a732c(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = FUN_021a72c4();
  uVar2 = func_0x0200fca0();
  iVar3 = (**(code **)(*DAT_021a7374 + 0x18))(uVar1);
  if (iVar3 != 0) {
    func_0x0214d168((uint *)(uintptr_t)(iVar3),0,uVar1);
    FUN_021a71c0(iVar3,(undefined1 *)(uintptr_t)(param_1));
    FUN_021a8b10(iVar3);
  }
  func_0x0200fcb4(uVar2);
  return iVar3;
}

