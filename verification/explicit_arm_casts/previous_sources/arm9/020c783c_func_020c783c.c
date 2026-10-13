/* Decompiled C draft; module arm9; ROM address 020c783c. No matching claim. */
#include "types.h"
#include "deps/020c783c_func_020c783c.h"

void func_020c783c(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar14;
  int iVar15;
  uint uVar13;
  
  iVar14 = 0;
  uVar2 = func_020c0db0();
  uVar1 = uRam020c79bc;
  uVar6 = *(uint *)(uRam020c79bc & 0xfffffffc) >> (uRam020c79bc & 3) * 8 |
          *(uint *)(uRam020c79bc & 0xfffffffc) << (uRam020c79bc & 3) * -8 + 0x20;
  iVar15 = 0;
  uVar12 = uVar6 + 8 & 3;
  uVar3 = *(uint *)(uVar6 + 8 & 0xfffffffc);
  if (0 < (int)(uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20)) {
    iVar11 = 0;
    iVar10 = 0;
    iVar9 = iVar14;
    do {
      uVar12 = uVar6 + 0xc & 3;
      uVar3 = *(uint *)(uVar6 + 0xc & 0xfffffffc);
      iVar4 = func_020b5f68((uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20) + iVar11);
      iVar14 = iVar9;
      if (iVar4 != 0) {
        uVar6 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
        uVar12 = (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                 *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + iVar15 * 4;
        uVar3 = uVar12 & 3;
        uVar12 = *(uint *)(uVar12 & 0xfffffffc);
        uVar13 = uVar12 >> uVar3 * 8 | uVar12 << uVar3 * -8 + 0x20;
        uVar12 = uVar6 + 0x10 & 3;
        uVar3 = *(uint *)(uVar6 + 0x10 & 0xfffffffc);
        iVar4 = func_020b5ae8(uVar13 + 4,
                              (uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20) + iVar10,uVar2,0,0
                             );
        if (iVar4 != 0) {
          uVar5 = GetB3C4_Cell_RaceS(0xaf);
          uVar12 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                   *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
          uVar3 = uVar12 & 3;
          uVar12 = *(uint *)(uVar12 & 0xfffffffc);
          *(undefined4 *)((uVar12 >> uVar3 * 8 | uVar12 << uVar3 * -8 + 0x20) + iVar10 + 8) = uVar5;
          iVar4 = (iVar9 + 1) * 0x14;
          uVar12 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                   *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
          uVar3 = uVar12 & 3;
          uVar12 = *(uint *)(uVar12 & 0xfffffffc);
          *(undefined2 *)((uVar12 >> uVar3 * 8 | uVar12 << uVar3 * -8 + 0x20) + iVar10 + 0xc) = 1;
          uVar12 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                   *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
          uVar3 = uVar12 & 3;
          uVar12 = *(uint *)(uVar12 & 0xfffffffc);
          uVar8 = uVar12 >> uVar3 * 8 | uVar12 << uVar3 * -8 + 0x20;
          uVar12 = uVar8 + iVar9 * 0x14;
          uVar3 = uVar12 & 3;
          uVar7 = *(uint *)(uVar12 & 0xfffffffc);
          uVar12 = uVar8 + iVar9 * 0x14 + 4;
          uVar6 = uVar12 & 3;
          uVar12 = *(uint *)(uVar12 & 0xfffffffc);
          *(uint *)(uVar8 + iVar4) = uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20;
          *(uint *)(uVar8 + iVar4 + 4) = uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20;
          uVar5 = GetB3C4_Cell_RaceS(0xb0);
          iVar10 = iVar10 + 0x28;
          uVar12 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                   *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
          uVar3 = uVar12 & 3;
          uVar12 = *(uint *)(uVar12 & 0xfffffffc);
          iVar14 = iVar9 + 2;
          *(undefined4 *)((uVar12 >> uVar3 * 8 | uVar12 << uVar3 * -8 + 0x20) + iVar4 + 8) = uVar5;
          uVar12 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                   *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
          uVar3 = uVar12 & 3;
          uVar12 = *(uint *)(uVar12 & 0xfffffffc);
          *(undefined2 *)((uVar12 >> uVar3 * 8 | uVar12 << uVar3 * -8 + 0x20) + iVar4 + 0xc) = 2;
          iVar4 = func_020db4c4(uVar13);
          uVar12 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                   *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
          uVar3 = uVar12 & 3;
          uVar12 = *(uint *)(uVar12 & 0xfffffffc);
          iVar9 = iVar9 * 0x14 + (uVar12 >> uVar3 * 8 | uVar12 << uVar3 * -8 + 0x20);
          uVar12 = iVar9 + 4;
          uVar3 = uVar12 & 3;
          uVar12 = *(uint *)(uVar12 & 0xfffffffc);
          *(uint *)(iVar9 + 4) =
               (uVar12 >> uVar3 * 8 | uVar12 << uVar3 * -8 + 0x20) - ((iVar4 << 4) >> 0xc);
        }
      }
      uVar6 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
      iVar15 = iVar15 + 1;
      uVar12 = uVar6 + 8 & 3;
      uVar3 = *(uint *)(uVar6 + 8 & 0xfffffffc);
      iVar11 = iVar11 + 8;
      iVar9 = iVar14;
    } while (iVar15 < (int)(uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20));
  }
  *(int *)(uVar6 + 4) = iVar14;
  return;
}

