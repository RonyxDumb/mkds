/* Decompiled C draft; module arm9; ROM address 02101f7c. No matching claim. */
#include "types.h"
#include "deps/02101f7c_func_02101f7c.h"

void func_02101f7c(int param_1,uint param_2)

{
  ushort uVar1;
  longlong lVar2;
  bool bVar3;
  uint uVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar10;
  ushort *puVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int *piVar17;
  int iVar18;
  uint uVar19;
  int local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  undefined2 local_44 [7];
  ushort local_36 [9];
  uint uVar9;
  uint uVar11;
  uint uVar20;
  
  puVar12 = puRam021025c0;
  local_6c = (uint)*(byte *)((*(uint *)(uRam021025bc & 0xfffffffc) >> (uRam021025bc & 3) * 8 |
                             *(uint *)(uRam021025bc & 0xfffffffc) << (uRam021025bc & 3) * -8 + 0x20)
                            + 0x3d0);
  iVar15 = 0;
  if ((*(ushort *)(param_1 + 0x78) & 0x8000) == 0) {
    uVar5 = *(ushort *)(param_1 + 0x78) & 0xff;
  }
  else {
    uVar5 = 8;
  }
  uVar14 = 0;
  local_70 = param_1;
  uVar4 = GetDriverPlace(uVar5);
  uVar8 = local_70 + 0x148U & 3;
  uVar6 = *(uint *)(local_70 + 0x148U & 0xfffffffc);
  if (uVar6 >> uVar8 * 8 == 0 && uVar6 << uVar8 * -8 + 0x20 == 0) {
    local_68 = *(uint *)(uRam021025c4 & 0xfffffffc) >> (uRam021025c4 & 3) * 8 |
               *(uint *)(uRam021025c4 & 0xfffffffc) << (uRam021025c4 & 3) * -8 + 0x20;
    local_64 = *(uint *)(uRam021025c8 & 0xfffffffc) >> (uRam021025c8 & 3) * 8 |
               *(uint *)(uRam021025c8 & 0xfffffffc) << (uRam021025c8 & 3) * -8 + 0x20;
    local_60 = *(uint *)(uRam021025bc & 0xfffffffc) >> (uRam021025bc & 3) * 8 |
               *(uint *)(uRam021025bc & 0xfffffffc) << (uRam021025bc & 3) * -8 + 0x20;
    uVar8 = uVar4;
    do {
      iVar16 = iVar15;
      if (uVar8 < local_6c) {
        uVar6 = uVar8 + 1;
        uVar8 = uVar6 & 0xffff;
        local_4c = 1;
        uVar5 = (ushort)*(char *)(local_68 + (uVar6 & 0xff) + 0x473);
        bVar3 = true;
        iVar18 = (uint)uVar5 * 0x210 + local_64;
        uVar6 = iVar18 + 0x1fcU & 3;
        uVar19 = *(uint *)(iVar18 + 0x1fcU & 0xfffffffc);
        uVar20 = uVar19 >> uVar6 * 8 | uVar19 << uVar6 * -8 + 0x20;
        uVar6 = uVar20 + 0x180 & 3;
        uVar19 = *(uint *)(uVar20 + 0x180 & 0xfffffffc);
        if (((int)(uVar19 >> uVar6 * 8 | uVar19 << uVar6 * -8 + 0x20) < 4) &&
           (uVar6 = uVar20 + 0x7c & 3, uVar19 = *(uint *)(uVar20 + 0x7c & 0xfffffffc),
           ((uVar19 >> uVar6 * 8 | uVar19 << uVar6 * -8 + 0x20) & uRam021025cc) == 0)) {
          bVar3 = false;
        }
        if ((!bVar3) &&
           (uVar6 = uVar20 + 0x4c & 3, uVar19 = *(uint *)(uVar20 + 0x4c & 0xfffffffc),
           ((uVar19 >> uVar6 * 8 | uVar19 << uVar6 * -8 + 0x20) & uRam021025d0) == 0)) {
          local_4c = 0;
        }
        uVar6 = uVar20 + 0x4c & 3;
        uVar19 = *(uint *)(uVar20 + 0x4c & 0xfffffffc);
        if (local_4c == 0 && ((uVar19 >> uVar6 * 8 | uVar19 << uVar6 * -8 + 0x20) & 0x40) == 0) {
          if ((param_2 == 0xffffffff) ||
             (uVar6 = (uint)uVar5 * 0x30 + local_60 + 0x74, uVar19 = uVar6 & 3,
             uVar6 = *(uint *)(uVar6 & 0xfffffffc),
             param_2 != (uVar6 >> uVar19 * 8 | uVar6 << uVar19 * -8 + 0x20))) {
            bVar3 = false;
            uVar6 = iVar18 + 0x30U & 3;
            uVar19 = *(uint *)(iVar18 + 0x30U & 0xfffffffc);
            uVar6 = uVar19 >> uVar6 * 8 | uVar19 << uVar6 * -8 + 0x20;
            if ((uVar6 != 0x13) &&
               ((uVar19 = iVar18 + 0x50U & 3, uVar20 = *(uint *)(iVar18 + 0x50U & 0xfffffffc),
                uVar20 >> uVar19 * 8 == 0 && uVar20 << uVar19 * -8 + 0x20 == 0 && (uVar6 != 0x10))))
            {
              bVar3 = true;
            }
          }
          else {
            bVar3 = false;
          }
        }
        else {
          bVar3 = false;
        }
        if (bVar3) {
          uVar1 = *puVar12;
          local_36[iVar15] = uVar5;
          uVar6 = uVar14 + uVar1;
          uVar14 = uVar6 & 0xffff;
          iVar16 = iVar15 + 1;
          local_44[iVar15] = (short)(uVar6 * 0x10000 >> 0x10);
        }
        puVar12 = puVar12 + 1;
      }
      iVar15 = iVar16;
      if (1 < uVar4) {
        uVar6 = uVar4 - 1;
        uVar4 = uVar6 & 0xffff;
        local_48 = 1;
        uVar5 = (ushort)*(char *)(local_68 + (uVar6 & 0xff) + 0x473);
        bVar3 = true;
        iVar18 = (uint)uVar5 * 0x210 + local_64;
        uVar6 = iVar18 + 0x1fcU & 3;
        uVar19 = *(uint *)(iVar18 + 0x1fcU & 0xfffffffc);
        uVar20 = uVar19 >> uVar6 * 8 | uVar19 << uVar6 * -8 + 0x20;
        uVar6 = uVar20 + 0x180 & 3;
        uVar19 = *(uint *)(uVar20 + 0x180 & 0xfffffffc);
        if (((int)(uVar19 >> uVar6 * 8 | uVar19 << uVar6 * -8 + 0x20) < 4) &&
           (uVar6 = uVar20 + 0x7c & 3, uVar19 = *(uint *)(uVar20 + 0x7c & 0xfffffffc),
           ((uVar19 >> uVar6 * 8 | uVar19 << uVar6 * -8 + 0x20) & uRam021025cc) == 0)) {
          bVar3 = false;
        }
        if ((!bVar3) &&
           (uVar6 = uVar20 + 0x4c & 3, uVar19 = *(uint *)(uVar20 + 0x4c & 0xfffffffc),
           ((uVar19 >> uVar6 * 8 | uVar19 << uVar6 * -8 + 0x20) & uRam021025d0) == 0)) {
          local_48 = 0;
        }
        uVar6 = uVar20 + 0x4c & 3;
        uVar19 = *(uint *)(uVar20 + 0x4c & 0xfffffffc);
        if (local_48 == 0 && ((uVar19 >> uVar6 * 8 | uVar19 << uVar6 * -8 + 0x20) & 0x40) == 0) {
          if ((param_2 == 0xffffffff) ||
             (uVar6 = (uint)uVar5 * 0x30 + local_60 + 0x74, uVar19 = uVar6 & 3,
             uVar6 = *(uint *)(uVar6 & 0xfffffffc),
             param_2 != (uVar6 >> uVar19 * 8 | uVar6 << uVar19 * -8 + 0x20))) {
            bVar3 = false;
            uVar6 = iVar18 + 0x30U & 3;
            uVar19 = *(uint *)(iVar18 + 0x30U & 0xfffffffc);
            uVar6 = uVar19 >> uVar6 * 8 | uVar19 << uVar6 * -8 + 0x20;
            if ((uVar6 != 0x13) &&
               ((uVar19 = iVar18 + 0x50U & 3, uVar20 = *(uint *)(iVar18 + 0x50U & 0xfffffffc),
                uVar20 >> uVar19 * 8 == 0 && uVar20 << uVar19 * -8 + 0x20 == 0 && (uVar6 != 0x10))))
            {
              bVar3 = true;
            }
          }
          else {
            bVar3 = false;
          }
        }
        else {
          bVar3 = false;
        }
        if (bVar3) {
          uVar1 = *puVar12;
          local_36[iVar16] = uVar5;
          uVar6 = uVar14 + uVar1;
          uVar14 = uVar6 & 0xffff;
          iVar15 = iVar16 + 1;
          local_44[iVar16] = (short)(uVar6 * 0x10000 >> 0x10);
        }
        puVar12 = puVar12 + 1;
      }
    } while ((uVar8 < local_6c) || (1 < uVar4));
  }
  else {
    local_68 = *(uint *)(uRam021025c4 & 0xfffffffc) >> (uRam021025c4 & 3) * 8 |
               *(uint *)(uRam021025c4 & 0xfffffffc) << (uRam021025c4 & 3) * -8 + 0x20;
    local_5c = *(uint *)(uRam021025c8 & 0xfffffffc) >> (uRam021025c8 & 3) * 8 |
               *(uint *)(uRam021025c8 & 0xfffffffc) << (uRam021025c8 & 3) * -8 + 0x20;
    local_58 = *(uint *)(uRam021025bc & 0xfffffffc) >> (uRam021025bc & 3) * 8 |
               *(uint *)(uRam021025bc & 0xfffffffc) << (uRam021025bc & 3) * -8 + 0x20;
    uVar8 = uVar4;
    do {
      iVar16 = iVar15;
      if (1 < uVar4) {
        uVar6 = uVar4 - 1;
        uVar4 = uVar6 & 0xffff;
        local_54 = 1;
        uVar5 = (ushort)*(char *)(local_68 + (uVar6 & 0xff) + 0x473);
        bVar3 = true;
        iVar18 = (uint)uVar5 * 0x210 + local_5c;
        uVar6 = iVar18 + 0x1fcU & 3;
        uVar19 = *(uint *)(iVar18 + 0x1fcU & 0xfffffffc);
        uVar20 = uVar19 >> uVar6 * 8 | uVar19 << uVar6 * -8 + 0x20;
        uVar6 = uVar20 + 0x180 & 3;
        uVar19 = *(uint *)(uVar20 + 0x180 & 0xfffffffc);
        if (((int)(uVar19 >> uVar6 * 8 | uVar19 << uVar6 * -8 + 0x20) < 4) &&
           (uVar6 = uVar20 + 0x7c & 3, uVar19 = *(uint *)(uVar20 + 0x7c & 0xfffffffc),
           ((uVar19 >> uVar6 * 8 | uVar19 << uVar6 * -8 + 0x20) & uRam021025cc) == 0)) {
          bVar3 = false;
        }
        if ((!bVar3) &&
           (uVar6 = uVar20 + 0x4c & 3, uVar19 = *(uint *)(uVar20 + 0x4c & 0xfffffffc),
           ((uVar19 >> uVar6 * 8 | uVar19 << uVar6 * -8 + 0x20) & uRam021025d0) == 0)) {
          local_54 = 0;
        }
        uVar6 = uVar20 + 0x4c & 3;
        uVar19 = *(uint *)(uVar20 + 0x4c & 0xfffffffc);
        if (local_54 == 0 && ((uVar19 >> uVar6 * 8 | uVar19 << uVar6 * -8 + 0x20) & 0x40) == 0) {
          if ((param_2 == 0xffffffff) ||
             (uVar6 = (uint)uVar5 * 0x30 + local_58 + 0x74, uVar19 = uVar6 & 3,
             uVar6 = *(uint *)(uVar6 & 0xfffffffc),
             param_2 != (uVar6 >> uVar19 * 8 | uVar6 << uVar19 * -8 + 0x20))) {
            bVar3 = false;
            uVar6 = iVar18 + 0x30U & 3;
            uVar19 = *(uint *)(iVar18 + 0x30U & 0xfffffffc);
            uVar6 = uVar19 >> uVar6 * 8 | uVar19 << uVar6 * -8 + 0x20;
            if ((uVar6 != 0x13) &&
               ((uVar19 = iVar18 + 0x50U & 3, uVar20 = *(uint *)(iVar18 + 0x50U & 0xfffffffc),
                uVar20 >> uVar19 * 8 == 0 && uVar20 << uVar19 * -8 + 0x20 == 0 && (uVar6 != 0x10))))
            {
              bVar3 = true;
            }
          }
          else {
            bVar3 = false;
          }
        }
        else {
          bVar3 = false;
        }
        if (bVar3) {
          uVar1 = *puVar12;
          local_36[iVar15] = uVar5;
          uVar6 = uVar14 + uVar1;
          uVar14 = uVar6 & 0xffff;
          iVar16 = iVar15 + 1;
          local_44[iVar15] = (short)(uVar6 * 0x10000 >> 0x10);
        }
        puVar12 = puVar12 + 1;
      }
      iVar15 = iVar16;
      if (uVar8 < local_6c) {
        uVar6 = uVar8 + 1;
        uVar8 = uVar6 & 0xffff;
        local_50 = 1;
        uVar5 = (ushort)*(char *)(local_68 + (uVar6 & 0xff) + 0x473);
        bVar3 = true;
        iVar18 = (uint)uVar5 * 0x210 + local_5c;
        uVar6 = iVar18 + 0x1fcU & 3;
        uVar19 = *(uint *)(iVar18 + 0x1fcU & 0xfffffffc);
        uVar20 = uVar19 >> uVar6 * 8 | uVar19 << uVar6 * -8 + 0x20;
        uVar6 = uVar20 + 0x180 & 3;
        uVar19 = *(uint *)(uVar20 + 0x180 & 0xfffffffc);
        if (((int)(uVar19 >> uVar6 * 8 | uVar19 << uVar6 * -8 + 0x20) < 4) &&
           (uVar6 = uVar20 + 0x7c & 3, uVar19 = *(uint *)(uVar20 + 0x7c & 0xfffffffc),
           ((uVar19 >> uVar6 * 8 | uVar19 << uVar6 * -8 + 0x20) & uRam021025cc) == 0)) {
          bVar3 = false;
        }
        if ((!bVar3) &&
           (uVar6 = uVar20 + 0x4c & 3, uVar19 = *(uint *)(uVar20 + 0x4c & 0xfffffffc),
           ((uVar19 >> uVar6 * 8 | uVar19 << uVar6 * -8 + 0x20) & uRam021025d0) == 0)) {
          local_50 = 0;
        }
        uVar6 = uVar20 + 0x4c & 3;
        uVar19 = *(uint *)(uVar20 + 0x4c & 0xfffffffc);
        if (local_50 == 0 && ((uVar19 >> uVar6 * 8 | uVar19 << uVar6 * -8 + 0x20) & 0x40) == 0) {
          if ((param_2 == 0xffffffff) ||
             (uVar6 = (uint)uVar5 * 0x30 + local_58 + 0x74, uVar19 = uVar6 & 3,
             uVar6 = *(uint *)(uVar6 & 0xfffffffc),
             param_2 != (uVar6 >> uVar19 * 8 | uVar6 << uVar19 * -8 + 0x20))) {
            bVar3 = false;
            uVar6 = iVar18 + 0x30U & 3;
            uVar19 = *(uint *)(iVar18 + 0x30U & 0xfffffffc);
            uVar6 = uVar19 >> uVar6 * 8 | uVar19 << uVar6 * -8 + 0x20;
            if ((uVar6 != 0x13) &&
               ((uVar19 = iVar18 + 0x50U & 3, uVar20 = *(uint *)(iVar18 + 0x50U & 0xfffffffc),
                uVar20 >> uVar19 * 8 == 0 && uVar20 << uVar19 * -8 + 0x20 == 0 && (uVar6 != 0x10))))
            {
              bVar3 = true;
            }
          }
          else {
            bVar3 = false;
          }
        }
        else {
          bVar3 = false;
        }
        if (bVar3) {
          uVar1 = *puVar12;
          local_36[iVar16] = uVar5;
          uVar6 = uVar14 + uVar1;
          uVar14 = uVar6 & 0xffff;
          iVar15 = iVar16 + 1;
          local_44[iVar16] = (short)(uVar6 * 0x10000 >> 0x10);
        }
        puVar12 = puVar12 + 1;
      }
    } while ((uVar8 < local_6c) || (1 < uVar4));
  }
  piVar17 = (int *)(local_68 + iRam021025d4);
  if (uVar14 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (uint)(piVar17 + 2) & 3;
    uVar8 = *(uint *)((uint)(piVar17 + 2) & 0xfffffffc);
    uVar9 = uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20;
    uVar7 = *(uint *)((uint)piVar17 & 0xfffffffc) >> ((uint)piVar17 & 3) * 8 |
            *(uint *)((uint)piVar17 & 0xfffffffc) << ((uint)piVar17 & 3) * -8 + 0x20;
    uVar4 = (uint)(piVar17 + 1) & 3;
    uVar19 = *(uint *)((uint)(piVar17 + 1) & 0xfffffffc);
    lVar2 = (ulonglong)uVar7 * (ulonglong)uVar9;
    uVar13 = (uint)lVar2;
    uVar8 = (uint)(piVar17 + 3) & 3;
    uVar20 = *(uint *)((uint)(piVar17 + 3) & 0xfffffffc);
    uVar6 = (uint)(piVar17 + 4) & 3;
    uVar10 = *(uint *)((uint)(piVar17 + 4) & 0xfffffffc);
    uVar11 = uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20;
    uVar6 = (uint)(piVar17 + 5) & 3;
    uVar10 = *(uint *)((uint)(piVar17 + 5) & 0xfffffffc);
    *piVar17 = uVar11 + uVar13;
    piVar17[1] = (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) +
                 (uVar20 >> uVar8 * 8 | uVar20 << uVar8 * -8 + 0x20) * uVar7 +
                 uVar9 * (uVar19 >> uVar4 * 8 | uVar19 << uVar4 * -8 + 0x20) +
                 (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar11,uVar13);
    if (uVar14 == 0) {
      uVar4 = (uint)(piVar17 + 1) & 3;
      uVar14 = *(uint *)((uint)(piVar17 + 1) & 0xfffffffc);
      uVar4 = uVar14 >> uVar4 * 8 | uVar14 << uVar4 * -8 + 0x20;
    }
    else {
      uVar4 = (uint)(piVar17 + 1) & 3;
      uVar8 = *(uint *)((uint)(piVar17 + 1) & 0xfffffffc);
      uVar4 = (uint)((ulonglong)uVar14 *
                     (ulonglong)(uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) >> 0x20);
    }
  }
  piVar17 = &local_70;
  if (iVar15 < 1) {
    piVar17 = (int *)&stack0xffffffdc;
  }
  uVar14 = 0;
  if (0 < iVar15) {
    do {
      if ((uVar4 & 0xffff) < (uint)*(ushort *)((int)piVar17 + uVar14 * 2 + 0x2c)) {
        *(uint *)(*piVar17 + 0x140) = (uint)*(ushort *)((int)piVar17 + uVar14 * 2 + 0x3a);
        return;
      }
      uVar14 = uVar14 + 1 & 0xffff;
    } while ((int)uVar14 < iVar15);
    return;
  }
  return;
}

