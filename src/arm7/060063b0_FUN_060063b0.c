/* Decompiled C draft; module arm7; ROM address 060063b0. No matching claim. */
#include "types.h"
#include "deps/060063b0_FUN_060063b0.h"

void FUN_060063b0(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar1 = FUN_06000680();
  uVar2 = iVar1 + 0x154cU & 3;
  uVar5 = *(uint *)(iVar1 + 0x154cU & 0xfffffffc);
  uVar6 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
  *(uint *)((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0xcc) = (uint)*DAT_06006448;
  uVar4 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
          *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
  uVar2 = uVar4 + 0xcc & 3;
  uVar5 = *(uint *)(uVar4 + 0xcc & 0xfffffffc);
  uVar3 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
  uVar2 = uVar4 + 0xd0 & 3;
  uVar5 = *(uint *)(uVar4 + 0xd0 & 0xfffffffc);
  if ((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) != uVar3) {
    *(uint *)(uVar4 + 0xd0) = uVar3;
    FUN_060064f0();
  }
  uVar3 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
          *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
  uVar2 = uVar3 + 0xd4;
  uVar5 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) < 0x80) {
    *(undefined4 *)(uVar3 + 0x1c) = 1;
    thunk_FUN_037fad34(uVar6 + 0xd0,0xf0,DAT_0600644c,DAT_06006450,0xf0);
  }
  else {
    thunk_FUN_037fad34(uVar6 + 0xd0,0xd0,DAT_0600644c,DAT_06006450,0xd0);
  }
  return;
}

