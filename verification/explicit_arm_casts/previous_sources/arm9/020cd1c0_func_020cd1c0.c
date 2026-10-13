/* Decompiled C draft; module arm9; ROM address 020cd1c0. No matching claim. */
#include "types.h"
#include "deps/020cd1c0_func_020cd1c0.h"

void func_020cd1c0(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined2 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  bool bVar12;
  undefined6 uVar13;
  
  iVar10 = 0;
  uVar2 = func_020c0db0();
  uVar1 = uRam020cd2d8;
  uVar3 = *(uint *)(uRam020cd2d8 & 0xfffffffc) >> (uRam020cd2d8 & 3) * 8 |
          *(uint *)(uRam020cd2d8 & 0xfffffffc) << (uRam020cd2d8 & 3) * -8 + 0x20;
  iVar11 = 0;
  uVar9 = uVar3 + 8 & 3;
  uVar7 = *(uint *)(uVar3 + 8 & 0xfffffffc);
  if (0 < (int)(uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20)) {
    iVar8 = 0;
    do {
      uVar9 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + iVar11 * 4;
      uVar7 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      uVar9 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
      if ((*(ushort *)(uVar9 + 2) & 2) == 0) {
        uVar7 = uVar3 + 0x10 & 3;
        uVar3 = *(uint *)(uVar3 + 0x10 & 0xfffffffc);
        iVar4 = func_020b5ae8(uVar9 + 4,(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + iVar8,
                              uVar2,1,1);
        if (iVar4 != 0) {
          uVar5 = GetB3C4_Cell_RaceS(0x90);
          uVar3 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                  *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
          uVar7 = uVar3 & 3;
          uVar3 = *(uint *)(uVar3 & 0xfffffffc);
          *(undefined4 *)((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + iVar8 + 8) = uVar5;
          uVar13 = CheckVectorBounds_Clock_Airship(uVar9 + 4);
          uVar6 = (undefined2)((uint6)uVar13 >> 0x20);
          bVar12 = (int)uVar13 != 0;
          if (bVar12) {
            uVar6 = 2;
          }
          uVar3 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                  *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
          uVar7 = uVar3 & 3;
          uVar3 = *(uint *)(uVar3 & 0xfffffffc);
          if (!bVar12) {
            uVar6 = 3;
          }
          *(undefined2 *)((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + iVar8 + 0xc) = uVar6;
          uVar3 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                  *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
          uVar7 = uVar3 & 3;
          uVar3 = *(uint *)(uVar3 & 0xfffffffc);
          iVar10 = iVar10 + 1;
          *(ushort *)((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + iVar8 + 0xe) =
               *(ushort *)(uVar9 + 2) & 0x400;
          uVar3 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                  *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
          uVar7 = uVar3 & 3;
          uVar3 = *(uint *)(uVar3 & 0xfffffffc);
          *(undefined2 *)((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + iVar8 + 0x10) =
               *(undefined2 *)(uVar9 + 0x7e);
          iVar8 = iVar8 + 0x14;
        }
      }
      uVar3 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
      iVar11 = iVar11 + 1;
      uVar9 = uVar3 + 8 & 3;
      uVar7 = *(uint *)(uVar3 + 8 & 0xfffffffc);
    } while (iVar11 < (int)(uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20));
  }
  *(int *)(uVar3 + 4) = iVar10;
  return;
}

