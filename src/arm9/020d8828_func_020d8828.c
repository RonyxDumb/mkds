/* Decompiled C draft; module arm9; ROM address 020d8828. No matching claim. */
#include "types.h"
#include "deps/020d8828_func_020d8828.h"

uint func_020d8828(uint param_1,uint param_2)

{
  longlong lVar1;
  longlong lVar2;
  ushort *puVar3;
  longlong *plVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  bool bVar16;
  
  plVar4 = plRam020d88f4;
  puVar3 = puRam020d88f0;
  uVar11 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
           *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar6 = uVar11 + 4 & 3;
  uVar5 = *(uint *)(uVar11 + 4 & 0xfffffffc);
  lVar2 = 0;
  iVar13 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) - 1;
  if (-1 < iVar13) {
    uVar12 = iVar13 * 0x54 +
             (*(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
             *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20);
    uVar11 = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
             *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
    uVar6 = param_2 + 8 & 3;
    uVar5 = *(uint *)(param_2 + 8 & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    lVar2 = 0;
    do {
      iVar15 = (int)((ulonglong)lVar2 >> 0x20);
      uVar5 = uVar12 + 8 & 3;
      uVar7 = *(uint *)(uVar12 + 8 & 0xfffffffc);
      iVar8 = uVar6 - (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
      iVar9 = uVar11 - (*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
                       *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20);
      lVar1 = (longlong)iVar9 * (longlong)iVar9 + (longlong)iVar8 * (longlong)iVar8;
      iVar9 = (int)((ulonglong)lVar1 >> 0x20);
      bVar16 = (uint)lVar2 < (uint)lVar1;
      uVar5 = uVar12 + 0x2c & 3;
      uVar10 = *(uint *)(uVar12 + 0x2c & 0xfffffffc);
      uVar7 = uVar12 + 0x24 & 3;
      uVar14 = *(uint *)(uVar12 + 0x24 & 0xfffffffc);
      iVar8 = uVar6 - (uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20);
      if ((int)(iVar15 - (iVar9 + (uint)bVar16)) < 0 !=
          (SBORROW4(iVar15,iVar9) != SBORROW4(iVar15 - iVar9,(uint)bVar16))) {
        lVar2 = lVar1;
      }
      iVar15 = (int)((ulonglong)lVar2 >> 0x20);
      iVar9 = uVar11 - (uVar14 >> uVar7 * 8 | uVar14 << uVar7 * -8 + 0x20);
      lVar1 = (longlong)iVar9 * (longlong)iVar9 + (longlong)iVar8 * (longlong)iVar8;
      iVar8 = (int)((ulonglong)lVar1 >> 0x20);
      bVar16 = (uint)lVar2 < (uint)lVar1;
      if ((int)(iVar15 - (iVar8 + (uint)bVar16)) < 0 !=
          (SBORROW4(iVar15,iVar8) != SBORROW4(iVar15 - iVar8,(uint)bVar16))) {
        lVar2 = lVar1;
      }
      uVar12 = uVar12 - 0x54;
      iVar13 = iVar13 + -1;
    } while (-1 < iVar13);
  }
  *puRam020d88f0 = 1;
  *plVar4 = lVar2;
  do {
  } while ((*puVar3 & 0x8000) != 0);
  return *(uint *)(uRam020d88f8 & 0xfffffffc) >> (uRam020d88f8 & 3) * 8 |
         *(uint *)(uRam020d88f8 & 0xfffffffc) << (uRam020d88f8 & 3) * -8 + 0x20;
}

