/* Decompiled C draft; module arm9; ROM address 02095228. No matching claim. */
#include "types.h"
#include "deps/02095228_func_02095228.h"

void func_02095228(uint param_1)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar16;
  int iVar17;
  uint uVar7;
  uint uVar15;
  
  iVar5 = iRam020952d8;
  uVar4 = uRam020952d4;
  if (param_1 == 0) {
    return;
  }
  iVar17 = 0;
  while( true ) {
    if ((int)(uint)*(ushort *)(param_1 + 4) <= iVar17) {
      return;
    }
    uVar9 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + iVar17 * 4;
    uVar2 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    uVar9 = uVar9 >> uVar2 * 8 | uVar9 << uVar2 * -8 + 0x20;
    if (uVar9 == 0) break;
    uVar2 = uVar4 & 3;
    uVar6 = *(uint *)(uVar4 & 0xfffffffc);
    uVar7 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
    iVar8 = uVar7 + iVar5;
    uVar2 = iVar8 + 8U & 3;
    uVar6 = *(uint *)(iVar8 + 8U & 0xfffffffc);
    uVar13 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
    uVar2 = uVar7 + 0x498 & 3;
    uVar6 = *(uint *)(uVar7 + 0x498 & 0xfffffffc);
    uVar12 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
    uVar2 = iVar8 + 4U & 3;
    uVar10 = *(uint *)(iVar8 + 4U & 0xfffffffc);
    lVar3 = (ulonglong)uVar12 * (ulonglong)uVar13;
    uVar16 = (uint)lVar3;
    uVar6 = iVar8 + 0xcU & 3;
    uVar11 = *(uint *)(iVar8 + 0xcU & 0xfffffffc);
    uVar1 = iVar8 + 0x10U & 3;
    uVar14 = *(uint *)(iVar8 + 0x10U & 0xfffffffc);
    uVar15 = uVar14 >> uVar1 * 8 | uVar14 << uVar1 * -8 + 0x20;
    uVar1 = iVar8 + 0x14U & 3;
    uVar14 = *(uint *)(iVar8 + 0x14U & 0xfffffffc);
    *(uint *)(uVar7 + 0x498) = uVar15 + uVar16;
    *(uint *)(iVar8 + 4) =
         (uVar14 >> uVar1 * 8 | uVar14 << uVar1 * -8 + 0x20) +
         (uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) * uVar12 +
         uVar13 * (uVar10 >> uVar2 * 8 | uVar10 << uVar2 * -8 + 0x20) +
         (int)((ulonglong)lVar3 >> 0x20) + (uint)CARRY4(uVar15,uVar16);
    uVar2 = iVar8 + 4U & 3;
    uVar6 = *(uint *)(iVar8 + 4U & 0xfffffffc);
    *(int *)(uVar9 + 0xa0) =
         (int)((ulonglong)(uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) * 0xf >> 0x20);
    iVar17 = iVar17 + 1;
  }
  return;
}

