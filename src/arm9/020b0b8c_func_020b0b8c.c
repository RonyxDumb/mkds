/* Decompiled C draft; module arm9; ROM address 020b0b8c. No matching claim. */
#include "types.h"
#include "deps/020b0b8c_func_020b0b8c.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void func_020b0b8c(void)

{
  ushort *puVar1;
  ushort *puVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  
  uVar5 = (*(uint *)(DAT_020b173c & 0xfffffffc) >> (DAT_020b173c & 3) * 8 |
          *(uint *)(DAT_020b173c & 0xfffffffc) << (DAT_020b173c & 3) * -8 + 0x20) + 0xc;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  if (uVar5 == 3) {
    LoadRaceIntroDataOam();
    return;
  }
  if (uVar5 == 5) {
    return;
  }
  if (uVar5 == 6) {
    _DAT_05000000 = 0;
    LoadStaffRollDataOam();
    func_0212b1c0();
    return;
  }
  uVar10 = *(uint *)(DAT_020b1740 & 0xfffffffc) >> (DAT_020b1740 & 3) * 8 |
           *(uint *)(DAT_020b1740 & 0xfffffffc) << (DAT_020b1740 & 3) * -8 + 0x20;
  uVar5 = uVar10 + 0x898 & 3;
  uVar6 = *(uint *)(uVar10 + 0x898 & 0xfffffffc);
  if (uVar6 >> uVar5 * 8 == 0 && uVar6 << uVar5 * -8 + 0x20 == 0) {
    return;
  }
  uVar5 = uVar10 + 0x840 & 3;
  uVar6 = *(uint *)(uVar10 + 0x840 & 0xfffffffc);
  if (uVar6 >> uVar5 * 8 == 0 && uVar6 << uVar5 * -8 + 0x20 == 0) {
    uVar5 = uVar10 + 0x844 & 3;
    uVar6 = *(uint *)(uVar10 + 0x844 & 0xfffffffc);
    if (((uVar6 >> uVar5 * 8 != 0 || uVar6 << uVar5 * -8 + 0x20 != 0) &&
        (iVar7 = IsRaceOptionMenuOn_from_thumb(), uVar5 = DAT_020b1740, iVar7 == 0)) &&
       (uVar12 = *(uint *)(DAT_020b1740 & 0xfffffffc) >> (DAT_020b1740 & 3) * 8 |
                 *(uint *)(DAT_020b1740 & 0xfffffffc) << (DAT_020b1740 & 3) * -8 + 0x20,
       uVar6 = uVar12 + 0x844, uVar10 = uVar6 & 3, uVar6 = *(uint *)(uVar6 & 0xfffffffc),
       uVar8 = uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20,
       *(uint *)(uVar12 + 0x844) = uVar8 + 1, puVar1 = DAT_020b1744,
       uVar6 = (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
               *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x850, uVar10 = uVar6 & 3
       , uVar6 = *(uint *)(uVar6 & 0xfffffffc),
       (int)(uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) <= (int)uVar8)) {
      uVar10 = *(uint *)(DAT_020b173c & 0xfffffffc) >> (DAT_020b173c & 3) * 8 |
               *(uint *)(DAT_020b173c & 0xfffffffc) << (DAT_020b173c & 3) * -8 + 0x20;
      uVar6 = uVar10 + 8;
      uVar8 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      if ((uVar6 >> uVar8 * 8 == 0 && uVar6 << uVar8 * -8 + 0x20 == 0) &&
         (uVar10 = uVar10 + 0xc, uVar6 = uVar10 & 3, uVar10 = *(uint *)(uVar10 & 0xfffffffc),
         uVar10 >> uVar6 * 8 == 0 && uVar10 << uVar6 * -8 + 0x20 == 0)) {
        _DAT_04000000 = _DAT_04000000 & 0xffffe0ff | ((_DAT_04000000 & 0x1f00) >> 8 | 8) << 8;
        *DAT_020b1744 = *DAT_020b1744 & 0xfffc | 1;
        *puVar1 = *puVar1 & 0xffbf;
        *puVar1 = *puVar1 & 0x43 | 0x500;
        uVar5 = (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x80c;
        uVar6 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
        uVar5 = uVar6 + 0xc;
        uVar10 = uVar5 & 3;
        uVar8 = *(uint *)(uVar5 & 0xfffffffc);
        uVar6 = uVar6 + 8;
        uVar5 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        CopyPaletteTop(uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20,0,
                       uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
        uVar5 = (*(uint *)(DAT_020b1740 & 0xfffffffc) >> (DAT_020b1740 & 3) * 8 |
                *(uint *)(DAT_020b1740 & 0xfffffffc) << (DAT_020b1740 & 3) * -8 + 0x20) + 0x814;
        uVar6 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
        uVar5 = uVar6 + 0x14;
        uVar10 = uVar5 & 3;
        uVar8 = *(uint *)(uVar5 & 0xfffffffc);
        uVar6 = uVar6 + 0x10;
        uVar5 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        CopyBgData_Bg3_Top(uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20,0,
                           uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
        uVar5 = (*(uint *)(DAT_020b1740 & 0xfffffffc) >> (DAT_020b1740 & 3) * 8 |
                *(uint *)(DAT_020b1740 & 0xfffffffc) << (DAT_020b1740 & 3) * -8 + 0x20) + 0x820;
        uVar6 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        TEQSub_Fn11Impl_Fn13Impl((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0xc,0,0x600);
        G2x_SetBlendAlpha_(DAT_020b1748,8,0x27,5);
      }
      uVar6 = DAT_020b1740;
      *(undefined4 *)
       ((*(uint *)(DAT_020b1740 & 0xfffffffc) >> (DAT_020b1740 & 3) * 8 |
        *(uint *)(DAT_020b1740 & 0xfffffffc) << (DAT_020b1740 & 3) * -8 + 0x20) + 0x844) = 0;
      uVar5 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      *(undefined4 *)((uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 0x84c) = 1;
    }
  }
  else {
    iVar7 = GetSomeBgTileData_from_thumb();
    uVar5 = iVar7 + 0x14U & 3;
    uVar6 = *(uint *)(iVar7 + 0x14U & 0xfffffffc);
    CopyBgData_Bg0_Bottom(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20,0,0x3000);
    *(undefined4 *)
     ((*(uint *)(DAT_020b1740 & 0xfffffffc) >> (DAT_020b1740 & 3) * 8 |
      *(uint *)(DAT_020b1740 & 0xfffffffc) << (DAT_020b1740 & 3) * -8 + 0x20) + 0x840) = 0;
    uVar5 = GetRacePaletteBlock(1);
    uVar10 = GetRacePaletteBlock(1);
    uVar5 = (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
            *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0xc;
    uVar6 = uVar5 & 3;
    uVar8 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = (*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
            *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) + 8;
    uVar10 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    CopySomePaletteData(uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20,0,
                        uVar5 >> uVar10 * 8 | uVar5 << uVar10 * -8 + 0x20);
    iVar7 = GetRacePaletteBlock(1);
    uVar5 = iVar7 + 4U & 3;
    uVar6 = *(uint *)(iVar7 + 4U & 0xfffffffc);
    uVar5 = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 0x14;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    CopyTileDataTop_0(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,0,0x4000);
    uVar6 = DAT_020b1740;
    *(undefined4 *)
     ((*(uint *)(DAT_020b1740 & 0xfffffffc) >> (DAT_020b1740 & 3) * 8 |
      *(uint *)(DAT_020b1740 & 0xfffffffc) << (DAT_020b1740 & 3) * -8 + 0x20) + 0x848) = 1;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    *(undefined4 *)((uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 0x844) = 1;
    _DAT_04000000 = _DAT_04000000 & 0xffff1fff;
  }
  uVar5 = (*(uint *)(DAT_020b173c & 0xfffffffc) >> (DAT_020b173c & 3) * 8 |
          *(uint *)(DAT_020b173c & 0xfffffffc) << (DAT_020b173c & 3) * -8 + 0x20) + 8;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  if ((uVar5 == 0) &&
     (uVar6 = (*(uint *)(DAT_020b1740 & 0xfffffffc) >> (DAT_020b1740 & 3) * 8 |
              *(uint *)(DAT_020b1740 & 0xfffffffc) << (DAT_020b1740 & 3) * -8 + 0x20) + 0x84c,
     uVar10 = uVar6 & 3, uVar6 = *(uint *)(uVar6 & 0xfffffffc),
     uVar6 >> uVar10 * 8 != 0 || uVar6 << uVar10 * -8 + 0x20 != 0)) {
    uVar9 = GetB3F0_Beb1();
    iVar7 = ComputeValueInterpolation_from_thumb(1,0xffffffc0,0,uVar9);
    *DAT_020b1750 = DAT_020b174c & iVar7 << 0x10;
  }
  else if ((uVar5 == 4) &&
          (uVar5 = (*(uint *)(DAT_020b1740 & 0xfffffffc) >> (DAT_020b1740 & 3) * 8 |
                   *(uint *)(DAT_020b1740 & 0xfffffffc) << (DAT_020b1740 & 3) * -8 + 0x20) + 0x84c,
          uVar6 = uVar5 & 3, uVar5 = *(uint *)(uVar5 & 0xfffffffc),
          uVar5 >> uVar6 * 8 != 0 || uVar5 << uVar6 * -8 + 0x20 != 0)) {
    iVar7 = GetSomeBgTileData_from_thumb();
    uVar5 = iVar7 + 0x14U & 3;
    uVar6 = *(uint *)(iVar7 + 0x14U & 0xfffffffc);
    CopyBgData_Bg0_Bottom(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20,0,0x3000);
    uVar9 = func_020b32f8();
    TEQSub_Fn24Impl(uVar9,0,0x600);
  }
  Arm_FlushRange((*(uint *)(DAT_020b1740 & 0xfffffffc) >> (DAT_020b1740 & 3) * 8 |
                 *(uint *)(DAT_020b1740 & 0xfffffffc) << (DAT_020b1740 & 3) * -8 + 0x20) + 4,0x400);
  CopyToOamA((*(uint *)(DAT_020b1740 & 0xfffffffc) >> (DAT_020b1740 & 3) * 8 |
             *(uint *)(DAT_020b1740 & 0xfffffffc) << (DAT_020b1740 & 3) * -8 + 0x20) + 4,0,0x400);
  Arm_FlushRange((*(uint *)(DAT_020b1740 & 0xfffffffc) >> (DAT_020b1740 & 3) * 8 |
                 *(uint *)(DAT_020b1740 & 0xfffffffc) << (DAT_020b1740 & 3) * -8 + 0x20) +
                 DAT_020b1754,0x400);
  CopyToOamB((*(uint *)(DAT_020b1740 & 0xfffffffc) >> (DAT_020b1740 & 3) * 8 |
             *(uint *)(DAT_020b1740 & 0xfffffffc) << (DAT_020b1740 & 3) * -8 + 0x20) + DAT_020b1754,
             0,0x400);
  puVar1 = DAT_020b1770;
  uVar6 = *(uint *)(DAT_020b1740 & 0xfffffffc) >> (DAT_020b1740 & 3) * 8 |
          *(uint *)(DAT_020b1740 & 0xfffffffc) << (DAT_020b1740 & 3) * -8 + 0x20;
  uVar5 = uVar6 + 0x82c;
  uVar10 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if (uVar5 >> uVar10 * 8 == 0 && uVar5 << uVar10 * -8 + 0x20 == 0) goto switchD_020b0f00_default;
  uVar6 = uVar6 + 0x828;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  switch(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) {
  case 0:
    *DAT_020b1758 =
         (*(uint *)((uint)DAT_020b1758 & 0xfffffffc) >> ((uint)DAT_020b1758 & 3) * 8 |
         *(uint *)((uint)DAT_020b1758 & 0xfffffffc) << ((uint)DAT_020b1758 & 3) * -8 + 0x20) &
         0xffffe0ff | 0x1c00;
    SetDispcntSubBgMode(0);
    puVar1 = DAT_020b1760;
    *DAT_020b175c = 0;
    uVar6 = DAT_020b1768;
    puVar2 = DAT_020b1764;
    *puVar1 = *puVar1 & 0xfffc | 2;
    *puVar1 = *puVar1 & 0xffbf;
    *puVar1 = *puVar1 & 0x43 | 0x208;
    *puVar1 = *puVar1 & 0xfffc | 3;
    *puVar2 = *puVar2 & 0xffbf;
    *puVar2 = *puVar2 & 0x43 | 0x308;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    CopyPaletteBottom(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20,0,0x200);
    break;
  case 1:
    goto LAB_020b0fc0;
  case 2:
    goto LAB_020b0fc0;
  case 3:
LAB_020b0fc0:
    func_020b18b0();
    iVar7 = GetChoises_s_b_Pallette_from_thumb();
    uVar5 = iVar7 + 0xcU & 3;
    uVar6 = *(uint *)(iVar7 + 0xcU & 0xfffffffc);
    CopyPaletteBottom(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20,0,0x200);
    break;
  case 4:
    goto LAB_020b0fdc;
  case 5:
LAB_020b0fdc:
    *DAT_020b176c = 0;
    *puVar1 = *puVar1 & 0xfffc;
    *puVar1 = *puVar1 & 0xffbf;
    *puVar1 = *puVar1 & 0x43 | 0x10c;
    func_020b17a4();
    uVar5 = func_020c3e2c(0);
    uVar10 = func_020c3e2c(0);
    uVar5 = (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
            *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0xc;
    uVar6 = uVar5 & 3;
    uVar8 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = (*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
            *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) + 8;
    uVar10 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    CopyPaletteBottom(uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20,0,
                      uVar5 >> uVar10 * 8 | uVar5 << uVar10 * -8 + 0x20);
    iVar7 = func_020c3e2c(0);
    iVar11 = func_020c3e2c(0);
    uVar5 = iVar7 + 4U & 3;
    uVar10 = *(uint *)(iVar7 + 4U & 0xfffffffc);
    uVar6 = iVar11 + 4U & 3;
    uVar12 = *(uint *)(iVar11 + 4U & 0xfffffffc);
    uVar5 = (uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20) + 0x14;
    uVar10 = uVar5 & 3;
    uVar8 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = (uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20) + 0x10;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    CopyBgData_Bg1_Bottom
              (uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20,0,
               uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
    uVar5 = GetRacePaletteBlock(7);
    uVar5 = (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
            *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0xc;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    TEQSub_Fn30Impl(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,0,0x80);
    iVar7 = GetRacePaletteBlock(7);
    uVar5 = iVar7 + 4U & 3;
    uVar6 = *(uint *)(iVar7 + 4U & 0xfffffffc);
    uVar5 = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 0x14;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    TEQSub_Fn35Impl(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,0,0x4000);
    iVar7 = GetSomeBgTileData_from_thumb();
    uVar5 = iVar7 + 0x14U & 3;
    uVar6 = *(uint *)(iVar7 + 0x14U & 0xfffffffc);
    CopyBgData_Bg0_Bottom(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20,0,0x3000);
    uVar9 = func_020b32f8();
    TEQSub_Fn24Impl(uVar9,0,0x600);
    break;
  case 6:
  }
switchD_020b0f00_default:
  uVar3 = DAT_020b1778;
  iVar7 = DAT_020b1774;
  uVar12 = DAT_020b1740;
  uVar8 = DAT_020b173c;
  uVar6 = *(uint *)(DAT_020b1740 & 0xfffffffc) >> (DAT_020b1740 & 3) * 8 |
          *(uint *)(DAT_020b1740 & 0xfffffffc) << (DAT_020b1740 & 3) * -8 + 0x20;
  uVar5 = uVar6 + 0x828;
  uVar10 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  switch(uVar5 >> uVar10 * 8 | uVar5 << uVar10 * -8 + 0x20) {
  case 0:
    *DAT_020b1758 =
         (*(uint *)((uint)DAT_020b1758 & 0xfffffffc) >> ((uint)DAT_020b1758 & 3) * 8 |
         *(uint *)((uint)DAT_020b1758 & 0xfffffffc) << ((uint)DAT_020b1758 & 3) * -8 + 0x20) &
         0xffffe0ff | 0x1c00;
    uVar5 = uVar12 & 3;
    uVar6 = *(uint *)(uVar12 & 0xfffffffc);
    uVar6 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar5 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
    uVar5 = (int)((ulonglong)((longlong)iVar7 * (longlong)(int)uVar5) >> 0x20) -
            ((int)uVar5 >> 0x1f);
    *DAT_020b177c = uVar5 & uVar3 | DAT_020b174c & (0x200 - uVar5) * 0x10000;
    break;
  case 1:
    goto LAB_020b1150;
  case 2:
    goto LAB_020b1150;
  case 3:
LAB_020b1150:
    uVar5 = (*(uint *)(DAT_020b173c & 0xfffffffc) >> (DAT_020b173c & 3) * 8 |
            *(uint *)(DAT_020b173c & 0xfffffffc) << (DAT_020b173c & 3) * -8 + 0x20) + 8;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    if ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) == 4) {
      uVar5 = GetRacePaletteBlock(6);
      uVar10 = GetRacePaletteBlock(6);
      uVar5 = (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
              *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0xc;
      uVar6 = uVar5 & 3;
      uVar8 = *(uint *)(uVar5 & 0xfffffffc);
      uVar5 = (*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
              *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) + 8;
      uVar10 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      TEQSub_Fn30Impl(uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20,0,
                      uVar5 >> uVar10 * 8 | uVar5 << uVar10 * -8 + 0x20);
    }
    uVar8 = *(uint *)(DAT_020b1740 & 0xfffffffc) >> (DAT_020b1740 & 3) * 8 |
            *(uint *)(DAT_020b1740 & 0xfffffffc) << (DAT_020b1740 & 3) * -8 + 0x20;
    uVar5 = uVar8 + 0x868 & 3;
    uVar10 = *(uint *)(uVar8 + 0x868 & 0xfffffffc);
    uVar6 = uVar8 + 0x86c & 3;
    uVar12 = *(uint *)(uVar8 + 0x86c & 0xfffffffc);
    func_0214a428(DAT_020b1784,uVar8 + DAT_020b1780,
                  uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20,
                  uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20);
    iVar7 = MaybeCircuitUsesLocal3();
    if (iVar7 != 0) {
      uVar8 = *(uint *)(DAT_020b1740 & 0xfffffffc) >> (DAT_020b1740 & 3) * 8 |
              *(uint *)(DAT_020b1740 & 0xfffffffc) << (DAT_020b1740 & 3) * -8 + 0x20;
      uVar5 = uVar8 + 0x888 & 3;
      uVar10 = *(uint *)(uVar8 + 0x888 & 0xfffffffc);
      uVar6 = uVar8 + 0x88c & 3;
      uVar12 = *(uint *)(uVar8 + 0x88c & 0xfffffffc);
      func_0214a428(DAT_020b178c,uVar8 + DAT_020b1788,
                    uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20,
                    uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20);
    }
    func_020cf340((*(uint *)(DAT_020b1768 & 0xfffffffc) >> (DAT_020b1768 & 3) * 8 |
                  *(uint *)(DAT_020b1768 & 0xfffffffc) << (DAT_020b1768 & 3) * -8 + 0x20) + 0x200);
    iVar7 = MaybeCircuitUsesLocal3();
    if (iVar7 == 0) {
      *DAT_020b1758 =
           (*(uint *)((uint)DAT_020b1758 & 0xfffffffc) >> ((uint)DAT_020b1758 & 3) * 8 |
           *(uint *)((uint)DAT_020b1758 & 0xfffffffc) << ((uint)DAT_020b1758 & 3) * -8 + 0x20) &
           0xffffe0ff | 0x1400;
    }
    else {
      iVar7 = CheckCourseSomeVectorBounds();
      if (iVar7 == 0) {
        *DAT_020b1758 =
             (*(uint *)((uint)DAT_020b1758 & 0xfffffffc) >> ((uint)DAT_020b1758 & 3) * 8 |
             *(uint *)((uint)DAT_020b1758 & 0xfffffffc) << ((uint)DAT_020b1758 & 3) * -8 + 0x20) &
             0xffffe0ff | 0x1800;
      }
      else {
        *DAT_020b1758 =
             (*(uint *)((uint)DAT_020b1758 & 0xfffffffc) >> ((uint)DAT_020b1758 & 3) * 8 |
             *(uint *)((uint)DAT_020b1758 & 0xfffffffc) << ((uint)DAT_020b1758 & 3) * -8 + 0x20) &
             0xffffe0ff | 0x1c00;
      }
    }
    break;
  case 4:
    *DAT_020b1758 =
         (*(uint *)((uint)DAT_020b1758 & 0xfffffffc) >> ((uint)DAT_020b1758 & 3) * 8 |
         *(uint *)((uint)DAT_020b1758 & 0xfffffffc) << ((uint)DAT_020b1758 & 3) * -8 + 0x20) &
         0xffffe0ff | 0x1e00;
    uVar5 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
            *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + 8;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    if ((uVar5 == 2) || (uVar5 == 3)) {
      iVar7 = GetSomeBgTileData_from_thumb();
      uVar5 = iVar7 + 0x14U & 3;
      uVar6 = *(uint *)(iVar7 + 0x14U & 0xfffffffc);
      CopyBgData_Bg0_Bottom(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20,0,0x800);
    }
    iVar7 = func_020c3e00();
    puVar4 = DAT_020b177c;
    if (iVar7 < 0x100) {
      uVar5 = DAT_020b1778 & -iVar7;
      *DAT_020b175c = uVar5;
      *puVar4 = uVar5;
      iVar7 = func_020c3e14(1);
      TEQSub_Fn26Impl_Fn28Impl(iVar7 + 0xc,0,0x600);
      iVar7 = func_020c3e14(2);
      TEQSub_Fn27Impl_Fn29Impl(iVar7 + 0xc,0,0x600);
    }
    break;
  case 5:
    *DAT_020b1758 =
         (*(uint *)((uint)DAT_020b1758 & 0xfffffffc) >> ((uint)DAT_020b1758 & 3) * 8 |
         *(uint *)((uint)DAT_020b1758 & 0xfffffffc) << ((uint)DAT_020b1758 & 3) * -8 + 0x20) &
         0xffffe0ff | 0x1e00;
    uVar5 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
            *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + 8;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    if ((uVar5 == 2) || (uVar5 == 3)) {
      iVar7 = GetSomeBgTileData_from_thumb();
      uVar5 = iVar7 + 0x14U & 3;
      uVar6 = *(uint *)(iVar7 + 0x14U & 0xfffffffc);
      CopyBgData_Bg0_Bottom(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20,0,0x800);
    }
    uVar10 = func_020c3e00();
    uVar5 = (*(uint *)(DAT_020b1740 & 0xfffffffc) >> (DAT_020b1740 & 3) * 8 |
            *(uint *)(DAT_020b1740 & 0xfffffffc) << (DAT_020b1740 & 3) * -8 + 0x20) + 0x830;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    if (uVar5 >> uVar6 * 8 != 0 || uVar5 << uVar6 * -8 + 0x20 != 0) {
      iVar7 = func_020c3e14(3);
      iVar11 = func_020c3e14(3);
      uVar5 = iVar11 + 8U & 3;
      uVar6 = *(uint *)(iVar11 + 8U & 0xfffffffc);
      TEQSub_Fn25Impl(iVar7 + 0xc,0,uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
      iVar7 = func_020c3e14(4);
      iVar11 = func_020c3e14(4);
      uVar5 = iVar11 + 8U & 3;
      uVar6 = *(uint *)(iVar11 + 8U & 0xfffffffc);
      TEQSub_Fn26Impl_Fn28Impl(iVar7 + 0xc,0,uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
      iVar7 = func_020c3e14(5);
      iVar11 = func_020c3e14(5);
      uVar5 = iVar11 + 8U & 3;
      uVar6 = *(uint *)(iVar11 + 8U & 0xfffffffc);
      TEQSub_Fn27Impl_Fn29Impl(iVar7 + 0xc,0,uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
      uVar5 = GetRacePaletteBlock(8);
      uVar5 = (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
              *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0xc;
      uVar6 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      TEQSub_Fn30Impl(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,0,0x20);
      uVar5 = GetRacePaletteBlock(8);
      uVar5 = (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
              *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0xc;
      uVar6 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      TEQSub_Fn30Impl((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x180,0x180,0x80);
      iVar7 = GetRacePaletteBlock(8);
      uVar5 = iVar7 + 4U & 3;
      uVar6 = *(uint *)(iVar7 + 4U & 0xfffffffc);
      uVar5 = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 0x14;
      uVar6 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      TEQSub_Fn35Impl(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,0,0x4000);
      *(undefined4 *)
       ((*(uint *)(DAT_020b1740 & 0xfffffffc) >> (DAT_020b1740 & 3) * 8 |
        *(uint *)(DAT_020b1740 & 0xfffffffc) << (DAT_020b1740 & 3) * -8 + 0x20) + 0x830) = 0;
    }
    puVar4 = DAT_020b177c;
    uVar5 = DAT_020b1778;
    if ((int)uVar10 < 0x100) {
      *DAT_020b175c = uVar10 & DAT_020b1778;
      *puVar4 = uVar5 & -uVar10;
    }
    break;
  case 6:
    uVar6 = uVar6 + 0x834;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    if (uVar6 >> uVar5 * 8 != 0 || uVar6 << uVar5 * -8 + 0x20 != 0) {
      *DAT_020b1758 =
           (*(uint *)((uint)DAT_020b1758 & 0xfffffffc) >> ((uint)DAT_020b1758 & 3) * 8 |
           *(uint *)((uint)DAT_020b1758 & 0xfffffffc) << ((uint)DAT_020b1758 & 3) * -8 + 0x20) &
           0xffffe0ff | 0x1200;
      SetDispcntSubBgMode(0);
      puVar1 = DAT_020b1794;
      *DAT_020b1790 = 0;
      uVar6 = DAT_020b1740;
      *puVar1 = *puVar1 & 0xfffc | 3;
      *puVar1 = *puVar1 & 0xffbf;
      *puVar1 = *puVar1 & 0x43 | 8;
      uVar5 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar5 = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 0x810;
      uVar6 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      uVar5 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0xc;
      uVar6 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      CopyPaletteBottom(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,0,0x20);
      uVar5 = (*(uint *)(DAT_020b1740 & 0xfffffffc) >> (DAT_020b1740 & 3) * 8 |
              *(uint *)(DAT_020b1740 & 0xfffffffc) << (DAT_020b1740 & 3) * -8 + 0x20) + 0x818;
      uVar6 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
      uVar5 = uVar6 + 0x14;
      uVar10 = uVar5 & 3;
      uVar8 = *(uint *)(uVar5 & 0xfffffffc);
      uVar6 = uVar6 + 0x10;
      uVar5 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      CopyBgData_Bg1_Bottom
                (uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20,0,
                 uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
      uVar5 = (*(uint *)(DAT_020b1740 & 0xfffffffc) >> (DAT_020b1740 & 3) * 8 |
              *(uint *)(DAT_020b1740 & 0xfffffffc) << (DAT_020b1740 & 3) * -8 + 0x20) + 0x824;
      uVar6 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      uVar10 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
      uVar5 = uVar10 + 8;
      uVar6 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      TEQSub_Fn25Impl(uVar10 + 0xc,0,uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
      uVar5 = GetRacePaletteBlock(9);
      uVar5 = (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
              *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0xc;
      uVar6 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      TEQSub_Fn30Impl(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,0,0xa0);
      uVar5 = GetRacePaletteBlock(9);
      uVar5 = (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
              *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0xc;
      uVar6 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      TEQSub_Fn30Impl((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x160,0x160,0xa0);
      iVar7 = GetRacePaletteBlock(9);
      uVar5 = iVar7 + 4U & 3;
      uVar6 = *(uint *)(iVar7 + 4U & 0xfffffffc);
      uVar5 = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 0x14;
      uVar6 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      TEQSub_Fn35Impl(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,0,0x4000);
      *(undefined4 *)
       ((*(uint *)(DAT_020b1740 & 0xfffffffc) >> (DAT_020b1740 & 3) * 8 |
        *(uint *)(DAT_020b1740 & 0xfffffffc) << (DAT_020b1740 & 3) * -8 + 0x20) + 0x834) = 0;
    }
  }
  iVar7 = func_020b2e98();
  if (iVar7 == 0) {
    *DAT_020b1758 =
         (*(uint *)((uint)DAT_020b1758 & 0xfffffffc) >> ((uint)DAT_020b1758 & 3) * 8 |
         *(uint *)((uint)DAT_020b1758 & 0xfffffffc) << ((uint)DAT_020b1758 & 3) * -8 + 0x20) &
         0xffffe0ff |
         (((*(uint *)((uint)DAT_020b1758 & 0xfffffffc) >> ((uint)DAT_020b1758 & 3) * 8 |
           *(uint *)((uint)DAT_020b1758 & 0xfffffffc) << ((uint)DAT_020b1758 & 3) * -8 + 0x20) &
          0x1f00) >> 8 & 0xfffffffe) << 8;
    _DAT_04000000 = _DAT_04000000 & 0xffffe0ff | ((_DAT_04000000 & 0x1f00) >> 8 & 0xfffffffb) << 8;
    G2x_SetBlendAlpha_(DAT_020b179c,0,0x3f,6);
  }
  else {
    uVar5 = (*(uint *)(DAT_020b1798 & 0xfffffffc) >> (DAT_020b1798 & 3) * 8 |
            *(uint *)(DAT_020b1798 & 0xfffffffc) << (DAT_020b1798 & 3) * -8 + 0x20) + 0x4cc;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    if (uVar5 >> uVar6 * 8 == 0 && uVar5 << uVar6 * -8 + 0x20 == 0) {
      _DAT_04000000 = _DAT_04000000 & 0xffffe0ff | ((_DAT_04000000 & 0x1f00) >> 8 | 4) << 8;
      uVar5 = (*(uint *)(DAT_020b1740 & 0xfffffffc) >> (DAT_020b1740 & 3) * 8 |
              *(uint *)(DAT_020b1740 & 0xfffffffc) << (DAT_020b1740 & 3) * -8 + 0x20) + 0x81c;
      uVar6 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      TEQSub_Fn10Impl_Fn12Impl((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0xc,0,0x600);
    }
    uVar9 = func_020b32f8();
    TEQSub_Fn24Impl(uVar9,0,0x600);
    *DAT_020b1758 =
         (*(uint *)((uint)DAT_020b1758 & 0xfffffffc) >> ((uint)DAT_020b1758 & 3) * 8 |
         *(uint *)((uint)DAT_020b1758 & 0xfffffffc) << ((uint)DAT_020b1758 & 3) * -8 + 0x20) &
         0xffffe0ff |
         (((*(uint *)((uint)DAT_020b1758 & 0xfffffffc) >> ((uint)DAT_020b1758 & 3) * 8 |
           *(uint *)((uint)DAT_020b1758 & 0xfffffffc) << ((uint)DAT_020b1758 & 3) * -8 + 0x20) &
          0x1f00) >> 8 | 1) << 8;
    UpdateBldcntBldalphaBldy(DAT_020b179c,0x3e,0x3f);
  }
  uVar9 = DAT_020b17a0;
  uVar6 = DAT_020b1740;
  uVar5 = DAT_020b173c;
  iVar7 = 0;
  if (*(char *)((*(uint *)(DAT_020b173c & 0xfffffffc) >> (DAT_020b173c & 3) * 8 |
                *(uint *)(DAT_020b173c & 0xfffffffc) << (DAT_020b173c & 3) * -8 + 0x20) + 0x3d0) ==
      '\0') {
    return;
  }
  do {
    iVar11 = (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
             *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + iVar7 * 4;
    uVar10 = iVar11 + 0x89c;
    uVar8 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    if ((uVar10 >> uVar8 * 8 != 0 || uVar10 << uVar8 * -8 + 0x20 != 0) &&
       (uVar10 = iVar11 + 0x8bc, uVar8 = uVar10 & 3, uVar10 = *(uint *)(uVar10 & 0xfffffffc),
       uVar10 >> uVar8 * 8 == 0 && uVar10 << uVar8 * -8 + 0x20 == 0)) {
      NNSi_MaybeSndPlayerStartSeq(uVar9,0,0x52);
      *(undefined4 *)
       ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
        *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + iVar7 * 4 + 0x8bc) = 1;
    }
    uVar10 = uVar5 & 3;
    uVar8 = *(uint *)(uVar5 & 0xfffffffc);
    iVar7 = iVar7 + 1;
  } while (iVar7 < (int)(uint)*(byte *)((uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) + 0x3d0)
          );
  return;
}

