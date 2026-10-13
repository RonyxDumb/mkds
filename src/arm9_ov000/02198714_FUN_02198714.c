/* Decompiled C draft; module arm9_ov000; ROM address 02198714. No matching claim. */
#include "types.h"
#include "deps/02198714_FUN_02198714.h"

undefined4 FUN_02198714(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0219a110((undefined4 *)(uintptr_t)(param_1[2]),*param_1,*(undefined2 *)(param_1 + 1),param_2,param_3);
  if (iVar1 == 0) {
    return 0;
  }
  uVar2 = FUN_0218e8c4();
  param_1[0x22] = uVar2;
  return 1;
}

