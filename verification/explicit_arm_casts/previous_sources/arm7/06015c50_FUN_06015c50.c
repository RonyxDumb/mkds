/* Decompiled C draft; module arm7; ROM address 06015c50. No matching claim. */
#include "types.h"
#include "deps/06015c50_FUN_06015c50.h"

void FUN_06015c50(void)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_28 [6];
  undefined1 auStack_22 [6];
  undefined2 local_1c;
  uint uVar4;
  
  uVar2 = *(uint *)(DAT_06015d64 & 0xfffffffc) >> (DAT_06015d64 & 3) * 8 |
          *(uint *)(DAT_06015d64 & 0xfffffffc) << (DAT_06015d64 & 3) * -8 + 0x20;
  uVar4 = uVar2 + 0x1e8 & 3;
  uVar3 = *(uint *)(uVar2 + 0x1e8 & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (uVar4 == 0xffffffff) {
    return;
  }
  if ((*(short *)(uVar2 + 0x34c) == 0x40) && (*(ushort *)(uVar4 + 0x20) <= DAT_06015d68)) {
    uVar1 = *(ushort *)(uVar4 + 0x24);
    if ((uVar1 & 0x100) == 0) {
      FUN_0600a954(auStack_28,uVar4 + 0x28);
      if ((uVar1 & 0x200) == 0) {
        FUN_0600a954(auStack_22,uVar4 + 0x2e);
      }
      else {
        FUN_0600a954(auStack_22,uVar4 + 0x34);
      }
    }
    else {
      FUN_0600a954(auStack_28,uVar4 + 0x34);
      if ((uVar1 & 0x200) != 0) goto LAB_06015d34;
      FUN_0600a954(auStack_22,uVar4 + 0x2e);
    }
    local_1c = *(undefined2 *)(uVar4 + 0x3a);
    if (((uVar1 & 0x400) == 0) || ((*(ushort *)(uVar4 + 0x3a) & 0xf) != 0)) {
      FUN_060157b8(uVar4 + 0x18,auStack_28);
    }
    else {
      FUN_060159f8(uVar4 + 0x18,auStack_28);
    }
  }
LAB_06015d34:
  FUN_060090b4(uVar2 + 0x1e8,uVar4);
  if (*(short *)(uVar2 + 0x1f0) != 0) {
    FUN_06008a8c(2,9);
  }
  return;
}

