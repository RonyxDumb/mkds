/* Decompiled C draft; module arm9_ov003; ROM address 021c2e40. No matching claim. */
#include "types.h"
#include "deps/021c2e40_FUN_021c2e40.h"

void FUN_021c2e40(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  iVar3 = DAT_021c2f14;
  do {
    iVar2 = FUN_021d2a34((ushort *)(uintptr_t)(iVar3));
    if (iVar2 != 0) {
      FUN_021bf31c(1);
      pbVar1 = DAT_021c2f18;
      *DAT_021c2f18 = (byte)uVar4;
      iVar3 = (uint)*pbVar1 * 8;
      FUN_021bf6c8(*(undefined2 *)(DAT_021c2f1c + iVar3),*(undefined2 *)(DAT_021c2f20 + iVar3),
                   *(undefined2 *)(DAT_021c2f24 + iVar3),*(undefined2 *)(DAT_021c2f28 + iVar3));
      return;
    }
    iVar3 = iVar3 + 8;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 2);
  iVar3 = FUN_021d2b04(1);
  if (iVar3 != 0) {
    FUN_021bf31c(1);
    return;
  }
  iVar3 = FUN_021d2b04(2);
  if (iVar3 != 0) {
    FUN_021bf31c(0);
    return;
  }
  iVar3 = FUN_021d2ae8(0x40);
  if (iVar3 != 0) {
    FUN_021c2cc8(1);
    return;
  }
  iVar3 = FUN_021d2ae8(0x80);
  if (iVar3 != 0) {
    FUN_021c2cc8(3);
    return;
  }
  iVar3 = FUN_021d2ae8(0x20);
  if (iVar3 != 0) {
    FUN_021c2cc8(0);
    return;
  }
  iVar3 = FUN_021d2ae8(0x10);
  if (iVar3 != 0) {
    FUN_021c2cc8(2);
  }
  return;
}

