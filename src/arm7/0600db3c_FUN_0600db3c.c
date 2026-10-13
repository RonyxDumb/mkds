/* Decompiled C draft; module arm7; ROM address 0600db3c. No matching claim. */
#include "types.h"
#include "deps/0600db3c_FUN_0600db3c.h"

void FUN_0600db3c(void)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = (*(uint *)(DAT_0600dc20 & 0xfffffffc) >> (DAT_0600dc20 & 3) * 8 |
          *(uint *)(DAT_0600dc20 & 0xfffffffc) << (DAT_0600dc20 & 3) * -8 + 0x20) + DAT_0600dc24;
  if (*(short *)(iVar6 + 0x3c) != 0) {
    uVar5 = iVar6 + 0x90U & 3;
    uVar2 = *(uint *)(iVar6 + 0x90U & 0xfffffffc);
    uVar4 = iVar6 + 0x44U & 3;
    uVar3 = *(uint *)(iVar6 + 0x44U & 0xfffffffc);
    if (*(short *)((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) + 0x10) !=
        *(short *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 2)) {
      FUN_0600dc28();
    }
    uVar5 = iVar6 + 0x44U & 3;
    uVar4 = *(uint *)(iVar6 + 0x44U & 0xfffffffc);
    uVar1 = *(ushort *)((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 4);
    if ((uVar1 & 0xff) == 0) {
      uVar2 = *(uint *)(DAT_0600dc20 & 0xfffffffc) >> (DAT_0600dc20 & 3) * 8 |
              *(uint *)(DAT_0600dc20 & 0xfffffffc) << (DAT_0600dc20 & 3) * -8 + 0x20;
      uVar5 = uVar2 + 0x5a0;
      uVar4 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      *(uint *)(uVar2 + 0x5a0) = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + 1;
    }
    else {
      uVar2 = *(uint *)(DAT_0600dc20 & 0xfffffffc) >> (DAT_0600dc20 & 3) * 8 |
              *(uint *)(DAT_0600dc20 & 0xfffffffc) << (DAT_0600dc20 & 3) * -8 + 0x20;
      uVar5 = uVar2 + 0x5a0;
      uVar4 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      *(uint *)(uVar2 + 0x5a0) = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + (uVar1 & 0xff);
    }
    *(short *)(iVar6 + 0x40) = *(short *)(iVar6 + 0x40) + 1;
    uVar5 = iVar6 + 0x90U & 3;
    uVar4 = *(uint *)(iVar6 + 0x90U & 0xfffffffc);
    uVar2 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    uVar5 = iVar6 + 0x44U & 3;
    uVar4 = *(uint *)(iVar6 + 0x44U & 0xfffffffc);
    *(ushort *)(uVar2 + 0x12) =
         *(ushort *)(uVar2 + 0x10) ^
         *(ushort *)((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 2);
    uVar5 = iVar6 + 0x90U & 3;
    uVar4 = *(uint *)(iVar6 + 0x90U & 0xfffffffc);
    *(undefined2 *)(iVar6 + 0xa0) =
         *(undefined2 *)((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x10);
    *(undefined2 *)(iVar6 + 0x3c) = 0;
    if (*(short *)((*(uint *)(DAT_0600dc20 & 0xfffffffc) >> (DAT_0600dc20 & 3) * 8 |
                   *(uint *)(DAT_0600dc20 & 0xfffffffc) << (DAT_0600dc20 & 3) * -8 + 0x20) + 0x3ea)
        != 0) {
      FUN_0600ac28();
    }
    uVar5 = iVar6 + 0x90U & 3;
    uVar4 = *(uint *)(iVar6 + 0x90U & 0xfffffffc);
    FUN_0600f19c((*(uint *)(DAT_0600dc20 & 0xfffffffc) >> (DAT_0600dc20 & 3) * 8 |
                 *(uint *)(DAT_0600dc20 & 0xfffffffc) << (DAT_0600dc20 & 3) * -8 + 0x20) + 0x188,
                 uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
  }
  return;
}

