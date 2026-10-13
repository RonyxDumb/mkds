/* Decompiled C draft; module arm9_ov000; ROM address 021839d0. No matching claim. */
#include "types.h"
#include "deps/021839d0_FUN_021839d0.h"

void FUN_021839d0(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_02183a00;
  *(int *)(*DAT_02183a00 + 8) = *(int *)(*DAT_02183a00 + 8) + 1;
  iVar2 = *piVar1;
  if (0x27 < *(int *)(iVar2 + 8)) {
    *(undefined4 *)(iVar2 + 4) = 4;
    *(undefined4 *)(*piVar1 + 8) = 0;
    func_0x0212ecc0(DAT_02183a04,0,DAT_02183a08);
  }
  return;
}

