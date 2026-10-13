/* Decompiled C draft; module arm9_ov003; ROM address 021cb580. No matching claim. */
#include "types.h"
#include "deps/021cb580_FUN_021cb580.h"

void FUN_021cb580(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar2 = DAT_021cb698;
  uVar5 = 0;
  iVar4 = 0;
  do {
    iVar1 = FUN_021c20a8(1);
    iVar1 = FUN_021d2a34((ushort *)(uintptr_t)(iVar2 + iVar1 * 0x20 + iVar4));
    if (iVar1 != 0) {
      FUN_021bf31c(1);
      *DAT_021cb69c = (char)uVar5;
      iVar2 = FUN_021c20a8(1);
      iVar4 = FUN_021c20a8(1);
      iVar1 = FUN_021c20a8(1);
      iVar3 = FUN_021c20a8(1);
      iVar6 = *DAT_021cb69c * 8;
      FUN_021bf6c8(*(undefined2 *)(iVar6 + DAT_021cb6a0 + iVar2 * 0x20),
                   *(undefined2 *)(iVar6 + DAT_021cb6a4 + iVar4 * 0x20),
                   *(undefined2 *)(iVar6 + DAT_021cb6a8 + iVar1 * 0x20),
                   *(undefined2 *)(iVar6 + DAT_021cb6ac + iVar3 * 0x20));
      return;
    }
    iVar4 = iVar4 + 8;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 4);
  iVar2 = FUN_021d2b04(1);
  if (iVar2 != 0) {
    FUN_021bf31c(1);
    return;
  }
  iVar2 = FUN_021d2b04(2);
  if (iVar2 != 0) {
    FUN_021bf31c(0);
    return;
  }
  iVar2 = FUN_021d2ae8(0x40);
  if (iVar2 != 0) {
    FUN_021cb320(1);
    return;
  }
  iVar2 = FUN_021d2ae8(0x80);
  if (iVar2 != 0) {
    FUN_021cb320(3);
    return;
  }
  iVar2 = FUN_021d2ae8(0x20);
  if (iVar2 != 0) {
    FUN_021cb320(0);
    return;
  }
  iVar2 = FUN_021d2ae8(0x10);
  if (iVar2 != 0) {
    FUN_021cb320(2);
  }
  return;
}

