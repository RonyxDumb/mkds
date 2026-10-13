/* Decompiled C draft; module arm9; ROM address 0207b354. No matching claim. */
#include "types.h"
#include "deps/0207b354_func_0207b354.h"

void func_0207b354(int param_1)

{
  short sVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar12;
  
  uVar7 = param_1 + 0x590U & 3;
  uVar4 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  uVar4 = uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20;
  uVar7 = uVar4 + 0x28 & 3;
  uVar5 = *(uint *)(uVar4 + 0x28 & 0xfffffffc);
  if (uVar5 >> uVar7 * 8 == 0 && uVar5 << uVar7 * -8 + 0x20 == 0) {
    return;
  }
  *(short *)(uVar4 + 0x34) = *(short *)(uVar4 + 0x34) + -1;
  if (*(short *)(uVar4 + 0x34) < 1) {
    uVar7 = param_1 + 0x7cU & 3;
    uVar6 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    uVar5 = param_1 + 0x590U & 3;
    uVar9 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
    if ((((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x40) == 0) &&
       (uVar7 = (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) + 8, uVar5 = uVar7 & 3,
       uVar7 = *(uint *)(uVar7 & 0xfffffffc),
       sVar1 = *(short *)((uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) + 0x1a), sVar1 != 2)) {
      if (sVar1 == 0) {
        DriverContext_UpdateCharacterAnimation(param_1,2,1);
      }
    }
    else {
      DriverContext_UpdateCharacterAnimation(param_1,0,1);
    }
    uVar13 = *(uint *)(uRam0207b444 & 0xfffffffc) >> (uRam0207b444 & 3) * 8 |
             *(uint *)(uRam0207b444 & 0xfffffffc) << (uRam0207b444 & 3) * -8 + 0x20;
    iVar14 = uVar13 + iRam0207b448;
    uVar7 = iVar14 + 8U & 3;
    uVar5 = *(uint *)(iVar14 + 8U & 0xfffffffc);
    uVar10 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
    uVar7 = uVar13 + 0x498 & 3;
    uVar5 = *(uint *)(uVar13 + 0x498 & 0xfffffffc);
    uVar8 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
    uVar7 = iVar14 + 4U & 3;
    uVar9 = *(uint *)(iVar14 + 4U & 0xfffffffc);
    lVar2 = (ulonglong)uVar8 * (ulonglong)uVar10;
    uVar15 = (uint)lVar2;
    uVar5 = iVar14 + 0xcU & 3;
    uVar3 = *(uint *)(iVar14 + 0xcU & 0xfffffffc);
    uVar6 = iVar14 + 0x10U & 3;
    uVar11 = *(uint *)(iVar14 + 0x10U & 0xfffffffc);
    uVar12 = uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20;
    uVar6 = iVar14 + 0x14U & 3;
    uVar11 = *(uint *)(iVar14 + 0x14U & 0xfffffffc);
    *(uint *)(uVar13 + 0x498) = uVar12 + uVar15;
    *(uint *)(iVar14 + 4) =
         (uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) +
         (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) * uVar8 +
         uVar10 * (uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) +
         (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar12,uVar15);
    uVar7 = iVar14 + 4U & 3;
    uVar5 = *(uint *)(iVar14 + 4U & 0xfffffffc);
    *(short *)(uVar4 + 0x34) =
         (short)((ulonglong)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) * 200 >> 0x20);
    *(short *)(uVar4 + 0x34) = *(short *)(uVar4 + 0x34) + 0x96;
    return;
  }
  return;
}

