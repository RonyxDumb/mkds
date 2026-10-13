/* Decompiled C draft; module arm9; ROM address 020be3e4. No matching claim. */
#include "types.h"
#include "deps/020be3e4_func_020be3e4.h"

void func_020be3e4(void)

{
  longlong lVar1;
  longlong lVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int *piVar16;
  int *piVar17;
  uint uVar18;
  uint uVar19;
  int iStack_98;
  int iStack_94;
  uint auStack_90 [8];
  int local_70 [19];
  uint uVar6;
  
  iVar15 = 4;
  piVar3 = local_70;
  piVar4 = piRam020be7cc;
  do {
    piVar17 = piVar4;
    piVar16 = piVar3;
    iVar8 = piVar17[1];
    iVar10 = piVar17[2];
    iVar14 = piVar17[3];
    *piVar16 = *piVar17;
    piVar16[1] = iVar8;
    piVar16[2] = iVar10;
    piVar16[3] = iVar14;
    iVar15 = iVar15 + -1;
    piVar3 = piVar16 + 4;
    piVar4 = piVar17 + 4;
  } while (iVar15 != 0);
  iVar15 = piVar17[5];
  piVar16[4] = piVar17[4];
  piVar16[5] = iVar15;
  uVar18 = (uint)*(ushort *)
                  ((*(uint *)(uRam020be7d0 & 0xfffffffc) >> (uRam020be7d0 & 3) * 8 |
                   *(uint *)(uRam020be7d0 & 0xfffffffc) << (uRam020be7d0 & 3) * -8 + 0x20) + 0xf8);
  iVar15 = GetRaceStartCountdown();
  if (iVar15 < 0x189) {
    iVar15 = GetRaceStartCountdown();
    *(int *)((*(uint *)(uRam020be7d0 & 0xfffffffc) >> (uRam020be7d0 & 3) * 8 |
             *(uint *)(uRam020be7d0 & 0xfffffffc) << (uRam020be7d0 & 3) * -8 + 0x20) + 0xe0) =
         (0x20 - (iVar15 + -0x168)) * 4;
  }
  else {
    *(undefined4 *)
     ((*(uint *)(uRam020be7d0 & 0xfffffffc) >> (uRam020be7d0 & 3) * 8 |
      *(uint *)(uRam020be7d0 & 0xfffffffc) << (uRam020be7d0 & 3) * -8 + 0x20) + 0xe0) = 0;
  }
  iVar15 = GetRaceStartCountdown();
  uVar12 = uRam020be7d4;
  uVar9 = uRam020be7d0;
  if (iVar15 < 0x168) {
    return;
  }
  uVar11 = *(uint *)(uRam020be7d4 & 0xfffffffc) >> (uRam020be7d4 & 3) * 8 |
           *(uint *)(uRam020be7d4 & 0xfffffffc) << (uRam020be7d4 & 3) * -8 + 0x20;
  uVar6 = uVar11 + 8 & 3;
  uVar5 = *(uint *)(uVar11 + 8 & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  if (uVar6 == 1) {
    return;
  }
  if (uVar6 != 4) {
    if ((uVar6 == 2) && (uVar6 = 0, *(char *)(uVar11 + 0x3d0) != '\0')) {
      do {
        uVar7 = func_020a1154(uVar6);
        uVar5 = uVar9 & 3;
        uVar11 = *(uint *)(uVar9 & 0xfffffffc);
        *(undefined4 *)((uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20) + uVar6 * 4 + 0xc0) =
             uVar7;
        uVar5 = uVar12 & 3;
        uVar11 = *(uint *)(uVar12 & 0xfffffffc);
        uVar11 = uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20;
        uVar6 = uVar6 + 1 & 0xff;
      } while (uVar6 < *(byte *)(uVar11 + 0x3d0));
    }
    iVar15 = iRam020be7dc;
    uVar9 = uRam020be7d0;
    uVar12 = (uint)*(byte *)(uVar11 + 0x3d0);
    uVar6 = 0;
    if (uVar12 != 0) {
      iVar8 = (uVar18 - 0x12) * 0x10;
      lVar1 = (longlong)iRam020be7d8;
      lVar2 = (longlong)iRam020be7d8;
      do {
        iVar10 = uVar6 * 0x210 +
                 (*(uint *)(uRam020be7e0 & 0xfffffffc) >> (uRam020be7e0 & 3) * 8 |
                 *(uint *)(uRam020be7e0 & 0xfffffffc) << (uRam020be7e0 & 3) * -8 + 0x20);
        uVar12 = iVar10 + 0x30;
        uVar5 = uVar12 & 3;
        uVar12 = *(uint *)(uVar12 & 0xfffffffc);
        uVar12 = uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20;
        if (uVar12 == 0x13) {
          uVar12 = iVar10 + 0x14;
          uVar5 = uVar12 & 3;
          uVar12 = *(uint *)(uVar12 & 0xfffffffc);
          uVar12 = uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20;
        }
        *(uint *)((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                  *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + uVar6 * 4 + 0x40) =
             uVar12;
        uVar5 = *(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20;
        uVar12 = (uint)*(ushort *)(uVar5 + 0xf8);
        if (uVar12 == iRam020be7e4 *
                      ((int)(uVar12 + (int)((ulonglong)((longlong)iVar15 * (longlong)(int)uVar12) >>
                                           0x20)) >> 4)) {
          iVar10 = uVar5 + uVar6 * 4;
          uVar12 = iVar10 + 0x80;
          uVar5 = uVar12 & 3;
          uVar12 = *(uint *)(uVar12 & 0xfffffffc);
          *(uint *)(iVar10 + 0x60) = uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20;
          uVar7 = GetDriverPlace(uVar6);
          *(undefined4 *)
           ((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
            *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + uVar6 * 4 + 0x80) = uVar7;
        }
        uVar19 = *(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                 *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20;
        iVar10 = uVar19 + uVar6 * 4;
        uVar12 = iVar10 + 0x60;
        uVar5 = uVar12 & 3;
        uVar12 = *(uint *)(uVar12 & 0xfffffffc);
        uVar11 = uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20;
        iVar14 = local_70[uVar11 * 2 + 1];
        iStack_98 = local_70[uVar11 * 2];
        uVar12 = iVar10 + 0x80;
        uVar5 = uVar12 & 3;
        uVar12 = *(uint *)(uVar12 & 0xfffffffc);
        uVar12 = uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20;
        iStack_94 = local_70[uVar12 * 2 + 1];
        if ((int)uVar12 < (int)uVar11) {
          if (uVar18 < 10) {
            iStack_98 = iStack_98 + (int)(lVar1 * (int)(uVar18 << 4) >> 0x22);
            iStack_94 = iVar14;
          }
          else if (uVar18 < 0x12) {
            iVar10 = (uVar18 - 10) * (local_70[uVar12 * 2] - iStack_98);
            iVar13 = (uVar18 - 10) * (iStack_94 - iVar14);
            iStack_98 = iStack_98 + ((int)(iVar10 + ((uint)(iVar10 >> 2) >> 0x1d)) >> 3) + 0x10;
            iStack_94 = iVar14 + ((int)(iVar13 + ((uint)(iVar13 >> 2) >> 0x1d)) >> 3);
          }
          else {
            iStack_98 = (iStack_98 + 0x10) - ((int)(lVar2 * iVar8 >> 0x22) - (iVar8 >> 0x1f));
          }
        }
        else {
          iVar13 = uVar18 * (local_70[uVar12 * 2] - iStack_98);
          iVar10 = uVar18 * (iStack_94 - iVar14);
          iStack_98 = iStack_98 +
                      ((iVar13 + (int)((ulonglong)((longlong)iVar15 * (longlong)iVar13) >> 0x20) >>
                       4) - (iVar13 >> 0x1f));
          iStack_94 = iVar14 + ((iVar10 + (int)((ulonglong)((longlong)iVar15 * (longlong)iVar10) >>
                                               0x20) >> 4) - (iVar10 >> 0x1f));
        }
        *(int *)(uVar19 + uVar6 * 8) = iStack_98;
        *(int *)(uVar19 + uVar6 * 8 + 4) = iStack_94;
        uVar6 = uVar6 + 1 & 0xff;
        uVar12 = (uint)*(byte *)((*(uint *)(uRam020be7d4 & 0xfffffffc) >> (uRam020be7d4 & 3) * 8 |
                                 *(uint *)(uRam020be7d4 & 0xfffffffc) <<
                                 (uRam020be7d4 & 3) * -8 + 0x20) + 0x3d0);
      } while (uVar6 < uVar12);
    }
    uVar9 = uRam020be7d4;
    uVar18 = uRam020be7d0;
    uVar6 = 0;
    if (uVar12 != 0) {
      do {
        *(uint *)((*(uint *)(uVar18 & 0xfffffffc) >> (uVar18 & 3) * 8 |
                  *(uint *)(uVar18 & 0xfffffffc) << (uVar18 & 3) * -8 + 0x20) + uVar6 * 4 + 0xa0) =
             uVar6;
        uVar11 = uVar9 & 3;
        uVar19 = *(uint *)(uVar9 & 0xfffffffc);
        uVar12 = (*(uint *)(uVar18 & 0xfffffffc) >> (uVar18 & 3) * 8 |
                 *(uint *)(uVar18 & 0xfffffffc) << (uVar18 & 3) * -8 + 0x20) + uVar6 * 4 + 0x80;
        uVar5 = uVar12 & 3;
        uVar12 = *(uint *)(uVar12 & 0xfffffffc);
        auStack_90[uVar6] = uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20;
        uVar6 = uVar6 + 1 & 0xff;
      } while (uVar6 < *(byte *)((uVar19 >> uVar11 * 8 | uVar19 << uVar11 * -8 + 0x20) + 0x3d0));
    }
    func_020ae770((*(uint *)(uRam020be7d0 & 0xfffffffc) >> (uRam020be7d0 & 3) * 8 |
                  *(uint *)(uRam020be7d0 & 0xfffffffc) << (uRam020be7d0 & 3) * -8 + 0x20) + 0xa0,
                  auStack_90);
    uVar12 = uRam020be7d4;
    uVar9 = uRam020be7d0;
    uVar18 = *(uint *)(uRam020be7d0 & 0xfffffffc) >> (uRam020be7d0 & 3) * 8 |
             *(uint *)(uRam020be7d0 & 0xfffffffc) << (uRam020be7d0 & 3) * -8 + 0x20;
    *(short *)(uVar18 + 0xf8) = *(short *)(uVar18 + 0xf8) + 1;
    uVar18 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    uVar18 = uVar9 >> uVar18 * 8 | uVar9 << uVar18 * -8 + 0x20;
    if (0x1b < *(ushort *)(uVar18 + 0xf8)) {
      *(undefined2 *)(uVar18 + 0xf8) = 0;
    }
    uVar18 = uRam020be7d0;
    uVar9 = 0;
    if (*(char *)((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
                  *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) + 0x3d0) != '\0') {
      do {
        iVar15 = (*(uint *)(uVar18 & 0xfffffffc) >> (uVar18 & 3) * 8 |
                 *(uint *)(uVar18 & 0xfffffffc) << (uVar18 & 3) * -8 + 0x20) + uVar9 * 0xc;
        uVar6 = iVar15 + 0xfc;
        uVar5 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        uVar6 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
        if (uVar6 != 0) {
          *(uint *)(iVar15 + 0xfc) = uVar6 + 1;
          iVar15 = (*(uint *)(uVar18 & 0xfffffffc) >> (uVar18 & 3) * 8 |
                   *(uint *)(uVar18 & 0xfffffffc) << (uVar18 & 3) * -8 + 0x20) + uVar9 * 0xc;
          uVar6 = iVar15 + 0xfc;
          uVar5 = uVar6 & 3;
          uVar6 = *(uint *)(uVar6 & 0xfffffffc);
          if (0x24 < (int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20)) {
            *(undefined4 *)(iVar15 + 0xfc) = 0;
          }
        }
        uVar9 = uVar9 + 1 & 0xff;
      } while (uVar9 < *(byte *)((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
                                 *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) + 0x3d0
                                ));
      return;
    }
    return;
  }
  return;
}

