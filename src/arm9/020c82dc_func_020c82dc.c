/* Decompiled C draft; module arm9; ROM address 020c82dc. No matching claim. */
#include "types.h"
#include "deps/020c82dc_func_020c82dc.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_020c82dc(int param_1)

{
  ushort uVar1;
  longlong lVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  
  iVar4 = func_020c0dc4();
  uVar5 = (*(uint *)(uRam020c8bd0 & 0xfffffffc) >> (uRam020c8bd0 & 3) * 8 |
          *(uint *)(uRam020c8bd0 & 0xfffffffc) << (uRam020c8bd0 & 3) * -8 + 0x20) + 4;
  uVar9 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if (0 < (int)(uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20)) {
    if (iVar4 == 0) {
      if (*(char *)((*(uint *)(uRam020c8bd4 & 0xfffffffc) >> (uRam020c8bd4 & 3) * 8 |
                    *(uint *)(uRam020c8bd4 & 0xfffffffc) << (uRam020c8bd4 & 3) * -8 + 0x20) + 0x57)
          == '\0') {
        sVar3 = func_020b6368();
        sVar3 = *(short *)((*(uint *)(uRam020c8bd0 & 0xfffffffc) >> (uRam020c8bd0 & 3) * 8 |
                           *(uint *)(uRam020c8bd0 & 0xfffffffc) << (uRam020c8bd0 & 3) * -8 + 0x20) +
                          0xc) + sVar3;
      }
      else {
        sVar3 = func_020b6368();
        sVar3 = *(short *)((*(uint *)(uRam020c8bd0 & 0xfffffffc) >> (uRam020c8bd0 & 3) * 8 |
                           *(uint *)(uRam020c8bd0 & 0xfffffffc) << (uRam020c8bd0 & 3) * -8 + 0x20) +
                          0xc) - sVar3;
      }
      iVar6 = func_020ae5c4(param_1);
      MaybeCreateRotationMatrix(&iStack_34,sVar3);
      uVar9 = *(uint *)(uRam020c8bd0 & 0xfffffffc) >> (uRam020c8bd0 & 3) * 8 |
              *(uint *)(uRam020c8bd0 & 0xfffffffc) << (uRam020c8bd0 & 3) * -8 + 0x20;
      uVar5 = uVar9 + 0x2c;
      uVar16 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      uVar16 = uVar5 >> uVar16 * 8 | uVar5 << uVar16 * -8 + 0x20;
      uVar9 = uVar9 + 0x30;
      uVar5 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      uVar5 = uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20;
      if ((((-0x20 < (int)uVar16) && ((int)uVar16 < 0x120)) && (-0x20 < (int)uVar5)) &&
         ((int)uVar5 < 0xe0)) {
        uVar7 = GetB3C4_Cell_RaceS(0x9c);
        sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                 0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar7,&iStack_34);
        *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
      }
      iVar22 = 0;
      uVar8 = *(uint *)(uRam020c8bd0 & 0xfffffffc) >> (uRam020c8bd0 & 3) * 8 |
              *(uint *)(uRam020c8bd0 & 0xfffffffc) << (uRam020c8bd0 & 3) * -8 + 0x20;
      iVar19 = 0;
      uVar5 = uVar8 + 0x14 & 3;
      uVar14 = *(uint *)(uVar8 + 0x14 & 0xfffffffc);
      uVar9 = uVar8 + 0x2c & 3;
      uVar13 = *(uint *)(uVar8 + 0x2c & 0xfffffffc);
      uVar16 = uVar8 + 0x18 & 3;
      uVar10 = *(uint *)(uVar8 + 0x18 & 0xfffffffc);
      uVar15 = uVar8 + 0x30 & 3;
      uVar8 = *(uint *)(uVar8 + 0x30 & 0xfffffffc);
      iVar18 = 0;
      iVar20 = (uVar10 >> uVar16 * 8 | uVar10 << uVar16 * -8 + 0x20) -
               (uVar8 >> uVar15 * 8 | uVar8 << uVar15 * -8 + 0x20);
      iVar21 = (uVar14 >> uVar5 * 8 | uVar14 << uVar5 * -8 + 0x20) -
               (uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20);
      do {
        iVar11 = iVar19 + iVar21;
        uVar9 = *(uint *)(uRam020c8bd0 & 0xfffffffc) >> (uRam020c8bd0 & 3) * 8 |
                *(uint *)(uRam020c8bd0 & 0xfffffffc) << (uRam020c8bd0 & 3) * -8 + 0x20;
        uVar5 = uVar9 + 0x2c;
        uVar16 = uVar5 & 3;
        uVar15 = *(uint *)(uVar5 & 0xfffffffc);
        uVar9 = uVar9 + 0x30;
        uVar5 = uVar9 & 3;
        uVar9 = *(uint *)(uVar9 & 0xfffffffc);
        iVar12 = iVar18 + iVar20;
        iVar17 = (uVar15 >> uVar16 * 8 | uVar15 << uVar16 * -8 + 0x20) +
                 ((int)(iVar11 + ((uint)(iVar11 >> 1) >> 0x1e)) >> 2);
        iVar11 = (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) +
                 ((int)(iVar12 + ((uint)(iVar12 >> 1) >> 0x1e)) >> 2);
        if (((-0x20 < iVar17) && (iVar17 < 0x120)) && ((-0x20 < iVar11 && (iVar11 < 0xe0)))) {
          uVar7 = GetB3C4_Cell_RaceS(0x9b);
          sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                   0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar7,&iStack_34);
          *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
        }
        iVar22 = iVar22 + 1;
        iVar19 = iVar19 + iVar21;
        iVar18 = iVar18 + iVar20;
      } while (iVar22 < 3);
      uVar9 = *(uint *)(uRam020c8bd0 & 0xfffffffc) >> (uRam020c8bd0 & 3) * 8 |
              *(uint *)(uRam020c8bd0 & 0xfffffffc) << (uRam020c8bd0 & 3) * -8 + 0x20;
      uVar5 = uVar9 + 0x14;
      uVar16 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      uVar16 = uVar5 >> uVar16 * 8 | uVar5 << uVar16 * -8 + 0x20;
      uVar9 = uVar9 + 0x18;
      uVar5 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      uVar5 = uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20;
      if (((-0x20 < (int)uVar16) && ((int)uVar16 < 0x120)) &&
         ((-0x20 < (int)uVar5 && ((int)uVar5 < 0xe0)))) {
        uVar7 = GetB3C4_Cell_RaceS(0x9a);
        sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                 0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar7,&iStack_34);
        *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
      }
      iVar6 = param_1 + iVar6 * 0x20;
      *(short *)(iVar6 + 6) = (short)(iStack_34 >> 4);
      *(short *)(iVar6 + 0xe) = (short)(iStack_30 >> 4);
      *(short *)(iVar6 + 0x16) = (short)(iStack_2c >> 4);
      *(short *)(iVar6 + 0x1e) = (short)(iStack_28 >> 4);
    }
    uVar5 = (*(uint *)(uRam020c8bd0 & 0xfffffffc) >> (uRam020c8bd0 & 3) * 8 |
            *(uint *)(uRam020c8bd0 & 0xfffffffc) << (uRam020c8bd0 & 3) * -8 + 0x20) + 8;
    uVar9 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    if (((uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) == 3) && (iVar4 == 0)) {
      if (*(char *)((*(uint *)(uRam020c8bd4 & 0xfffffffc) >> (uRam020c8bd4 & 3) * 8 |
                    *(uint *)(uRam020c8bd4 & 0xfffffffc) << (uRam020c8bd4 & 3) * -8 + 0x20) + 0x57)
          == '\0') {
        sVar3 = func_020b6368();
        sVar3 = *(short *)((*(uint *)(uRam020c8bd0 & 0xfffffffc) >> (uRam020c8bd0 & 3) * 8 |
                           *(uint *)(uRam020c8bd0 & 0xfffffffc) << (uRam020c8bd0 & 3) * -8 + 0x20) +
                          0x10) + sVar3;
      }
      else {
        sVar3 = func_020b6368();
        sVar3 = *(short *)((*(uint *)(uRam020c8bd0 & 0xfffffffc) >> (uRam020c8bd0 & 3) * 8 |
                           *(uint *)(uRam020c8bd0 & 0xfffffffc) << (uRam020c8bd0 & 3) * -8 + 0x20) +
                          0x10) - sVar3;
      }
      iVar4 = func_020ae5c4(param_1);
      MaybeCreateRotationMatrix(&iStack_34,sVar3);
      uVar9 = *(uint *)(uRam020c8bd0 & 0xfffffffc) >> (uRam020c8bd0 & 3) * 8 |
              *(uint *)(uRam020c8bd0 & 0xfffffffc) << (uRam020c8bd0 & 3) * -8 + 0x20;
      uVar5 = uVar9 + 0x3c;
      uVar16 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      uVar16 = uVar5 >> uVar16 * 8 | uVar5 << uVar16 * -8 + 0x20;
      uVar9 = uVar9 + 0x40;
      uVar5 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      uVar5 = uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20;
      if ((((-0x20 < (int)uVar16) && ((int)uVar16 < 0x120)) && (-0x20 < (int)uVar5)) &&
         ((int)uVar5 < 0xe0)) {
        uVar7 = GetB3C4_Cell_RaceS(0x9c);
        sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                 0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar7,&iStack_34);
        *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
      }
      iVar21 = 0;
      uVar8 = *(uint *)(uRam020c8bd0 & 0xfffffffc) >> (uRam020c8bd0 & 3) * 8 |
              *(uint *)(uRam020c8bd0 & 0xfffffffc) << (uRam020c8bd0 & 3) * -8 + 0x20;
      iVar18 = 0;
      uVar5 = uVar8 + 0x24 & 3;
      uVar14 = *(uint *)(uVar8 + 0x24 & 0xfffffffc);
      uVar9 = uVar8 + 0x3c & 3;
      uVar13 = *(uint *)(uVar8 + 0x3c & 0xfffffffc);
      uVar16 = uVar8 + 0x28 & 3;
      uVar10 = *(uint *)(uVar8 + 0x28 & 0xfffffffc);
      uVar15 = uVar8 + 0x40 & 3;
      uVar8 = *(uint *)(uVar8 + 0x40 & 0xfffffffc);
      iVar6 = 0;
      iVar19 = (uVar10 >> uVar16 * 8 | uVar10 << uVar16 * -8 + 0x20) -
               (uVar8 >> uVar15 * 8 | uVar8 << uVar15 * -8 + 0x20);
      iVar20 = (uVar14 >> uVar5 * 8 | uVar14 << uVar5 * -8 + 0x20) -
               (uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20);
      do {
        iVar22 = iVar18 + iVar20;
        uVar9 = *(uint *)(uRam020c8bd0 & 0xfffffffc) >> (uRam020c8bd0 & 3) * 8 |
                *(uint *)(uRam020c8bd0 & 0xfffffffc) << (uRam020c8bd0 & 3) * -8 + 0x20;
        iVar11 = iVar6 + iVar19;
        uVar5 = uVar9 + 0x3c;
        uVar16 = uVar5 & 3;
        uVar15 = *(uint *)(uVar5 & 0xfffffffc);
        uVar9 = uVar9 + 0x40;
        uVar5 = uVar9 & 3;
        uVar9 = *(uint *)(uVar9 & 0xfffffffc);
        iVar12 = (uVar15 >> uVar16 * 8 | uVar15 << uVar16 * -8 + 0x20) +
                 ((int)((ulonglong)((longlong)iRam020c8bd8 * (longlong)iVar22) >> 0x20) -
                 (iVar22 >> 0x1f));
        lVar2 = (longlong)iRam020c8bd8 * (longlong)iVar11;
        uVar16 = (uint)lVar2;
        iVar22 = (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) +
                 ((int)((ulonglong)lVar2 >> 0x20) - (iVar11 >> 0x1f));
        if (((-0x20 < iVar12) && (iVar12 < 0x120)) && ((-0x20 < iVar22 && (iVar22 < 0xe0)))) {
          uVar7 = GetB3C4_Cell_RaceS(0x9b,iRam020c8bd8,uVar16);
          sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                   0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar7,&iStack_34);
          uVar1 = *(ushort *)(param_1 + 0x400);
          uVar16 = (uint)uVar1;
          *(ushort *)(param_1 + 0x400) = uVar1 + sVar3;
        }
        iVar21 = iVar21 + 1;
        iVar18 = iVar18 + iVar20;
        iVar6 = iVar6 + iVar19;
      } while (iVar21 < 2);
      uVar9 = *(uint *)(uRam020c8bd0 & 0xfffffffc) >> (uRam020c8bd0 & 3) * 8 |
              *(uint *)(uRam020c8bd0 & 0xfffffffc) << (uRam020c8bd0 & 3) * -8 + 0x20;
      uVar5 = uVar9 + 0x24 & 3;
      uVar15 = *(uint *)(uVar9 + 0x24 & 0xfffffffc);
      uVar8 = uVar15 >> uVar5 * 8 | uVar15 << uVar5 * -8 + 0x20;
      uVar5 = uVar9 + 0x28 & 3;
      uVar15 = *(uint *)(uVar9 + 0x28 & 0xfffffffc);
      uVar5 = uVar15 >> uVar5 * 8 | uVar15 << uVar5 * -8 + 0x20;
      if (((-0x20 < (int)uVar8) && ((int)uVar8 < 0x120)) &&
         ((-0x20 < (int)uVar5 && ((int)uVar5 < 0xe0)))) {
        uVar7 = GetB3C4_Cell_RaceS(0x9a,uVar9,uVar16);
        sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                 0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar7,&iStack_34);
        *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
      }
      iVar4 = param_1 + iVar4 * 0x20;
      *(short *)(iVar4 + 6) = (short)(iStack_34 >> 4);
      *(short *)(iVar4 + 0xe) = (short)(iStack_30 >> 4);
      *(short *)(iVar4 + 0x16) = (short)(iStack_2c >> 4);
      *(short *)(iVar4 + 0x1e) = (short)(iStack_28 >> 4);
    }
    if (*(char *)((*(uint *)(uRam020c8bd4 & 0xfffffffc) >> (uRam020c8bd4 & 3) * 8 |
                  *(uint *)(uRam020c8bd4 & 0xfffffffc) << (uRam020c8bd4 & 3) * -8 + 0x20) + 0x57) ==
        '\0') {
      sVar3 = func_020b6368();
      sVar3 = *(short *)((*(uint *)(uRam020c8bd0 & 0xfffffffc) >> (uRam020c8bd0 & 3) * 8 |
                         *(uint *)(uRam020c8bd0 & 0xfffffffc) << (uRam020c8bd0 & 3) * -8 + 0x20) +
                        0xe) + sVar3;
    }
    else {
      sVar3 = func_020b6368();
      sVar3 = *(short *)((*(uint *)(uRam020c8bd0 & 0xfffffffc) >> (uRam020c8bd0 & 3) * 8 |
                         *(uint *)(uRam020c8bd0 & 0xfffffffc) << (uRam020c8bd0 & 3) * -8 + 0x20) +
                        0xe) - sVar3;
    }
    iVar4 = func_020ae5c4(param_1);
    MaybeCreateRotationMatrix(&iStack_34,sVar3);
    uVar9 = *(uint *)(uRam020c8bd0 & 0xfffffffc) >> (uRam020c8bd0 & 3) * 8 |
            *(uint *)(uRam020c8bd0 & 0xfffffffc) << (uRam020c8bd0 & 3) * -8 + 0x20;
    uVar5 = uVar9 + 0x34;
    uVar16 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar16 = uVar5 >> uVar16 * 8 | uVar5 << uVar16 * -8 + 0x20;
    uVar9 = uVar9 + 0x38;
    uVar5 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    uVar5 = uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20;
    if ((((-0x10 < (int)uVar16) && ((int)uVar16 < 0x110)) && (-0x10 < (int)uVar5)) &&
       ((int)uVar5 < 0xd0)) {
      uVar7 = GetB3C4_Cell_RaceS(0x9f);
      sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                               0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar7,&iStack_34);
      *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
    }
    iVar21 = 0;
    uVar8 = *(uint *)(uRam020c8bd0 & 0xfffffffc) >> (uRam020c8bd0 & 3) * 8 |
            *(uint *)(uRam020c8bd0 & 0xfffffffc) << (uRam020c8bd0 & 3) * -8 + 0x20;
    iVar18 = 0;
    uVar5 = uVar8 + 0x1c & 3;
    uVar14 = *(uint *)(uVar8 + 0x1c & 0xfffffffc);
    uVar9 = uVar8 + 0x34 & 3;
    uVar13 = *(uint *)(uVar8 + 0x34 & 0xfffffffc);
    uVar16 = uVar8 + 0x20 & 3;
    uVar10 = *(uint *)(uVar8 + 0x20 & 0xfffffffc);
    uVar15 = uVar8 + 0x38 & 3;
    uVar8 = *(uint *)(uVar8 + 0x38 & 0xfffffffc);
    iVar6 = 0;
    iVar19 = (uVar10 >> uVar16 * 8 | uVar10 << uVar16 * -8 + 0x20) -
             (uVar8 >> uVar15 * 8 | uVar8 << uVar15 * -8 + 0x20);
    iVar20 = (uVar14 >> uVar5 * 8 | uVar14 << uVar5 * -8 + 0x20) -
             (uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20);
    do {
      iVar22 = iVar18 + iVar20;
      uVar9 = *(uint *)(uRam020c8bd0 & 0xfffffffc) >> (uRam020c8bd0 & 3) * 8 |
              *(uint *)(uRam020c8bd0 & 0xfffffffc) << (uRam020c8bd0 & 3) * -8 + 0x20;
      uVar5 = uVar9 + 0x34;
      uVar16 = uVar5 & 3;
      uVar15 = *(uint *)(uVar5 & 0xfffffffc);
      uVar9 = uVar9 + 0x38;
      uVar5 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      iVar11 = iVar6 + iVar19;
      iVar12 = (uVar15 >> uVar16 * 8 | uVar15 << uVar16 * -8 + 0x20) +
               ((int)(iVar22 + ((uint)(iVar22 >> 1) >> 0x1e)) >> 2);
      iVar22 = (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) +
               ((int)(iVar11 + ((uint)(iVar11 >> 1) >> 0x1e)) >> 2);
      if (((-0x10 < iVar12) && (iVar12 < 0x110)) && ((-0x10 < iVar22 && (iVar22 < 0xd0)))) {
        uVar7 = GetB3C4_Cell_RaceS(0x9e);
        sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                 0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar7,&iStack_34);
        *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
      }
      iVar21 = iVar21 + 1;
      iVar18 = iVar18 + iVar20;
      iVar6 = iVar6 + iVar19;
    } while (iVar21 < 3);
    uVar9 = *(uint *)(uRam020c8bd0 & 0xfffffffc) >> (uRam020c8bd0 & 3) * 8 |
            *(uint *)(uRam020c8bd0 & 0xfffffffc) << (uRam020c8bd0 & 3) * -8 + 0x20;
    uVar5 = uVar9 + 0x1c;
    uVar16 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar16 = uVar5 >> uVar16 * 8 | uVar5 << uVar16 * -8 + 0x20;
    uVar9 = uVar9 + 0x20;
    uVar5 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    uVar5 = uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20;
    if (((-0x10 < (int)uVar16) && ((int)uVar16 < 0x110)) &&
       ((-0x10 < (int)uVar5 && ((int)uVar5 < 0xd0)))) {
      uVar7 = GetB3C4_Cell_RaceS(0x9d);
      sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                               0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar7,&iStack_34);
      *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
    }
    param_1 = param_1 + iVar4 * 0x20;
    *(short *)(param_1 + 6) = (short)(iStack_34 >> 4);
    *(short *)(param_1 + 0xe) = (short)(iStack_30 >> 4);
    *(short *)(param_1 + 0x16) = (short)(iStack_2c >> 4);
    *(short *)(param_1 + 0x1e) = (short)(iStack_28 >> 4);
    return;
  }
  return;
}

