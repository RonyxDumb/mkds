/* Decompiled C draft; module arm9; ROM address 020af99c. No matching claim. */
#include "types.h"
#include "deps/020af99c_func_020af99c.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void func_020af99c(void)

{
  undefined2 uVar1;
  ushort *puVar2;
  undefined2 *puVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  
  uVar8 = uRam020afd34;
  uVar5 = (*(uint *)(uRam020afd28 & 0xfffffffc) >> (uRam020afd28 & 3) * 8 |
          *(uint *)(uRam020afd28 & 0xfffffffc) << (uRam020afd28 & 3) * -8 + 0x20) + 0xc;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  if (uVar5 == 3) {
    return;
  }
  if (1 < uVar5 - 5) {
    uVar5 = (*(uint *)(uRam020afd2c & 0xfffffffc) >> (uRam020afd2c & 3) * 8 |
            *(uint *)(uRam020afd2c & 0xfffffffc) << (uRam020afd2c & 3) * -8 + 0x20) + 0x18;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x14;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    _DAT_05000000 =
         ((ushort)(uVar5 >> uVar6 * 8) | (ushort)(uVar5 << uVar6 * -8 + 0x20)) &
         (ushort)uRam020afd30;
    uVar5 = (*(uint *)(uRam020afd34 & 0xfffffffc) >> (uRam020afd34 & 3) * 8 |
            *(uint *)(uRam020afd34 & 0xfffffffc) << (uRam020afd34 & 3) * -8 + 0x20) + 0x80c;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0xc;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(ushort *)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) = _DAT_05000000;
    uVar5 = uVar8 & 3;
    uVar6 = *(uint *)(uVar8 & 0xfffffffc);
    uVar5 = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 0x80c;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    uVar5 = uVar6 + 0xc;
    uVar8 = uVar5 & 3;
    uVar7 = *(uint *)(uVar5 & 0xfffffffc);
    uVar6 = uVar6 + 8;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    Arm_FlushRange(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20,
                   uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
    uVar5 = (*(uint *)(uRam020afd34 & 0xfffffffc) >> (uRam020afd34 & 3) * 8 |
            *(uint *)(uRam020afd34 & 0xfffffffc) << (uRam020afd34 & 3) * -8 + 0x20) + 0x80c;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    uVar5 = uVar6 + 0xc;
    uVar8 = uVar5 & 3;
    uVar7 = *(uint *)(uVar5 & 0xfffffffc);
    uVar6 = uVar6 + 8;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    CopyPaletteTop(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20,0,
                   uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
    uVar5 = (*(uint *)(uRam020afd34 & 0xfffffffc) >> (uRam020afd34 & 3) * 8 |
            *(uint *)(uRam020afd34 & 0xfffffffc) << (uRam020afd34 & 3) * -8 + 0x20) + 0x814;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    uVar5 = uVar6 + 0x14;
    uVar8 = uVar5 & 3;
    uVar7 = *(uint *)(uVar5 & 0xfffffffc);
    uVar6 = uVar6 + 0x10;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    CopyBgData_Bg2_Top(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20,0,
                       uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
    uVar5 = (*(uint *)(uRam020afd34 & 0xfffffffc) >> (uRam020afd34 & 3) * 8 |
            *(uint *)(uRam020afd34 & 0xfffffffc) << (uRam020afd34 & 3) * -8 + 0x20) + 0x81c;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar8 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    uVar5 = uVar8 + 8;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    TEQSub_Fn10Impl_Fn12Impl(uVar8 + 0xc,0,uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
    uVar5 = GetRacePaletteBlock(0);
    uVar8 = GetRacePaletteBlock(0);
    uVar5 = (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
            *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0xc;
    uVar6 = uVar5 & 3;
    uVar7 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
            *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + 8;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    CopySomePaletteData(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20,0,
                        uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20);
    iVar9 = GetRacePaletteBlock(0);
    uVar5 = iVar9 + 4U & 3;
    uVar6 = *(uint *)(iVar9 + 4U & 0xfffffffc);
    uVar5 = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 0x14;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    CopyTileDataTop_0(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,0,0x4000);
    puVar3 = puRam020afd3c;
    puVar2 = puRam020afd38;
    _DAT_04000000 = _DAT_04000000 & 0xffff1fff | 0xe000;
    *puRam020afd38 = *puRam020afd38 & 0xffc0 | 0x3f;
    *puVar3 = 0xff;
    uVar1 = (undefined2)uRam020afd48;
    *puRam020afd44 = (short)uRam020afd40;
    puVar3 = puRam020afd4c;
    *puVar2 = *puVar2 & 0xc0ff | 0x3f00;
    *puVar3 = uVar1;
    puVar2 = puRam020afd54;
    *puRam020afd50 = 0x60;
    puVar4 = puRam020afd58;
    *puVar2 = *puVar2 & 0xc0ff | 0x3200;
    *puVar2 = *puVar2 & 0xffc0 | 0x2f;
    *puVar4 = (*(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
              *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20) & 0xffff1fff;
    SetDispcntSubBgMode(5);
    uVar5 = GetRacePaletteBlock(6);
    uVar8 = GetRacePaletteBlock(6);
    uVar5 = (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
            *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0xc;
    uVar6 = uVar5 & 3;
    uVar7 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
            *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + 8;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    TEQSub_Fn30Impl(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20,0,
                    uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20);
    iVar9 = GetRacePaletteBlock(6);
    uVar5 = iVar9 + 4U & 3;
    uVar6 = *(uint *)(iVar9 + 4U & 0xfffffffc);
    uVar5 = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 0x14;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    TEQSub_Fn35Impl(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,0,0x4000);
    func_020b17a4();
    iVar9 = func_020c3e14(0);
    iVar10 = func_020c3e14(0);
    uVar5 = iVar10 + 8U & 3;
    uVar6 = *(uint *)(iVar10 + 8U & 0xfffffffc);
    TEQSub_Fn25Impl(iVar9 + 0xc,0,uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
    iVar9 = func_020c3e14(1);
    iVar10 = func_020c3e14(1);
    uVar5 = iVar10 + 8U & 3;
    uVar6 = *(uint *)(iVar10 + 8U & 0xfffffffc);
    TEQSub_Fn26Impl_Fn28Impl(iVar9 + 0xc,0,uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
    iVar9 = func_020c3e14(2);
    iVar10 = func_020c3e14(2);
    uVar5 = iVar10 + 8U & 3;
    uVar6 = *(uint *)(iVar10 + 8U & 0xfffffffc);
    TEQSub_Fn27Impl_Fn29Impl(iVar9 + 0xc,0,uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
    CopyPaletteBottom((*(uint *)(uRam020afd5c & 0xfffffffc) >> (uRam020afd5c & 3) * 8 |
                      *(uint *)(uRam020afd5c & 0xfffffffc) << (uRam020afd5c & 3) * -8 + 0x20) +
                      0x200,0,0x200);
    func_020cfca4();
    GX_SetBankForSubBGExtPltt(0x80);
    func_0214b4dc();
    func_0214b468((*(uint *)(uRam020afd5c & 0xfffffffc) >> (uRam020afd5c & 3) * 8 |
                  *(uint *)(uRam020afd5c & 0xfffffffc) << (uRam020afd5c & 3) * -8 + 0x20) + 0x200,
                  0x4000,0x200);
    func_0214b468((*(uint *)(uRam020afd5c & 0xfffffffc) >> (uRam020afd5c & 3) * 8 |
                  *(uint *)(uRam020afd5c & 0xfffffffc) << (uRam020afd5c & 3) * -8 + 0x20) + 0x200,
                  0x6000,0x200);
    GXS_EndLoadBGExtPltt();
    iVar9 = GetChoises_s_b_Pallette_from_thumb();
    uVar5 = iVar9 + 0xcU & 3;
    uVar6 = *(uint *)(iVar9 + 0xcU & 0xfffffffc);
    CopyPaletteBottom(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20,0,0x200);
    puVar2 = puRam020afd64;
    *puRam020afd60 = 0;
    *puVar2 = *puVar2 & 0xfffc;
    *puVar2 = *puVar2 & 0xffbf;
    *puVar2 = *puVar2 & 0x43 | 0x10c;
    iVar9 = GetSomeBgTileData_from_thumb();
    iVar10 = GetSomeBgTileData_from_thumb();
    uVar5 = iVar9 + 0x14U & 3;
    uVar8 = *(uint *)(iVar9 + 0x14U & 0xfffffffc);
    uVar6 = iVar10 + 0x10U & 3;
    uVar7 = *(uint *)(iVar10 + 0x10U & 0xfffffffc);
    CopyBgData_Bg0_Bottom
              (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20,0,
               uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20);
    uVar11 = func_020b32f8();
    TEQSub_Fn24Impl(uVar11,0,0x600);
    func_020b18b0();
    *(undefined4 *)
     ((*(uint *)(uRam020afd34 & 0xfffffffc) >> (uRam020afd34 & 3) * 8 |
      *(uint *)(uRam020afd34 & 0xfffffffc) << (uRam020afd34 & 3) * -8 + 0x20) + 0x898) = 1;
    return;
  }
  return;
}

