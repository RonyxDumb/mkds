/* Decompiled C draft; module arm9_ov000; ROM address 0219f4c4. No matching claim. */
#include "types.h"
#include "deps/0219f4c4_FUN_0219f4c4.h"

undefined4 FUN_0219f4c4(undefined4 *param_1,uint param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  
  piVar1 = DAT_0219f538;
  puVar2 = (undefined4 *)*DAT_0219f538;
  if ((*(char *)((int)puVar2 + DAT_0219f53c) != '\0') && (*(int *)((int)puVar2 + DAT_0219f540) == 4)
     ) {
    return 1;
  }
  uVar4 = 0;
  if (param_2 != 0) {
    do {
      iVar3 = FUN_0218eb9c((int *)(uintptr_t)(*puVar2),*param_1);
      if (iVar3 == 0) {
        return 0;
      }
      puVar2 = (undefined4 *)*piVar1;
      if ((*(char *)((int)puVar2 + DAT_0219f53c) != '\0') &&
         (*(int *)((int)puVar2 + DAT_0219f540) == 1)) {
        return 1;
      }
      param_1 = param_1 + 1;
      uVar4 = uVar4 + 1;
    } while (uVar4 < param_2);
  }
  return 1;
}

