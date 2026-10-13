/* Decompiled C draft; module arm9_ov000; ROM address 021a2d68. No matching claim. */
#include "types.h"
#include "deps/021a2d68_FUN_021a2d68.h"

void FUN_021a2d68(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  iVar2 = *DAT_021a2df0 + param_1 * 0x30;
  iVar1 = FUN_021a2fb4();
  if (iVar1 == 2) {
    if (*(int *)(iVar2 + 8) < *(int *)(iVar2 + 0x10) + param_3) {
      func_0x0200fd1c();
    }
    func_0x0214d1fc((ushort *)(uintptr_t)(param_2),(uint *)(uintptr_t)(*(int *)(iVar2 + 4) + *(int *)(iVar2 + 0x10)),param_3);
  }
  *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + param_3;
  if (*(int *)(iVar2 + 0x10) == *(int *)(iVar2 + 0x18)) {
    *(undefined1 *)(iVar2 + 0x1d) = 1;
    *(undefined4 *)(iVar2 + 0x10) = 0;
    *(undefined4 *)(iVar2 + 0x18) = 0;
    if (*(code **)(*DAT_021a2df0 + DAT_021a2df4) != (code *)0x0) {
      (**(code **)(*DAT_021a2df0 + DAT_021a2df4))(param_1,*(undefined4 *)(iVar2 + 4));
    }
  }
  if ((*(int *)(*DAT_021a2df0 + DAT_021a2df8) != 0) && (*(int *)(iVar2 + 0x2c) != 0)) {
    uVar3 = func_0x0200f5ac();
    *(undefined8 *)(iVar2 + 0x24) = uVar3;
  }
  return;
}

