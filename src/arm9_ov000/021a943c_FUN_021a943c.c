/* Decompiled C draft; module arm9_ov000; ROM address 021a943c. No matching claim. */
#include "types.h"
#include "deps/021a943c_FUN_021a943c.h"

undefined4 FUN_021a943c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0xc);
  if ((*(char *)(param_1 + 8) != '\x04') && (iVar1 = FUN_021ae16c(), iVar1 != 0)) {
    return 1;
  }
  *(undefined1 *)(iVar3 + DAT_021a9484) = 0;
  *(undefined1 *)(iVar3 + DAT_021a9488) = 0;
  FUN_021abd2c((undefined4 *)(uintptr_t)(iVar3 + DAT_021a948c));
  FUN_021ab7b4((undefined4 *)(uintptr_t)(iVar3 + DAT_021a9490));
  uVar2 = FUN_021a9494(param_1);
  return uVar2;
}

