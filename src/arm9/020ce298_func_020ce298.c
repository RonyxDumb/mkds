/* Decompiled C draft; module arm9; ROM address 020ce298. No matching claim. */
#include "types.h"
#include "deps/020ce298_func_020ce298.h"

void func_020ce298(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined2 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  bool bVar17;
  undefined6 uVar18;
  uint uVar11;
  
  iVar15 = 0;
  uVar2 = func_020c0db0();
  uVar1 = uRam020ce3c8;
  uVar8 = *(uint *)(uRam020ce3c8 & 0xfffffffc) >> (uRam020ce3c8 & 3) * 8 |
          *(uint *)(uRam020ce3c8 & 0xfffffffc) << (uRam020ce3c8 & 3) * -8 + 0x20;
  iVar16 = 0;
  uVar10 = uVar8 + 8 & 3;
  uVar3 = *(uint *)(uVar8 + 8 & 0xfffffffc);
  if (0 < (int)(uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20)) {
    iVar14 = 0;
    iVar13 = 0;
    do {
      uVar10 = uVar8 + 0xc & 3;
      uVar3 = *(uint *)(uVar8 + 0xc & 0xfffffffc);
      iVar4 = func_020b5f68((uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20) + iVar14);
      if (iVar4 != 0) {
        uVar12 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                 *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
        uVar10 = (*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
                 *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) + iVar16 * 4;
        uVar3 = uVar10 & 3;
        uVar10 = *(uint *)(uVar10 & 0xfffffffc);
        uVar11 = uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20;
        uVar10 = uVar11 + 8 & 3;
        uVar9 = *(uint *)(uVar11 + 8 & 0xfffffffc);
        uVar3 = uVar11 + 0xac & 3;
        uVar8 = *(uint *)(uVar11 + 0xac & 0xfffffffc);
        iVar4 = (uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) -
                (uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20);
        if (-1 < iVar4) {
          uVar10 = uVar12 + 0x10 & 3;
          uVar3 = *(uint *)(uVar12 + 0x10 & 0xfffffffc);
          iVar5 = func_020b5ae8(uVar11 + 4,
                                (int *)(uintptr_t)((uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20) + iVar13),uVar2,0
                                ,1);
          if (iVar5 != 0) {
            uVar10 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                     *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
            uVar3 = uVar10 & 3;
            uVar10 = *(uint *)(uVar10 & 0xfffffffc);
            iVar5 = (uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20) + iVar13;
            uVar10 = iVar5 + 4;
            uVar3 = uVar10 & 3;
            uVar10 = *(uint *)(uVar10 & 0xfffffffc);
            *(uint *)(iVar5 + 4) =
                 (uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20) - (iVar4 >> 0xe);
            uVar6 = GetB3C4_Cell_RaceS(0xb1);
            uVar10 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                     *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
            uVar3 = uVar10 & 3;
            uVar10 = *(uint *)(uVar10 & 0xfffffffc);
            *(undefined4 *)((uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20) + iVar13 + 8) =
                 uVar6;
            uVar18 = CheckVectorBounds_Clock_Airship(uVar11 + 4);
            uVar7 = (undefined2)((uint6)uVar18 >> 0x20);
            bVar17 = (int)uVar18 != 0;
            if (bVar17) {
              uVar7 = 2;
            }
            uVar10 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                     *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
            uVar3 = uVar10 & 3;
            uVar10 = *(uint *)(uVar10 & 0xfffffffc);
            if (!bVar17) {
              uVar7 = 3;
            }
            iVar15 = iVar15 + 1;
            *(undefined2 *)((uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20) + iVar13 + 0xc) =
                 uVar7;
            iVar13 = iVar13 + 0x14;
          }
        }
      }
      uVar8 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
      iVar16 = iVar16 + 1;
      uVar10 = uVar8 + 8 & 3;
      uVar3 = *(uint *)(uVar8 + 8 & 0xfffffffc);
      iVar14 = iVar14 + 8;
    } while (iVar16 < (int)(uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20));
  }
  *(int *)(uVar8 + 4) = iVar15;
  return;
}

