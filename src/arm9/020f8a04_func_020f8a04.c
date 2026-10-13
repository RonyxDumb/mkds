/* Decompiled C draft; module arm9; ROM address 020f8a04. No matching claim. */
#include "types.h"
#include "deps/020f8a04_func_020f8a04.h"

int func_020f8a04(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  uint uVar1;
  ushort uVar2;
  longlong lVar3;
  ushort *puVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  bool bVar27;
  int local_2c [2];
  uint uVar12;
  uint uVar26;
  
  local_2c[0] = 0x13;
  if (param_2 == 0) {
    bVar27 = param_4 != 0;
    if (bVar27) {
      param_4 = iRam020f8d64;
    }
    uVar5 = param_3 - 1;
    if (!bVar27) {
      param_4 = iRam020f8d68;
    }
  }
  else {
    uVar5 = param_2 - 1;
    param_1 = 0;
    param_4 = iRam020f8d60;
  }
  uVar13 = param_4 + 4U & 3;
  uVar14 = *(uint *)(param_4 + 4U & 0xfffffffc);
  uVar11 = (*(uint *)(uRam020f8d6c & 0xfffffffc) >> (uRam020f8d6c & 3) * 8 |
           *(uint *)(uRam020f8d6c & 0xfffffffc) << (uRam020f8d6c & 3) * -8 + 0x20) + 8;
  uVar12 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  uVar12 = uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20;
  uVar11 = 0;
  iVar15 = (uVar5 & 0xffff) * 0x24 + (uVar14 >> uVar13 * 8 | uVar14 << uVar13 * -8 + 0x20);
  iVar16 = 0;
  if (uVar12 != 4) {
    uVar12 = 0;
    do {
      iVar22 = uVar12 * 0x44 +
               (*(uint *)(uRam020f8d70 & 0xfffffffc) >> (uRam020f8d70 & 3) * 8 |
               *(uint *)(uRam020f8d70 & 0xfffffffc) << (uRam020f8d70 & 3) * -8 + 0x20);
      iVar18 = uVar12 * 0xa8;
      uVar5 = iVar22 + 0x1c;
      uVar13 = uVar5 & 3;
      uVar19 = *(uint *)(uVar5 & 0xfffffffc);
      uVar5 = iVar22 + 0x18;
      uVar14 = uVar5 & 3;
      uVar17 = *(uint *)(uVar5 & 0xfffffffc);
      uVar12 = uVar12 + 1;
      uVar5 = iVar18 + (*(uint *)(uRam020f8d74 & 0xfffffffc) >> (uRam020f8d74 & 3) * 8 |
                       *(uint *)(uRam020f8d74 & 0xfffffffc) << (uRam020f8d74 & 3) * -8 + 0x20) +
              0x90;
      uVar9 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      iVar16 = iVar16 + ((uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) *
                         ((uVar19 >> uVar13 * 8 | uVar19 << uVar13 * -8 + 0x20) -
                         (uVar17 >> uVar14 * 8 | uVar17 << uVar14 * -8 + 0x20)) & 0xffff);
    } while ((int)uVar12 < 0xe);
  }
  iVar18 = 0;
  if (0 < param_6) {
    uVar5 = uRam020f8d70 & 3;
    uVar19 = *(uint *)(uRam020f8d70 & 0xfffffffc);
    uVar13 = uRam020f8d74 & 3;
    uVar7 = *(uint *)(uRam020f8d74 & 0xfffffffc);
    uVar14 = uRam020f8d78 & 3;
    uVar24 = *(uint *)(uRam020f8d78 & 0xfffffffc);
    uVar12 = *(uint *)(uRam020f8d7c & 0xfffffffc) >> (uRam020f8d7c & 3) * 8 |
             *(uint *)(uRam020f8d7c & 0xfffffffc) << (uRam020f8d7c & 3) * -8 + 0x20;
    uVar9 = uRam020f8d80 & 3;
    uVar10 = *(uint *)(uRam020f8d80 & 0xfffffffc);
    uVar17 = uRam020f8d84 & 3;
    uVar23 = *(uint *)(uRam020f8d84 & 0xfffffffc);
    do {
      uVar8 = iVar18 * 0x1c + (uVar24 >> uVar14 * 8 | uVar24 << uVar14 * -8 + 0x20);
      uVar26 = uVar8 + 8 & 3;
      uVar25 = *(uint *)(uVar8 + 8 & 0xfffffffc);
      uVar26 = uVar25 >> uVar26 * 8 | uVar25 << uVar26 * -8 + 0x20;
      if ((((iVar18 != 8) || ((int)uVar12 < 1)) &&
          ((iVar18 != 7 || ((int)(uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20) < 1)))) &&
         (((((iVar18 != 0xf || ((int)(uVar23 >> uVar17 * 8 | uVar23 << uVar17 * -8 + 0x20) < 1)) &&
            (iVar22 = uVar26 * 0x44 + (uVar19 >> uVar5 * 8 | uVar19 << uVar5 * -8 + 0x20),
            uVar25 = iVar22 + 0x20, uVar21 = uVar25 & 3, uVar20 = *(uint *)(uVar25 & 0xfffffffc),
            uVar25 = iVar22 + 0x1c, uVar1 = uVar25 & 3, uVar25 = *(uint *)(uVar25 & 0xfffffffc),
            0 < (int)((uVar20 >> uVar21 * 8 | uVar20 << uVar21 * -8 + 0x20) -
                     (uVar25 >> uVar1 * 8 | uVar25 << uVar1 * -8 + 0x20)))) &&
           (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 != 0 ||
            *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20 != 0)) &&
          ((uVar25 = uVar8 + 0xc & 3, uVar21 = *(uint *)(uVar8 + 0xc & 0xfffffffc),
           uVar26 = uVar26 * 0xa8 + (uVar7 >> uVar13 * 8 | uVar7 << uVar13 * -8 + 0x20) + 0x90,
           uVar8 = uVar26 & 3, uVar26 = *(uint *)(uVar26 & 0xfffffffc),
           iVar22 = (uVar26 >> uVar8 * 8 | uVar26 << uVar8 * -8 + 0x20) *
                    (uVar21 >> uVar25 * 8 | uVar21 << uVar25 * -8 + 0x20), iVar22 == 0 ||
           (iVar22 + iVar16 < 0x29)))))) {
        if ((iVar18 < 9) || (param_1 == 0)) {
          uVar11 = uVar11 + *(ushort *)(iVar15 + iVar18 * 2) & 0xffff;
        }
        else if (param_1 == 1) {
          uVar11 = uVar11 + ((int)(uint)*(ushort *)(iVar15 + iVar18 * 2) >> 2) & 0xffff;
        }
        else {
          uVar11 = (uint)*(ushort *)(iVar15 + iVar18 * 2) * 3 + uVar11 & 0xffff;
        }
      }
      iVar22 = iVar18 * 2;
      iVar18 = iVar18 + 1;
      *(short *)(iRam020f8d88 + iVar22) = (short)uVar11;
    } while (iVar18 < param_6);
  }
  uVar5 = *(uint *)(uRam020f8d8c & 0xfffffffc) >> (uRam020f8d8c & 3) * 8 |
          *(uint *)(uRam020f8d8c & 0xfffffffc) << (uRam020f8d8c & 3) * -8 + 0x20;
  if (uVar11 == 0) {
    uVar12 = 0;
  }
  lVar3 = CONCAT44(uVar12,uVar5);
  piVar6 = (int *)(uVar5 + iRam020f8d90);
  if (uVar11 != 0) {
    uVar5 = (uint)(piVar6 + 2) & 3;
    uVar13 = *(uint *)((uint)(piVar6 + 2) & 0xfffffffc);
    uVar7 = uVar13 >> uVar5 * 8 | uVar13 << uVar5 * -8 + 0x20;
    uVar19 = *(uint *)((uint)piVar6 & 0xfffffffc) >> ((uint)piVar6 & 3) * 8 |
             *(uint *)((uint)piVar6 & 0xfffffffc) << ((uint)piVar6 & 3) * -8 + 0x20;
    uVar5 = (uint)(piVar6 + 1) & 3;
    uVar14 = *(uint *)((uint)(piVar6 + 1) & 0xfffffffc);
    lVar3 = (ulonglong)uVar19 * (ulonglong)uVar7;
    uVar23 = (uint)lVar3;
    uVar13 = (uint)(piVar6 + 3) & 3;
    uVar9 = *(uint *)((uint)(piVar6 + 3) & 0xfffffffc);
    uVar12 = (uint)(piVar6 + 4) & 3;
    uVar17 = *(uint *)((uint)(piVar6 + 4) & 0xfffffffc);
    uVar10 = uVar17 >> uVar12 * 8 | uVar17 << uVar12 * -8 + 0x20;
    uVar12 = (uint)(piVar6 + 5) & 3;
    uVar17 = *(uint *)((uint)(piVar6 + 5) & 0xfffffffc);
    iVar16 = uVar10 + uVar23;
    iVar18 = (uVar17 >> uVar12 * 8 | uVar17 << uVar12 * -8 + 0x20) +
             (uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20) * uVar19 +
             uVar7 * (uVar14 >> uVar5 * 8 | uVar14 << uVar5 * -8 + 0x20) +
             (int)((ulonglong)lVar3 >> 0x20) + (uint)CARRY4(uVar10,uVar23);
    *piVar6 = iVar16;
    bVar27 = uVar11 == 0;
    piVar6[1] = iVar18;
    if (bVar27) {
      uVar5 = (uint)(piVar6 + 1) & 3;
      uVar13 = *(uint *)((uint)(piVar6 + 1) & 0xfffffffc);
      uVar10 = uVar13 >> uVar5 * 8 | uVar13 << uVar5 * -8 + 0x20;
    }
    lVar3 = CONCAT44(uVar10,iVar18);
    if (!bVar27) {
      uVar5 = (uint)(piVar6 + 1) & 3;
      uVar13 = *(uint *)((uint)(piVar6 + 1) & 0xfffffffc);
      piVar6 = (int *)(uVar13 >> uVar5 * 8 | uVar13 << uVar5 * -8 + 0x20);
      iVar16 = 0;
      lVar3 = (ulonglong)uVar11 * ZEXT48(piVar6);
    }
    if (!bVar27) {
      lVar3 = CONCAT44(iVar16 * uVar11 + (int)piVar6 * iVar16 + (int)((ulonglong)lVar3 >> 0x20),
                       (int)lVar3);
    }
  }
  iVar22 = 0;
  iVar16 = (int)lVar3;
  iVar18 = local_2c[0];
  if (0 < param_6) {
    do {
      iVar16 = iRam020f8d88;
      iVar18 = iVar22;
      if (((uint)((ulonglong)lVar3 >> 0x20) & 0xffff) < (uint)*(ushort *)(iRam020f8d88 + iVar22 * 2)
         ) break;
      iVar22 = iVar22 + 1;
      iVar18 = local_2c[0];
    } while (iVar22 < param_6);
  }
  local_2c[0] = iVar18;
  iVar16 = func_020fab34(local_2c,iVar16);
  if (iVar16 != 0) {
    func_020faa78(local_2c[0]);
  }
  puVar4 = puRam020f8d94;
  if (param_5 != 0) {
    if (param_2 == 0) {
      *puRam020f8d94 = 0;
    }
    else {
      iVar18 = 0;
      *puRam020f8d94 = 0;
      iVar16 = iRam020f8d98;
      if (0 < param_6) {
        do {
          if ((iVar18 == local_2c[0]) || (*(short *)(iVar15 + iVar18 * 2) != 0)) {
            uVar2 = *puVar4;
            *puVar4 = uVar2 + 1;
            *(int *)(iVar16 + (uint)uVar2 * 4) = iVar18;
          }
          iVar18 = iVar18 + 1;
        } while (iVar18 < param_6);
      }
    }
  }
  return local_2c[0];
}

