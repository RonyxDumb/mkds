/* Decompiled C draft; module arm9; ROM address 020c7d8c. No matching claim. */
#include "types.h"
#include "deps/020c7d8c_func_020c7d8c.h"

void func_020c7d8c(void)

{
  bool bVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined4 local_3c;
  undefined4 local_34;
  undefined4 local_30;
  uint uVar13;
  
  iVar15 = 0;
  uVar4 = func_020c0db0();
  uVar2 = uRam020c7f6c;
  uVar8 = *(uint *)(uRam020c7f6c & 0xfffffffc) >> (uRam020c7f6c & 3) * 8 |
          *(uint *)(uRam020c7f6c & 0xfffffffc) << (uRam020c7f6c & 3) * -8 + 0x20;
  iVar16 = 0;
  uVar12 = uVar8 + 8 & 3;
  uVar5 = *(uint *)(uVar8 + 8 & 0xfffffffc);
  if (0 < (int)(uVar5 >> uVar12 * 8 | uVar5 << uVar12 * -8 + 0x20)) {
    local_3c = 1;
    local_30 = 0xa8;
    local_34 = 0xa7;
    iVar17 = 0;
    iVar10 = iVar15;
    do {
      uVar12 = uVar8 + 0xc & 3;
      uVar5 = *(uint *)(uVar8 + 0xc & 0xfffffffc);
      iVar6 = func_020b5f68((uVar5 >> uVar12 * 8 | uVar5 << uVar12 * -8 + 0x20) + iVar17);
      iVar15 = iVar10;
      if (iVar6 != 0) {
        uVar8 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
        iVar11 = iVar10 * 0x14;
        uVar12 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                 *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + iVar16 * 4;
        uVar5 = uVar12 & 3;
        uVar12 = *(uint *)(uVar12 & 0xfffffffc);
        uVar13 = uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20;
        uVar12 = uVar8 + 0x10 & 3;
        uVar5 = *(uint *)(uVar8 + 0x10 & 0xfffffffc);
        iVar6 = func_020b5ae8(uVar13 + 4,
                              (int *)(uintptr_t)((uVar5 >> uVar12 * 8 | uVar5 << uVar12 * -8 + 0x20) + iVar11),uVar4,0,0
                             );
        if (iVar6 != 0) {
          uVar12 = uVar13 + 8 & 3;
          uVar9 = *(uint *)(uVar13 + 8 & 0xfffffffc);
          uVar5 = uVar13 + 0xa8 & 3;
          uVar8 = *(uint *)(uVar13 + 0xa8 & 0xfffffffc);
          iVar6 = (uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20) -
                  (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20);
          if (iVar6 < -0x9000) {
            uVar7 = GetB3C4_Cell_RaceS(0xa9);
            iVar15 = iVar10 + 1;
            uVar12 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                     *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10;
            uVar5 = uVar12 & 3;
            uVar12 = *(uint *)(uVar12 & 0xfffffffc);
            *(undefined4 *)((uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20) + iVar11 + 8) =
                 uVar7;
            uVar12 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                     *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10;
            uVar5 = uVar12 & 3;
            uVar12 = *(uint *)(uVar12 & 0xfffffffc);
            *(undefined2 *)((uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20) + iVar11 + 0xc) = 2;
          }
          else {
            bVar1 = 0 < iVar6;
            uVar7 = local_34;
            if (!bVar1) {
              uVar7 = local_30;
            }
            uVar7 = GetB3C4_Cell_RaceS(uVar7);
            uVar12 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                     *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10;
            uVar5 = uVar12 & 3;
            uVar12 = *(uint *)(uVar12 & 0xfffffffc);
            *(undefined4 *)((uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20) + iVar11 + 8) =
                 uVar7;
            if (bVar1) {
              uVar7 = local_3c;
            }
            uVar3 = (undefined2)uVar7;
            uVar12 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                     *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10;
            uVar5 = uVar12 & 3;
            uVar12 = *(uint *)(uVar12 & 0xfffffffc);
            iVar14 = (iVar10 + 1) * 0x14;
            if (!bVar1) {
              uVar3 = 2;
            }
            *(undefined2 *)((uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20) + iVar11 + 0xc) =
                 uVar3;
            uVar12 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                     *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10;
            uVar5 = uVar12 & 3;
            uVar12 = *(uint *)(uVar12 & 0xfffffffc);
            uVar8 = uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20;
            uVar12 = uVar8 + iVar11 + 4;
            uVar5 = uVar12 & 3;
            uVar13 = *(uint *)(uVar12 & 0xfffffffc);
            uVar12 = uVar8 + iVar11 & 3;
            uVar9 = *(uint *)(uVar8 + iVar11 & 0xfffffffc);
            *(uint *)(uVar8 + iVar14) = uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20;
            *(uint *)(uVar8 + iVar14 + 4) = uVar13 >> uVar5 * 8 | uVar13 << uVar5 * -8 + 0x20;
            uVar7 = GetB3C4_Cell_RaceS(0xa9);
            iVar15 = iVar10 + 2;
            uVar12 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                     *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10;
            uVar5 = uVar12 & 3;
            uVar12 = *(uint *)(uVar12 & 0xfffffffc);
            *(undefined4 *)((uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20) + iVar14 + 8) =
                 uVar7;
            uVar12 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                     *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10;
            uVar5 = uVar12 & 3;
            uVar12 = *(uint *)(uVar12 & 0xfffffffc);
            *(undefined2 *)((uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20) + iVar14 + 0xc) = 2;
            uVar12 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                     *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10;
            uVar5 = uVar12 & 3;
            uVar12 = *(uint *)(uVar12 & 0xfffffffc);
            iVar10 = iVar10 * 0x14 + (uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20);
            uVar12 = iVar10 + 4;
            uVar5 = uVar12 & 3;
            uVar12 = *(uint *)(uVar12 & 0xfffffffc);
            *(uint *)(iVar10 + 4) =
                 (uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20) - (iVar6 >> 0xe);
          }
        }
      }
      uVar8 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
              *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
      iVar16 = iVar16 + 1;
      iVar17 = iVar17 + 8;
      uVar12 = uVar8 + 8 & 3;
      uVar5 = *(uint *)(uVar8 + 8 & 0xfffffffc);
      iVar10 = iVar15;
    } while (iVar16 < (int)(uVar5 >> uVar12 * 8 | uVar5 << uVar12 * -8 + 0x20));
  }
  *(int *)(uVar8 + 4) = iVar15;
  return;
}

