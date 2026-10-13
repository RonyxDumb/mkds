/* Decompiled C draft; module arm9; ROM address 020f371c. No matching claim. */
#include "types.h"
#include "deps/020f371c_func_020f371c.h"

void func_020f371c(uint param_1,uint *param_2,uint param_3,int param_4)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  longlong lVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint unaff_r8;
  uint uVar17;
  uint uVar18;
  uint uVar20;
  bool bVar21;
  uint local_40;
  uint local_3c;
  uint local_38;
  int local_2c;
  uint local_28;
  uint uVar19;
  
  uVar14 = param_1 + 4 & 3;
  uVar12 = *(uint *)(param_1 + 4 & 0xfffffffc);
  local_40 = uVar12 >> uVar14 * 8 | uVar12 << uVar14 * -8 + 0x20;
  uVar14 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
           *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (local_40 == 0) {
    uVar3 = *(ushort *)(uVar14 + 0x26);
    uVar12 = uVar14 + 0xc & 3;
    uVar13 = *(uint *)(uVar14 + 0xc & 0xfffffffc);
    uVar12 = uVar13 >> uVar12 * 8 | uVar13 << uVar12 * -8 + 0x20;
  }
  else {
    uVar3 = *(ushort *)(uVar14 + 0x24);
    uVar12 = *(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
             *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20;
  }
  local_38 = (uint)uVar3;
  if (local_38 < 2) {
    if (local_40 == 0) {
      uVar3 = *(ushort *)(uVar12 + 0x24);
    }
    else {
      uVar3 = *(ushort *)(uVar12 + 0x26);
    }
    uVar13 = uVar12;
    if (uVar3 < 2) goto LAB_020f3778;
  }
  uVar13 = uVar14 + 0x18 & 3;
  uVar6 = *(uint *)(uVar14 + 0x18 & 0xfffffffc);
  uVar6 = uVar6 >> uVar13 * 8 | uVar6 << uVar13 * -8 + 0x20;
  bVar5 = false;
  local_2c = iRam020f3a50;
  if (param_3 < 8) {
    iVar7 = GetDriverEntry(param_3);
    unaff_r8 = iVar7 + 0x98;
    uVar13 = iVar7 + 0xa0U & 3;
    uVar11 = *(uint *)(iVar7 + 0xa0U & 0xfffffffc);
    uVar17 = uVar6 + 8 & 3;
    uVar9 = *(uint *)(uVar6 + 8 & 0xfffffffc);
    uVar16 = iVar7 + 0x98U & 3;
    uVar15 = *(uint *)(iVar7 + 0x98U & 0xfffffffc);
    iVar10 = (uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20) -
             (uVar9 >> uVar17 * 8 | uVar9 << uVar17 * -8 + 0x20);
    iVar8 = (uVar15 >> uVar16 * 8 | uVar15 << uVar16 * -8 + 0x20) -
            (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20);
    lVar4 = (longlong)iVar8 * (longlong)iVar8 + (longlong)iVar10 * (longlong)iVar10;
    iVar8 = (int)((ulonglong)lVar4 >> 0x20);
    bVar21 = (uint)lVar4 < 0x10000000;
    if ((int)(iVar8 - (iRam020f3a54 + (uint)bVar21)) < 0 !=
        (SBORROW4(iVar8,iRam020f3a54) != SBORROW4(iVar8 - iRam020f3a54,(uint)bVar21))) {
      iVar8 = 0;
      bVar5 = true;
      if (local_38 != 0) {
        do {
          if (local_40 == 0) {
            uVar13 = uVar14 + iVar8 * 4 + 0xc;
            uVar17 = uVar13 & 3;
            uVar13 = *(uint *)(uVar13 & 0xfffffffc);
            uVar13 = uVar13 >> uVar17 * 8 | uVar13 << uVar17 * -8 + 0x20;
          }
          else {
            uVar13 = uVar14 + iVar8 * 4;
            uVar17 = uVar13 & 3;
            uVar13 = *(uint *)(uVar13 & 0xfffffffc);
            uVar13 = uVar13 >> uVar17 * 8 | uVar13 << uVar17 * -8 + 0x20;
          }
          if (uVar13 != 0) {
            uVar17 = uVar13 + 0x18 & 3;
            uVar16 = *(uint *)(uVar13 + 0x18 & 0xfffffffc);
            uVar15 = uVar16 >> uVar17 * 8 | uVar16 << uVar17 * -8 + 0x20;
            uVar11 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                     *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
            uVar20 = *(uint *)(unaff_r8 & 0xfffffffc) >> (unaff_r8 & 3) * 8 |
                     *(uint *)(unaff_r8 & 0xfffffffc) << (unaff_r8 & 3) * -8 + 0x20;
            uVar17 = uVar6 + 8 & 3;
            uVar16 = *(uint *)(uVar6 + 8 & 0xfffffffc);
            uVar16 = uVar16 >> uVar17 * 8 | uVar16 << uVar17 * -8 + 0x20;
            uVar9 = *(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
                    *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20;
            uVar17 = iVar7 + 0xa0U & 3;
            uVar18 = *(uint *)(iVar7 + 0xa0U & 0xfffffffc);
            uVar19 = uVar18 >> uVar17 * 8 | uVar18 << uVar17 * -8 + 0x20;
            uVar17 = uVar15 + 8 & 3;
            uVar18 = *(uint *)(uVar15 + 8 & 0xfffffffc);
            uVar17 = uVar18 >> uVar17 * 8 | uVar18 << uVar17 * -8 + 0x20;
            if ((0 < ((int)(uVar20 - uVar11) >> 0xc) * ((int)(uVar9 - uVar11) >> 0xc) +
                     ((int)(uVar19 - uVar16) >> 0xc) * ((int)(uVar17 - uVar16) >> 0xc)) &&
               (iVar10 = (int)(uVar17 - uVar19) >> 0xc, uVar17 = uVar15 + 4 & 3,
               uVar15 = *(uint *)(uVar15 + 4 & 0xfffffffc), uVar16 = iVar7 + 0x9cU & 3,
               uVar11 = *(uint *)(iVar7 + 0x9cU & 0xfffffffc), iVar1 = (int)(uVar9 - uVar20) >> 0xc,
               iVar2 = (int)((uVar15 >> uVar17 * 8 | uVar15 << uVar17 * -8 + 0x20) -
                            (uVar11 >> uVar16 * 8 | uVar11 << uVar16 * -8 + 0x20)) >> 0xc,
               iVar10 = iVar10 * iVar10 + iVar1 * iVar1 + iVar2 * iVar2, iVar10 < local_2c)) {
              uVar12 = uVar13;
              local_2c = iVar10;
            }
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < (int)local_38);
      }
    }
  }
  uVar13 = uVar12;
  if ((local_40 == 0) || ((bVar5 && (param_4 != 0)))) {
    if (local_40 == 0) {
      uVar3 = *(ushort *)(uVar12 + 0x24);
    }
    else {
      uVar3 = *(ushort *)(uVar12 + 0x26);
    }
    if (1 < uVar3) {
      iVar7 = 0;
      local_28 = 0;
      if (local_40 == 0) {
        uVar3 = *(ushort *)(uVar12 + 0x24);
      }
      else {
        uVar3 = *(ushort *)(uVar12 + 0x26);
      }
      local_3c = (uint)uVar3;
      if (local_3c != 0) {
        do {
          if (local_40 == 0) {
            uVar13 = uVar12 + iVar7 * 4;
            uVar17 = uVar13 & 3;
            uVar13 = *(uint *)(uVar13 & 0xfffffffc);
            uVar13 = uVar13 >> uVar17 * 8 | uVar13 << uVar17 * -8 + 0x20;
          }
          else {
            uVar13 = uVar12 + iVar7 * 4 + 0xc;
            uVar17 = uVar13 & 3;
            uVar13 = *(uint *)(uVar13 & 0xfffffffc);
            uVar13 = uVar13 >> uVar17 * 8 | uVar13 << uVar17 * -8 + 0x20;
          }
          if ((uVar13 != 0) && (uVar13 != uVar14)) {
            if (!bVar5) {
              local_40 = 1;
              goto LAB_020f3778;
            }
            uVar17 = uVar13 + 0x18 & 3;
            uVar16 = *(uint *)(uVar13 + 0x18 & 0xfffffffc);
            uVar18 = uVar16 >> uVar17 * 8 | uVar16 << uVar17 * -8 + 0x20;
            uVar11 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                     *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
            uVar15 = *(uint *)(unaff_r8 & 0xfffffffc) >> (unaff_r8 & 3) * 8 |
                     *(uint *)(unaff_r8 & 0xfffffffc) << (unaff_r8 & 3) * -8 + 0x20;
            uVar17 = uVar6 + 8 & 3;
            uVar16 = *(uint *)(uVar6 + 8 & 0xfffffffc);
            uVar16 = uVar16 >> uVar17 * 8 | uVar16 << uVar17 * -8 + 0x20;
            uVar9 = *(uint *)(uVar18 & 0xfffffffc) >> (uVar18 & 3) * 8 |
                    *(uint *)(uVar18 & 0xfffffffc) << (uVar18 & 3) * -8 + 0x20;
            uVar17 = unaff_r8 + 8 & 3;
            uVar19 = *(uint *)(unaff_r8 + 8 & 0xfffffffc);
            uVar20 = uVar19 >> uVar17 * 8 | uVar19 << uVar17 * -8 + 0x20;
            uVar17 = uVar18 + 8 & 3;
            uVar19 = *(uint *)(uVar18 + 8 & 0xfffffffc);
            uVar17 = uVar19 >> uVar17 * 8 | uVar19 << uVar17 * -8 + 0x20;
            if ((0 < ((int)(uVar15 - uVar11) >> 0xc) * ((int)(uVar9 - uVar11) >> 0xc) +
                     ((int)(uVar20 - uVar16) >> 0xc) * ((int)(uVar17 - uVar16) >> 0xc)) &&
               (iVar8 = (int)(uVar17 - uVar20) >> 0xc, uVar17 = uVar18 + 4 & 3,
               uVar18 = *(uint *)(uVar18 + 4 & 0xfffffffc), uVar16 = unaff_r8 + 4 & 3,
               uVar11 = *(uint *)(unaff_r8 + 4 & 0xfffffffc), iVar10 = (int)(uVar9 - uVar15) >> 0xc,
               iVar1 = (int)((uVar18 >> uVar17 * 8 | uVar18 << uVar17 * -8 + 0x20) -
                            (uVar11 >> uVar16 * 8 | uVar11 << uVar16 * -8 + 0x20)) >> 0xc,
               iVar8 = iVar8 * iVar8 + iVar10 * iVar10 + iVar1 * iVar1, iVar8 < local_2c)) {
              local_2c = iVar8;
              local_28 = uVar13;
            }
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < (int)local_3c);
      }
      uVar13 = uVar12;
      if (local_28 != 0) {
        local_40 = (uint)(local_40 == 0);
        uVar13 = local_28;
      }
    }
  }
LAB_020f3778:
  *param_2 = uVar13;
  param_2[1] = local_40;
  return;
}

