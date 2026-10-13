/* Decompiled C draft; module arm9; ROM address 020138b4. No matching claim. */
#include "types.h"
#include "deps/020138b4_NNS_G3dGetResDataByName.h"

int NNS_G3dGetResDataByName(int param_1,uint param_2)

{
  byte bVar1;
  ushort *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  
  if (*(byte *)(param_1 + 1) < 0x10) {
    uVar5 = param_2 + 4 & 3;
    uVar16 = *(uint *)(param_2 + 4 & 0xfffffffc);
    uVar13 = param_2 + 8 & 3;
    uVar8 = *(uint *)(param_2 + 8 & 0xfffffffc);
    uVar7 = param_2 + 0xc & 3;
    uVar4 = *(uint *)(param_2 + 0xc & 0xfffffffc);
    uVar10 = 0;
    if (*(byte *)(param_1 + 1) != 0) {
      iVar3 = 0;
      iVar14 = param_1 + (uint)*(ushort *)(param_1 + 6);
      iVar14 = iVar14 + (uint)*(ushort *)(iVar14 + 2);
      do {
        uVar11 = iVar14 + iVar3;
        uVar12 = uVar11 & 3;
        uVar11 = *(uint *)(uVar11 & 0xfffffffc);
        iVar15 = iVar14 + iVar3;
        if ((((uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20) ==
              (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
              *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20)) &&
            (uVar11 = iVar15 + 4U & 3, uVar12 = *(uint *)(iVar15 + 4U & 0xfffffffc),
            (uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20) ==
            (uVar16 >> uVar5 * 8 | uVar16 << uVar5 * -8 + 0x20))) &&
           ((uVar11 = iVar15 + 8U & 3, uVar12 = *(uint *)(iVar15 + 8U & 0xfffffffc),
            (uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20) ==
            (uVar8 >> uVar13 * 8 | uVar8 << uVar13 * -8 + 0x20) &&
            (uVar11 = iVar15 + 0xcU & 3, uVar12 = *(uint *)(iVar15 + 0xcU & 0xfffffffc),
            (uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20) ==
            (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20))))) {
          return *(ushort *)(param_1 + (uint)*(ushort *)(param_1 + 6)) * uVar10 +
                 param_1 + (uint)*(ushort *)(param_1 + 6) + 4;
        }
        uVar10 = uVar10 + 1;
        iVar3 = iVar3 + 0x10;
      } while (uVar10 < *(byte *)(param_1 + 1));
    }
  }
  else {
    pbVar9 = (byte *)(param_1 + 8);
    uVar5 = (uint)*(byte *)(param_1 + 9);
    if (uVar5 != 0) {
      uVar13 = (uint)pbVar9[uVar5 * 4];
      pbVar6 = pbVar9 + uVar5 * 4;
      if (uVar13 < *pbVar9) {
        do {
          uVar5 = param_2 + ((int)uVar13 >> 5) * 4;
          uVar7 = uVar5 & 3;
          uVar4 = *(uint *)(uVar5 & 0xfffffffc);
          uVar5 = uVar13 & 0x1f;
          bVar1 = *pbVar6;
          uVar13 = (uint)pbVar9[(uint)pbVar6[((uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) >>
                                              uVar5 & 1) + 1] * 4];
          pbVar6 = pbVar9 + (uint)pbVar6[((uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) >> uVar5
                                         & 1) + 1] * 4;
        } while (uVar13 < bVar1);
      }
      uVar7 = (uint)pbVar6[3];
      puVar2 = (ushort *)(param_1 + (uint)*(ushort *)(param_1 + 6));
      uVar5 = (int)puVar2 + uVar7 * 0x10 + (uint)puVar2[1];
      uVar13 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      iVar3 = uVar7 * 0x10 + (uint)puVar2[1];
      if (((((uVar5 >> uVar13 * 8 | uVar5 << uVar13 * -8 + 0x20) ==
             (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
             *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20)) &&
           (uVar5 = (int)puVar2 + iVar3 + 4, uVar13 = uVar5 & 3,
           uVar8 = *(uint *)(uVar5 & 0xfffffffc), uVar5 = param_2 + 4 & 3,
           uVar4 = *(uint *)(param_2 + 4 & 0xfffffffc),
           (uVar8 >> uVar13 * 8 | uVar8 << uVar13 * -8 + 0x20) ==
           (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20))) &&
          (uVar5 = (int)puVar2 + iVar3 + 8, uVar13 = uVar5 & 3,
          uVar8 = *(uint *)(uVar5 & 0xfffffffc), uVar5 = param_2 + 8 & 3,
          uVar4 = *(uint *)(param_2 + 8 & 0xfffffffc),
          (uVar8 >> uVar13 * 8 | uVar8 << uVar13 * -8 + 0x20) ==
          (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20))) &&
         (uVar5 = (int)puVar2 + iVar3 + 0xc, uVar13 = uVar5 & 3,
         uVar8 = *(uint *)(uVar5 & 0xfffffffc), uVar5 = param_2 + 0xc & 3,
         uVar4 = *(uint *)(param_2 + 0xc & 0xfffffffc),
         (uVar8 >> uVar13 * 8 | uVar8 << uVar13 * -8 + 0x20) ==
         (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20))) {
        return (int)puVar2 + *puVar2 * uVar7 + 4;
      }
    }
  }
  return 0;
}

