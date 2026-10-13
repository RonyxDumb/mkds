/* Decompiled C draft; module arm9; ROM address 020cd87c. No matching claim. */
#include "types.h"
#include "deps/020cd87c_func_020cd87c.h"

void func_020cd87c(void)

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
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  bool bVar14;
  undefined6 uVar15;
  undefined4 local_38;
  undefined4 local_34;
  
  iVar13 = 0;
  uVar2 = func_020c0db0();
  uVar1 = uRam020cd9c4;
  uVar7 = *(uint *)(uRam020cd9c4 & 0xfffffffc) >> (uRam020cd9c4 & 3) * 8 |
          *(uint *)(uRam020cd9c4 & 0xfffffffc) << (uRam020cd9c4 & 3) * -8 + 0x20;
  iVar12 = 0;
  uVar11 = uVar7 + 8 & 3;
  uVar3 = *(uint *)(uVar7 + 8 & 0xfffffffc);
  if (0 < (int)(uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20)) {
    iVar10 = 0;
    iVar9 = 0;
    local_34 = 0xaa;
    local_38 = 0xab;
    do {
      uVar11 = uVar7 + 0xc & 3;
      uVar3 = *(uint *)(uVar7 + 0xc & 0xfffffffc);
      iVar4 = func_020b5f68((uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20) + iVar10);
      if (iVar4 != 0) {
        uVar7 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
        uVar11 = (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                 *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + iVar12 * 4;
        uVar3 = uVar11 & 3;
        uVar11 = *(uint *)(uVar11 & 0xfffffffc);
        uVar11 = uVar11 >> uVar3 * 8 | uVar11 << uVar3 * -8 + 0x20;
        if ((*(ushort *)(uVar11 + 2) & 1) == 0) {
          uVar3 = uVar7 + 0x10 & 3;
          uVar7 = *(uint *)(uVar7 + 0x10 & 0xfffffffc);
          iVar4 = func_020b5ae8(uVar11 + 4,(int *)(uintptr_t)((uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) + iVar9)
                                ,uVar2,0,0);
          if (iVar4 != 0) {
            iVar4 = func_02095f30(uVar11);
            uVar3 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
            uVar7 = uVar3 & 3;
            uVar3 = *(uint *)(uVar3 & 0xfffffffc);
            iVar8 = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + iVar9;
            uVar3 = iVar8 + 4;
            uVar7 = uVar3 & 3;
            uVar3 = *(uint *)(uVar3 & 0xfffffffc);
            *(uint *)(iVar8 + 4) =
                 (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) - (iVar4 >> 0xe);
            iVar4 = func_02095f38(uVar11);
            uVar5 = local_38;
            if (iVar4 == 0) {
              uVar5 = local_34;
            }
            uVar5 = GetB3C4_Cell_RaceS(uVar5);
            uVar3 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
            uVar7 = uVar3 & 3;
            uVar3 = *(uint *)(uVar3 & 0xfffffffc);
            *(undefined4 *)((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + iVar9 + 8) = uVar5;
            uVar15 = CheckVectorBounds_Clock_Airship(uVar11 + 4);
            uVar6 = (undefined2)((uint6)uVar15 >> 0x20);
            bVar14 = (int)uVar15 != 0;
            if (bVar14) {
              uVar6 = 2;
            }
            uVar11 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                     *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
            uVar3 = uVar11 & 3;
            uVar11 = *(uint *)(uVar11 & 0xfffffffc);
            if (!bVar14) {
              uVar6 = 3;
            }
            iVar13 = iVar13 + 1;
            *(undefined2 *)((uVar11 >> uVar3 * 8 | uVar11 << uVar3 * -8 + 0x20) + iVar9 + 0xc) =
                 uVar6;
            iVar9 = iVar9 + 0x14;
          }
        }
      }
      uVar7 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
      iVar12 = iVar12 + 1;
      uVar11 = uVar7 + 8 & 3;
      uVar3 = *(uint *)(uVar7 + 8 & 0xfffffffc);
      iVar10 = iVar10 + 8;
    } while (iVar12 < (int)(uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20));
  }
  *(int *)(uVar7 + 4) = iVar13;
  return;
}

