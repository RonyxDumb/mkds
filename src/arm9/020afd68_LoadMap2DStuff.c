/* Decompiled C draft; module arm9; ROM address 020afd68. No matching claim. */
#include "types.h"
#include "deps/020afd68_LoadMap2DStuff.h"

/* WARNING: Type propagation algorithm not settling */

void LoadMap2DStuff(void)

{
  undefined2 uVar1;
  ushort uVar2;
  undefined4 *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int unaff_r4;
  int iVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  bool bVar17;
  int aiStack_40 [4];
  int iStack_30;
  int iStack_2c;
  int aiStack_28 [3];
  int iStack_1c;
  
  uVar8 = *(uint *)(uRam020b0354 & 0xfffffffc) >> (uRam020b0354 & 3) * 8 |
          *(uint *)(uRam020b0354 & 0xfffffffc) << (uRam020b0354 & 3) * -8 + 0x20;
  uVar6 = uVar8 + 8;
  uVar10 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  bVar17 = (uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) != 4;
  if (bVar17) {
    unaff_r4 = 1;
  }
  uVar8 = uVar8 + 0xc;
  uVar6 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  uVar6 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
  if (!bVar17) {
    unaff_r4 = 0;
  }
  if (uVar6 == 3) {
    return;
  }
  if (uVar6 - 5 < 2) {
    return;
  }
  GetActiveExecutionContext();
  uVar7 = ExecutionContext_GetHeapHandle();
  uVar7 = Mem_AllocateHeap(uVar7,0x400);
  iVar11 = 0;
  *puRam020b0358 = uVar7;
  iVar9 = 0;
  do {
    aiStack_40[iVar11] = 0;
    aiStack_40[iVar11 + 3] = 0;
    iVar11 = iVar11 + 1;
  } while (iVar11 < 2);
  do {
    aiStack_40[iVar9 + 6] = 0;
    iVar9 = iVar9 + 1;
  } while (iVar9 < 3);
  iVar9 = GetMountData7FlagBit31_from_thumb();
  if (iVar9 == 0) {
    if (unaff_r4 != 0) {
      uVar7 = func_020b47b4(uRam020b0368);
      Gfx_ReadPaletteRelative(aiStack_40,uVar7);
      uVar7 = func_020b47b4(uRam020b036c);
      Gfx_ReadPaletteRelative(aiStack_40 + 1,uVar7);
    }
    uVar7 = func_020b47b4(uRam020b0370);
    Gfx_ReadPaletteRelative(aiStack_40 + 2,uVar7);
  }
  else {
    if (unaff_r4 != 0) {
      uVar7 = func_020b47b4(uRam020b035c);
      Gfx_ReadPalette(aiStack_40,uVar7);
      uVar7 = func_020b47b4(uRam020b0360);
      Gfx_ReadPalette(aiStack_40 + 1,uVar7);
    }
    uVar7 = func_020b47b4(uRam020b0364);
    Gfx_ReadPalette(aiStack_40 + 2,uVar7);
  }
  iVar9 = GetMountData7FlagBit31_from_thumb();
  if (iVar9 == 0) {
    if (unaff_r4 != 0) {
      uVar7 = func_020b47b4(uRam020b0380);
      MaybeReadCharBlock_1(aiStack_40 + 3,uVar7);
      uVar7 = func_020b47b4(uRam020b0384);
      MaybeReadCharBlock_1(aiStack_40 + 4,uVar7);
    }
    uVar7 = func_020b47b4(uRam020b0388);
    MaybeReadCharBlock_1(aiStack_40 + 5,uVar7);
  }
  else {
    if (unaff_r4 != 0) {
      uVar7 = func_020b47b4(uRam020b0374);
      Gfx_ReadCharGraphicsV2(aiStack_40 + 3,uVar7);
      uVar7 = func_020b47b4(uRam020b0378);
      Gfx_ReadCharGraphicsV2(aiStack_40 + 4,uVar7);
    }
    uVar7 = func_020b47b4(uRam020b037c);
    Gfx_ReadCharGraphicsV2(aiStack_40 + 5,uVar7);
  }
  iVar9 = GetMountData7FlagBit31_from_thumb();
  if (iVar9 == 0) {
    if (unaff_r4 != 0) {
      uVar7 = func_020b47b4(uRam020b039c);
      MaybeReadScreenBlock(aiStack_40 + 6,uVar7);
      uVar7 = func_020b47b4(uRam020b03a0);
      MaybeReadScreenBlock(aiStack_40 + 7,uVar7);
    }
    uVar7 = func_020b47b4(uRam020b03a4);
    MaybeReadScreenBlock(aiStack_40 + 8,uVar7);
    iVar9 = MaybeCircuitUsesLocal3();
    if (iVar9 != 0) {
      uVar7 = func_020b47b4(uRam020b03a8);
      MaybeReadScreenBlock(aiStack_40 + 9,uVar7);
    }
  }
  else {
    if (unaff_r4 != 0) {
      uVar7 = func_020b47b4(uRam020b038c);
      MaybeReadScreenBlock_0(aiStack_40 + 6,uVar7);
      uVar7 = func_020b47b4(uRam020b0390);
      MaybeReadScreenBlock_0(aiStack_40 + 7,uVar7);
    }
    uVar7 = func_020b47b4(uRam020b0394);
    MaybeReadScreenBlock_0(aiStack_40 + 8,uVar7);
    iVar9 = MaybeCircuitUsesLocal3();
    if (iVar9 != 0) {
      uVar7 = func_020b47b4(uRam020b0398);
      MaybeReadScreenBlock_0(aiStack_40 + 9,uVar7);
    }
  }
  if (unaff_r4 != 0) {
    if (*(char *)((*(uint *)(uRam020b0354 & 0xfffffffc) >> (uRam020b0354 & 3) * 8 |
                  *(uint *)(uRam020b0354 & 0xfffffffc) << (uRam020b0354 & 3) * -8 + 0x20) + 0x57) !=
        '\0') {
      iVar12 = 3;
      iVar11 = aiStack_28[0] + 0xc;
      iVar9 = 0x60;
      do {
        iVar15 = 0xe;
        do {
          iVar14 = iVar15 + iVar9;
          iVar13 = iVar9 + (0x2d - iVar15);
          if (iVar14 < iVar13) {
            iVar13 = iVar13 * 2;
            uVar1 = *(undefined2 *)(iVar11 + iVar13);
            *(undefined2 *)(iVar11 + iVar13) = *(undefined2 *)(iVar11 + iVar14 * 2);
            *(undefined2 *)(iVar11 + iVar14 * 2) = uVar1;
          }
          iVar15 = iVar15 + 1;
          *(ushort *)(iVar11 + iVar14 * 2) = *(ushort *)(iVar11 + iVar14 * 2) ^ 0x400;
        } while (iVar15 < 0x20);
        iVar12 = iVar12 + 1;
        iVar9 = iVar9 + 0x20;
      } while (iVar12 < 0x18);
    }
    iVar9 = 0;
    uVar8 = *(uint *)(uRam020b0354 & 0xfffffffc) >> (uRam020b0354 & 3) * 8 |
            *(uint *)(uRam020b0354 & 0xfffffffc) << (uRam020b0354 & 3) * -8 + 0x20;
    uVar6 = uVar8 + 8;
    uVar10 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    if (((uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) == 2) &&
       (uVar8 = uVar8 + 0x18, uVar6 = uVar8 & 3, uVar8 = *(uint *)(uVar8 & 0xfffffffc),
       (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) == 1)) {
      iVar9 = 1;
    }
    iVar11 = (iVar9 + 1) * 0x10;
    iVar12 = 0;
    do {
      iVar15 = iVar12 + 0x10;
      uVar6 = aiStack_40[1] + 0xcU & 3;
      uVar16 = *(uint *)(aiStack_40[1] + 0xcU & 0xfffffffc);
      iVar12 = iVar12 + 1;
      uVar8 = aiStack_40[0] + 0xcU & 3;
      uVar10 = *(uint *)(aiStack_40[0] + 0xcU & 0xfffffffc);
      *(undefined2 *)((uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) + iVar15 * 2) =
           *(undefined2 *)((uVar16 >> uVar6 * 8 | uVar16 << uVar6 * -8 + 0x20) + iVar11 * 2);
      iVar11 = iVar11 + 1;
    } while (iVar12 < 0x10);
    iVar11 = 0;
    do {
      iVar12 = aiStack_28[1] + iVar11 * 2;
      uVar2 = *(ushort *)(iVar12 + 0xc);
      iVar11 = iVar11 + 1;
      *(ushort *)(iVar12 + 0xc) = (uVar2 & 0x3ff) + ((short)iVar9 + 6) * 0x20 | uVar2 & 0xfc00;
    } while (iVar11 < 0x400);
    DC_func_0002();
    SetDispcntSubBgMode(5);
    *puRam020b03ac =
         (*(uint *)((uint)puRam020b03ac & 0xfffffffc) >> ((uint)puRam020b03ac & 3) * 8 |
         *(uint *)((uint)puRam020b03ac & 0xfffffffc) << ((uint)puRam020b03ac & 3) * -8 + 0x20) &
         0xffffe0ff | 0x1c00;
    SetDispcntSubBgMode(0);
    puVar4 = puRam020b03b4;
    *puRam020b03b0 = 0;
    puVar5 = puRam020b03b8;
    *puVar4 = *puVar4 & 0xfffc | 2;
    *puVar4 = *puVar4 & 0xffbf;
    *puVar4 = *puVar4 & 0x43 | 0x208;
    *puVar4 = *puVar4 & 0xfffc | 3;
    *puVar5 = *puVar5 & 0xffbf;
    *puVar5 = *puVar5 & 0x43 | 0x308;
    uVar6 = aiStack_40[0] + 0xcU & 3;
    uVar10 = *(uint *)(aiStack_40[0] + 0xcU & 0xfffffffc);
    uVar8 = aiStack_40[0] + 8U & 3;
    uVar16 = *(uint *)(aiStack_40[0] + 8U & 0xfffffffc);
    CopyPaletteBottom(uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20,0,
                      uVar16 >> uVar8 * 8 | uVar16 << uVar8 * -8 + 0x20);
    uVar6 = aiStack_40[3] + 0x14U & 3;
    uVar10 = *(uint *)(aiStack_40[3] + 0x14U & 0xfffffffc);
    uVar8 = aiStack_40[3] + 0x10U & 3;
    uVar16 = *(uint *)(aiStack_40[3] + 0x10U & 0xfffffffc);
    CopyBgData_Bg2_Bottom
              (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20,0,
               uVar16 >> uVar8 * 8 | uVar16 << uVar8 * -8 + 0x20);
    uVar6 = iStack_30 + 0x14U & 3;
    uVar10 = *(uint *)(iStack_30 + 0x14U & 0xfffffffc);
    uVar8 = iStack_30 + 0x10U & 3;
    uVar16 = *(uint *)(iStack_30 + 0x10U & 0xfffffffc);
    CopyBgData_Bg2_Bottom
              (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20,0x1800,
               uVar16 >> uVar8 * 8 | uVar16 << uVar8 * -8 + 0x20);
    uVar6 = aiStack_28[0] + 8U & 3;
    uVar8 = *(uint *)(aiStack_28[0] + 8U & 0xfffffffc);
    TEQSub_Fn26Impl_Fn28Impl(aiStack_28[0] + 0xc,0,uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20);
    uVar6 = aiStack_28[1] + 8U & 3;
    uVar8 = *(uint *)(aiStack_28[1] + 8U & 0xfffffffc);
    TEQSub_Fn27Impl_Fn29Impl(aiStack_28[1] + 0xc,0,uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20);
  }
  func_020b18b0();
  uVar6 = aiStack_40[2] + 0xcU & 3;
  uVar8 = *(uint *)(aiStack_40[2] + 0xcU & 0xfffffffc);
  CopyPaletteBottom(uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20,0,0x200);
  uVar6 = iStack_2c + 0x14U & 3;
  uVar10 = *(uint *)(iStack_2c + 0x14U & 0xfffffffc);
  uVar8 = iStack_2c + 0x10U & 3;
  uVar16 = *(uint *)(iStack_2c + 0x10U & 0xfffffffc);
  CopyBgData_Bg3_Bottom
            (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20,0,
             uVar16 >> uVar8 * 8 | uVar16 << uVar8 * -8 + 0x20);
  uVar6 = aiStack_28[2] + 8U & 3;
  uVar8 = *(uint *)(aiStack_28[2] + 8U & 0xfffffffc);
  TEQSub_Fn26Impl_Fn28Impl(aiStack_28[2] + 0xc,0,uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20);
  iVar9 = MaybeCircuitUsesLocal3();
  if (iVar9 != 0) {
    uVar6 = iStack_1c + 8U & 3;
    uVar8 = *(uint *)(iStack_1c + 8U & 0xfffffffc);
    TEQSub_Fn27Impl_Fn29Impl(iStack_1c + 0xc,0,uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20);
  }
  GX_SetBankForSubBGExtPltt(0x80);
  func_0214b4dc();
  uVar6 = aiStack_40[2] + 0xcU & 3;
  uVar8 = *(uint *)(aiStack_40[2] + 0xcU & 0xfffffffc);
  func_0214b468(uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20,0x4000,0x200);
  uVar6 = aiStack_40[2] + 0xcU & 3;
  uVar8 = *(uint *)(aiStack_40[2] + 0xcU & 0xfffffffc);
  func_0214b468(uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20,0x6000,0x200);
  GXS_EndLoadBGExtPltt();
  puVar3 = puRam020b0358;
  iVar9 = 0;
  do {
    if (unaff_r4 != 0) {
      uVar6 = aiStack_40[0] + 0xcU & 3;
      uVar8 = *(uint *)(aiStack_40[0] + 0xcU & 0xfffffffc);
      *(undefined2 *)
       ((*(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
        *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20) + iVar9 * 2) =
           *(undefined2 *)((uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) + iVar9 * 2);
    }
    uVar6 = aiStack_40[2] + 0xcU & 3;
    uVar8 = *(uint *)(aiStack_40[2] + 0xcU & 0xfffffffc);
    iVar11 = iVar9 * 2;
    iVar12 = iVar9 * 2;
    iVar9 = iVar9 + 1;
    *(undefined2 *)
     ((*(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
      *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20) + iVar12 + 0x200) =
         *(undefined2 *)((uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) + iVar11);
  } while (iVar9 < 0x100);
  if (unaff_r4 != 0) {
    Arm_FlushRange(*(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
                   *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20,0x200);
  }
  Arm_FlushRange((*(uint *)((uint)puRam020b0358 & 0xfffffffc) >> ((uint)puRam020b0358 & 3) * 8 |
                 *(uint *)((uint)puRam020b0358 & 0xfffffffc) <<
                 ((uint)puRam020b0358 & 3) * -8 + 0x20) + 0x200,0x200);
  return;
}

