/* Decompiled C draft; module arm9; ROM address 020cd5d0. No matching claim. */
#include "types.h"
#include "deps/020cd5d0_func_020cd5d0.h"

void func_020cd5d0(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined2 uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  bool bVar14;
  undefined6 uVar15;
  
  iVar12 = 0;
  uVar2 = func_020c0db0();
  uVar1 = uRam020cd6dc;
  uVar7 = *(uint *)(uRam020cd6dc & 0xfffffffc) >> (uRam020cd6dc & 3) * 8 |
          *(uint *)(uRam020cd6dc & 0xfffffffc) << (uRam020cd6dc & 3) * -8 + 0x20;
  iVar13 = 0;
  uVar8 = uVar7 + 8 & 3;
  uVar3 = *(uint *)(uVar7 + 8 & 0xfffffffc);
  if (0 < (int)(uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20)) {
    iVar10 = 0;
    iVar9 = 0;
    do {
      uVar8 = uVar7 + 0xc & 3;
      uVar3 = *(uint *)(uVar7 + 0xc & 0xfffffffc);
      iVar4 = func_020b5f68((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) + iVar10);
      if (iVar4 != 0) {
        uVar7 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
        uVar8 = (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + iVar13 * 4;
        uVar3 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        uVar8 = uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20;
        if ((*(ushort *)(uVar8 + 2) & 1) == 0) {
          uVar3 = uVar7 + 0x10 & 3;
          uVar7 = *(uint *)(uVar7 + 0x10 & 0xfffffffc);
          iVar11 = uVar8 + 4;
          iVar4 = func_020b5ae8(iVar11,(int *)(uintptr_t)((uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) + iVar9),
                                uVar2,0,0);
          if (iVar4 != 0) {
            uVar5 = GetB3C4_Cell_RaceS(0x8e);
            uVar8 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
            uVar3 = uVar8 & 3;
            uVar8 = *(uint *)(uVar8 & 0xfffffffc);
            *(undefined4 *)((uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) + iVar9 + 8) = uVar5;
            uVar15 = CheckVectorBounds_Clock_Airship(iVar11);
            uVar6 = (undefined2)((uint6)uVar15 >> 0x20);
            bVar14 = (int)uVar15 != 0;
            if (bVar14) {
              uVar6 = 2;
            }
            uVar8 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
            uVar3 = uVar8 & 3;
            uVar8 = *(uint *)(uVar8 & 0xfffffffc);
            if (!bVar14) {
              uVar6 = 3;
            }
            iVar12 = iVar12 + 1;
            *(undefined2 *)((uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) + iVar9 + 0xc) = uVar6
            ;
            iVar9 = iVar9 + 0x14;
          }
        }
      }
      uVar7 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
      iVar13 = iVar13 + 1;
      uVar8 = uVar7 + 8 & 3;
      uVar3 = *(uint *)(uVar7 + 8 & 0xfffffffc);
      iVar10 = iVar10 + 8;
    } while (iVar13 < (int)(uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20));
  }
  *(int *)(uVar7 + 4) = iVar12;
  return;
}

