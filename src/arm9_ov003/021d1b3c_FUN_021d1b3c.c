/* Decompiled C draft; module arm9_ov003; ROM address 021d1b3c. No matching claim. */
#include "types.h"
#include "deps/021d1b3c_FUN_021d1b3c.h"

void FUN_021d1b3c(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = FUN_021d283c(DAT_021d1bc0,4);
  piVar1 = DAT_021d1bc4;
  *DAT_021d1bc4 = iVar2;
  iVar2 = DAT_021d1bc8;
  iVar6 = 0;
  iVar5 = 0;
  do {
    uVar3 = FUN_021d1d60(0x20,*piVar1 + iVar5,0x10);
    *(undefined4 *)(*piVar1 + iVar5 + DAT_021d1bcc) = uVar3;
    uVar3 = FUN_021d2ecc();
    *(undefined4 *)(*piVar1 + iVar5 + iVar2) = uVar3;
    uVar3 = FUN_021d2eec(iVar6,0x40);
    *(undefined4 *)(*piVar1 + iVar5 + DAT_021d1bd0) = uVar3;
    iVar4 = FUN_021d2eec(iVar6,0x7f);
    *(int *)(*piVar1 + iVar5 + DAT_021d1bd4) = iVar4 + 8;
    FUN_021d2e50(*(undefined4 *)(*piVar1 + iVar5 + iVar2),*piVar1 + iVar5 + DAT_021d1bd8);
    FUN_021d2e5c(*(undefined4 *)(*piVar1 + iVar5 + iVar2),*piVar1 + iVar5 + DAT_021d1bdc);
    iVar5 = iVar5 + DAT_021d1be0;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 2);
  return;
}

