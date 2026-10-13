/* Decompiled C draft; module arm9_ov003; ROM address 021bf9e8. No matching claim. */
#include "types.h"
#include "deps/021bf9e8_FUN_021bf9e8.h"

void FUN_021bf9e8(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  
  if (*DAT_021bfa60 == 0) {
    iVar2 = FUN_021d285c(0xc,4);
    *DAT_021bfa60 = iVar2;
    *(char *)(iVar2 + 8) = (char)param_1;
    uVar3 = FUN_021d1c18(0,*(undefined1 *)(DAT_021bfa64 + param_1 * 4));
    piVar1 = DAT_021bfa60;
    *(undefined4 *)*DAT_021bfa60 = uVar3;
    puVar4 = *(uint **)*piVar1;
    *puVar4 = (*DAT_021bfa68 & DAT_021bfa6c) << 0x10 |
              *puVar4 & DAT_021bfa70 | DAT_021bfa68[1] & 0xff;
    iVar2 = *(int *)*piVar1;
    *(ushort *)(iVar2 + 4) = *(ushort *)(iVar2 + 4) & (ushort)DAT_021bfa74 | (ushort)DAT_021bfa78;
    uVar3 = FUN_021d3544(0,DAT_021bfa7c,0,0x78);
    *(undefined4 *)(*DAT_021bfa60 + 4) = uVar3;
  }
  return;
}

