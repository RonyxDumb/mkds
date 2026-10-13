/* Decompiled C draft; module arm9_ov003; ROM address 021bf364. No matching claim. */
#include "types.h"
#include "deps/021bf364_FUN_021bf364.h"

void FUN_021bf364(int param_1)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 *puVar6;
  
  bVar1 = *(byte *)(DAT_021bf400 + param_1);
  iVar3 = FUN_021d283c(0x1c,4);
  *DAT_021bf404 = iVar3;
  *(undefined1 *)(iVar3 + 0x16) = 0xfe;
  *(char *)(*DAT_021bf404 + 0x17) = (char)param_1;
  iVar3 = 0;
  if (bVar1 != 0) {
    puVar6 = (undefined1 *)(DAT_021bf408 + param_1 * 2);
    iVar5 = 0;
    do {
      uVar4 = FUN_021d1be4(0,*puVar6,1);
      *(undefined4 *)(*DAT_021bf404 + iVar5) = uVar4;
      FUN_021d1790(*(undefined4 *)(*DAT_021bf404 + iVar5),0xffffffff,1);
      puVar6 = puVar6 + 1;
      iVar5 = iVar5 + 4;
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)(uint)bVar1);
  }
  uVar4 = FUN_021d1be4(0,1,1);
  piVar2 = DAT_021bf404;
  *(undefined4 *)(*DAT_021bf404 + 8) = uVar4;
  FUN_021d1790(*(undefined4 *)(*piVar2 + 8),0xffffffff,1);
  FUN_021bf258(0xc0);
  uVar4 = FUN_021d3544(0,DAT_021bf40c,0,0x78);
  *(undefined4 *)(*DAT_021bf404 + 0xc) = uVar4;
  return;
}

