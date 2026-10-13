/* Decompiled C draft; module arm9_ov003; ROM address 021d2fdc. No matching claim. */
#include "types.h"
#include "deps/021d2fdc_FUN_021d2fdc.h"

void FUN_021d2fdc(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = FUN_021d285c(DAT_021d3040,4);
  *DAT_021d3044 = iVar2;
  func_0x0214d05c(DAT_021d3048,(undefined4 *)(uintptr_t)(iVar2),DAT_021d304c);
  piVar1 = DAT_021d3044;
  iVar5 = 0;
  iVar4 = 0;
  iVar2 = 0;
  do {
    uVar3 = FUN_021d1d60(0x40,*piVar1 + iVar4,8);
    *(undefined4 *)(*piVar1 + iVar2 + DAT_021d304c) = uVar3;
    iVar4 = iVar4 + DAT_021d3050;
    iVar2 = iVar2 + 4;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  uVar3 = FUN_021d3544(1,DAT_021d3054,0,200);
  *(undefined4 *)(*DAT_021d3044 + DAT_021d3058) = uVar3;
  return;
}

