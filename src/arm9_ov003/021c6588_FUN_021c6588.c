/* Decompiled C draft; module arm9_ov003; ROM address 021c6588. No matching claim. */
#include "types.h"
#include "deps/021c6588_FUN_021c6588.h"

void FUN_021c6588(void)

{
  undefined1 uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 local_38 [25];
  undefined1 local_1f [31];
  
  puVar5 = local_38;
  iVar4 = 0x19;
  puVar6 = DAT_021c663c;
  do {
    uVar1 = *puVar6;
    puVar6 = puVar6 + 1;
    *puVar5 = uVar1;
    puVar5 = puVar5 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  puVar5 = local_1f;
  iVar4 = 0x16;
  puVar6 = DAT_021c6640;
  do {
    uVar1 = *puVar6;
    puVar6 = puVar6 + 1;
    *puVar5 = uVar1;
    puVar5 = puVar5 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  FUN_021bf620(DAT_021c6644,DAT_021c6648);
  uVar3 = FUN_021bf650((int)(uintptr_t)(local_38));
  uVar3 = FUN_021d14b8(uVar3,0,4);
  piVar2 = DAT_021c664c;
  *(undefined4 *)(*DAT_021c664c + 4) = uVar3;
  FUN_021cca30(*(undefined4 *)(*piVar2 + 4));
  FUN_021cc9fc();
  uVar3 = FUN_021bf650((int)(uintptr_t)(local_1f));
  uVar3 = FUN_021d14b8(uVar3,0,4);
  *(undefined4 *)(*DAT_021c664c + 8) = uVar3;
  *DAT_021c6650 = *DAT_021c6650 & 0xfffc | 3;
  *DAT_021c6654 = *DAT_021c6654 & 0xfffc | 3;
  *DAT_021c6658 = *DAT_021c6658 & 0xfffc | 3;
  *DAT_021c665c = *DAT_021c665c & 0xfffc | 2;
  *DAT_021c6660 = *DAT_021c6660 & 0xfffc | 3;
  *DAT_021c6664 = *DAT_021c6664 & 0xfffc | 2;
  return;
}

