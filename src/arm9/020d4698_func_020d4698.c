/* Decompiled C draft; module arm9; ROM address 020d4698. No matching claim. */
#include "types.h"
#include "deps/020d4698_func_020d4698.h"

void func_020d4698(void)

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
  int iVar15;
  uint uVar14;
  
  uVar4 = func_0207a780();
  uVar5 = *(uint *)(uRam020d47d4 & 0xfffffffc) >> (uRam020d47d4 & 3) * 8 |
          *(uint *)(uRam020d47d4 & 0xfffffffc) << (uRam020d47d4 & 3) * -8 + 0x20;
  iVar15 = 0;
  uVar1 = *(ushort *)(uVar5 + 4);
  uVar12 = *(uint *)(uVar5 & 0xfffffffc);
  if (uVar1 == 0) {
    return;
  }
  uVar2 = *puRam020d47d8;
  uVar3 = uRam020d47dc & 3;
  uVar11 = *(uint *)(uRam020d47dc & 0xfffffffc);
  do {
    uVar13 = (uVar12 >> (uVar5 & 3) * 8 | uVar12 << (uVar5 & 3) * -8 + 0x20) + iVar15 * 4;
    uVar6 = uVar13 & 3;
    uVar13 = *(uint *)(uVar13 & 0xfffffffc);
    uVar14 = uVar13 >> uVar6 * 8 | uVar13 << uVar6 * -8 + 0x20;
    uVar13 = uVar14 + 0x78 & 3;
    uVar6 = *(uint *)(uVar14 + 0x78 & 0xfffffffc);
    *(uint *)(uVar14 + 0x78) = (uVar6 >> uVar13 * 8 | uVar6 << uVar13 * -8 + 0x20) & 0xfffffff7;
    if ((*(ushort *)(uVar14 + 2) & 2) == 0) {
      uVar13 = uVar14 + 0x74 & 3;
      uVar6 = *(uint *)(uVar14 + 0x74 & 0xfffffffc);
      if (((uVar6 >> uVar13 * 8 | uVar6 << uVar13 * -8 + 0x20) & uVar4) == 0) {
        if (*(short *)(uVar14 + 0x7c) == 0) {
          uVar13 = uVar14 + 0x68 & 3;
          uVar7 = *(uint *)(uVar14 + 0x68 & 0xfffffffc);
          uVar6 = uVar14 + 0x6c & 3;
          uVar9 = *(uint *)(uVar14 + 0x6c & 0xfffffffc);
          uVar8 = uVar14 + 0x70 & 3;
          uVar10 = *(uint *)(uVar14 + 0x70 & 0xfffffffc);
          uVar6 = func_01ffd778(uVar14 + 4,uVar7 >> uVar13 * 8 | uVar7 << uVar13 * -8 + 0x20,
                                uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20,
                                uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20);
          uVar13 = uVar14 + 0x78 & 3;
          uVar8 = *(uint *)(uVar14 + 0x78 & 0xfffffffc);
          *(uint *)(uVar14 + 0x78) =
               (uVar8 >> uVar13 * 8 | uVar8 << uVar13 * -8 + 0x20) & 0x10 | uVar6;
        }
        else {
          uVar13 = uVar14 + 0x68 & 3;
          uVar7 = *(uint *)(uVar14 + 0x68 & 0xfffffffc);
          uVar6 = uVar14 + 0x6c & 3;
          uVar9 = *(uint *)(uVar14 + 0x6c & 0xfffffffc);
          uVar8 = uVar14 + 0x70 & 3;
          uVar10 = *(uint *)(uVar14 + 0x70 & 0xfffffffc);
          uVar6 = func_01ffd648(uVar14 + 4,uVar7 >> uVar13 * 8 | uVar7 << uVar13 * -8 + 0x20,
                                uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20,
                                uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20);
          uVar13 = uVar14 + 0x78 & 3;
          uVar8 = *(uint *)(uVar14 + 0x78 & 0xfffffffc);
          *(uint *)(uVar14 + 0x78) =
               (uVar8 >> uVar13 * 8 | uVar8 << uVar13 * -8 + 0x20) & 0x10 | uVar6;
        }
        uVar13 = uVar14 + 0x78 & 3;
        uVar6 = *(uint *)(uVar14 + 0x78 & 0xfffffffc);
        *(uint *)(uVar14 + 0x78) =
             uVar6 >> uVar13 * 8 | uVar6 << uVar13 * -8 + 0x20 |
             uVar11 >> uVar3 * 8 | uVar11 << uVar3 * -8 + 0x20;
        uVar13 = uVar14 + 0x78 & 3;
        uVar6 = *(uint *)(uVar14 + 0x78 & 0xfffffffc);
        if (((uVar6 >> uVar13 * 8 | uVar6 << uVar13 * -8 + 0x20) & 1) == 0) {
          *(undefined2 *)(uVar14 + 0x66) = 0x1f;
        }
        else {
          *(undefined2 *)(uVar14 + 0x66) = 0;
        }
        uVar13 = uVar14 + 0x78 & 3;
        uVar6 = *(uint *)(uVar14 + 0x78 & 0xfffffffc);
        if (((uVar6 >> uVar13 * 8 | uVar6 << uVar13 * -8 + 0x20) & 2) == 0) {
          *(ushort *)(uVar14 + 2) = *(ushort *)(uVar14 + 2) & 0xffef;
        }
        else {
          *(ushort *)(uVar14 + 2) = *(ushort *)(uVar14 + 2) | uVar2;
        }
      }
      else {
        *(ushort *)(uVar14 + 2) = *(ushort *)(uVar14 + 2) | uVar2;
      }
    }
    iVar15 = iVar15 + 1;
  } while (iVar15 < (int)(uint)uVar1);
  return;
}

