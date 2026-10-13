/* Decompiled C draft; module arm9; ROM address 020bc208. No matching claim. */
#include "types.h"
#include "deps/020bc208_func_020bc208.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_020bc208(int param_1)

{
  int iVar1;
  short sVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uStack_b4;
  uint uStack_b0;
  int iStack_ac;
  int iStack_a8;
  int iStack_a4;
  int iStack_a0;
  int iStack_9c;
  int iStack_98;
  int iStack_94;
  int iStack_90;
  int iStack_8c;
  undefined4 uStack_88;
  int iStack_84;
  undefined4 uStack_80;
  int iStack_7c;
  undefined4 uStack_78;
  int iStack_74;
  undefined4 uStack_70;
  int iStack_6c;
  undefined4 uStack_68;
  int iStack_64;
  undefined4 uStack_60;
  int iStack_5c;
  undefined4 uStack_58;
  int iStack_54;
  undefined4 uStack_50;
  int iStack_4c;
  undefined4 uStack_48;
  int iStack_44;
  undefined4 uStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  uint uVar7;
  
  uVar8 = DAT_020bc940 & 3;
  uVar11 = *(uint *)(DAT_020bc940 & 0xfffffffc);
  uVar4 = DAT_020bc940 + 4 & 3;
  uVar10 = *(uint *)(DAT_020bc940 + 4 & 0xfffffffc);
  uVar9 = *(uint *)(DAT_020bc944 & 0xfffffffc) >> (DAT_020bc944 & 3) * 8 |
          *(uint *)(DAT_020bc944 & 0xfffffffc) << (DAT_020bc944 & 3) * -8 + 0x20;
  uVar7 = uVar9 + 0xc & 3;
  uVar6 = *(uint *)(uVar9 + 0xc & 0xfffffffc);
  uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  if (uVar7 == 4) {
    return;
  }
  if (uVar7 == 1) {
    return;
  }
  uVar7 = uVar9 + 8 & 3;
  uVar6 = *(uint *)(uVar9 + 8 & 0xfffffffc);
  uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  if (uVar7 != 4) goto LAB_020bc2bc;
  switch(*(undefined1 *)(uVar9 + 0x2f)) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    goto LAB_020bc29c;
  case 3:
    break;
  case 4:
    goto LAB_020bc29c;
  case 5:
    break;
  case 6:
    goto LAB_020bc29c;
  case 7:
    break;
  case 8:
    break;
  case 9:
    break;
  case 10:
LAB_020bc29c:
    uVar6 = (*(uint *)(DAT_020bc948 & 0xfffffffc) >> (DAT_020bc948 & 3) * 8 |
            *(uint *)(DAT_020bc948 & 0xfffffffc) << (DAT_020bc948 & 3) * -8 + 0x20) + 8;
    uVar9 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    if (1 < (int)(uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20)) {
LAB_020bc2bc:
      if (uVar7 == 2) {
        return;
      }
      uVar3 = GetB3C4_Cell_RaceM(0x20);
      iVar5 = (uVar11 >> uVar8 * 8 | uVar11 << uVar8 * -8 + 0x20) << 0xc;
      iVar1 = (uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20) << 0xc;
      iStack_ac = iVar5;
      iStack_a8 = iVar1;
      sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                               0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3);
      uVar7 = DAT_020bc948;
      *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
      uVar4 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      uVar8 = uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20;
      uVar4 = uVar8 + 0x10 & 3;
      uVar7 = *(uint *)(uVar8 + 0x10 & 0xfffffffc);
      if (uVar7 >> uVar4 * 8 != 0 || uVar7 << uVar4 * -8 + 0x20 != 0) {
        uVar3 = GetB3C4_Cell_RaceM((*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                                   *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + 0x21)
        ;
        iStack_a4 = iVar5;
        iStack_a0 = iVar1;
        sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                 0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3);
        *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
      }
      uVar4 = (*(uint *)(DAT_020bc948 & 0xfffffffc) >> (DAT_020bc948 & 3) * 8 |
              *(uint *)(DAT_020bc948 & 0xfffffffc) << (DAT_020bc948 & 3) * -8 + 0x20) + 8;
      uVar7 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      uVar4 = uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20;
      if (uVar4 == 2) {
        uVar3 = GetB3C4_Cell_RaceM(0x26);
        iStack_9c = iVar5;
        iStack_98 = iVar1;
        sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                 0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3);
        *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
      }
      else if (uVar4 == 4) {
        uVar3 = GetB3C4_Cell_RaceM(0x27);
        iStack_94 = iVar5;
        iStack_90 = iVar1;
        sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                 0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3);
        *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
      }
      iVar5 = func_020b19f8();
      if (iVar5 == 0) {
        return;
      }
      iVar5 = func_020b1a20();
      if (iVar5 == 0) {
        return;
      }
      iVar5 = func_020b1a0c();
      if (iVar5 - DAT_020bc950 *
                  ((int)((longlong)DAT_020bc94c * (longlong)iVar5 >> 0x23) - (iVar5 >> 0x1f)) < 0x18
         ) {
        iStack_3c = *DAT_020bc954;
        iStack_38 = DAT_020bc954[1];
        iStack_34 = DAT_020bc954[2];
        iStack_30 = DAT_020bc954[3];
        iStack_2c = DAT_020bc954[4];
        iStack_28 = DAT_020bc954[5];
        iStack_24 = DAT_020bc954[6];
        iStack_20 = DAT_020bc954[7];
        iStack_1c = DAT_020bc954[8];
        iStack_18 = DAT_020bc954[9];
        func_020b19b4(&uStack_b4,&uStack_b0);
        uVar3 = GetB3C4_Cell_RaceTaM
                          (*(uint *)(uStack_b4 & 0xfffffffc) >> (uStack_b4 & 3) * 8 == 0 &&
                           *(uint *)(uStack_b4 & 0xfffffffc) << (uStack_b4 & 3) * -8 + 0x20 == 0);
        iStack_8c = iStack_3c << 0xc;
        uStack_88 = 0x58000;
        sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                 0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3);
        *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
        uVar4 = *(uint *)(uStack_b0 & 0xfffffffc) >> (uStack_b0 & 3) * 8 |
                *(uint *)(uStack_b0 & 0xfffffffc) << (uStack_b0 & 3) * -8 + 0x20;
        if (uVar4 != 0) {
          uVar3 = GetB3C4_Cell_RaceTaM(uVar4 + 2);
          iStack_84 = iStack_38 << 0xc;
          uStack_80 = 0x58000;
          sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                   0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3);
          *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
        }
        uVar4 = uStack_b0 + 4 & 3;
        uVar7 = *(uint *)(uStack_b0 + 4 & 0xfffffffc);
        uVar3 = GetB3C4_Cell_RaceTaM((uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + 2);
        iStack_7c = iStack_34 << 0xc;
        uStack_78 = 0x58000;
        sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                 0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3);
        *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
        uVar3 = GetB3C4_Cell_RaceTaM(0xc);
        iStack_74 = iStack_30 << 0xc;
        uStack_70 = 0x58000;
        sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                 0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3);
        *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
        uVar4 = uStack_b0 + 8 & 3;
        uVar7 = *(uint *)(uStack_b0 + 8 & 0xfffffffc);
        uVar3 = GetB3C4_Cell_RaceTaM((uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + 2);
        uStack_68 = 0x58000;
        iStack_6c = iStack_2c << 0xc;
        sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                 0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3);
        *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
        uVar4 = uStack_b0 + 0xc & 3;
        uVar7 = *(uint *)(uStack_b0 + 0xc & 0xfffffffc);
        uVar3 = GetB3C4_Cell_RaceTaM((uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + 2);
        uStack_60 = 0x58000;
        iStack_64 = iStack_28 << 0xc;
        sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                 0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3);
        *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
        uVar3 = GetB3C4_Cell_RaceTaM(0xc);
        uStack_58 = 0x58000;
        iStack_5c = iStack_24 << 0xc;
        sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                 0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3);
        *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
        uVar4 = uStack_b0 + 0x10 & 3;
        uVar7 = *(uint *)(uStack_b0 + 0x10 & 0xfffffffc);
        uVar3 = GetB3C4_Cell_RaceTaM((uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + 2);
        uStack_50 = 0x58000;
        iStack_54 = iStack_20 << 0xc;
        sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                 0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3);
        *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
        uVar4 = uStack_b0 + 0x14 & 3;
        uVar7 = *(uint *)(uStack_b0 + 0x14 & 0xfffffffc);
        uVar3 = GetB3C4_Cell_RaceTaM((uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + 2);
        uStack_48 = 0x58000;
        iStack_4c = iStack_1c << 0xc;
        sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                 0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3);
        *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
        uVar4 = uStack_b0 + 0x18 & 3;
        uVar7 = *(uint *)(uStack_b0 + 0x18 & 0xfffffffc);
        uVar3 = GetB3C4_Cell_RaceTaM((uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + 2);
        uStack_40 = 0x58000;
        iStack_44 = iStack_18 << 0xc;
        sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                 0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3);
        *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
        return;
      }
      return;
    }
  }
  return;
}

