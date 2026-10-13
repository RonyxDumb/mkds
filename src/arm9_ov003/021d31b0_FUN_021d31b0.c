/* Decompiled C draft; module arm9_ov003; ROM address 021d31b0. No matching claim. */
#include "types.h"
#include "deps/021d31b0_FUN_021d31b0.h"

void FUN_021d31b0(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = FUN_021d283c(DAT_021d3228,4);
  piVar1 = DAT_021d322c;
  *DAT_021d322c = iVar2;
  iVar2 = DAT_021d3230;
  iVar5 = 0;
  iVar4 = 0;
  do {
    uVar3 = FUN_021d1d60(0x20,*piVar1 + iVar4,0xc);
    *(undefined4 *)(*piVar1 + iVar4 + DAT_021d3234) = uVar3;
    uVar3 = FUN_021d2ecc();
    *(undefined4 *)(*piVar1 + iVar4 + iVar2) = uVar3;
    *(short *)(*piVar1 + iVar4 + DAT_021d323c) = (short)DAT_021d3238;
    *(short *)(*piVar1 + iVar4 + DAT_021d3244) = (short)DAT_021d3240;
    FUN_021d2e50(*(undefined4 *)(*piVar1 + iVar4 + iVar2),*piVar1 + iVar4 + DAT_021d3248);
    FUN_021d2e5c(*(undefined4 *)(*piVar1 + iVar4 + iVar2),*piVar1 + iVar4 + DAT_021d324c);
    iVar4 = iVar4 + DAT_021d3250;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  return;
}

