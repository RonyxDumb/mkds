/* Decompiled C draft; module arm9_ov000; ROM address 02182878. No matching claim. */
#include "types.h"
#include "deps/02182878_FUN_02182878.h"

void FUN_02182878(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_021828e0;
  *(int *)(*DAT_021828e0 + 0x10) = *(int *)(*DAT_021828e0 + 0x10) + 1;
  iVar2 = *piVar1;
  if (*(int *)(iVar2 + 0x10) < 10) {
    if (4 < *(int *)(iVar2 + 0x10)) {
      *(undefined4 *)(iVar2 + 0x24) = 1;
    }
    return;
  }
  *(undefined4 *)(iVar2 + 4) = 6;
  *(undefined4 *)(*piVar1 + 0x10) = 0;
  func_0x02125fc0();
  iVar2 = FUN_021832f0();
  if ((iVar2 == 0) &&
     ((iVar2 = *DAT_021828e0, *(int *)(iVar2 + 0x20) != 3 || (*(int *)(iVar2 + 0xc) == 0)))) {
    *(undefined4 *)(iVar2 + 0x28) = 0;
    return;
  }
  func_0x021282c8();
  *(undefined4 *)(*DAT_021828e0 + 0x28) = 1;
  return;
}

