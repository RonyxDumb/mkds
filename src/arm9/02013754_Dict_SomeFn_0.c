/* Decompiled C draft; module arm9; ROM address 02013754. No matching claim. */
#include "types.h"
#include "deps/02013754_Dict_SomeFn_0.h"

uint Dict_SomeFn_0(int param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  
  if (*(byte *)(param_1 + 1) < 0x10) {
    uVar5 = param_2 + 4 & 3;
    uVar15 = *(uint *)(param_2 + 4 & 0xfffffffc);
    uVar12 = param_2 + 8 & 3;
    uVar7 = *(uint *)(param_2 + 8 & 0xfffffffc);
    uVar2 = param_2 + 0xc & 3;
    uVar4 = *(uint *)(param_2 + 0xc & 0xfffffffc);
    uVar9 = 0;
    if (*(byte *)(param_1 + 1) != 0) {
      iVar3 = 0;
      iVar13 = param_1 + (uint)*(ushort *)(param_1 + 6);
      iVar13 = iVar13 + (uint)*(ushort *)(iVar13 + 2);
      do {
        uVar10 = iVar13 + iVar3;
        uVar11 = uVar10 & 3;
        uVar10 = *(uint *)(uVar10 & 0xfffffffc);
        iVar14 = iVar13 + iVar3;
        if ((((uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20) ==
              (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
              *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20)) &&
            (uVar10 = iVar14 + 4U & 3, uVar11 = *(uint *)(iVar14 + 4U & 0xfffffffc),
            (uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20) ==
            (uVar15 >> uVar5 * 8 | uVar15 << uVar5 * -8 + 0x20))) &&
           ((uVar10 = iVar14 + 8U & 3, uVar11 = *(uint *)(iVar14 + 8U & 0xfffffffc),
            (uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20) ==
            (uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20) &&
            (uVar10 = iVar14 + 0xcU & 3, uVar11 = *(uint *)(iVar14 + 0xcU & 0xfffffffc),
            (uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20) ==
            (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20))))) {
          return uVar9;
        }
        uVar9 = uVar9 + 1;
        iVar3 = iVar3 + 0x10;
      } while (uVar9 < *(byte *)(param_1 + 1));
    }
  }
  else {
    pbVar8 = (byte *)(param_1 + 8);
    uVar5 = (uint)*(byte *)(param_1 + 9);
    if (uVar5 != 0) {
      uVar12 = (uint)pbVar8[uVar5 * 4];
      pbVar6 = pbVar8 + uVar5 * 4;
      if (uVar12 < *pbVar8) {
        do {
          uVar5 = param_2 + ((int)uVar12 >> 5) * 4;
          uVar2 = uVar5 & 3;
          uVar4 = *(uint *)(uVar5 & 0xfffffffc);
          uVar5 = uVar12 & 0x1f;
          bVar1 = *pbVar6;
          uVar12 = (uint)pbVar8[(uint)pbVar6[((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) >>
                                              uVar5 & 1) + 1] * 4];
          pbVar6 = pbVar8 + (uint)pbVar6[((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) >> uVar5
                                         & 1) + 1] * 4;
        } while (uVar12 < bVar1);
      }
      param_1 = param_1 + (uint)*(ushort *)(param_1 + 6);
      uVar2 = (uint)pbVar6[3];
      param_1 = param_1 + (uint)*(ushort *)(param_1 + 2);
      uVar5 = param_1 + uVar2 * 0x10;
      uVar12 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      param_1 = param_1 + uVar2 * 0x10;
      if (((((uVar5 >> uVar12 * 8 | uVar5 << uVar12 * -8 + 0x20) ==
             (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
             *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20)) &&
           (uVar5 = param_1 + 4U & 3, uVar7 = *(uint *)(param_1 + 4U & 0xfffffffc),
           uVar12 = param_2 + 4 & 3, uVar4 = *(uint *)(param_2 + 4 & 0xfffffffc),
           (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) ==
           (uVar4 >> uVar12 * 8 | uVar4 << uVar12 * -8 + 0x20))) &&
          (uVar5 = param_1 + 8U & 3, uVar7 = *(uint *)(param_1 + 8U & 0xfffffffc),
          uVar12 = param_2 + 8 & 3, uVar4 = *(uint *)(param_2 + 8 & 0xfffffffc),
          (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) ==
          (uVar4 >> uVar12 * 8 | uVar4 << uVar12 * -8 + 0x20))) &&
         (uVar5 = param_1 + 0xcU & 3, uVar7 = *(uint *)(param_1 + 0xcU & 0xfffffffc),
         uVar12 = param_2 + 0xc & 3, uVar4 = *(uint *)(param_2 + 0xc & 0xfffffffc),
         (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) ==
         (uVar4 >> uVar12 * 8 | uVar4 << uVar12 * -8 + 0x20))) {
        return uVar2;
      }
    }
  }
  return 0xffffffff;
}

