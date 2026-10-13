/* Decompiled C draft; module arm9_ov000; ROM address 0219903c. No matching claim. */
#include "types.h"
#include "deps/0219903c_FUN_0219903c.h"

undefined4 FUN_0219903c(int param_1,undefined1 param_2,int param_3,undefined4 *param_4)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = FUN_02197e58(param_1 + 0x50);
  if (iVar2 < param_3) {
    iVar2 = FUN_02199f80(param_1);
    if (iVar2 == 0) {
      return 0;
    }
    *param_4 = 1;
    return 1;
  }
  iVar2 = FUN_021990f8(param_1,*(undefined2 *)(param_1 + 100),param_3);
  if (iVar2 != 0) {
    FUN_02197d84((int *)(uintptr_t)(param_1 + 0x50),DAT_021990f4,2);
    FUN_02197e20((int *)(uintptr_t)(param_1 + 0x50),param_2);
    uVar1 = *(undefined2 *)(param_1 + 100);
    *(short *)(param_1 + 100) = *(short *)(param_1 + 100) + 1;
    FUN_02197ddc((int *)(uintptr_t)(param_1 + 0x50),uVar1);
    FUN_02197ddc((int *)(uintptr_t)(param_1 + 0x50),*(undefined2 *)(param_1 + 0x66));
    *param_4 = 0;
    return 1;
  }
  iVar2 = FUN_02199f80(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  *param_4 = 1;
  return 1;
}

