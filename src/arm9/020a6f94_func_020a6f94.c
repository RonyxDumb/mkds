/* Decompiled C draft; module arm9; ROM address 020a6f94. No matching claim. */
#include "types.h"
#include "deps/020a6f94_func_020a6f94.h"

undefined4 func_020a6f94(uint param_1)

{
  longlong lVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  bool bVar16;
  uint uVar15;
  
  uVar13 = 0;
  if (param_1 != 0) {
    iVar9 = 0;
    while ((iVar9 < (int)(uint)*(ushort *)(param_1 + 4) &&
           (uVar10 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                     *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + iVar9 * 4,
           uVar14 = uVar10 & 3, uVar10 = *(uint *)(uVar10 & 0xfffffffc),
           uVar10 = uVar10 >> uVar14 * 8 | uVar10 << uVar14 * -8 + 0x20, uVar10 != 0))) {
      uVar14 = uVar10 + 0xa0 & 3;
      uVar3 = *(uint *)(uVar10 + 0xa0 & 0xfffffffc);
      iVar8 = 0;
      if ((uVar3 >> uVar14 * 8 == 0 && uVar3 << uVar14 * -8 + 0x20 == 0) &&
         (uVar14 = uVar10 + 0xa4 & 3, uVar10 = *(uint *)(uVar10 + 0xa4 & 0xfffffffc),
         uVar10 >> uVar14 * 8 == 0 && uVar10 << uVar14 * -8 + 0x20 == 0)) {
        iVar8 = 1;
      }
      uVar13 = uVar13 + iVar8;
      iVar9 = iVar9 + 1;
    }
  }
  if (0 < (int)uVar13) {
    uVar13 = uVar13 & 0xffff;
    if (uVar13 == 0x10000) {
      piVar2 = (int *)func_020d22d0();
      uVar13 = (uint)(piVar2 + 2) & 3;
      uVar10 = *(uint *)((uint)(piVar2 + 2) & 0xfffffffc);
      uVar6 = uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20;
      uVar4 = *(uint *)((uint)piVar2 & 0xfffffffc) >> ((uint)piVar2 & 3) * 8 |
              *(uint *)((uint)piVar2 & 0xfffffffc) << ((uint)piVar2 & 3) * -8 + 0x20;
      uVar13 = (uint)(piVar2 + 1) & 3;
      uVar3 = *(uint *)((uint)(piVar2 + 1) & 0xfffffffc);
      lVar1 = (ulonglong)uVar4 * (ulonglong)uVar6;
      uVar11 = (uint)lVar1;
      uVar10 = (uint)(piVar2 + 4) & 3;
      uVar14 = *(uint *)((uint)(piVar2 + 4) & 0xfffffffc);
      uVar15 = uVar14 >> uVar10 * 8 | uVar14 << uVar10 * -8 + 0x20;
      uVar10 = (uint)(piVar2 + 3) & 3;
      uVar7 = *(uint *)((uint)(piVar2 + 3) & 0xfffffffc);
      uVar14 = (uint)(piVar2 + 5) & 3;
      uVar5 = *(uint *)((uint)(piVar2 + 5) & 0xfffffffc);
      *piVar2 = uVar15 + uVar11;
      piVar2[1] = (uVar5 >> uVar14 * 8 | uVar5 << uVar14 * -8 + 0x20) +
                  (uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20) * uVar4 +
                  uVar6 * (uVar3 >> uVar13 * 8 | uVar3 << uVar13 * -8 + 0x20) +
                  (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar15,uVar11);
      uVar13 = (uint)(piVar2 + 1) & 3;
      uVar10 = *(uint *)((uint)(piVar2 + 1) & 0xfffffffc);
      uVar13 = (uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) >> 0x10;
    }
    else {
      piVar2 = (int *)func_020d22d0();
      if (uVar13 == 0) {
        uVar13 = 0;
      }
      else {
        uVar10 = (uint)(piVar2 + 2) & 3;
        uVar14 = *(uint *)((uint)(piVar2 + 2) & 0xfffffffc);
        uVar15 = uVar14 >> uVar10 * 8 | uVar14 << uVar10 * -8 + 0x20;
        uVar7 = *(uint *)((uint)piVar2 & 0xfffffffc) >> ((uint)piVar2 & 3) * 8 |
                *(uint *)((uint)piVar2 & 0xfffffffc) << ((uint)piVar2 & 3) * -8 + 0x20;
        uVar10 = (uint)(piVar2 + 1) & 3;
        uVar4 = *(uint *)((uint)(piVar2 + 1) & 0xfffffffc);
        lVar1 = (ulonglong)uVar7 * (ulonglong)uVar15;
        uVar11 = (uint)lVar1;
        uVar14 = (uint)(piVar2 + 3) & 3;
        uVar5 = *(uint *)((uint)(piVar2 + 3) & 0xfffffffc);
        uVar3 = (uint)(piVar2 + 4) & 3;
        uVar6 = *(uint *)((uint)(piVar2 + 4) & 0xfffffffc);
        uVar12 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
        uVar3 = (uint)(piVar2 + 5) & 3;
        uVar6 = *(uint *)((uint)(piVar2 + 5) & 0xfffffffc);
        *piVar2 = uVar12 + uVar11;
        piVar2[1] = (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) +
                    (uVar5 >> uVar14 * 8 | uVar5 << uVar14 * -8 + 0x20) * uVar7 +
                    uVar15 * (uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20) +
                    (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar12,uVar11);
        if (uVar13 == 0) {
          uVar13 = (uint)(piVar2 + 1) & 3;
          uVar10 = *(uint *)((uint)(piVar2 + 1) & 0xfffffffc);
          uVar13 = uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20;
        }
        else {
          uVar10 = (uint)(piVar2 + 1) & 3;
          uVar14 = *(uint *)((uint)(piVar2 + 1) & 0xfffffffc);
          uVar13 = (uint)((ulonglong)uVar13 *
                          (ulonglong)(uVar14 >> uVar10 * 8 | uVar14 << uVar10 * -8 + 0x20) >> 0x20);
        }
      }
      uVar13 = uVar13 & 0xffff;
    }
    if (param_1 != 0) {
      iVar9 = 0;
      while ((iVar9 < (int)(uint)*(ushort *)(param_1 + 4) &&
             (uVar10 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                       *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + iVar9 * 4,
             uVar14 = uVar10 & 3, uVar10 = *(uint *)(uVar10 & 0xfffffffc),
             uVar10 = uVar10 >> uVar14 * 8 | uVar10 << uVar14 * -8 + 0x20, uVar10 != 0))) {
        uVar14 = uVar10 + 0xa0 & 3;
        uVar3 = *(uint *)(uVar10 + 0xa0 & 0xfffffffc);
        if ((uVar3 >> uVar14 * 8 == 0 && uVar3 << uVar14 * -8 + 0x20 == 0) &&
           ((uVar14 = uVar10 + 0xa4 & 3, uVar3 = *(uint *)(uVar10 + 0xa4 & 0xfffffffc),
            uVar3 >> uVar14 * 8 == 0 && uVar3 << uVar14 * -8 + 0x20 == 0 &&
            (bVar16 = uVar13 == 0, uVar13 = uVar13 - 1, bVar16)))) {
          func_020a5744(uVar10 + 4,iVar9,1);
          *(undefined4 *)(uVar10 + 0xa0) = 1;
          return 1;
        }
        iVar9 = iVar9 + 1;
      }
    }
  }
  return 0;
}

