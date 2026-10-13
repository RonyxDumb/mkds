/* Decompiled C draft; module arm9_ov003; ROM address 021d2490. No matching claim. */
#include "types.h"
#include "deps/021d2490_FUN_021d2490.h"

void FUN_021d2490(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_021d285c(DAT_021d24f8,4);
  *DAT_021d24fc = iVar1;
  uVar2 = FUN_021d1d60(0x20,iVar1 + 0x18,0x38);
  *(undefined4 *)(*DAT_021d24fc + DAT_021d2500) = uVar2;
  iVar5 = 0;
  iVar1 = 0;
  iVar4 = 0;
  puVar3 = DAT_021d2504;
  do {
    uVar2 = FUN_021d14b8(*puVar3,0,4);
    *(undefined4 *)(*DAT_021d24fc + iVar1 + DAT_021d2508) = uVar2;
    func_0x02022d44(*DAT_021d24fc + iVar4,*(undefined4 *)(*DAT_021d24fc + iVar1 + DAT_021d2508));
    puVar3 = puVar3 + 1;
    iVar1 = iVar1 + 4;
    iVar4 = iVar4 + 0xc;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  return;
}

