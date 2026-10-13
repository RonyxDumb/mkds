/* Decompiled C draft; module arm9; ROM address 020c28dc. No matching claim. */
#include "types.h"
#include "deps/020c28dc_StructRA_SomeFn_3.h"

void StructRA_SomeFn_3(int param_1)

{
  uint uVar1;
  longlong lVar2;
  short sVar3;
  undefined4 uVar4;
  uint uVar5;
  ushort *puVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iStack_e8;
  undefined4 uStack_d0;
  undefined4 uStack_c4;
  
  uVar10 = *(uint *)(DAT_020c3198 & 0xfffffffc) >> (DAT_020c3198 & 3) * 8 |
           *(uint *)(DAT_020c3198 & 0xfffffffc) << (DAT_020c3198 & 3) * -8 + 0x20;
  uVar5 = uVar10 + 0x20d8;
  uVar7 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  switch(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) {
  case 0:
    goto switchD_020c2918_default;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    goto LAB_020c29f0;
  case 5:
    goto LAB_020c29f0;
  case 6:
LAB_020c29f0:
    uVar4 = GetB3C4_Cell_RaceGoalS(0x22);
    uVar5 = (uint)*(ushort *)(param_1 + 0x400);
    iVar9 = param_1 + uVar5 * 8;
    sVar3 = MaybeMakeOamSlot(iVar9,0x80 - uVar5 & 0xffff,uVar4);
    puVar6 = (ushort *)(param_1 + 0x400);
    *puVar6 = *puVar6 + sVar3;
    if (uVar5 < *puVar6) {
      do {
        uVar10 = iVar9 + 4U & 3;
        uVar7 = *(uint *)(iVar9 + 4U & 0xfffffffc);
        uVar5 = uVar5 + 1;
        *(uint *)(iVar9 + 4) =
             (uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20) & 0xfffff3ff | 0x400;
        iVar9 = iVar9 + 8;
      } while ((int)uVar5 < (int)(uint)*puVar6);
    }
    goto switchD_020c2918_default;
  case 7:
    goto LAB_020c2a98;
  case 8:
LAB_020c2a98:
    uVar10 = uVar10 + 0x20dc;
    uVar5 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar5 = uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20;
    lVar2 = (longlong)DAT_020c31a4 *
            (longlong)
            ((int)((longlong)DAT_020c31a0 * (longlong)(int)uVar5 >> 0x24) - ((int)uVar5 >> 0x1f));
    if ((int)(uVar5 - (int)lVar2) < 0x20) {
      uVar4 = GetB3C4_Cell_RaceGoalS(0x2b,(int)((ulonglong)lVar2 >> 0x20));
      uVar5 = (uint)*(ushort *)(param_1 + 0x400);
      iVar9 = param_1 + uVar5 * 8;
      sVar3 = MaybeMakeOamSlot(iVar9,0x80 - uVar5 & 0xffff,uVar4);
      puVar6 = (ushort *)(param_1 + 0x400);
      *puVar6 = *puVar6 + sVar3;
      if (uVar5 < *puVar6) {
        do {
          uVar10 = iVar9 + 4U & 3;
          uVar7 = *(uint *)(iVar9 + 4U & 0xfffffffc);
          uVar5 = uVar5 + 1;
          *(uint *)(iVar9 + 4) =
               (uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20) & 0xfffff3ff | 0x400;
          iVar9 = iVar9 + 8;
        } while ((int)uVar5 < (int)(uint)*puVar6);
      }
    }
    goto switchD_020c2918_default;
  case 9:
    break;
  default:
    goto switchD_020c2918_default;
  }
  uVar4 = GetB3C4_Cell_RaceGoalS(0x21);
  uVar5 = (uint)*(ushort *)(param_1 + 0x400);
  iVar9 = param_1 + uVar5 * 8;
  sVar3 = MaybeMakeOamSlot(iVar9,0x80 - uVar5 & 0xffff,uVar4);
  puVar6 = (ushort *)(param_1 + 0x400);
  *puVar6 = *puVar6 + sVar3;
  if (uVar5 < *puVar6) {
    do {
      uVar10 = iVar9 + 4U & 3;
      uVar7 = *(uint *)(iVar9 + 4U & 0xfffffffc);
      uVar5 = uVar5 + 1;
      *(uint *)(iVar9 + 4) =
           (uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20) & 0xfffff3ff | 0x400;
      iVar9 = iVar9 + 8;
    } while ((int)uVar5 < (int)(uint)*puVar6);
  }
switchD_020c2918_default:
  uVar5 = 0;
  if (*(char *)((*(uint *)(DAT_020c31a8 & 0xfffffffc) >> (DAT_020c31a8 & 3) * 8 |
                *(uint *)(DAT_020c31a8 & 0xfffffffc) << (DAT_020c31a8 & 3) * -8 + 0x20) + 0x3d0) ==
      '\0') {
    return;
  }
  uStack_d0 = 0x1a;
  uStack_c4 = 0x1f;
  iStack_e8 = 9;
  do {
    uVar7 = *(uint *)(DAT_020c3198 & 0xfffffffc) >> (DAT_020c3198 & 3) * 8 |
            *(uint *)(DAT_020c3198 & 0xfffffffc) << (DAT_020c3198 & 3) * -8 + 0x20;
    uVar10 = uVar7 + uVar5 * 4 + 0x40;
    uVar8 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar11 = uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20;
    uVar10 = uVar7 + uVar11 * 4 + 0x20;
    uVar8 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar10 = uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20;
    iVar9 = -((int)uVar10 >> 0x1f) + (int)((longlong)DAT_020c31ac * (longlong)(int)uVar10 >> 0x25);
    iVar12 = uVar10 + iVar9 * -100;
    iVar13 = uVar10 - DAT_020c31b0 *
                      (-((int)uVar10 >> 0x1f) +
                      (int)((longlong)DAT_020c31a0 * (longlong)(int)uVar10 >> 0x22));
    if (9 < iVar9) {
      iVar13 = iStack_e8;
    }
    uVar7 = uVar7 + uVar5 * 4;
    uVar8 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    iVar12 = (int)((longlong)DAT_020c31a0 * (longlong)iVar12 >> 0x22) - (iVar12 >> 0x1f);
    if (9 < iVar9) {
      iVar9 = iVar13;
      iVar12 = iVar13;
    }
    if (uVar7 >> uVar8 * 8 == 0 && uVar7 << uVar8 * -8 + 0x20 == 0) {
      func_020c3b6c(uVar5,2);
    }
    else {
      uVar7 = GetCurrentPlayerRacerId();
      if (uVar11 == uVar7) {
        func_020c3b6c(uVar5,0);
      }
      else {
        func_020c3b6c(uVar5,1);
      }
    }
    uVar7 = (*(uint *)(DAT_020c3198 & 0xfffffffc) >> (DAT_020c3198 & 3) * 8 |
            *(uint *)(DAT_020c3198 & 0xfffffffc) << (DAT_020c3198 & 3) * -8 + 0x20) + uVar5 * 4;
    uVar8 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    if (uVar7 >> uVar8 * 8 != 0 || uVar7 << uVar8 * -8 + 0x20 != 0) {
      if (iVar9 == 0) {
        if (iVar12 != 0) goto LAB_020c2da4;
      }
      else {
        uVar4 = GetB3C4_Cell_RaceGoalS(iVar9 + 0x10);
        sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                 0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar4);
        *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
LAB_020c2da4:
        uVar4 = GetB3C4_Cell_RaceGoalS(iVar12 + 0x10);
        sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                 0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar4);
        *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
      }
      uVar4 = GetB3C4_Cell_RaceGoalS(iVar13 + 0x10);
      sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                               0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar4);
      *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
      uVar8 = *(uint *)(DAT_020c31a8 & 0xfffffffc) >> (DAT_020c31a8 & 3) * 8 |
              *(uint *)(DAT_020c31a8 & 0xfffffffc) << (DAT_020c31a8 & 3) * -8 + 0x20;
      uVar7 = uVar8 + 0x1c;
      uVar1 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      if (((uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) != 1) &&
         (uVar8 = uVar8 + 8, uVar7 = uVar8 & 3, uVar8 = *(uint *)(uVar8 & 0xfffffffc),
         (uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) != 2)) {
        iVar9 = SomeCheckLangFrench(uVar10);
        uVar4 = uStack_d0;
        if (iVar9 == 0) {
          uVar4 = 0x1b;
        }
        uVar4 = GetB3C4_Cell_RaceGoalS(uVar4);
        sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                 0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar4);
        *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
      }
      uVar10 = *(uint *)(DAT_020c31a8 & 0xfffffffc) >> (DAT_020c31a8 & 3) * 8 |
               *(uint *)(DAT_020c31a8 & 0xfffffffc) << (DAT_020c31a8 & 3) * -8 + 0x20;
      if (*(char *)(uVar10 + 0x58) != '\0') {
        uVar10 = (uVar11 & 0xffff) * 0x30 + uVar10 + 0x74;
        uVar7 = uVar10 & 3;
        uVar10 = *(uint *)(uVar10 & 0xfffffffc);
        uVar4 = uStack_c4;
        if (uVar10 >> uVar7 * 8 != 0 || uVar10 << uVar7 * -8 + 0x20 != 0) {
          uVar4 = 0x20;
        }
        uVar4 = GetB3C4_Cell_RaceGoalS(uVar4);
        sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                 0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar4);
        *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
      }
      uVar8 = *(uint *)(DAT_020c31a8 & 0xfffffffc) >> (DAT_020c31a8 & 3) * 8 |
              *(uint *)(DAT_020c31a8 & 0xfffffffc) << (DAT_020c31a8 & 3) * -8 + 0x20;
      uVar10 = uVar8 + 0x1c & 3;
      uVar7 = *(uint *)(uVar8 + 0x1c & 0xfffffffc);
      if ((((uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20) != 1) &&
          (uVar10 = uVar8 + 8 & 3, uVar7 = *(uint *)(uVar8 + 8 & 0xfffffffc),
          (uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20) != 2)) &&
         (*(short *)(uVar8 + 0x60) != 1)) {
        uVar8 = *(uint *)(DAT_020c3198 & 0xfffffffc) >> (DAT_020c3198 & 3) * 8 |
                *(uint *)(DAT_020c3198 & 0xfffffffc) << (DAT_020c3198 & 3) * -8 + 0x20;
        uVar10 = uVar8 + 0xac;
        uVar7 = uVar10 & 3;
        uVar10 = *(uint *)(uVar10 & 0xfffffffc);
        uVar10 = uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20;
        if (((uVar10 == DAT_020c31b4) || (uVar10 == DAT_020c31b8)) || (uVar10 == DAT_020c31bc)) {
          uVar10 = uVar8 + uVar11 * 4 + 0x80;
          uVar7 = uVar10 & 3;
          uVar10 = *(uint *)(uVar10 & 0xfffffffc);
          uVar4 = GetB3C4_Cell_RaceGoalS((uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) + 0x1c)
          ;
          sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                   0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar4);
          *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
        }
      }
      uVar4 = GetB3C4_Cell_RaceGoalS(uVar5 + 8);
      sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                               0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar4);
      *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
      uVar4 = GetB3C4_Cell_RaceGoalS(uVar11);
      sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                               0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar4);
      *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
      uVar4 = GetB3C4_Cell_RaceGoalS(uVar11 + 0x23);
      sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                               0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar4);
      *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
    }
    uVar5 = uVar5 + 1 & 0xffff;
    if (*(byte *)((*(uint *)(DAT_020c31a8 & 0xfffffffc) >> (DAT_020c31a8 & 3) * 8 |
                  *(uint *)(DAT_020c31a8 & 0xfffffffc) << (DAT_020c31a8 & 3) * -8 + 0x20) + 0x3d0)
        <= uVar5) {
      return;
    }
  } while( true );
}

