/* Decompiled C draft; module arm9_ov000; ROM address 021adf78. No matching claim. */
#include "types.h"
#include "deps/021adf78_FUN_021adf78.h"

undefined4 FUN_021adf78(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(DAT_021adfc4 + 4) + 0xa4);
  if (iVar2 == 0) {
    *param_1 = 0;
    return 0;
  }
  if ((byte)(*(char *)(iVar2 + 8) - 10U) < 2) {
    uVar1 = FUN_021ae01c();
    return uVar1;
  }
  if (*(char *)(iVar2 + 9) != '\0') {
    uVar1 = FUN_021a93e0();
    return uVar1;
  }
  uVar1 = FUN_021adfc8();
  return uVar1;
}

