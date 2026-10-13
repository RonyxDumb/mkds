/* Decompiled C draft; module arm7; ROM address 06006358. No matching claim. */
#include "types.h"
#include "deps/06006358_FUN_06006358.h"

void FUN_06006358(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = FUN_06000680();
  uVar2 = iVar1 + 0x154cU & 3;
  uVar4 = *(uint *)(iVar1 + 0x154cU & 0xfffffffc);
  uVar5 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
  FUN_06006454();
  uVar3 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
          *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
  uVar2 = uVar3 + 0xd4;
  uVar4 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (0x7e < (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20)) {
    *(undefined4 *)(uVar3 + 0x1c) = 0;
  }
  thunk_FUN_037fad34(uVar5 + 0xd0,0xf0,DAT_060063a8,DAT_060063ac,0xf0);
  return;
}

