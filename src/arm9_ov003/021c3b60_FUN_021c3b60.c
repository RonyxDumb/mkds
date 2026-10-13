/* Decompiled C draft; module arm9_ov003; ROM address 021c3b60. No matching claim. */
#include "types.h"
#include "deps/021c3b60_FUN_021c3b60.h"

void FUN_021c3b60(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  iVar3 = DAT_021c3c04;
  do {
    iVar2 = FUN_021d2a34((ushort *)(uintptr_t)(iVar3));
    if (iVar2 != 0) {
      FUN_021bf31c(1);
      pbVar1 = DAT_021c3c08;
      *DAT_021c3c08 = (byte)uVar4;
      iVar3 = (uint)*pbVar1 * 8;
      FUN_021bf6c8(*(undefined2 *)(DAT_021c3c0c + iVar3),*(undefined2 *)(DAT_021c3c10 + iVar3),
                   *(undefined2 *)(DAT_021c3c14 + iVar3),*(undefined2 *)(DAT_021c3c18 + iVar3));
      return;
    }
    iVar3 = iVar3 + 8;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 3);
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
    FUN_021c3940(1);
    return;
  }
  iVar3 = FUN_021d2ae8(0x80);
  if (iVar3 != 0) {
    FUN_021c3940(3);
  }
  return;
}

