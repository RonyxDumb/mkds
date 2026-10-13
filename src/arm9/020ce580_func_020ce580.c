/* Decompiled C draft; module arm9; ROM address 020ce580. No matching claim. */
#include "types.h"
#include "deps/020ce580_func_020ce580.h"

void func_020ce580(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined2 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar12;
  int iVar13;
  bool bVar14;
  undefined6 uVar15;
  uint uVar11;
  
  iVar12 = 0;
  uVar2 = func_020c0db0();
  uVar1 = uRam020ce690;
  uVar7 = *(uint *)(uRam020ce690 & 0xfffffffc) >> (uRam020ce690 & 3) * 8 |
          *(uint *)(uRam020ce690 & 0xfffffffc) << (uRam020ce690 & 3) * -8 + 0x20;
  iVar13 = 0;
  uVar10 = uVar7 + 8 & 3;
  uVar3 = *(uint *)(uVar7 + 8 & 0xfffffffc);
  if (0 < (int)(uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20)) {
    iVar8 = 0;
    do {
      uVar7 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
      uVar10 = (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
               *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + iVar13 * 4;
      uVar3 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      uVar11 = uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20;
      uVar10 = uVar7 + 0x10 & 3;
      uVar3 = *(uint *)(uVar7 + 0x10 & 0xfffffffc);
      iVar9 = uVar11 + 4;
      iVar4 = func_020b5ae8(iVar9,(int *)(uintptr_t)((uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20) + iVar8),uVar2,
                            1,1);
      if (iVar4 != 0) {
        uVar5 = GetB3C4_Cell_RaceS(0xb3);
        uVar10 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                 *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
        uVar3 = uVar10 & 3;
        uVar10 = *(uint *)(uVar10 & 0xfffffffc);
        *(undefined4 *)((uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20) + iVar8 + 8) = uVar5;
        uVar15 = CheckVectorBounds_Clock_Airship(iVar9);
        uVar6 = (undefined2)((uint6)uVar15 >> 0x20);
        bVar14 = (int)uVar15 != 0;
        if (bVar14) {
          uVar6 = 2;
        }
        uVar10 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                 *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
        uVar3 = uVar10 & 3;
        uVar10 = *(uint *)(uVar10 & 0xfffffffc);
        if (!bVar14) {
          uVar6 = 3;
        }
        *(undefined2 *)((uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20) + iVar8 + 0xc) = uVar6;
        iVar12 = iVar12 + 1;
        uVar10 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                 *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
        uVar3 = uVar10 & 3;
        uVar10 = *(uint *)(uVar10 & 0xfffffffc);
        *(undefined2 *)((uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20) + iVar8 + 0xe) = 0;
        uVar10 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                 *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
        uVar3 = uVar10 & 3;
        uVar10 = *(uint *)(uVar10 & 0xfffffffc);
        *(undefined2 *)((uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20) + iVar8 + 0x10) =
             *(undefined2 *)(uVar11 + 0x7e);
        iVar8 = iVar8 + 0x14;
      }
      uVar7 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
      iVar13 = iVar13 + 1;
      uVar10 = uVar7 + 8 & 3;
      uVar3 = *(uint *)(uVar7 + 8 & 0xfffffffc);
    } while (iVar13 < (int)(uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20));
  }
  *(int *)(uVar7 + 4) = iVar12;
  return;
}

