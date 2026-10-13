/* Decompiled C draft; module arm7; ROM address 06007b28. No matching claim. */
#include "types.h"
#include "deps/06007b28_FUN_06007b28.h"

void FUN_06007b28(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ushort auStack_218 [4];
  uint uStack_210;
  undefined1 auStack_20c [516];
  
  iVar1 = FUN_06000680();
  uVar4 = iVar1 + 0x154cU & 3;
  uVar2 = *(uint *)(iVar1 + 0x154cU & 0xfffffffc);
  uVar2 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  uVar4 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar4 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  if (*(short *)(uVar4 + 0x17e) == 0) {
    return;
  }
  *(undefined2 *)(uVar4 + 0x8a) = 1;
  auStack_218[0] = 0;
  iVar1 = FUN_06007394(1,1,1,auStack_218);
  if (iVar1 == 1) {
    *(undefined2 *)(uVar4 + 0x8a) = 0;
    return;
  }
  uVar2 = uVar4 + 0x1c & 3;
  uVar3 = *(uint *)(uVar4 + 0x1c & 0xfffffffc);
  if ((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) == 1) {
    auStack_218[0] = auStack_218[0] | 0x8000;
  }
  uVar2 = uVar4 + 0x50 & 3;
  uVar3 = *(uint *)(uVar4 + 0x50 & 0xfffffffc);
  iVar1 = FUN_060026f4(auStack_20c,uStack_210 & 0xffff,auStack_218[0],
                       uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  if (*(short *)(iVar1 + 4) == 0) {
    return;
  }
  if (*(short *)(iVar1 + 4) != 8) {
    *(undefined2 *)(uVar4 + 0x8a) = 0;
  }
  return;
}

