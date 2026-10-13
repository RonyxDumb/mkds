/* Decompiled C draft; module arm9_ov000; ROM address 02183674. No matching claim. */
#include "types.h"
#include "deps/02183674_FUN_02183674.h"

void FUN_02183674(void)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  
  piVar1 = DAT_021836ec;
  *(int *)(*DAT_021836ec + 8) = *(int *)(*DAT_021836ec + 8) + 1;
  uVar2 = func_0x020ae4c0(1,0,DAT_021836f0,*(undefined4 *)(*piVar1 + 8),10);
  piVar1 = DAT_021836ec;
  *(undefined2 *)(*DAT_021836ec + 0x10) = uVar2;
  if (9 < *(int *)(*piVar1 + 8)) {
    *(undefined4 *)(*piVar1 + 8) = 10;
  }
  iVar3 = func_0x02125f88();
  if (((iVar3 != 0) && (iVar3 = func_0x02128294(), iVar3 != 0)) &&
     (iVar3 = *DAT_021836ec, 9 < *(int *)(iVar3 + 8))) {
    if (*(int *)(iVar3 + 0x40) != 0) {
      func_ov000_021806e0(*(undefined4 *)(iVar3 + 0x20));
      return;
    }
    iVar3 = func_0x0212137c();
    if (iVar3 != 0) {
      func_ov000_021806e0(*(undefined4 *)(*DAT_021836ec + 0x20));
    }
  }
  return;
}

