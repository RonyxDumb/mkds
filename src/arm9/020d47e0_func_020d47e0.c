/* Decompiled C draft; module arm9; ROM address 020d47e0. No matching claim. */
#include "types.h"
#include "deps/020d47e0_func_020d47e0.h"

void func_020d47e0(void)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar16;
  uint uVar15;
  
  uVar4 = *(uint *)(uRam020d4960 & 0xfffffffc) >> (uRam020d4960 & 3) * 8 |
          *(uint *)(uRam020d4960 & 0xfffffffc) << (uRam020d4960 & 3) * -8 + 0x20;
  uVar1 = *(ushort *)(uVar4 + 4);
  uVar13 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = func_0207a780();
  uVar6 = GetSomeTimeOrDuration();
  uVar16 = 0;
  if (uVar1 != 0) {
    uVar2 = *puRam020d4964;
    uVar3 = uRam020d4968 & 3;
    uVar12 = *(uint *)(uRam020d4968 & 0xfffffffc);
    do {
      uVar14 = (uVar13 >> (uVar4 & 3) * 8 | uVar13 << (uVar4 & 3) * -8 + 0x20) + uVar16 * 4;
      uVar7 = uVar14 & 3;
      uVar14 = *(uint *)(uVar14 & 0xfffffffc);
      uVar15 = uVar14 >> uVar7 * 8 | uVar14 << uVar7 * -8 + 0x20;
      uVar14 = uVar15 + 0x78 & 3;
      uVar7 = *(uint *)(uVar15 + 0x78 & 0xfffffffc);
      *(uint *)(uVar15 + 0x78) = (uVar7 >> uVar14 * 8 | uVar7 << uVar14 * -8 + 0x20) & 0xfffffff7;
      if ((*(ushort *)(uVar15 + 2) & 2) == 0) {
        uVar14 = uVar15 + 0x78 & 3;
        uVar7 = *(uint *)(uVar15 + 0x78 & 0xfffffffc);
        if (((uVar7 >> uVar14 * 8 | uVar7 << uVar14 * -8 + 0x20) & 1) == 0) {
          if (*(ushort *)(uVar15 + 0x66) < 0x1f) {
            *(ushort *)(uVar15 + 0x66) = *(ushort *)(uVar15 + 0x66) + 1;
          }
        }
        else if (*(short *)(uVar15 + 0x66) != 0) {
          *(short *)(uVar15 + 0x66) = *(short *)(uVar15 + 0x66) + -1;
        }
        if ((uVar16 & 3) == (uVar6 & 3)) {
          uVar14 = uVar15 + 0x74 & 3;
          uVar7 = *(uint *)(uVar15 + 0x74 & 0xfffffffc);
          if (((uVar7 >> uVar14 * 8 | uVar7 << uVar14 * -8 + 0x20) & uVar5) == 0) {
            if (*(short *)(uVar15 + 0x7c) == 0) {
              uVar14 = uVar15 + 0x68 & 3;
              uVar8 = *(uint *)(uVar15 + 0x68 & 0xfffffffc);
              uVar7 = uVar15 + 0x6c & 3;
              uVar10 = *(uint *)(uVar15 + 0x6c & 0xfffffffc);
              uVar9 = uVar15 + 0x70 & 3;
              uVar11 = *(uint *)(uVar15 + 0x70 & 0xfffffffc);
              uVar7 = func_01ffd778(uVar15 + 4,uVar8 >> uVar14 * 8 | uVar8 << uVar14 * -8 + 0x20,
                                    uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20,
                                    uVar11 >> uVar9 * 8 | uVar11 << uVar9 * -8 + 0x20);
              uVar14 = uVar15 + 0x78 & 3;
              uVar9 = *(uint *)(uVar15 + 0x78 & 0xfffffffc);
              *(uint *)(uVar15 + 0x78) =
                   (uVar9 >> uVar14 * 8 | uVar9 << uVar14 * -8 + 0x20) & 0x10 | uVar7;
            }
            else {
              uVar14 = uVar15 + 0x68 & 3;
              uVar8 = *(uint *)(uVar15 + 0x68 & 0xfffffffc);
              uVar7 = uVar15 + 0x6c & 3;
              uVar10 = *(uint *)(uVar15 + 0x6c & 0xfffffffc);
              uVar9 = uVar15 + 0x70 & 3;
              uVar11 = *(uint *)(uVar15 + 0x70 & 0xfffffffc);
              uVar7 = func_01ffd648(uVar15 + 4,uVar8 >> uVar14 * 8 | uVar8 << uVar14 * -8 + 0x20,
                                    uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20,
                                    uVar11 >> uVar9 * 8 | uVar11 << uVar9 * -8 + 0x20);
              uVar14 = uVar15 + 0x78 & 3;
              uVar9 = *(uint *)(uVar15 + 0x78 & 0xfffffffc);
              *(uint *)(uVar15 + 0x78) =
                   (uVar9 >> uVar14 * 8 | uVar9 << uVar14 * -8 + 0x20) & 0x10 | uVar7;
            }
            uVar14 = uVar15 + 0x78 & 3;
            uVar7 = *(uint *)(uVar15 + 0x78 & 0xfffffffc);
            *(uint *)(uVar15 + 0x78) =
                 uVar7 >> uVar14 * 8 | uVar7 << uVar14 * -8 + 0x20 |
                 uVar12 >> uVar3 * 8 | uVar12 << uVar3 * -8 + 0x20;
            uVar14 = uVar15 + 0x78 & 3;
            uVar7 = *(uint *)(uVar15 + 0x78 & 0xfffffffc);
            if (((uVar7 >> uVar14 * 8 | uVar7 << uVar14 * -8 + 0x20) & 2) == 0) {
              *(ushort *)(uVar15 + 2) = *(ushort *)(uVar15 + 2) & 0xffef;
            }
            else {
              *(ushort *)(uVar15 + 2) = *(ushort *)(uVar15 + 2) | uVar2;
            }
          }
          else {
            uVar14 = uVar15 + 0x78 & 3;
            uVar7 = *(uint *)(uVar15 + 0x78 & 0xfffffffc);
            *(uint *)(uVar15 + 0x78) =
                 (uVar7 >> uVar14 * 8 | uVar7 << uVar14 * -8 + 0x20) & 0x10 | uRam020d496c;
            *(ushort *)(uVar15 + 2) = *(ushort *)(uVar15 + 2) | uVar2;
          }
        }
      }
      uVar16 = uVar16 + 1;
    } while ((int)uVar16 < (int)(uint)uVar1);
    return;
  }
  return;
}

