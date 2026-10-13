/* Decompiled C draft; module arm7; ROM address 03802c90. No matching claim. */
#include "types.h"
#include "deps/03802c90_FUN_03802c90.h"

void FUN_03802c90(void)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  bool bVar11;
  
  iVar2 = DAT_03802db0;
  uVar4 = *(uint *)(DAT_03802da8 & 0xfffffffc) >> (DAT_03802da8 & 3) * 8 |
          *(uint *)(DAT_03802da8 & 0xfffffffc) << (DAT_03802da8 & 3) * -8 + 0x20;
  if (uVar4 == 0) {
    iVar2 = FUN_03801320(3,0x66,1,1);
    if (iVar2 != 0) {
      FUN_03802c6c(1);
    }
  }
  else if ((int)uVar4 < 4) {
    if (uVar4 != (*(uint *)(DAT_03802dac & 0xfffffffc) >> (DAT_03802dac & 3) * 8 |
                 *(uint *)(DAT_03802dac & 0xfffffffc) << (DAT_03802dac & 3) * -8 + 0x20)) {
      FUN_03801320(3,0x66,1);
    }
  }
  else {
    iVar6 = (uVar4 - 4) * 0xc;
    iVar5 = DAT_03802db0 + iVar6;
    uVar3 = FUN_03806d38(*(uint *)((uint)DAT_03802db4 & 0xfffffffc) >> ((uint)DAT_03802db4 & 3) * 8
                         | *(uint *)((uint)DAT_03802db4 & 0xfffffffc) <<
                           ((uint)DAT_03802db4 & 3) * -8 + 0x20,*(undefined2 *)(iVar5 + 10));
    puVar1 = DAT_03802db4;
    uVar4 = iVar2 + iVar6;
    uVar8 = uVar4 & 3;
    uVar7 = *(uint *)(uVar4 & 0xfffffffc);
    uVar4 = iVar5 + 4U & 3;
    uVar9 = *(uint *)(iVar5 + 4U & 0xfffffffc);
    bVar10 = ((uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) & 0x80000000U >> (uVar3 & 0xff)) ==
             0;
    bVar11 = ((uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) &
             (0U >> (uVar3 & 0xff) | -0x80000000 << (0x20 - uVar3 & 0xff) |
             0x80000000U >> (uVar3 - 0x20 & 0xff))) != 0;
    uVar4 = (uint)(!bVar10 || bVar11);
    if (bVar10 && !bVar11) {
      uVar4 = 2;
    }
    uVar8 = (*(uint *)((uint)DAT_03802db4 & 0xfffffffc) >> ((uint)DAT_03802db4 & 3) * 8 |
            *(uint *)((uint)DAT_03802db4 & 0xfffffffc) << ((uint)DAT_03802db4 & 3) * -8 + 0x20) + 1;
    *DAT_03802db4 = uVar8;
    if ((uint)*(ushort *)(iVar5 + 8) * (uint)*(ushort *)(iVar5 + 10) <= uVar8) {
      *puVar1 = 0;
    }
    if (uVar4 != (*(uint *)(DAT_03802dac & 0xfffffffc) >> (DAT_03802dac & 3) * 8 |
                 *(uint *)(DAT_03802dac & 0xfffffffc) << (DAT_03802dac & 3) * -8 + 0x20)) {
      FUN_03801320(3,0x66,1);
    }
  }
  return;
}

