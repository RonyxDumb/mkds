/* Decompiled C draft; module arm7; ROM address 06013db0. No matching claim. */
#include "types.h"
#include "deps/06013db0_FUN_06013db0.h"

void FUN_06013db0(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined2 *puVar4;
  uint uVar5;
  int iVar6;
  
  uVar1 = *(uint *)(DAT_06013eac & 0xfffffffc) >> (DAT_06013eac & 3) * 8 |
          *(uint *)(DAT_06013eac & 0xfffffffc) << (DAT_06013eac & 3) * -8 + 0x20;
  uVar5 = uVar1 + 0x4ac & 3;
  uVar2 = *(uint *)(uVar1 + 0x4ac & 0xfffffffc);
  iVar6 = (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) + 0x24 +
          (uint)*(ushort *)(uVar1 + 0x3da);
  uVar5 = (uint)*(ushort *)(uVar1 + 0x3e4);
  if (uVar5 != 0) {
    if ((*(ushort *)(uVar1 + 0x3e6) & 1) == 0) {
      uVar2 = uVar1 + 0x3e0 & 3;
      uVar3 = *(uint *)(uVar1 + 0x3e0 & 0xfffffffc);
      FUN_06009788(iVar6 + 10,uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20,uVar5 + 1);
    }
    else {
      uVar2 = uVar1 + 0x3e0 & 3;
      uVar3 = *(uint *)(uVar1 + 0x3e0 & 0xfffffffc);
      FUN_06009788(iVar6 + 9,uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20,uVar5 + 2);
      FUN_060096e4(iVar6 + 9,(int)(uint)*DAT_06013eb0 >> 8);
    }
  }
  uVar5 = (*(uint *)(DAT_06013eac & 0xfffffffc) >> (DAT_06013eac & 3) * 8 |
          *(uint *)(DAT_06013eac & 0xfffffffc) << (DAT_06013eac & 3) * -8 + 0x20) + 0x4ac;
  uVar2 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(short *)((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + 10) =
       *(short *)(uVar1 + 0x3da) + 0x26 + *(short *)(uVar1 + 0x3e4);
  FUN_060096e4(iVar6 + 1,*(short *)(uVar1 + 0x3e4) + 8U & 0xff);
  if ((*(ushort *)
        ((*(uint *)(DAT_06013eac & 0xfffffffc) >> (DAT_06013eac & 3) * 8 |
         *(uint *)(DAT_06013eac & 0xfffffffc) << (DAT_06013eac & 3) * -8 + 0x20) + 0x690) & 4) != 0)
  {
    puVar4 = (undefined2 *)(iVar6 + 0xd + (uint)*(ushort *)(uVar1 + 0x3e4) & 0xfffffffc);
    *puVar4 = (short)DAT_06013eb4;
    puVar4[1] = (short)DAT_06013eb8;
  }
  *(undefined2 *)(uVar1 + 1000) = 0;
  return;
}

