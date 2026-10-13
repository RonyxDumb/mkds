/* Decompiled C draft; module arm9_ov003; ROM address 021d35f4. No matching claim. */
#include "types.h"
#include "deps/021d35f4_FUN_021d35f4.h"

void FUN_021d35f4(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  byte *pbVar4;
  int iVar5;
  
  iVar2 = FUN_021d285c(0x78,4);
  piVar1 = DAT_021d368c;
  *DAT_021d368c = iVar2;
  iVar5 = 0;
  iVar2 = 0;
  pbVar4 = DAT_021d3690;
  do {
    *(uint *)(*piVar1 + iVar2 + 0x34) = (uint)*pbVar4;
    uVar3 = FUN_021d285c((uint)*pbVar4 * 0x14,4);
    *(undefined4 *)(*piVar1 + iVar2 + 0x38) = uVar3;
    uVar3 = FUN_021d1d60(*pbVar4,*(undefined4 *)(*piVar1 + iVar2 + 0x38),0x14);
    *(undefined4 *)(*piVar1 + iVar2) = uVar3;
    uVar3 = FUN_021d1d88(*pbVar4);
    *(undefined4 *)(*piVar1 + iVar2 + 4) = uVar3;
    uVar3 = FUN_021d2ecc();
    *(undefined4 *)(*piVar1 + iVar2 + 8) = uVar3;
    *(undefined1 *)(*piVar1 + iVar2 + 0x1c) = 0;
    *(undefined1 *)(*piVar1 + iVar2 + 0x30) = 0xff;
    FUN_021d2e50(*(undefined4 *)(*piVar1 + iVar2 + 8),*piVar1 + iVar2 + 0xc);
    FUN_021d2e5c(*(undefined4 *)(*piVar1 + iVar2 + 8),*piVar1 + iVar2 + 0x20);
    pbVar4 = pbVar4 + 1;
    iVar2 = iVar2 + 0x3c;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  return;
}

