/* Decompiled C draft; module arm9; ROM address 0209e988. No matching claim. */
#include "types.h"
#include "deps/0209e988_func_0209e988.h"

undefined4 func_0209e988(int param_1,uint param_2,int param_3)

{
  ushort *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  bool bVar17;
  
  puVar1 = (ushort *)(param_1 + 0xa0);
  iVar9 = 0;
  if (*puVar1 != 0) {
    lVar6 = (longlong)(param_3 + 0xf000) * (longlong)(param_3 + 0xf000);
    iVar8 = (int)((ulonglong)lVar6 >> 0x20);
    uVar2 = param_2 + 4 & 3;
    uVar16 = *(uint *)(param_2 + 4 & 0xfffffffc);
    uVar3 = param_2 + 8 & 3;
    uVar7 = *(uint *)(param_2 + 8 & 0xfffffffc);
    do {
      uVar4 = param_1 + 200U & 3;
      uVar10 = *(uint *)(param_1 + 200U & 0xfffffffc);
      uVar13 = param_1 + 0xc4U & 3;
      uVar15 = *(uint *)(param_1 + 0xc4U & 0xfffffffc);
      iVar11 = (uVar16 >> uVar2 * 8 | uVar16 << uVar2 * -8 + 0x20) -
               (uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20);
      iVar12 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
               *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) -
               (uVar15 >> uVar13 * 8 | uVar15 << uVar13 * -8 + 0x20);
      uVar4 = param_1 + 0xccU & 3;
      uVar13 = *(uint *)(param_1 + 0xccU & 0xfffffffc);
      iVar14 = (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) -
               (uVar13 >> uVar4 * 8 | uVar13 << uVar4 * -8 + 0x20);
      lVar5 = (longlong)iVar14 * (longlong)iVar14 +
              (longlong)iVar12 * (longlong)iVar12 + (longlong)iVar11 * (longlong)iVar11;
      iVar11 = (int)((ulonglong)lVar5 >> 0x20);
      bVar17 = (uint)lVar5 < (uint)lVar6;
      if ((int)(iVar11 - (iVar8 + (uint)bVar17)) < 0 !=
          (SBORROW4(iVar11,iVar8) != SBORROW4(iVar11 - iVar8,(uint)bVar17))) {
        return 1;
      }
      iVar9 = iVar9 + 1;
      param_1 = param_1 + 0x140;
    } while (iVar9 < (int)(uint)*puVar1);
  }
  return 0;
}

