/* Decompiled C draft; module arm9_ov000; ROM address 021aaaf8. No matching claim. */
#include "types.h"
#include "deps/021aaaf8_FUN_021aaaf8.h"

undefined2 FUN_021aaaf8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined2 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  puVar2 = DAT_021aab38;
  do {
    iVar1 = FUN_021aab3c((byte *)(uintptr_t)(param_1),param_2,param_3,*puVar2);
    if (iVar1 != 0) {
      return DAT_021aab38[uVar3];
    }
    puVar2 = puVar2 + 1;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 2);
  return 0;
}

