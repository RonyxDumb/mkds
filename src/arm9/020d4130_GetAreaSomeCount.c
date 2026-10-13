/* Decompiled C draft; module arm9; ROM address 020d4130. No matching claim. */
#include "types.h"
#include "deps/020d4130_GetAreaSomeCount.h"

int GetAreaSomeCount(uint param_1,int param_2,uint param_3)

{
  short sVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  bool bVar15;
  ushort *puVar8;
  
  iVar10 = 0;
  func_020d5180(param_1,param_2,0x2000);
  uVar4 = uRam020d41dc;
  uVar3 = uRam020d41d8;
  iVar14 = 0;
  sVar1 = *psRam020d41d4;
  if (0 < sVar1) {
    iVar9 = (int)((ulonglong)((longlong)param_2 * (longlong)param_2) >> 0x20);
    do {
      uVar7 = uVar4 & 3;
      uVar5 = *(uint *)(uVar4 & 0xfffffffc);
      uVar7 = (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) + iVar14 * 4;
      uVar5 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      puVar8 = (ushort *)(uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
      if ((*puVar8 == param_3) &&
         (uVar7 = param_1 + 8 & 3, uVar12 = *(uint *)(param_1 + 8 & 0xfffffffc),
         uVar5 = (uint)(puVar8 + 6) & 3, uVar11 = *(uint *)((uint)(puVar8 + 6) & 0xfffffffc),
         iVar13 = (uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20) -
                  (uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20),
         uVar7 = (uint)(puVar8 + 2) & 3, uVar5 = *(uint *)((uint)(puVar8 + 2) & 0xfffffffc),
         iVar6 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                 *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) -
                 (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20),
         lVar2 = (longlong)iVar6 * (longlong)iVar6 + (longlong)iVar13 * (longlong)iVar13,
         iVar6 = (int)((ulonglong)lVar2 >> 0x20),
         bVar15 = (uint)lVar2 < (uint)((longlong)param_2 * (longlong)param_2),
         (int)(iVar6 - (iVar9 + (uint)bVar15)) < 0 !=
         (SBORROW4(iVar6,iVar9) != SBORROW4(iVar6 - iVar9,(uint)bVar15)))) {
        uVar7 = uVar3 & 3;
        uVar5 = *(uint *)(uVar3 & 0xfffffffc);
        *(ushort **)((uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) + iVar10 * 4) = puVar8;
        iVar10 = iVar10 + 1;
      }
      iVar14 = iVar14 + 1;
    } while (iVar14 < sVar1);
  }
  return iVar10;
}

