/* Decompiled C draft; module arm9; ROM address 020ce414. No matching claim. */
#include "types.h"
#include "deps/020ce414_func_020ce414.h"

void func_020ce414(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined2 uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  bool bVar13;
  undefined6 uVar14;
  
  iVar9 = 0;
  uVar2 = func_020c0db0();
  uVar1 = uRam020ce530;
  uVar8 = *(uint *)(uRam020ce530 & 0xfffffffc) >> (uRam020ce530 & 3) * 8 |
          *(uint *)(uRam020ce530 & 0xfffffffc) << (uRam020ce530 & 3) * -8 + 0x20;
  iVar10 = 0;
  uVar12 = uVar8 + 8 & 3;
  uVar3 = *(uint *)(uVar8 + 8 & 0xfffffffc);
  if (0 < (int)(uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20)) {
    iVar11 = 0;
    do {
      uVar12 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
               *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + iVar10 * 4;
      uVar3 = uVar12 & 3;
      uVar12 = *(uint *)(uVar12 & 0xfffffffc);
      uVar12 = uVar12 >> uVar3 * 8 | uVar12 << uVar3 * -8 + 0x20;
      if (((*(ushort *)(uVar12 + 2) & 1) == 0) && (iVar4 = func_02092194(uVar12), iVar4 != 0)) {
        uVar3 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
        uVar8 = uVar3 & 3;
        uVar3 = *(uint *)(uVar3 & 0xfffffffc);
        iVar5 = func_020b5ae8(uVar12 + 4,(uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) + iVar11,
                              uVar2,1,1);
        if (iVar5 != 0) {
          if (iVar4 == 2) {
            uVar6 = GetB3C4_Cell_RaceS(0xb5);
          }
          else {
            uVar6 = GetB3C4_Cell_RaceS(0xb4);
          }
          uVar3 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                  *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
          uVar8 = uVar3 & 3;
          uVar3 = *(uint *)(uVar3 & 0xfffffffc);
          *(undefined4 *)((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) + iVar11 + 8) = uVar6;
          uVar14 = CheckVectorBounds_Clock_Airship(uVar12 + 4);
          uVar7 = (undefined2)((uint6)uVar14 >> 0x20);
          bVar13 = (int)uVar14 != 0;
          if (bVar13) {
            uVar7 = 2;
          }
          uVar12 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                   *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
          uVar3 = uVar12 & 3;
          uVar12 = *(uint *)(uVar12 & 0xfffffffc);
          if (!bVar13) {
            uVar7 = 3;
          }
          iVar9 = iVar9 + 1;
          *(undefined2 *)((uVar12 >> uVar3 * 8 | uVar12 << uVar3 * -8 + 0x20) + iVar11 + 0xc) =
               uVar7;
          iVar11 = iVar11 + 0x14;
        }
      }
      uVar8 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
      iVar10 = iVar10 + 1;
      uVar12 = uVar8 + 8 & 3;
      uVar3 = *(uint *)(uVar8 + 8 & 0xfffffffc);
    } while (iVar10 < (int)(uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20));
  }
  *(int *)(uVar8 + 4) = iVar9;
  return;
}

