/* Decompiled C draft; module arm9; ROM address 020c7310. No matching claim. */
#include "types.h"
#include "deps/020c7310_func_020c7310.h"

void func_020c7310(void)

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
  int iVar11;
  int iVar12;
  bool bVar13;
  undefined6 uVar14;
  
  iVar12 = 0;
  uVar2 = func_020c0db0();
  uVar1 = uRam020c7448;
  uVar3 = *(uint *)(uRam020c7448 & 0xfffffffc) >> (uRam020c7448 & 3) * 8 |
          *(uint *)(uRam020c7448 & 0xfffffffc) << (uRam020c7448 & 3) * -8 + 0x20;
  iVar11 = 0;
  uVar10 = uVar3 + 8 & 3;
  uVar7 = *(uint *)(uVar3 + 8 & 0xfffffffc);
  if (0 < (int)(uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20)) {
    iVar9 = 0;
    iVar8 = 0;
    do {
      if ((*(uint *)(uRam020c744c & 0xfffffffc) >> (uRam020c744c & 3) * 8 == 0 &&
           *(uint *)(uRam020c744c & 0xfffffffc) << (uRam020c744c & 3) * -8 + 0x20 == 0) ||
         (uVar10 = uVar3 + 0xc & 3, uVar3 = *(uint *)(uVar3 + 0xc & 0xfffffffc),
         iVar4 = func_020b5f68((uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20) + iVar9),
         iVar4 != 0)) {
        uVar7 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
        uVar10 = (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                 *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + iVar11 * 4;
        uVar3 = uVar10 & 3;
        uVar10 = *(uint *)(uVar10 & 0xfffffffc);
        uVar10 = uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20;
        if ((*(ushort *)(uVar10 + 2) & 1) == 0) {
          uVar3 = uVar7 + 0x10 & 3;
          uVar7 = *(uint *)(uVar7 + 0x10 & 0xfffffffc);
          iVar4 = func_020b5ae8(uVar10 + 4,(int *)(uintptr_t)((uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) + iVar8)
                                ,uVar2,0,0);
          if (iVar4 != 0) {
            uVar5 = GetB3C4_Cell_RaceS(0x4e);
            uVar3 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
            uVar7 = uVar3 & 3;
            uVar3 = *(uint *)(uVar3 & 0xfffffffc);
            *(undefined4 *)((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + iVar8 + 8) = uVar5;
            uVar14 = CheckVectorBounds_Clock_Airship(uVar10 + 4);
            uVar6 = (undefined2)((uint6)uVar14 >> 0x20);
            bVar13 = (int)uVar14 != 0;
            if (bVar13) {
              uVar6 = 2;
            }
            uVar3 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
            uVar7 = uVar3 & 3;
            uVar3 = *(uint *)(uVar3 & 0xfffffffc);
            if (!bVar13) {
              uVar6 = 3;
            }
            *(undefined2 *)((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + iVar8 + 0xc) = uVar6
            ;
            uVar3 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
            uVar7 = uVar3 & 3;
            uVar3 = *(uint *)(uVar3 & 0xfffffffc);
            iVar12 = iVar12 + 1;
            *(ushort *)((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + iVar8 + 0xe) =
                 *(ushort *)(uVar10 + 2) & 0x20;
            iVar8 = iVar8 + 0x14;
          }
        }
      }
      uVar3 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
      iVar11 = iVar11 + 1;
      uVar10 = uVar3 + 8 & 3;
      uVar7 = *(uint *)(uVar3 + 8 & 0xfffffffc);
      iVar9 = iVar9 + 8;
    } while (iVar11 < (int)(uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20));
  }
  *(int *)(uVar3 + 4) = iVar12;
  return;
}

