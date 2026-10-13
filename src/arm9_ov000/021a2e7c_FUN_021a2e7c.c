/* Decompiled C draft; module arm9_ov000; ROM address 021a2e7c. No matching claim. */
#include "types.h"
#include "deps/021a2e7c_FUN_021a2e7c.h"

void FUN_021a2e7c(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  iVar1 = FUN_0219b9c4();
  iVar2 = *DAT_021a2ee0 + iVar1 * 0x30;
  if ((*(int *)(iVar2 + 4) != 0) && (param_3 <= *(int *)(iVar2 + 8))) {
    func_0x0214d1fc((ushort *)(uintptr_t)(param_2),(uint *)(uintptr_t)(*(int *)(iVar2 + 4)),param_3);
    if (*(code **)(*DAT_021a2ee0 + DAT_021a2ee4) != (code *)0x0) {
      (**(code **)(*DAT_021a2ee0 + DAT_021a2ee4))(iVar1,*(undefined4 *)(iVar2 + 4),param_3);
    }
    if ((*(int *)(*DAT_021a2ee0 + DAT_021a2ee8) != 0) && (*(int *)(iVar2 + 0x2c) != 0)) {
      uVar3 = func_0x0200f5ac();
      *(undefined8 *)(iVar2 + 0x24) = uVar3;
    }
  }
  return;
}

