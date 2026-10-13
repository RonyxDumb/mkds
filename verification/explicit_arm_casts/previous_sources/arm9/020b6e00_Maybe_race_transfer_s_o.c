/* Decompiled C draft; module arm9; ROM address 020b6e00. No matching claim. */
#include "types.h"
#include "deps/020b6e00_Maybe_race_transfer_s_o.h"

void Maybe_race_transfer_s_o(int param_1,undefined4 param_2)

{
  ushort uVar1;
  short sVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int local_b0;
  undefined1 local_ac [4];
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  undefined4 local_68 [4];
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  uint uVar12;
  
  local_a8 = 0;
  uVar3 = func_020b47c0(DAT_020b7a2c);
  Gfx_ReadCharGraphics(&local_a8,uVar3);
  uVar10 = DAT_020b7a34;
  uVar9 = DAT_020b7a30;
  uVar4 = *(uint *)(DAT_020b7a30 & 0xfffffffc) >> (DAT_020b7a30 & 3) * 8 |
          *(uint *)(DAT_020b7a30 & 0xfffffffc) << (DAT_020b7a30 & 3) * -8 + 0x20;
  uVar7 = local_a8 + 0x14U & 3;
  uVar11 = *(uint *)(local_a8 + 0x14U & 0xfffffffc);
  uVar12 = uVar11 >> uVar7 * 8 | uVar11 << uVar7 * -8 + 0x20;
  uVar7 = (uint)*(byte *)(uVar4 + 0x3d0);
  uVar11 = 0;
  if (uVar7 != 0) {
    do {
      GetRacerCharacterIdAndUnk(uVar11,&local_b0,local_ac);
      func_020b46d0(uVar12,local_b0 << 1,0,2,2,param_2,uVar11 << 1,0);
      uVar7 = uVar10 & 3;
      uVar4 = *(uint *)(uVar10 & 0xfffffffc);
      uVar7 = (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + uVar11 * 4 + 0x2d8;
      uVar4 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      uVar11 = uVar11 + 1 & 0xff;
      uVar7 = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + 4;
      uVar4 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      uVar7 = uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20;
      *(ushort *)(uVar7 + 4) =
           (*(ushort *)(uVar7 + 4) & (ushort)DAT_020b7a38) + MKDS_SLICE_2(local_ac,0) * 0x1000;
      uVar7 = uVar9 & 3;
      uVar4 = *(uint *)(uVar9 & 0xfffffffc);
      uVar4 = uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20;
      uVar7 = (uint)*(byte *)(uVar4 + 0x3d0);
    } while (uVar11 < uVar7);
  }
  uVar3 = DAT_020b7a38;
  uVar9 = DAT_020b7a34;
  uVar10 = 0;
  if (uVar7 != 0) {
    do {
      GetRacerCharacterIdAndUnk(uVar10,&local_b0,local_ac);
      func_020b46d0(uVar12,local_b0 << 1,2,2,2,param_2,uVar10 * 2 + 0x10,0);
      uVar7 = (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
              *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + (uVar10 + 8) * 4 + 0x2d8;
      uVar4 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      sVar2 = MKDS_SLICE_2(local_ac,0);
      uVar7 = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + 4;
      uVar4 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      uVar7 = uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20;
      uVar1 = (ushort)uVar3;
      *(ushort *)(uVar7 + 4) = (*(ushort *)(uVar7 + 4) & uVar1) + sVar2 * 0x1000;
      uVar7 = (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
              *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + uVar10 * 4 + 0x5fc;
      uVar4 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      uVar7 = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + 4;
      uVar4 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      uVar7 = uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20;
      *(ushort *)(uVar7 + 4) = (*(ushort *)(uVar7 + 4) & uVar1) + sVar2 * 0x1000;
      uVar7 = (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
              *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + uVar10 * 4 + 0x6ac;
      uVar4 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      uVar7 = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + 4;
      uVar4 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      uVar7 = uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20;
      *(ushort *)(uVar7 + 4) = (*(ushort *)(uVar7 + 4) & uVar1) + sVar2 * 0x1000;
      uVar7 = (*(uint *)(DAT_020b7a30 & 0xfffffffc) >> (DAT_020b7a30 & 3) * 8 |
              *(uint *)(DAT_020b7a30 & 0xfffffffc) << (DAT_020b7a30 & 3) * -8 + 0x20) + 8;
      uVar4 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      if ((uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) == 1) {
        uVar7 = (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + (uVar10 + 7) * 4 + 0x74c
        ;
        uVar4 = uVar7 & 3;
        uVar7 = *(uint *)(uVar7 & 0xfffffffc);
        uVar7 = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + 4;
        uVar4 = uVar7 & 3;
        uVar7 = *(uint *)(uVar7 & 0xfffffffc);
        uVar7 = uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20;
        *(ushort *)(uVar7 + 4) = (*(ushort *)(uVar7 + 4) & uVar1) + sVar2 * 0x1000;
      }
      uVar4 = *(uint *)(DAT_020b7a30 & 0xfffffffc) >> (DAT_020b7a30 & 3) * 8 |
              *(uint *)(DAT_020b7a30 & 0xfffffffc) << (DAT_020b7a30 & 3) * -8 + 0x20;
      uVar10 = uVar10 + 1 & 0xff;
    } while (uVar10 < *(byte *)(uVar4 + 0x3d0));
  }
  uVar3 = DAT_020b7a38;
  uVar9 = DAT_020b7a34;
  uVar7 = uVar4 + 8 & 3;
  uVar10 = *(uint *)(uVar4 + 8 & 0xfffffffc);
  if ((uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) == 1) {
    uVar7 = 0;
    do {
      GetTimeTrialRecordCharacterIdAndUnk(uVar7,&local_b0,local_ac);
      func_020b46d0(uVar12,local_b0 << 1,2,2,2,param_2,(uVar7 + 2) * 2 + 0x10,0);
      uVar10 = uVar9 & 3;
      uVar4 = *(uint *)(uVar9 & 0xfffffffc);
      uVar10 = (uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20) + (uVar7 + 8) * 4 + 0x74c;
      uVar4 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      uVar7 = uVar7 + 1 & 0xff;
      uVar10 = (uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20) + 4;
      uVar4 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      uVar10 = uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20;
      *(ushort *)(uVar10 + 4) = ((ushort)uVar3 & *(ushort *)(uVar10 + 4)) + MKDS_SLICE_2(local_ac,0) * 0x1000;
    } while (uVar7 < 6);
  }
  uVar7 = 0;
  if (*(char *)((*(uint *)(DAT_020b7a30 & 0xfffffffc) >> (DAT_020b7a30 & 3) * 8 |
                *(uint *)(DAT_020b7a30 & 0xfffffffc) << (DAT_020b7a30 & 3) * -8 + 0x20) + 0x3d0) !=
      '\0') {
    do {
      local_68[0] = *DAT_020b7a3c;
      local_68[1] = DAT_020b7a3c[1];
      local_68[2] = DAT_020b7a3c[2];
      local_68[3] = DAT_020b7a3c[3];
      local_58 = DAT_020b7a3c[4];
      uStack_54 = DAT_020b7a3c[5];
      uStack_50 = DAT_020b7a3c[6];
      uStack_4c = DAT_020b7a3c[7];
      local_48 = DAT_020b7a3c[8];
      uStack_44 = DAT_020b7a3c[9];
      uStack_40 = DAT_020b7a3c[10];
      uStack_3c = DAT_020b7a3c[0xb];
      local_38 = DAT_020b7a3c[0xc];
      uStack_34 = DAT_020b7a3c[0xd];
      uStack_30 = DAT_020b7a3c[0xe];
      uStack_2c = DAT_020b7a3c[0xf];
      uVar3 = GetSomeBgCanvasTileData_from_thumb();
      func_020b46d0(uVar3,(uVar7 & 3) << 3,(uVar7 >> 2) << 1,7,2,param_2,local_68[uVar7 * 2],
                    local_68[uVar7 * 2 + 1]);
      uVar7 = uVar7 + 1 & 0xff;
    } while (uVar7 < *(byte *)((*(uint *)(DAT_020b7a30 & 0xfffffffc) >> (DAT_020b7a30 & 3) * 8 |
                               *(uint *)(DAT_020b7a30 & 0xfffffffc) <<
                               (DAT_020b7a30 & 3) * -8 + 0x20) + 0x3d0));
  }
  Clear1A44SomeTileData_from_thumb();
  uVar3 = func_020b47c0(DAT_020b7a40);
  Gfx_ReadCharGraphics(&local_a8,uVar3);
  uVar10 = *(uint *)(DAT_020b7a30 & 0xfffffffc) >> (DAT_020b7a30 & 3) * 8 |
           *(uint *)(DAT_020b7a30 & 0xfffffffc) << (DAT_020b7a30 & 3) * -8 + 0x20;
  uVar7 = local_a8 + 0x14U & 3;
  uVar9 = *(uint *)(local_a8 + 0x14U & 0xfffffffc);
  uVar4 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
  uVar7 = uVar10 + 8 & 3;
  uVar9 = *(uint *)(uVar10 + 8 & 0xfffffffc);
  if ((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) == 2) {
    func_020b46d0(uVar4,0x14,6,0xc,4,param_2,0,8);
    func_020b46d0(uVar4,0x14,10,0xb,4,param_2,0,0xc);
    local_a4 = 0;
    uVar3 = func_020b47c0(DAT_020b7a44);
    Gfx_ReadPalette(&local_a4,uVar3);
    iVar8 = 0;
    do {
      iVar5 = iVar8 + 0xd0;
      uVar7 = local_a4 + 0xcU & 3;
      uVar9 = *(uint *)(local_a4 + 0xcU & 0xfffffffc);
      iVar6 = iVar8 + 0x40;
      iVar8 = iVar8 + 1;
      *(undefined2 *)(param_1 + iVar6 * 2) =
           *(undefined2 *)((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) + iVar5 * 2);
    } while (iVar8 < 0x10);
    goto switchD_020b7228_default;
  }
  switch(*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
         *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) {
  case 0:
    break;
  case 1:
    goto LAB_020b771c;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    break;
  case 7:
    break;
  case 8:
    break;
  case 9:
    goto LAB_020b771c;
  case 10:
    goto LAB_020b7364;
  case 0xb:
    goto LAB_020b7794;
  case 0xc:
    goto LAB_020b788c;
  case 0xd:
    break;
  case 0xe:
    goto LAB_020b7794;
  case 0xf:
    goto LAB_020b72ec;
  case 0x10:
    goto LAB_020b7628;
  case 0x11:
    func_020b46d0(uVar4,0xc,4,8,4,param_2,0,8);
    local_84 = 0;
    uVar3 = func_020b47c0(DAT_020b7a64);
    Gfx_ReadPalette(&local_84,uVar3);
    iVar8 = 0;
    do {
      iVar5 = iVar8 + 0x70;
      uVar7 = local_84 + 0xcU & 3;
      uVar9 = *(uint *)(local_84 + 0xcU & 0xfffffffc);
      iVar6 = iVar8 + 0x40;
      iVar8 = iVar8 + 1;
      *(undefined2 *)(param_1 + iVar6 * 2) =
           *(undefined2 *)((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) + iVar5 * 2);
    } while (iVar8 < 0x10);
    break;
  case 0x12:
    goto LAB_020b7364;
  case 0x13:
    goto LAB_020b7794;
  case 0x14:
    break;
  case 0x15:
    break;
  case 0x16:
    break;
  case 0x17:
    func_020b46d0(uVar4,0,10,8,6,param_2,0,8);
    local_6c = 0;
    uVar3 = func_020b47c0(DAT_020b7a7c);
    Gfx_ReadPalette(&local_6c,uVar3);
    iVar8 = 0;
    do {
      iVar5 = iVar8 + 0xe0;
      uVar7 = local_6c + 0xcU & 3;
      uVar9 = *(uint *)(local_6c + 0xcU & 0xfffffffc);
      iVar6 = iVar8 + 0x40;
      iVar8 = iVar8 + 1;
      *(undefined2 *)(param_1 + iVar6 * 2) =
           *(undefined2 *)((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) + iVar5 * 2);
    } while (iVar8 < 0x10);
    break;
  case 0x18:
    goto LAB_020b75b0;
  case 0x19:
    goto LAB_020b771c;
  case 0x1a:
LAB_020b7794:
    func_020b46d0(uVar4,0x13,4,0xc,4,param_2,0,8);
    local_7c = 0;
    uVar3 = func_020b47c0(DAT_020b7a6c);
    Gfx_ReadPalette(&local_7c,uVar3);
    iVar8 = 0;
    do {
      iVar5 = iVar8 + 0x90;
      uVar7 = local_7c + 0xcU & 3;
      uVar9 = *(uint *)(local_7c + 0xcU & 0xfffffffc);
      iVar6 = iVar8 + 0x40;
      iVar8 = iVar8 + 1;
      *(undefined2 *)(param_1 + iVar6 * 2) =
           *(undefined2 *)((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) + iVar5 * 2);
    } while (iVar8 < 0x10);
    break;
  case 0x1b:
    func_020b46d0(uVar4,9,0,6,2,param_2,0,8);
    local_98 = 0;
    uVar3 = func_020b47c0(DAT_020b7a50);
    Gfx_ReadPalette(&local_98,uVar3);
    iVar8 = 0;
    do {
      iVar5 = iVar8 + 0x20;
      uVar7 = local_98 + 0xcU & 3;
      uVar9 = *(uint *)(local_98 + 0xcU & 0xfffffffc);
      iVar6 = iVar8 + 0x40;
      iVar8 = iVar8 + 1;
      *(undefined2 *)(param_1 + iVar6 * 2) =
           *(undefined2 *)((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) + iVar5 * 2);
    } while (iVar8 < 0x10);
    break;
  case 0x1c:
    break;
  case 0x1d:
    func_020b46d0(uVar4,0x12,10,2,2,param_2,0,8);
    local_70 = 0;
    uVar3 = func_020b47c0(DAT_020b7a78);
    Gfx_ReadPalette(&local_70,uVar3);
    iVar8 = 0;
    do {
      iVar5 = iVar8 + 0xb0;
      uVar7 = local_70 + 0xcU & 3;
      uVar9 = *(uint *)(local_70 + 0xcU & 0xfffffffc);
      iVar6 = iVar8 + 0x40;
      iVar8 = iVar8 + 1;
      *(undefined2 *)(param_1 + iVar6 * 2) =
           *(undefined2 *)((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) + iVar5 * 2);
    } while (iVar8 < 0x10);
    break;
  case 0x1e:
LAB_020b7628:
    func_020b46d0(uVar4,0x1d,0,3,2,param_2,0,8);
    local_88 = 0;
    uVar3 = func_020b47c0(DAT_020b7a60);
    Gfx_ReadPalette(&local_88,uVar3);
    iVar8 = 0;
    do {
      iVar5 = iVar8 + 0x60;
      uVar7 = local_88 + 0xcU & 3;
      uVar9 = *(uint *)(local_88 + 0xcU & 0xfffffffc);
      iVar6 = iVar8 + 0x40;
      iVar8 = iVar8 + 1;
      *(undefined2 *)(param_1 + iVar6 * 2) =
           *(undefined2 *)((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) + iVar5 * 2);
    } while (iVar8 < 0x10);
    break;
  case 0x1f:
    goto LAB_020b72ec;
  case 0x20:
LAB_020b788c:
    func_020b46d0(uVar4,0xc,8,8,2,param_2,0,8);
    local_74 = 0;
    uVar3 = func_020b47c0(DAT_020b7a74);
    Gfx_ReadPalette(&local_74,uVar3);
    iVar8 = 0;
    do {
      iVar5 = iVar8 + 0xa0;
      uVar7 = local_74 + 0xcU & 3;
      uVar9 = *(uint *)(local_74 + 0xcU & 0xfffffffc);
      iVar6 = iVar8 + 0x40;
      iVar8 = iVar8 + 1;
      *(undefined2 *)(param_1 + iVar6 * 2) =
           *(undefined2 *)((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) + iVar5 * 2);
    } while (iVar8 < 0x10);
    break;
  case 0x21:
    func_020b46d0(uVar4,0,2,0xc,4,param_2,0,8);
    func_020b46d0(uVar4,0,6,0xb,4,param_2,0,0xc);
    if (*(char *)((*(uint *)(DAT_020b7a30 & 0xfffffffc) >> (DAT_020b7a30 & 3) * 8 |
                  *(uint *)(DAT_020b7a30 & 0xfffffffc) << (DAT_020b7a30 & 3) * -8 + 0x20) + 0x57) !=
        '\0') {
      func_020b45b0(uVar4,0,2,8,8,param_2,0,8);
    }
    local_90 = 0;
    uVar3 = func_020b47c0(DAT_020b7a58);
    Gfx_ReadPalette(&local_90,uVar3);
    iVar8 = 0;
    do {
      uVar7 = local_90 + 0xcU & 3;
      uVar9 = *(uint *)(local_90 + 0xcU & 0xfffffffc);
      iVar5 = (iVar8 + 0x40) * 2;
      iVar8 = iVar8 + 1;
      *(undefined2 *)(param_1 + iVar5) =
           *(undefined2 *)((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) + iVar5);
    } while (iVar8 < 0x10);
    break;
  case 0x22:
    func_020b46d0(uVar4,8,10,8,4,param_2,0,8);
    local_78 = 0;
    uVar3 = func_020b47c0(DAT_020b7a70);
    Gfx_ReadPalette(&local_78,uVar3);
    iVar8 = 0;
    do {
      iVar5 = iVar8 + 0x80;
      uVar7 = local_78 + 0xcU & 3;
      uVar9 = *(uint *)(local_78 + 0xcU & 0xfffffffc);
      iVar6 = iVar8 + 0x40;
      iVar8 = iVar8 + 1;
      *(undefined2 *)(param_1 + iVar6 * 2) =
           *(undefined2 *)((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) + iVar5 * 2);
    } while (iVar8 < 0x10);
    break;
  case 0x23:
LAB_020b7364:
    func_020b46d0(uVar4,4,0,5,2,param_2,0,8);
    local_9c = 0;
    uVar3 = func_020b47c0(DAT_020b7a4c);
    Gfx_ReadPalette(&local_9c,uVar3);
    iVar8 = 0;
    do {
      iVar5 = iVar8 + 0x10;
      uVar7 = local_9c + 0xcU & 3;
      uVar9 = *(uint *)(local_9c + 0xcU & 0xfffffffc);
      iVar6 = iVar8 + 0x40;
      iVar8 = iVar8 + 1;
      *(undefined2 *)(param_1 + iVar6 * 2) =
           *(undefined2 *)((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) + iVar5 * 2);
    } while (iVar8 < 0x10);
    break;
  case 0x24:
    func_020b46d0(uVar4,0xf,0,3,2,param_2,0,8);
    local_94 = 0;
    uVar3 = func_020b47c0(DAT_020b7a54);
    Gfx_ReadPalette(&local_94,uVar3);
    iVar8 = 0;
    do {
      iVar5 = iVar8 + 0x30;
      uVar7 = local_94 + 0xcU & 3;
      uVar9 = *(uint *)(local_94 + 0xcU & 0xfffffffc);
      iVar6 = iVar8 + 0x40;
      iVar8 = iVar8 + 1;
      *(undefined2 *)(param_1 + iVar6 * 2) =
           *(undefined2 *)((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) + iVar5 * 2);
    } while (iVar8 < 0x10);
    break;
  case 0x25:
    break;
  case 0x26:
LAB_020b75b0:
    func_020b46d0(uVar4,0x14,0,8,4,param_2,0,8);
    local_8c = 0;
    uVar3 = func_020b47c0(DAT_020b7a5c);
    Gfx_ReadPalette(&local_8c,uVar3);
    iVar8 = 0;
    do {
      iVar5 = iVar8 + 0x50;
      uVar7 = local_8c + 0xcU & 3;
      uVar9 = *(uint *)(local_8c + 0xcU & 0xfffffffc);
      iVar6 = iVar8 + 0x40;
      iVar8 = iVar8 + 1;
      *(undefined2 *)(param_1 + iVar6 * 2) =
           *(undefined2 *)((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) + iVar5 * 2);
    } while (iVar8 < 0x10);
    break;
  case 0x27:
LAB_020b771c:
    func_020b46d0(uVar4,0xc,2,8,2,param_2,0,8);
    local_80 = 0;
    uVar3 = func_020b47c0(DAT_020b7a68);
    Gfx_ReadPalette(&local_80,uVar3);
    iVar8 = 0;
    do {
      iVar5 = iVar8 + 0x80;
      uVar7 = local_80 + 0xcU & 3;
      uVar9 = *(uint *)(local_80 + 0xcU & 0xfffffffc);
      iVar6 = iVar8 + 0x40;
      iVar8 = iVar8 + 1;
      *(undefined2 *)(param_1 + iVar6 * 2) =
           *(undefined2 *)((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) + iVar5 * 2);
    } while (iVar8 < 0x10);
    break;
  case 0x28:
    break;
  case 0x29:
    break;
  case 0x2a:
    break;
  case 0x2b:
    break;
  case 0x2c:
    break;
  case 0x2d:
    break;
  case 0x2e:
LAB_020b72ec:
    func_020b46d0(uVar4,0,0,4,2,param_2,0,8);
    local_a0 = 0;
    uVar3 = func_020b47c0(DAT_020b7a48);
    Gfx_ReadPalette(&local_a0,uVar3);
    iVar8 = 0;
    do {
      iVar6 = iVar8 + 0x40;
      uVar7 = local_a0 + 0xcU & 3;
      uVar9 = *(uint *)(local_a0 + 0xcU & 0xfffffffc);
      iVar5 = iVar8 * 2;
      iVar8 = iVar8 + 1;
      *(undefined2 *)(param_1 + iVar6 * 2) =
           *(undefined2 *)((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) + iVar5);
    } while (iVar8 < 0x10);
  }
switchD_020b7228_default:
  uVar7 = (*(uint *)(DAT_020b7a30 & 0xfffffffc) >> (DAT_020b7a30 & 3) * 8 |
          *(uint *)(DAT_020b7a30 & 0xfffffffc) << (DAT_020b7a30 & 3) * -8 + 0x20) + 8;
  uVar9 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  if ((uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) == 4) {
    Maybe_race_transfer_map_mr_s_o(param_1,param_2);
    return;
  }
  return;
}

