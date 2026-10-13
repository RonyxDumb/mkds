/* Decompiled C draft; module arm9; ROM address 0214d464. No matching claim. */
#include "types.h"
#include "deps/0214d464_LzDecompressContext_DoCycle.h"

uint LzDecompressContext_DoCycle(undefined4 *param_1,byte *param_2,int param_3)

{
  bool bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  byte bVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  char cVar13;
  uint uVar14;
  uint uVar8;
  
  pbVar6 = (byte *)(*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                   *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20);
  uVar8 = (uint)(param_1 + 1) & 3;
  uVar7 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
  bVar9 = *(byte *)((int)param_1 + 0xb);
  uVar7 = (uint)*(byte *)(param_1 + 3);
  uVar11 = (uint)*(byte *)((int)param_1 + 0xd);
  cVar13 = *(char *)((int)param_1 + 0xe);
  while (uVar10 = (uint)bVar9, pbVar3 = param_2, 0 < (int)uVar8) {
    for (; uVar7 != 0; uVar7 = uVar7 - 1) {
      bVar9 = (byte)uVar10;
      if (param_3 == 0) goto LAB_0214d540;
      if ((uVar10 & 0x80) == 0) {
        pbVar4 = pbVar3 + 1;
        uVar8 = uVar8 - 1;
        param_3 = param_3 + -1;
        *pbVar6 = *pbVar3;
        pbVar6 = pbVar6 + 1;
      }
      else {
        pbVar5 = pbVar3;
        if (cVar13 == '\0') {
          pbVar5 = pbVar3 + 1;
          uVar11 = (uint)*pbVar3;
          cVar13 = '\x01';
          param_3 = param_3 + -1;
        }
        if (param_3 == 0) goto LAB_0214d540;
        uVar14 = uVar11 & 0xf;
        pbVar4 = pbVar5 + 1;
        bVar2 = *pbVar5;
        cVar13 = '\0';
        param_3 = param_3 + -1;
        uVar11 = ((int)uVar11 >> 4) + 3;
        uVar12 = uVar11;
        if (uVar11 != 0) {
          do {
            uVar8 = uVar8 - 1;
            *pbVar6 = pbVar6[-(((uint)bVar2 | uVar14 << 8) + 1)];
            pbVar6 = pbVar6 + 1;
            uVar11 = uVar12 - 1;
            bVar1 = 0 < (int)uVar12;
            uVar12 = uVar11;
          } while (uVar11 != 0 && bVar1);
        }
      }
      if (uVar8 == 0) goto LAB_0214d540;
      uVar10 = uVar10 << 1;
      bVar9 = (byte)uVar10;
      pbVar3 = pbVar4;
    }
    if (param_3 == 0) break;
    param_2 = pbVar3 + 1;
    bVar9 = *pbVar3;
    uVar7 = 8;
    param_3 = param_3 + -1;
  }
LAB_0214d540:
  *param_1 = pbVar6;
  param_1[1] = uVar8;
  *(byte *)((int)param_1 + 0xb) = bVar9;
  *(char *)(param_1 + 3) = (char)uVar7;
  *(char *)((int)param_1 + 0xd) = (char)uVar11;
  *(char *)((int)param_1 + 0xe) = cVar13;
  return uVar8;
}

