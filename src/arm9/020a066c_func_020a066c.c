/* Decompiled C draft; module arm9; ROM address 020a066c. No matching claim. */
#include "types.h"
#include "deps/020a066c_func_020a066c.h"

void func_020a066c(uint param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar15;
  uint uVar8;
  uint uVar14;
  
  if (param_1 == 0) {
    return;
  }
  iVar12 = 0;
  while( true ) {
    if ((int)(uint)*(ushort *)(param_1 + 4) <= iVar12) {
      return;
    }
    uVar11 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
             *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + iVar12 * 4;
    uVar3 = uVar11 & 3;
    uVar11 = *(uint *)(uVar11 & 0xfffffffc);
    uVar11 = uVar11 >> uVar3 * 8 | uVar11 << uVar3 * -8 + 0x20;
    if (uVar11 == 0) break;
    uVar2 = *(uint *)(uRam020a0880 & 0xfffffffc) >> (uRam020a0880 & 3) * 8 |
            *(uint *)(uRam020a0880 & 0xfffffffc) << (uRam020a0880 & 3) * -8 + 0x20;
    uVar3 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    if (uVar3 == 0x12) {
      *(undefined4 *)(uVar11 + 0xa8) = uRam020a0884;
      uVar3 = uVar11 + 4 & 3;
      uVar2 = *(uint *)(uVar11 + 4 & 0xfffffffc);
      *(uint *)(uVar11 + 0xac) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + iRam020a0888;
      uVar3 = uVar11 + 8 & 3;
      uVar2 = *(uint *)(uVar11 + 8 & 0xfffffffc);
      *(uint *)(uVar11 + 0xb0) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      uVar3 = uVar11 + 0xc & 3;
      uVar2 = *(uint *)(uVar11 + 0xc & 0xfffffffc);
      *(uint *)(uVar11 + 0xb4) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0xfec00000;
      *(undefined4 *)(uVar11 + 0xb8) = 1;
    }
    else if (uVar3 == 0x1f) {
      *(undefined4 *)(uVar11 + 0xa8) = uRam020a088c;
      uVar3 = uVar11 + 4 & 3;
      uVar2 = *(uint *)(uVar11 + 4 & 0xfffffffc);
      *(uint *)(uVar11 + 0xac) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + iRam020a0890;
      uVar3 = uVar11 + 8 & 3;
      uVar2 = *(uint *)(uVar11 + 8 & 0xfffffffc);
      *(uint *)(uVar11 + 0xb0) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      uVar3 = uVar11 + 0xc & 3;
      uVar2 = *(uint *)(uVar11 + 0xc & 0xfffffffc);
      *(uint *)(uVar11 + 0xb4) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) - 0x32000;
      *(undefined4 *)(uVar11 + 0xb8) = 0;
    }
    else {
      *(undefined4 *)(uVar11 + 0xa8) = uRam020a0884;
      uVar3 = uVar11 + 4 & 3;
      uVar2 = *(uint *)(uVar11 + 4 & 0xfffffffc);
      *(uint *)(uVar11 + 0xac) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      uVar3 = uVar11 + 8 & 3;
      uVar2 = *(uint *)(uVar11 + 8 & 0xfffffffc);
      *(uint *)(uVar11 + 0xb0) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      uVar3 = uVar11 + 0xc & 3;
      uVar2 = *(uint *)(uVar11 + 0xc & 0xfffffffc);
      *(uint *)(uVar11 + 0xb4) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      *(undefined4 *)(uVar11 + 0xb8) = 0;
    }
    uVar9 = *(uint *)(uRam020a0894 & 0xfffffffc) >> (uRam020a0894 & 3) * 8 |
            *(uint *)(uRam020a0894 & 0xfffffffc) << (uRam020a0894 & 3) * -8 + 0x20;
    uVar3 = uVar9 + 0x498 & 3;
    uVar2 = *(uint *)(uVar9 + 0x498 & 0xfffffffc);
    uVar15 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    iVar10 = uVar9 + iRam020a0898;
    uVar3 = iVar10 + 0xcU & 3;
    uVar4 = *(uint *)(iVar10 + 0xcU & 0xfffffffc);
    uVar2 = iVar10 + 8U & 3;
    uVar13 = *(uint *)(iVar10 + 8U & 0xfffffffc);
    uVar14 = uVar13 >> uVar2 * 8 | uVar13 << uVar2 * -8 + 0x20;
    uVar2 = iVar10 + 4U & 3;
    uVar5 = *(uint *)(iVar10 + 4U & 0xfffffffc);
    lVar1 = (ulonglong)uVar15 * (ulonglong)uVar14;
    uVar6 = (uint)lVar1;
    uVar13 = iVar10 + 0x10U & 3;
    uVar7 = *(uint *)(iVar10 + 0x10U & 0xfffffffc);
    uVar8 = uVar7 >> uVar13 * 8 | uVar7 << uVar13 * -8 + 0x20;
    uVar13 = iVar10 + 0x14U & 3;
    uVar7 = *(uint *)(iVar10 + 0x14U & 0xfffffffc);
    *(uint *)(uVar9 + 0x498) = uVar8 + uVar6;
    *(uint *)(iVar10 + 4) =
         (uVar7 >> uVar13 * 8 | uVar7 << uVar13 * -8 + 0x20) +
         (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) * uVar15 +
         uVar14 * (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) +
         (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar8,uVar6);
    uVar3 = iVar10 + 4U & 3;
    uVar2 = *(uint *)(iVar10 + 4U & 0xfffffffc);
    *(int *)(uVar11 + 200) =
         (int)((ulonglong)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) * 0x3c >> 0x20) + 600;
    iVar12 = iVar12 + 1;
    *(undefined4 *)(uVar11 + 0xa4) = 0x7f000;
    uVar14 = *(uint *)(uRam020a0894 & 0xfffffffc) >> (uRam020a0894 & 3) * 8 |
             *(uint *)(uRam020a0894 & 0xfffffffc) << (uRam020a0894 & 3) * -8 + 0x20;
    uVar3 = uVar14 + 0x498 & 3;
    uVar2 = *(uint *)(uVar14 + 0x498 & 0xfffffffc);
    uVar15 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    iVar10 = uVar14 + iRam020a0898;
    uVar3 = iVar10 + 8U & 3;
    uVar2 = *(uint *)(iVar10 + 8U & 0xfffffffc);
    uVar6 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    uVar3 = iVar10 + 4U & 3;
    uVar4 = *(uint *)(iVar10 + 4U & 0xfffffffc);
    lVar1 = (ulonglong)uVar15 * (ulonglong)uVar6;
    uVar7 = (uint)lVar1;
    uVar2 = iVar10 + 0xcU & 3;
    uVar5 = *(uint *)(iVar10 + 0xcU & 0xfffffffc);
    uVar13 = iVar10 + 0x10U & 3;
    uVar8 = *(uint *)(iVar10 + 0x10U & 0xfffffffc);
    uVar9 = uVar8 >> uVar13 * 8 | uVar8 << uVar13 * -8 + 0x20;
    uVar13 = iVar10 + 0x14U & 3;
    uVar8 = *(uint *)(iVar10 + 0x14U & 0xfffffffc);
    *(uint *)(uVar14 + 0x498) = uVar9 + uVar7;
    *(uint *)(iVar10 + 4) =
         (uVar8 >> uVar13 * 8 | uVar8 << uVar13 * -8 + 0x20) +
         (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) * uVar15 +
         uVar6 * (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + (int)((ulonglong)lVar1 >> 0x20)
         + (uint)CARRY4(uVar9,uVar7);
    uVar3 = iVar10 + 4U & 3;
    uVar2 = *(uint *)(iVar10 + 4U & 0xfffffffc);
    *(int *)(uVar11 + 0xc0) =
         (int)((ulonglong)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) * 0xf >> 0x20);
  }
  return;
}

