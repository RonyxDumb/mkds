/* Decompiled C draft; module arm9; ROM address 020c8dbc. No matching claim. */
#include "types.h"
#include "deps/020c8dbc_OamBuffer_SomeFn_1.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void OamBuffer_SomeFn_1(int param_1)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  ushort *puVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint *puVar15;
  uint uVar16;
  int local_e4;
  int local_b0;
  int iStack_a4;
  int iStack_a0;
  int iStack_9c;
  int local_84;
  int local_80;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  int iStack_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  uint uVar17;
  
  uVar2 = func_020b1dbc();
  switch(uVar2) {
  case 0:
    local_e4 = 0;
    if (*(char *)((*(uint *)(DAT_020c97ac & 0xfffffffc) >> (DAT_020c97ac & 3) * 8 |
                  *(uint *)(DAT_020c97ac & 0xfffffffc) << (DAT_020c97ac & 3) * -8 + 0x20) + 0x3d0)
        == '\0') {
      return;
    }
    iStack_a4 = 0;
    iStack_a0 = 0x5d;
    iStack_9c = 0x5e;
    do {
      uVar8 = *(uint *)(DAT_020c97b0 & 0xfffffffc) >> (DAT_020c97b0 & 3) * 8 |
              *(uint *)(DAT_020c97b0 & 0xfffffffc) << (DAT_020c97b0 & 3) * -8 + 0x20;
      uVar16 = uVar8 + local_e4 * 4 + 0x130;
      uVar5 = uVar16 & 3;
      uVar16 = *(uint *)(uVar16 & 0xfffffffc);
      uVar10 = uVar16 >> uVar5 * 8 | uVar16 << uVar5 * -8 + 0x20;
      uVar16 = uVar8 + uVar10 * 4;
      uVar5 = uVar16 & 3;
      uVar16 = *(uint *)(uVar16 & 0xfffffffc);
      if (uVar16 >> uVar5 * 8 != 0 || uVar16 << uVar5 * -8 + 0x20 != 0) {
        iVar4 = uVar8 + uVar10 * 4;
        uVar16 = iVar4 + 0x40U & 3;
        uVar13 = *(uint *)(iVar4 + 0x40U & 0xfffffffc);
        uVar5 = uVar13 >> uVar16 * 8;
        iVar3 = uVar13 << uVar16 * -8 + 0x20;
        uVar16 = iVar4 + 0x20U & 3;
        uVar13 = *(uint *)(iVar4 + 0x20U & 0xfffffffc);
        if (uVar13 >> uVar16 * 8 == 0 && uVar13 << uVar16 * -8 + 0x20 == 0) {
          uVar16 = uVar8 + uVar10 * 0xc + 0xa4;
          uVar8 = uVar16 & 3;
          uVar16 = *(uint *)(uVar16 & 0xfffffffc);
          if (((uVar16 >> uVar8 * 8 | uVar16 << uVar8 * -8 + 0x20) == 0x1000) &&
             (uVar16 = iVar4 + 0x110U & 3, uVar8 = *(uint *)(iVar4 + 0x110U & 0xfffffffc),
             uVar8 >> uVar16 * 8 == 0 && uVar8 << uVar16 * -8 + 0x20 == 0)) {
            iVar4 = GetDriverCollisionMode(uVar10 & 0xffff);
            if (iVar4 == 3) {
              uVar2 = GetB3C4_Cell_RaceS(0x10);
            }
            else {
              uVar2 = GetB3C4_Cell_RaceS(uVar10);
            }
            uVar16 = (uint)*(ushort *)(param_1 + 0x400);
            puVar15 = (uint *)(param_1 + uVar16 * 8);
            sVar1 = MaybeMakeOamSlot(puVar15,0x80 - uVar16 & 0xffff,uVar2,0);
            puVar9 = (ushort *)(param_1 + 0x400);
            *puVar9 = *puVar9 + sVar1;
            if (uVar16 < *puVar9) {
              do {
                if (uVar5 == 0 && iVar3 == 0) {
                  iVar4 = -1;
                }
                else {
                  iVar4 = 1;
                }
                uVar8 = 0xffffffff;
                if (iVar4 != -1) {
                  if (uVar5 != 0 || iVar3 != 0) {
                    uVar8 = 1;
                  }
                  if (uVar5 == 0 && iVar3 == 0) {
                    uVar8 = 0xffffffff;
                  }
                  *puVar15 = (*(uint *)((uint)puVar15 & 0xfffffffc) >> ((uint)puVar15 & 3) * 8 |
                             *(uint *)((uint)puVar15 & 0xfffffffc) <<
                             ((uint)puVar15 & 3) * -8 + 0x20) & 0xfffff3ff | (uVar8 & 3) << 10;
                }
                puVar15 = puVar15 + 2;
                uVar16 = uVar16 + 1;
              } while ((int)uVar16 < (int)(uint)*(ushort *)(param_1 + 0x400));
            }
          }
          else {
            iVar4 = func_020ae5c4(param_1);
            uVar13 = *(uint *)(DAT_020c97b0 & 0xfffffffc) >> (DAT_020c97b0 & 3) * 8 |
                     *(uint *)(DAT_020c97b0 & 0xfffffffc) << (DAT_020c97b0 & 3) * -8 + 0x20;
            uVar16 = uVar13 + uVar10 * 0xc + 0xa4;
            uVar8 = uVar16 & 3;
            uVar16 = *(uint *)(uVar16 & 0xfffffffc);
            func_020b4bf8(&iStack_48,uVar16 >> uVar8 * 8 | uVar16 << uVar8 * -8 + 0x20,
                          *(undefined2 *)(uVar13 + uVar10 * 2 + 0x100));
            iVar14 = GetDriverCollisionMode(uVar10 & 0xffff);
            if (iVar14 == 3) {
              uVar2 = GetB3C4_Cell_RaceS(0x10);
            }
            else {
              uVar2 = GetB3C4_Cell_RaceS(uVar10);
            }
            uVar16 = (uint)*(ushort *)(param_1 + 0x400);
            puVar15 = (uint *)(param_1 + uVar16 * 8);
            sVar1 = MaybeMakeOamSlot(puVar15,0x80 - uVar16 & 0xffff,uVar2,&iStack_48);
            puVar9 = (ushort *)(param_1 + 0x400);
            *puVar9 = *puVar9 + sVar1;
            if (uVar16 < *puVar9) {
              do {
                if (uVar5 == 0 && iVar3 == 0) {
                  iVar14 = -1;
                }
                else {
                  iVar14 = 1;
                }
                uVar8 = 0xffffffff;
                if (iVar14 != -1) {
                  if (uVar5 != 0 || iVar3 != 0) {
                    uVar8 = 1;
                  }
                  if (uVar5 == 0 && iVar3 == 0) {
                    uVar8 = 0xffffffff;
                  }
                  *puVar15 = (*(uint *)((uint)puVar15 & 0xfffffffc) >> ((uint)puVar15 & 3) * 8 |
                             *(uint *)((uint)puVar15 & 0xfffffffc) <<
                             ((uint)puVar15 & 3) * -8 + 0x20) & 0xfffff3ff | (uVar8 & 3) << 10;
                }
                puVar15 = puVar15 + 2;
                uVar16 = uVar16 + 1;
              } while ((int)uVar16 < (int)(uint)*(ushort *)(param_1 + 0x400));
            }
            iVar3 = param_1 + iVar4 * 0x20;
            *(short *)(iVar3 + 6) = (short)(iStack_48 >> 4);
            *(short *)(iVar3 + 0xe) = (short)(iStack_44 >> 4);
            *(short *)(iVar3 + 0x16) = (short)(iStack_40 >> 4);
            *(short *)(iVar3 + 0x1e) = (short)(iStack_3c >> 4);
          }
        }
        uVar16 = (*(uint *)(DAT_020c97b0 & 0xfffffffc) >> (DAT_020c97b0 & 3) * 8 |
                 *(uint *)(DAT_020c97b0 & 0xfffffffc) << (DAT_020c97b0 & 3) * -8 + 0x20) +
                 uVar10 * 4 + 0x170;
        uVar5 = uVar16 & 3;
        uVar16 = *(uint *)(uVar16 & 0xfffffffc);
        uVar16 = uVar16 >> uVar5 * 8 | uVar16 << uVar5 * -8 + 0x20;
        if (uVar16 != 0) {
          iVar6 = DAT_020c97b8 *
                  ((int)((longlong)DAT_020c97b4 * (longlong)(int)uVar16 >> 0x21) -
                  ((int)uVar16 >> 0x1f));
          iVar3 = iStack_9c;
          iVar4 = iStack_a0;
          iVar14 = iStack_a4;
          do {
            iVar11 = iVar4;
            if (5 < (int)(uVar16 - iVar6)) {
              iVar11 = iVar3;
            }
            uVar2 = GetB3C4_Cell_RaceS(iVar11);
            sVar1 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                     0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar2);
            iVar14 = iVar14 + 1;
            iVar4 = iVar4 + 2;
            *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar1;
            iVar3 = iVar3 + 2;
          } while (iVar14 < 3);
        }
      }
      local_e4 = local_e4 + 1;
    } while (local_e4 <
             (int)(uint)*(byte *)((*(uint *)(DAT_020c97ac & 0xfffffffc) >> (DAT_020c97ac & 3) * 8 |
                                  *(uint *)(DAT_020c97ac & 0xfffffffc) <<
                                  (DAT_020c97ac & 3) * -8 + 0x20) + 0x3d0));
    return;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  default:
    goto switchD_020c8dd0_default;
  }
  iVar3 = func_020c0dc4();
  local_b0 = 0;
  if (*(char *)((*(uint *)(DAT_020c97ac & 0xfffffffc) >> (DAT_020c97ac & 3) * 8 |
                *(uint *)(DAT_020c97ac & 0xfffffffc) << (DAT_020c97ac & 3) * -8 + 0x20) + 0x3d0) !=
      '\0') {
    local_84 = 0x5d;
    local_80 = 0x5e;
    do {
      uVar8 = *(uint *)(DAT_020c97b0 & 0xfffffffc) >> (DAT_020c97b0 & 3) * 8 |
              *(uint *)(DAT_020c97b0 & 0xfffffffc) << (DAT_020c97b0 & 3) * -8 + 0x20;
      uVar16 = uVar8 + local_b0 * 4 + 0x130;
      uVar5 = uVar16 & 3;
      uVar16 = *(uint *)(uVar16 & 0xfffffffc);
      uVar17 = uVar16 >> uVar5 * 8 | uVar16 << uVar5 * -8 + 0x20;
      uVar16 = uVar8 + uVar17 * 4;
      uVar5 = uVar16 & 3;
      uVar10 = *(uint *)(uVar16 & 0xfffffffc);
      iVar4 = uVar8 + uVar17 * 4;
      uVar16 = iVar4 + 0x150U & 3;
      uVar13 = *(uint *)(iVar4 + 0x150U & 0xfffffffc);
      uVar16 = uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20;
      if ((uVar10 >> uVar5 * 8 != 0 || uVar10 << uVar5 * -8 + 0x20 != 0) && (iVar3 <= (int)uVar16))
      {
        uVar5 = iVar4 + 0x20U & 3;
        uVar10 = *(uint *)(iVar4 + 0x20U & 0xfffffffc);
        if (uVar10 >> uVar5 * 8 == 0 && uVar10 << uVar5 * -8 + 0x20 == 0) {
          uVar5 = uVar8 + uVar17 * 0xc + 0xa4;
          uVar8 = uVar5 & 3;
          uVar13 = *(uint *)(uVar5 & 0xfffffffc);
          uVar5 = iVar4 + 0x40U & 3;
          uVar12 = *(uint *)(iVar4 + 0x40U & 0xfffffffc);
          uVar10 = uVar12 >> uVar5 * 8;
          iVar14 = uVar12 << uVar5 * -8 + 0x20;
          if (((uVar13 >> uVar8 * 8 | uVar13 << uVar8 * -8 + 0x20) == 0x1000) &&
             (uVar5 = iVar4 + 0x110U & 3, uVar8 = *(uint *)(iVar4 + 0x110U & 0xfffffffc),
             uVar8 >> uVar5 * 8 == 0 && uVar8 << uVar5 * -8 + 0x20 == 0)) {
            iVar4 = GetDriverCollisionMode(uVar17 & 0xffff);
            if (iVar4 == 3) {
              uVar2 = GetB3C4_Cell_RaceS(0x10);
            }
            else {
              uVar2 = GetB3C4_Cell_RaceS(uVar17);
            }
            uVar5 = (uint)*(ushort *)(param_1 + 0x400);
            puVar15 = (uint *)(param_1 + uVar5 * 8);
            sVar1 = MaybeMakeOamSlot(puVar15,0x80 - uVar5 & 0xffff,uVar2);
            puVar9 = (ushort *)(param_1 + 0x400);
            *puVar9 = *puVar9 + sVar1;
            if (uVar5 < *puVar9) {
              do {
                if (uVar10 == 0 && iVar14 == 0) {
                  iVar4 = -1;
                }
                else {
                  iVar4 = 1;
                }
                uVar8 = 0xffffffff;
                if (iVar4 != -1) {
                  if (uVar10 != 0 || iVar14 != 0) {
                    uVar8 = 1;
                  }
                  if (uVar10 == 0 && iVar14 == 0) {
                    uVar8 = 0xffffffff;
                  }
                  *puVar15 = (*(uint *)((uint)puVar15 & 0xfffffffc) >> ((uint)puVar15 & 3) * 8 |
                             *(uint *)((uint)puVar15 & 0xfffffffc) <<
                             ((uint)puVar15 & 3) * -8 + 0x20) & 0xfffff3ff | (uVar8 & 3) << 10;
                }
                if (uVar16 != 0xffffffff) {
                  uVar8 = (uint)(puVar15 + 1) & 3;
                  uVar13 = *(uint *)((uint)(puVar15 + 1) & 0xfffffffc);
                  puVar15[1] = (uVar13 >> uVar8 * 8 | uVar13 << uVar8 * -8 + 0x20) & 0xfffff3ff |
                               (uVar16 & 3) << 10;
                }
                uVar5 = uVar5 + 1;
                puVar15 = puVar15 + 2;
              } while ((int)uVar5 < (int)(uint)*(ushort *)(param_1 + 0x400));
            }
          }
          else {
            iVar4 = func_020ae5c4(param_1);
            uVar13 = *(uint *)(DAT_020c97b0 & 0xfffffffc) >> (DAT_020c97b0 & 3) * 8 |
                     *(uint *)(DAT_020c97b0 & 0xfffffffc) << (DAT_020c97b0 & 3) * -8 + 0x20;
            uVar5 = uVar13 + uVar17 * 4 + 0x110;
            uVar8 = uVar5 & 3;
            uVar5 = *(uint *)(uVar5 & 0xfffffffc);
            if (uVar5 >> uVar8 * 8 != 0 || uVar5 << uVar8 * -8 + 0x20 != 0) {
              func_020b6368();
            }
            uVar5 = uVar13 + uVar17 * 0xc + 0xa4;
            uVar8 = uVar5 & 3;
            uVar5 = *(uint *)(uVar5 & 0xfffffffc);
            func_020b4bf8(&local_38,uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20);
            iVar6 = GetDriverCollisionMode(uVar17 & 0xffff);
            if (iVar6 == 3) {
              uVar2 = GetB3C4_Cell_RaceS(0x10);
            }
            else {
              uVar2 = GetB3C4_Cell_RaceS(uVar17);
            }
            uVar5 = (uint)*(ushort *)(param_1 + 0x400);
            puVar15 = (uint *)(param_1 + uVar5 * 8);
            sVar1 = MaybeMakeOamSlot(puVar15,0x80 - uVar5 & 0xffff,uVar2,&local_38);
            puVar9 = (ushort *)(param_1 + 0x400);
            *puVar9 = *puVar9 + sVar1;
            if (uVar5 < *puVar9) {
              do {
                if (uVar10 == 0 && iVar14 == 0) {
                  iVar6 = -1;
                }
                else {
                  iVar6 = 1;
                }
                uVar8 = 0xffffffff;
                if (iVar6 != -1) {
                  if (uVar10 != 0 || iVar14 != 0) {
                    uVar8 = 1;
                  }
                  if (uVar10 == 0 && iVar14 == 0) {
                    uVar8 = 0xffffffff;
                  }
                  *puVar15 = (*(uint *)((uint)puVar15 & 0xfffffffc) >> ((uint)puVar15 & 3) * 8 |
                             *(uint *)((uint)puVar15 & 0xfffffffc) <<
                             ((uint)puVar15 & 3) * -8 + 0x20) & 0xfffff3ff | (uVar8 & 3) << 10;
                }
                if (uVar16 != 0xffffffff) {
                  uVar8 = (uint)(puVar15 + 1) & 3;
                  uVar13 = *(uint *)((uint)(puVar15 + 1) & 0xfffffffc);
                  puVar15[1] = (uVar13 >> uVar8 * 8 | uVar13 << uVar8 * -8 + 0x20) & 0xfffff3ff |
                               (uVar16 & 3) << 10;
                }
                uVar5 = uVar5 + 1;
                puVar15 = puVar15 + 2;
              } while ((int)uVar5 < (int)(uint)*(ushort *)(param_1 + 0x400));
            }
            iVar4 = param_1 + iVar4 * 0x20;
            *(short *)(iVar4 + 6) = (short)(local_38 >> 4);
            *(short *)(iVar4 + 0xe) = (short)(local_34 >> 4);
            *(short *)(iVar4 + 0x16) = (short)(local_30 >> 4);
            *(short *)(iVar4 + 0x1e) = (short)(local_2c >> 4);
          }
        }
        uVar16 = (*(uint *)(DAT_020c97b0 & 0xfffffffc) >> (DAT_020c97b0 & 3) * 8 |
                 *(uint *)(DAT_020c97b0 & 0xfffffffc) << (DAT_020c97b0 & 3) * -8 + 0x20) +
                 uVar17 * 4 + 0x170;
        uVar5 = uVar16 & 3;
        uVar16 = *(uint *)(uVar16 & 0xfffffffc);
        uVar16 = uVar16 >> uVar5 * 8 | uVar16 << uVar5 * -8 + 0x20;
        if (uVar16 != 0) {
          iVar11 = DAT_020c97b8 *
                   ((int)((longlong)DAT_020c97b4 * (longlong)(int)uVar16 >> 0x21) -
                   ((int)uVar16 >> 0x1f));
          iVar4 = local_80;
          iVar14 = local_84;
          iVar6 = 0;
          do {
            iVar7 = iVar14;
            if (5 < (int)(uVar16 - iVar11)) {
              iVar7 = iVar4;
            }
            uVar2 = GetB3C4_Cell_RaceS(iVar7);
            sVar1 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                     0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar2);
            iVar6 = iVar6 + 1;
            iVar14 = iVar14 + 2;
            *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar1;
            iVar4 = iVar4 + 2;
          } while (iVar6 < 3);
        }
      }
      local_b0 = local_b0 + 1;
    } while (local_b0 <
             (int)(uint)*(byte *)((*(uint *)(DAT_020c97ac & 0xfffffffc) >> (DAT_020c97ac & 3) * 8 |
                                  *(uint *)(DAT_020c97ac & 0xfffffffc) <<
                                  (DAT_020c97ac & 3) * -8 + 0x20) + 0x3d0));
  }
  uVar16 = (*(uint *)(DAT_020c97b0 & 0xfffffffc) >> (DAT_020c97b0 & 3) * 8 |
           *(uint *)(DAT_020c97b0 & 0xfffffffc) << (DAT_020c97b0 & 3) * -8 + 0x20) + 400;
  uVar5 = uVar16 & 3;
  uVar16 = *(uint *)(uVar16 & 0xfffffffc);
  func_020c092c(param_1,uVar16 >> uVar5 * 8 | uVar16 << uVar5 * -8 + 0x20,0);
switchD_020c8dd0_default:
  return;
}

