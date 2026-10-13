/* Decompiled C draft; module arm9; ROM address 020c3e44. No matching claim. */
#include "types.h"
#include "deps/020c3e44_func_020c3e44.h"

void func_020c3e44(int param_1)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  ushort *puVar10;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  uint uVar14;
  int iVar15;
  int iStack_80;
  int iStack_78;
  int iStack_74;
  int iStack_70;
  int iStack_6c;
  int iStack_68;
  int iStack_5c;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  
  uVar8 = (*(uint *)(DAT_020c43b4 & 0xfffffffc) >> (DAT_020c43b4 & 3) * 8 |
          *(uint *)(DAT_020c43b4 & 0xfffffffc) << (DAT_020c43b4 & 3) * -8 + 0x20) + 8;
  uVar9 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  if ((uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) != 1) {
    return;
  }
  uVar9 = *(uint *)(DAT_020c43b8 & 0xfffffffc) >> (DAT_020c43b8 & 3) * 8 |
          *(uint *)(DAT_020c43b8 & 0xfffffffc) << (DAT_020c43b8 & 3) * -8 + 0x20;
  uVar8 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  if (uVar9 >> uVar8 * 8 == 0 && uVar9 << uVar8 * -8 + 0x20 == 0) {
    return;
  }
  iVar3 = func_020ae5c4();
  iVar12 = 1;
  do {
    func_020ae5c4(param_1);
    iVar12 = iVar12 + 1;
  } while (iVar12 < 0x10);
  iVar12 = func_020b1d50();
  if (iVar12 * 3 < 1) {
    iVar12 = func_020b1d50();
    uVar4 = FUN_02132440(iVar12 * 0x3000);
    func_021329f8(uVar4,0x3f000000);
  }
  else {
    iVar12 = func_020b1d50();
    uVar4 = FUN_02132440(iVar12 * 0x3000);
    func_02131234(0x3f000000,uVar4);
  }
  uVar8 = func_021322c8();
  iVar12 = 0;
  uVar8 = (uint)((ulonglong)uVar8 * 0x14) >> 0xc |
          (((int)uVar8 >> 0x1f) * 0x14 + (int)((ulonglong)uVar8 * 0x14 >> 0x20)) * 0x100000;
  if (*(char *)((*(uint *)(DAT_020c43b4 & 0xfffffffc) >> (DAT_020c43b4 & 3) * 8 |
                *(uint *)(DAT_020c43b4 & 0xfffffffc) << (DAT_020c43b4 & 3) * -8 + 0x20) + 0x3d0) !=
      '\0') {
    iStack_78 = 0;
    iStack_74 = 0;
    iStack_68 = 0;
    iStack_5c = 0;
    do {
      uVar5 = *(uint *)(DAT_020c43b8 & 0xfffffffc) >> (DAT_020c43b8 & 3) * 8 |
              *(uint *)(DAT_020c43b8 & 0xfffffffc) << (DAT_020c43b8 & 3) * -8 + 0x20;
      uVar9 = uVar5 + iVar12 * 4 + 4;
      uVar14 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      if (uVar9 >> uVar14 * 8 != 0 || uVar9 << uVar14 * -8 + 0x20 != 0) {
        uVar9 = (*(uint *)(DAT_020c43bc & 0xfffffffc) >> (DAT_020c43bc & 3) * 8 |
                *(uint *)(DAT_020c43bc & 0xfffffffc) << (DAT_020c43bc & 3) * -8 + 0x20) + 0x4cc;
        uVar14 = uVar9 & 3;
        uVar9 = *(uint *)(uVar9 & 0xfffffffc);
        if ((uVar9 >> uVar14 * 8 == 0 && uVar9 << uVar14 * -8 + 0x20 == 0) &&
           (uVar9 = uVar5 + iVar12 * 0x40 + 0x790, uVar14 = uVar9 & 3,
           uVar9 = *(uint *)(uVar9 & 0xfffffffc),
           0 < (int)(uVar9 >> uVar14 * 8 | uVar9 << uVar14 * -8 + 0x20))) {
          iStack_70 = 0;
          iVar15 = iStack_68;
          do {
            uVar9 = uVar5 + iVar12 * 0x40 + iVar15 * 4 + 0x7c4;
            uVar14 = uVar9 & 3;
            uVar9 = *(uint *)(uVar9 & 0xfffffffc);
            if (((int)(uVar9 >> uVar14 * 8 | uVar9 << uVar14 * -8 + 0x20) < 0x28) &&
               (iVar6 = func_020b5ae8(uVar5 + DAT_020c43c0 + iStack_78 + iStack_70,&iStack_48,uVar8,
                                      1), iVar6 != 0)) {
              uVar9 = (*(uint *)(DAT_020c43b8 & 0xfffffffc) >> (DAT_020c43b8 & 3) * 8 |
                      *(uint *)(DAT_020c43b8 & 0xfffffffc) << (DAT_020c43b8 & 3) * -8 + 0x20) +
                      iVar12 * 0x40 + iVar15 * 4 + 0x7b8;
              uVar14 = uVar9 & 3;
              uVar9 = *(uint *)(uVar9 & 0xfffffffc);
              uVar14 = uVar9 >> uVar14 * 8 | uVar9 << uVar14 * -8 + 0x20;
              uVar4 = GetB3C4_Cell_RaceS(0x4f);
              uVar9 = (uint)*(ushort *)(param_1 + 0x400);
              iStack_38 = iStack_48 << 0xc;
              iStack_34 = iStack_44 << 0xc;
              iVar6 = param_1 + uVar9 * 8;
              sVar2 = MaybeMakeOamSlot(iVar6,0x80 - uVar9 & 0xffff,uVar4,0);
              puVar10 = (ushort *)(param_1 + 0x400);
              *puVar10 = *puVar10 + sVar2;
              if (uVar9 < *puVar10) {
                do {
                  if (uVar14 != 0xffffffff) {
                    uVar5 = iVar6 + 4U & 3;
                    uVar11 = *(uint *)(iVar6 + 4U & 0xfffffffc);
                    *(uint *)(iVar6 + 4) =
                         (uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20) & 0xfffff3ff |
                         (uVar14 & 3) << 10;
                  }
                  uVar9 = uVar9 + 1;
                  iVar6 = iVar6 + 8;
                } while ((int)uVar9 < (int)(uint)*(ushort *)(param_1 + 0x400));
              }
            }
            iVar15 = iVar15 + 1;
            iStack_70 = iStack_70 + 0xc;
            uVar5 = *(uint *)(DAT_020c43b8 & 0xfffffffc) >> (DAT_020c43b8 & 3) * 8 |
                    *(uint *)(DAT_020c43b8 & 0xfffffffc) << (DAT_020c43b8 & 3) * -8 + 0x20;
            uVar9 = uVar5 + iVar12 * 0x40 + 0x790;
            uVar14 = uVar9 & 3;
            uVar9 = *(uint *)(uVar9 & 0xfffffffc);
          } while (iVar15 < (int)(uVar9 >> uVar14 * 8 | uVar9 << uVar14 * -8 + 0x20));
        }
        iStack_6c = 0;
        iVar15 = iStack_5c;
        do {
          uVar9 = *(uint *)(DAT_020c43b8 & 0xfffffffc) >> (DAT_020c43b8 & 3) * 8 |
                  *(uint *)(DAT_020c43b8 & 0xfffffffc) << (DAT_020c43b8 & 3) * -8 + 0x20;
          iVar6 = func_020b6368();
          uVar1 = *(ushort *)(iVar15 + iStack_74 + uVar9 + 0x1c);
          iVar7 = func_020b5ae8(uVar9 + 0x10 + iStack_74 + iVar15,&iStack_40,uVar8,1);
          if (iVar7 != 0) {
            uVar9 = iVar15 + iStack_74 +
                             (*(uint *)(DAT_020c43b8 & 0xfffffffc) >> (DAT_020c43b8 & 3) * 8 |
                             *(uint *)(DAT_020c43b8 & 0xfffffffc) << (DAT_020c43b8 & 3) * -8 + 0x20)
                    + 0x20;
            uVar14 = uVar9 & 3;
            uVar9 = *(uint *)(uVar9 & 0xfffffffc);
            switch(uVar9 >> uVar14 * 8 | uVar9 << uVar14 * -8 + 0x20) {
            case 0:
              iStack_80 = 0;
              break;
            case 1:
              iStack_80 = GetB3C4_Cell_RaceS(0x51);
              break;
            case 2:
              iStack_80 = GetB3C4_Cell_RaceS(0x52);
              break;
            case 3:
              iStack_80 = GetB3C4_Cell_RaceS(0x53);
            }
            if (iStack_80 != 0) {
              uVar11 = (uint)*(ushort *)(param_1 + 0x400);
              uVar5 = *(uint *)(DAT_020c43b8 & 0xfffffffc) >> (DAT_020c43b8 & 3) * 8 |
                      *(uint *)(DAT_020c43b8 & 0xfffffffc) << (DAT_020c43b8 & 3) * -8 + 0x20;
              uVar9 = iVar15 + iStack_74 + uVar5 + 0x24;
              uVar14 = uVar9 & 3;
              uVar9 = *(uint *)(uVar9 & 0xfffffffc);
              uVar9 = uVar9 >> uVar14 * 8 | uVar9 << uVar14 * -8 + 0x20;
              iStack_30 = iStack_40 << 0xc;
              iStack_2c = iStack_3c << 0xc;
              puVar13 = (uint *)(param_1 + uVar11 * 8);
              sVar2 = MaybeMakeOamSlot(puVar13,0x80 - uVar11 & 0xffff,iStack_80,
                                       uVar5 + 0x810 +
                                       ((int)((((uint)uVar1 + iVar6 & 0xffff) + 0x800) * 0x10000 >>
                                             0xc) >> 0x10) * 0x10);
              puVar10 = (ushort *)(param_1 + 0x400);
              *puVar10 = *puVar10 + sVar2;
              if (uVar11 < *puVar10) {
                do {
                  if (iVar12 == 0) {
                    iVar6 = -1;
                  }
                  else {
                    iVar6 = 1;
                  }
                  uVar14 = 0xffffffff;
                  if (iVar6 != -1) {
                    if (iVar12 != 0) {
                      uVar14 = 1;
                    }
                    if (iVar12 == 0) {
                      uVar14 = 0xffffffff;
                    }
                    *puVar13 = (*(uint *)((uint)puVar13 & 0xfffffffc) >> ((uint)puVar13 & 3) * 8 |
                               *(uint *)((uint)puVar13 & 0xfffffffc) <<
                               ((uint)puVar13 & 3) * -8 + 0x20) & 0xfffff3ff | (uVar14 & 3) << 10;
                  }
                  if (uVar9 != 0xffffffff) {
                    uVar14 = (uint)(puVar13 + 1) & 3;
                    uVar5 = *(uint *)((uint)(puVar13 + 1) & 0xfffffffc);
                    puVar13[1] = (uVar5 >> uVar14 * 8 | uVar5 << uVar14 * -8 + 0x20) & 0xfffff3ff |
                                 (uVar9 & 3) << 10;
                  }
                  uVar11 = uVar11 + 1;
                  puVar13 = puVar13 + 2;
                } while ((int)uVar11 < (int)(uint)*(ushort *)(param_1 + 0x400));
              }
            }
          }
          iVar15 = iVar15 + 0x18;
          iStack_6c = iStack_6c + 1;
        } while (iStack_6c < 0x28);
      }
      iVar12 = iVar12 + 1;
      iStack_78 = iStack_78 + 0x40;
      iStack_74 = iStack_74 + 0x3c0;
    } while (iVar12 < (int)(uint)*(byte *)((*(uint *)(DAT_020c43b4 & 0xfffffffc) >>
                                            (DAT_020c43b4 & 3) * 8 |
                                           *(uint *)(DAT_020c43b4 & 0xfffffffc) <<
                                           (DAT_020c43b4 & 3) * -8 + 0x20) + 0x3d0));
  }
  uVar8 = DAT_020c43b8;
  iVar12 = 0;
  iVar15 = 0;
  do {
    uVar9 = uVar8 & 3;
    uVar14 = *(uint *)(uVar8 & 0xfffffffc);
    iVar6 = param_1 + iVar3 * 0x20 + iVar12 * 0x20;
    iVar7 = (uVar14 >> uVar9 * 8 | uVar14 << uVar9 * -8 + 0x20) + 0x810;
    uVar9 = iVar7 + iVar15;
    uVar14 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    iVar7 = iVar7 + iVar15;
    *(short *)(iVar6 + 6) = (short)((int)(uVar9 >> uVar14 * 8 | uVar9 << uVar14 * -8 + 0x20) >> 4);
    uVar9 = iVar7 + 4U & 3;
    uVar14 = *(uint *)(iVar7 + 4U & 0xfffffffc);
    iVar12 = iVar12 + 1;
    *(short *)(iVar6 + 0xe) = (short)((int)(uVar14 >> uVar9 * 8 | uVar14 << uVar9 * -8 + 0x20) >> 4)
    ;
    uVar9 = iVar7 + 8U & 3;
    uVar14 = *(uint *)(iVar7 + 8U & 0xfffffffc);
    *(short *)(iVar6 + 0x16) =
         (short)((int)(uVar14 >> uVar9 * 8 | uVar14 << uVar9 * -8 + 0x20) >> 4);
    uVar9 = iVar7 + 0xcU & 3;
    uVar14 = *(uint *)(iVar7 + 0xcU & 0xfffffffc);
    iVar15 = iVar15 + 0x10;
    *(short *)(iVar6 + 0x1e) =
         (short)((int)(uVar14 >> uVar9 * 8 | uVar14 << uVar9 * -8 + 0x20) >> 4);
  } while (iVar12 < 0x10);
  return;
}

