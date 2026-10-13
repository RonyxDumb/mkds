/* Decompiled C draft; module arm9; ROM address 020f3a58. No matching claim. */
#include "types.h"
#include "deps/020f3a58_func_020f3a58.h"

bool func_020f3a58(uint param_1,uint *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar12;
  uint uVar13;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar11;
  uint uVar14;
  
  uVar7 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar17 = uVar7 + 0x18 & 3;
  uVar13 = *(uint *)(uVar7 + 0x18 & 0xfffffffc);
  uVar14 = uVar13 >> uVar17 * 8 | uVar13 << uVar17 * -8 + 0x20;
  uVar17 = uVar14 + 4 & 3;
  uVar12 = *(uint *)(uVar14 + 4 & 0xfffffffc);
  uVar13 = param_3 + 4 & 3;
  uVar8 = *(uint *)(param_3 + 4 & 0xfffffffc);
  iVar1 = (int)((uVar12 >> uVar17 * 8 | uVar12 << uVar17 * -8 + 0x20) -
               (uVar8 >> uVar13 * 8 | uVar8 << uVar13 * -8 + 0x20)) >> 0xc;
  uVar8 = *(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
          *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20;
  uVar17 = uVar14 + 8 & 3;
  uVar15 = *(uint *)(uVar14 + 8 & 0xfffffffc);
  iVar2 = (int)((*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) - uVar8) >> 0xc;
  uVar13 = param_3 + 8 & 3;
  uVar12 = *(uint *)(param_3 + 8 & 0xfffffffc);
  iVar3 = (int)((uVar15 >> uVar17 * 8 | uVar15 << uVar17 * -8 + 0x20) -
               (uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20)) >> 0xc;
  uVar13 = (uint)*(ushort *)
                  ((*(uint *)(uRam020f3bb0 & 0xfffffffc) >> (uRam020f3bb0 & 3) * 8 |
                   *(uint *)(uRam020f3bb0 & 0xfffffffc) << (uRam020f3bb0 & 3) * -8 + 0x20) + 0x58);
  uVar17 = uVar7;
  while( true ) {
    uVar12 = 0;
    iVar16 = 0x7fffffff;
    uVar14 = uVar12;
    if (*(ushort *)(uVar17 + 0x24) != 0) {
      do {
        uVar15 = uVar17 + uVar12 * 4;
        uVar6 = uVar15 & 3;
        uVar15 = *(uint *)(uVar15 & 0xfffffffc);
        uVar15 = uVar15 >> uVar6 * 8 | uVar15 << uVar6 * -8 + 0x20;
        if (uVar15 != 0) {
          uVar6 = uVar15 + 0x18 & 3;
          uVar10 = *(uint *)(uVar15 + 0x18 & 0xfffffffc);
          uVar11 = uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20;
          uVar6 = param_3 + 4 & 3;
          uVar18 = *(uint *)(param_3 + 4 & 0xfffffffc);
          uVar10 = uVar11 + 4 & 3;
          uVar19 = *(uint *)(uVar11 + 4 & 0xfffffffc);
          iVar9 = (int)((uVar19 >> uVar10 * 8 | uVar19 << uVar10 * -8 + 0x20) -
                       (uVar18 >> uVar6 * 8 | uVar18 << uVar6 * -8 + 0x20)) >> 0xc;
          iVar4 = (int)((*(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
                        *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20) - uVar8) >> 0xc;
          uVar6 = uVar11 + 8 & 3;
          uVar18 = *(uint *)(uVar11 + 8 & 0xfffffffc);
          uVar10 = param_3 + 8 & 3;
          uVar11 = *(uint *)(param_3 + 8 & 0xfffffffc);
          iVar5 = (int)((uVar18 >> uVar6 * 8 | uVar18 << uVar6 * -8 + 0x20) -
                       (uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20)) >> 0xc;
          iVar9 = iVar5 * iVar5 + iVar4 * iVar4 + iVar9 * iVar9;
          if (iVar9 < iVar16) {
            iVar16 = iVar9;
            uVar14 = uVar15;
          }
        }
        uVar12 = uVar12 + 1;
      } while ((int)uVar12 < (int)(uint)*(ushort *)(uVar17 + 0x24));
    }
    if (iVar16 < iVar3 * iVar3 + iVar2 * iVar2 + iVar1 * iVar1) break;
    uVar13 = uVar13 - 1;
    if (((int)uVar13 < 2) || (uVar17 = uVar14, uVar14 == uVar7)) {
      *param_2 = uVar7;
      param_2[1] = 1;
      return false;
    }
  }
  *param_2 = uVar14;
  param_2[1] = 1;
  return uVar14 != uVar7;
}

