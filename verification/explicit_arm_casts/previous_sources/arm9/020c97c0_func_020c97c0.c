/* Decompiled C draft; module arm9; ROM address 020c97c0. No matching claim. */
#include "types.h"
#include "deps/020c97c0_func_020c97c0.h"

void func_020c97c0(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined2 uVar11;
  uint uVar12;
  short *psVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  bool bVar17;
  undefined6 uVar18;
  uint local_a8;
  short *local_9c;
  short *local_98;
  int local_94;
  int local_90;
  uint local_6c [8];
  undefined1 auStack_4c [12];
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  uVar1 = func_020c0db0();
  uVar4 = DAT_020c9f78;
  uVar10 = DAT_020c9f74;
  uVar14 = 0;
  if (*(char *)((*(uint *)(DAT_020c9f74 & 0xfffffffc) >> (DAT_020c9f74 & 3) * 8 |
                *(uint *)(DAT_020c9f74 & 0xfffffffc) << (DAT_020c9f74 & 3) * -8 + 0x20) + 0x3d0) !=
      '\0') {
    do {
      *(undefined4 *)
       ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
        *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + uVar14 * 4) = 0;
      *(uint *)((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + uVar14 * 4 + 0x130) =
           uVar14;
      uVar2 = GetDriverPlace(uVar14 & 0xff);
      uVar9 = uVar10 & 3;
      uVar12 = *(uint *)(uVar10 & 0xfffffffc);
      local_6c[uVar14] = uVar2;
      uVar14 = uVar14 + 1 & 0xffff;
    } while (uVar14 < *(byte *)((uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20) + 0x3d0));
  }
  uVar3 = func_020b1dbc();
  uVar14 = DAT_020c9f78;
  switch(uVar3) {
  case 0:
    uVar10 = 0;
    if (*(char *)((*(uint *)(DAT_020c9f74 & 0xfffffffc) >> (DAT_020c9f74 & 3) * 8 |
                  *(uint *)(DAT_020c9f74 & 0xfffffffc) << (DAT_020c9f74 & 3) * -8 + 0x20) + 0x3d0)
        != '\0') {
      do {
        func_020b6078(uVar10,(*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                             *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + 0x60 +
                             uVar10 * 8);
        iVar8 = (*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + uVar10 * 8;
        uVar4 = iVar8 + 0x60;
        uVar9 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        uVar2 = uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20;
        uVar4 = iVar8 + 100;
        uVar9 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        uVar4 = uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20;
        if ((((-0x10 < (int)uVar2) && ((int)uVar2 < 0x110)) && (-0x10 < (int)uVar4)) &&
           (((int)uVar4 < 0xd0 && (iVar8 = IsDriverKilledOrBeingKilled(uVar10), iVar8 == 0)))) {
          *(undefined4 *)
           ((*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
            *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + uVar10 * 4) = 1;
          uVar2 = *(uint *)(DAT_020c9f74 & 0xfffffffc) >> (DAT_020c9f74 & 3) * 8 |
                  *(uint *)(DAT_020c9f74 & 0xfffffffc) << (DAT_020c9f74 & 3) * -8 + 0x20;
          uVar4 = uVar2 + 8;
          uVar9 = uVar4 & 3;
          uVar4 = *(uint *)(uVar4 & 0xfffffffc);
          if (((uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) == 1) &&
             (uVar4 = uVar10 * 0x30 + uVar2 + 0x70, uVar9 = uVar4 & 3,
             uVar4 = *(uint *)(uVar4 & 0xfffffffc),
             (uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) == 2)) {
            *(undefined4 *)
             ((*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
              *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + uVar10 * 4 + 0x40) = 1;
          }
          else {
            *(undefined4 *)
             ((*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
              *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + uVar10 * 4 + 0x40) = 0;
          }
          GetDriverScale(uVar10 * 0xc +
                         (*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                         *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + 0xa0,uVar10);
          iVar8 = GetDriverEntry(uVar10);
          uVar4 = iVar8 + 0x180U & 3;
          uVar9 = *(uint *)(iVar8 + 0x180U & 0xfffffffc);
          if (uVar9 >> uVar4 * 8 == 0 && uVar9 << uVar4 * -8 + 0x20 == 0) {
            *(undefined2 *)
             ((*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
              *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + uVar10 * 2 + 0x100) = 0;
            *(undefined4 *)
             ((*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
              *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + uVar10 * 4 + 0x110) = 0;
          }
          else {
            iVar8 = (*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                    *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + uVar10 * 4;
            uVar4 = iVar8 + 0x110;
            uVar9 = uVar4 & 3;
            uVar4 = *(uint *)(uVar4 & 0xfffffffc);
            *(uint *)(iVar8 + 0x110) = (uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + 1;
            uVar2 = *(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                    *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20;
            uVar4 = uVar2 + uVar10 * 4 + 0x110;
            uVar9 = uVar4 & 3;
            uVar4 = *(uint *)(uVar4 & 0xfffffffc);
            uVar4 = uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20;
            iVar8 = uVar4 * 0x1000;
            *(short *)(uVar2 + uVar10 * 2 + 0x100) =
                 (short)(uVar4 * 0x10000000 + (iVar8 >> 0x1f) >> 0x10) - (short)(iVar8 >> 0x1f);
          }
        }
        uVar10 = uVar10 + 1 & 0xffff;
      } while (uVar10 < *(byte *)((*(uint *)(DAT_020c9f74 & 0xfffffffc) >> (DAT_020c9f74 & 3) * 8 |
                                  *(uint *)(DAT_020c9f74 & 0xfffffffc) <<
                                  (DAT_020c9f74 & 3) * -8 + 0x20) + 0x3d0));
    }
    goto switchD_020c9838_default;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  default:
    goto switchD_020c9838_default;
  }
  uVar10 = 0;
  uVar4 = (*(uint *)(DAT_020c9f78 & 0xfffffffc) >> (DAT_020c9f78 & 3) * 8 |
          *(uint *)(DAT_020c9f78 & 0xfffffffc) << (DAT_020c9f78 & 3) * -8 + 0x20) + 400;
  uVar9 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(undefined4 *)((uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + 4) = 0;
  if (*(char *)((*(uint *)(DAT_020c9f74 & 0xfffffffc) >> (DAT_020c9f74 & 3) * 8 |
                *(uint *)(DAT_020c9f74 & 0xfffffffc) << (DAT_020c9f74 & 3) * -8 + 0x20) + 0x3d0) !=
      '\0') {
    local_98 = (short *)0x3;
    local_90 = 0;
    local_94 = 0;
    local_9c = (short *)0x2;
    do {
      GetDriverMaybeSfxPosition(auStack_4c,uVar10 & 0xff);
      func_020b5dcc(uVar10,(*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                           *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + 0x60 +
                           uVar10 * 8,uVar1);
      iVar8 = (*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
              *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + uVar10 * 8;
      uVar4 = iVar8 + 0x60;
      uVar9 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      uVar2 = uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20;
      uVar4 = iVar8 + 100;
      uVar9 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      uVar4 = uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20;
      if ((((-0x10 < (int)uVar2) && ((int)uVar2 < 0x110)) && (-0x10 < (int)uVar4)) &&
         (((int)uVar4 < 0xd0 && (iVar8 = IsDriverKilledOrBeingKilled(uVar10), iVar8 == 0)))) {
        *(undefined4 *)
         ((*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
          *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + uVar10 * 4) = 1;
        uVar3 = func_020b4dc4(uVar10);
        psVar13 = (short *)&PrefetchAbort;
        *(undefined4 *)
         ((*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
          *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + uVar10 * 4 + 0x40) = uVar3;
        GetDriverScale(uVar10 * 0xc +
                       (*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                       *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + 0xa0,uVar10);
        iVar8 = GetDriverEntry(uVar10);
        uVar4 = iVar8 + 0x180U & 3;
        uVar9 = *(uint *)(iVar8 + 0x180U & 0xfffffffc);
        if (uVar9 >> uVar4 * 8 == 0 && uVar9 << uVar4 * -8 + 0x20 == 0) {
          *(undefined2 *)
           ((*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
            *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + uVar10 * 2 + 0x100) = 0;
          *(undefined4 *)
           ((*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
            *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + uVar10 * 4 + 0x110) = 0;
        }
        else {
          iVar8 = (*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                  *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + uVar10 * 4;
          uVar4 = iVar8 + 0x110;
          uVar9 = uVar4 & 3;
          uVar4 = *(uint *)(uVar4 & 0xfffffffc);
          *(uint *)(iVar8 + 0x110) = (uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + 1;
          uVar2 = *(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                  *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20;
          uVar4 = uVar2 + uVar10 * 4 + 0x110;
          uVar9 = uVar4 & 3;
          uVar4 = *(uint *)(uVar4 & 0xfffffffc);
          uVar4 = uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20;
          iVar8 = uVar4 * 0x1000;
          psVar13 = (short *)(uVar2 + uVar10 * 2 + 0x100);
          *psVar13 = (short)(uVar4 * 0x10000000 + (iVar8 >> 0x1f) >> 0x10) - (short)(iVar8 >> 0x1f);
        }
        iVar8 = CheckVectorBounds_Clock_Airship(auStack_4c);
        if (iVar8 != 0) {
          psVar13 = local_9c;
        }
        if (iVar8 == 0) {
          psVar13 = local_98;
        }
        *(short **)
         ((*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
          *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + uVar10 * 4 + 0x150) =
             psVar13;
        iVar8 = uVar10 * 0x210 +
                (*(uint *)(DAT_020c9f7c & 0xfffffffc) >> (DAT_020c9f7c & 3) * 8 |
                *(uint *)(DAT_020c9f7c & 0xfffffffc) << (DAT_020c9f7c & 3) * -8 + 0x20);
        uVar4 = (*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + 400;
        uVar9 = uVar4 & 3;
        uVar12 = *(uint *)(uVar4 & 0xfffffffc);
        uVar4 = iVar8 + 0x78;
        uVar2 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
        uVar4 = (uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20) + 4;
        uVar9 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        local_a8 = uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20;
        uVar3 = func_020c0db0();
        if (0 < (int)uVar2) {
          iVar15 = local_a8 * 0x14;
          iVar16 = local_94;
          do {
            uVar4 = iVar8 + 0x6c + iVar16 * 4;
            uVar9 = uVar4 & 3;
            uVar4 = *(uint *)(uVar4 & 0xfffffffc);
            uVar12 = uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20;
            uVar4 = uVar12 + 0x74 & 3;
            uVar9 = *(uint *)(uVar12 + 0x74 & 0xfffffffc);
            iVar6 = local_90;
            if (((uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) & 0x80000) == 0) {
              iVar6 = uVar12 + 0x50;
            }
            iVar5 = func_020f91e0(uVar12);
            if ((iVar6 == 0) || (iVar5 == 0)) goto LAB_020c9de8;
            func_020b4f64(&local_34,auStack_4c,iVar6);
            local_40 = local_34;
            uStack_3c = uStack_30;
            uStack_38 = uStack_2c;
            uVar4 = (*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                    *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + 400;
            uVar9 = uVar4 & 3;
            uVar4 = *(uint *)(uVar4 & 0xfffffffc);
            uVar4 = (uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + 0x10;
            uVar9 = uVar4 & 3;
            uVar4 = *(uint *)(uVar4 & 0xfffffffc);
            iVar6 = func_020b5ae8(&local_40,
                                  (uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + iVar15,uVar3,0
                                  ,1);
            if (iVar6 == 0) goto LAB_020c9de8;
            uVar4 = uVar12 + 0x44 & 3;
            uVar9 = *(uint *)(uVar12 + 0x44 & 0xfffffffc);
            switch(uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) {
            case 0:
              uVar7 = GetB3C4_Cell_RaceS(0x4c);
              uVar4 = (*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                      *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + 400;
              uVar9 = uVar4 & 3;
              uVar4 = *(uint *)(uVar4 & 0xfffffffc);
              uVar4 = (uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + 0x10;
              uVar9 = uVar4 & 3;
              uVar4 = *(uint *)(uVar4 & 0xfffffffc);
              *(undefined4 *)((uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + iVar15 + 8) =
                   uVar7;
              break;
            case 1:
              uVar7 = GetB3C4_Cell_RaceS(0x4d);
              uVar4 = (*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                      *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + 400;
              uVar9 = uVar4 & 3;
              uVar4 = *(uint *)(uVar4 & 0xfffffffc);
              uVar4 = (uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + 0x10;
              uVar9 = uVar4 & 3;
              uVar4 = *(uint *)(uVar4 & 0xfffffffc);
              *(undefined4 *)((uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + iVar15 + 8) =
                   uVar7;
              break;
            case 2:
              uVar7 = GetB3C4_Cell_RaceS(0x4b);
              uVar4 = (*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                      *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + 400;
              uVar9 = uVar4 & 3;
              uVar4 = *(uint *)(uVar4 & 0xfffffffc);
              uVar4 = (uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + 0x10;
              uVar9 = uVar4 & 3;
              uVar4 = *(uint *)(uVar4 & 0xfffffffc);
              *(undefined4 *)((uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + iVar15 + 8) =
                   uVar7;
              break;
            case 3:
            default:
switchD_020c9c60_default:
              uVar7 = GetB3C4_Cell_RaceS(0x4c);
              uVar4 = (*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                      *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + 400;
              uVar9 = uVar4 & 3;
              uVar4 = *(uint *)(uVar4 & 0xfffffffc);
              uVar4 = (uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + 0x10;
              uVar9 = uVar4 & 3;
              uVar4 = *(uint *)(uVar4 & 0xfffffffc);
              *(undefined4 *)((uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + iVar15 + 8) =
                   uVar7;
              break;
            case 4:
              goto switchD_020c9c60_default;
            case 5:
              uVar7 = GetB3C4_Cell_RaceS(0x56);
              uVar4 = (*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                      *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + 400;
              uVar9 = uVar4 & 3;
              uVar4 = *(uint *)(uVar4 & 0xfffffffc);
              uVar4 = (uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + 0x10;
              uVar9 = uVar4 & 3;
              uVar4 = *(uint *)(uVar4 & 0xfffffffc);
              *(undefined4 *)((uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + iVar15 + 8) =
                   uVar7;
              break;
            case 6:
              goto switchD_020c9c60_default;
            case 7:
              uVar7 = GetB3C4_Cell_RaceS(0x54);
              uVar4 = (*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                      *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + 400;
              uVar9 = uVar4 & 3;
              uVar4 = *(uint *)(uVar4 & 0xfffffffc);
              uVar4 = (uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + 0x10;
              uVar9 = uVar4 & 3;
              uVar4 = *(uint *)(uVar4 & 0xfffffffc);
              *(undefined4 *)((uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + iVar15 + 8) =
                   uVar7;
              break;
            case 8:
              uVar7 = GetB3C4_Cell_RaceS(0x4e);
              uVar4 = (*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                      *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + 400;
              uVar9 = uVar4 & 3;
              uVar4 = *(uint *)(uVar4 & 0xfffffffc);
              uVar4 = (uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + 0x10;
              uVar9 = uVar4 & 3;
              uVar4 = *(uint *)(uVar4 & 0xfffffffc);
              *(undefined4 *)((uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + iVar15 + 8) =
                   uVar7;
              break;
            case 9:
              uVar7 = GetB3C4_Cell_RaceS(0x55);
              uVar4 = (*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                      *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + 400;
              uVar9 = uVar4 & 3;
              uVar4 = *(uint *)(uVar4 & 0xfffffffc);
              uVar4 = (uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + 0x10;
              uVar9 = uVar4 & 3;
              uVar4 = *(uint *)(uVar4 & 0xfffffffc);
              *(undefined4 *)((uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + iVar15 + 8) =
                   uVar7;
            }
            uVar18 = CheckVectorBounds_Clock_Airship(&local_40);
            uVar11 = (undefined2)((uint6)uVar18 >> 0x20);
            bVar17 = (int)uVar18 != 0;
            if (bVar17) {
              uVar11 = 2;
            }
            uVar4 = (*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                    *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + 400;
            uVar9 = uVar4 & 3;
            uVar4 = *(uint *)(uVar4 & 0xfffffffc);
            if (!bVar17) {
              uVar11 = 3;
            }
            uVar4 = (uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + 0x10;
            uVar9 = uVar4 & 3;
            uVar4 = *(uint *)(uVar4 & 0xfffffffc);
            *(undefined2 *)((uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + iVar15 + 0xc) =
                 uVar11;
            uVar4 = uVar12 + 0x74 & 3;
            uVar9 = *(uint *)(uVar12 + 0x74 & 0xfffffffc);
            local_a8 = local_a8 + 1;
            uVar4 = (uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) & 0x40000;
            bVar17 = uVar4 != 0;
            if (bVar17) {
              uVar4 = 1;
            }
            uVar11 = (undefined2)uVar4;
            uVar4 = (*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                    *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + 400;
            uVar9 = uVar4 & 3;
            uVar4 = *(uint *)(uVar4 & 0xfffffffc);
            if (!bVar17) {
              uVar11 = 0;
            }
            uVar4 = (uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + 0x10;
            uVar9 = uVar4 & 3;
            uVar4 = *(uint *)(uVar4 & 0xfffffffc);
            *(undefined2 *)((uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + iVar15 + 0xe) =
                 uVar11;
            iVar15 = iVar15 + 0x14;
LAB_020c9de8:
            iVar16 = iVar16 + 1;
          } while (iVar16 < (int)uVar2);
        }
        uVar4 = (*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20) + 400;
        uVar9 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        *(uint *)((uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + 4) = local_a8;
      }
      uVar10 = uVar10 + 1 & 0xffff;
    } while (uVar10 < *(byte *)((*(uint *)(DAT_020c9f74 & 0xfffffffc) >> (DAT_020c9f74 & 3) * 8 |
                                *(uint *)(DAT_020c9f74 & 0xfffffffc) <<
                                (DAT_020c9f74 & 3) * -8 + 0x20) + 0x3d0));
  }
switchD_020c9838_default:
  uVar9 = DAT_020c9f80;
  uVar4 = DAT_020c9f78;
  uVar10 = DAT_020c9f74;
  uVar14 = 0;
  uVar2 = *(uint *)(DAT_020c9f74 & 0xfffffffc) >> (DAT_020c9f74 & 3) * 8 |
          *(uint *)(DAT_020c9f74 & 0xfffffffc) << (DAT_020c9f74 & 3) * -8 + 0x20;
  uVar12 = (uint)*(byte *)(uVar2 + 0x3d0);
  if (uVar12 != 0) {
    do {
      iVar8 = GetDriverCollisionMode(uVar14);
      if (iVar8 == 1) {
        iVar8 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + uVar14 * 4;
        uVar2 = iVar8 + 0x170;
        uVar12 = uVar2 & 3;
        uVar2 = *(uint *)(uVar2 & 0xfffffffc);
        *(uint *)(iVar8 + 0x170) = (uVar2 >> uVar12 * 8 | uVar2 << uVar12 * -8 + 0x20) + 1;
      }
      else {
        *(undefined4 *)
         ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + uVar14 * 4 + 0x170) = 0;
      }
      uVar2 = GetCurrentPlayerRacerId();
      if ((uVar14 == uVar2) ||
         (iVar8 = GetDriverEntry(uVar14), uVar2 = iVar8 + 0x7cU & 3,
         uVar12 = *(uint *)(iVar8 + 0x7cU & 0xfffffffc),
         ((uVar12 >> uVar2 * 8 | uVar12 << uVar2 * -8 + 0x20) & uVar9) == 0)) {
        *(undefined4 *)
         ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + uVar14 * 4 + 0x20) = 0;
      }
      else {
        *(undefined4 *)
         ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + uVar14 * 4 + 0x20) = 1;
      }
      uVar2 = uVar10 & 3;
      uVar12 = *(uint *)(uVar10 & 0xfffffffc);
      uVar2 = uVar12 >> uVar2 * 8 | uVar12 << uVar2 * -8 + 0x20;
      uVar12 = (uint)*(byte *)(uVar2 + 0x3d0);
      uVar14 = uVar14 + 1 & 0xffff;
    } while (uVar14 < uVar12);
  }
  uVar4 = DAT_020c9f78;
  uVar10 = DAT_020c9f74;
  uVar14 = 0;
  if (uVar12 != 0) {
    do {
      uVar9 = uVar4 & 3;
      uVar2 = *(uint *)(uVar4 & 0xfffffffc);
      uVar9 = (uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20) + uVar14 * 4 + 0x40;
      uVar2 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      if (uVar9 >> uVar2 * 8 == 0 && uVar9 << uVar2 * -8 + 0x20 == 0) {
        local_6c[uVar14] = local_6c[uVar14] - 0x20;
      }
      uVar9 = GetCurrentPlayerRacerId();
      bVar17 = uVar14 == uVar9;
      if (bVar17) {
        uVar9 = local_6c[uVar14];
      }
      if (bVar17) {
        local_6c[uVar14] = uVar9 - 0x10;
      }
      uVar9 = uVar10 & 3;
      uVar2 = *(uint *)(uVar10 & 0xfffffffc);
      uVar2 = uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20;
      uVar14 = uVar14 + 1 & 0xffff;
    } while (uVar14 < *(byte *)(uVar2 + 0x3d0));
  }
  uVar14 = uVar2 + 8 & 3;
  uVar10 = *(uint *)(uVar2 + 8 & 0xfffffffc);
  if ((uVar10 >> uVar14 * 8 | uVar10 << uVar14 * -8 + 0x20) != 1) {
    func_020ae770((*(uint *)(DAT_020c9f78 & 0xfffffffc) >> (DAT_020c9f78 & 3) * 8 |
                  *(uint *)(DAT_020c9f78 & 0xfffffffc) << (DAT_020c9f78 & 3) * -8 + 0x20) + 0x130,
                  local_6c);
    return;
  }
  return;
}

