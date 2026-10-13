/* Decompiled C draft; module arm9; ROM address 020b8624. No matching claim. */
#include "types.h"
#include "deps/020b8624_CreateGlobalB3C4.h"

void CreateGlobalB3C4(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  undefined4 uVar14;
  int iVar15;
  undefined4 local_224;
  undefined4 local_21c;
  undefined4 local_214;
  undefined4 local_210;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  undefined4 local_200;
  undefined4 local_1fc;
  int local_1f8;
  int local_1f4;
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined4 local_1e8;
  undefined4 uStack_1e4;
  undefined1 auStack_1e0 [32];
  undefined1 *local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined1 auStack_1b0 [32];
  undefined1 *local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined1 auStack_180 [32];
  undefined1 *local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined1 auStack_150 [32];
  undefined1 *local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined1 auStack_120 [40];
  undefined1 auStack_f8 [32];
  undefined1 *local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined1 auStack_c8 [32];
  undefined1 *local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined1 auStack_98 [40];
  undefined1 auStack_70 [32];
  undefined1 *puStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined1 auStack_40 [28];
  
  GetActiveExecutionContext();
  uVar3 = ExecutionContext_GetHeapHandle();
  uVar3 = Mem_AllocateHeap(uVar3,DAT_020b95c0);
  puVar1 = DAT_020b95c4;
  uVar10 = 0;
  *DAT_020b95c4 = uVar3;
  uVar13 = 0;
  do {
    uVar11 = (uint)puVar1 & 3;
    uVar9 = *(uint *)((uint)puVar1 & 0xfffffffc);
    *(undefined4 *)((uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) + uVar10 * 4) = 0;
    puVar2 = DAT_020b95c4;
    uVar10 = uVar10 + 1 & 0xffff;
  } while (uVar10 < 0x38);
  uVar10 = 0;
  do {
    uVar11 = (uint)puVar2 & 3;
    uVar9 = *(uint *)((uint)puVar2 & 0xfffffffc);
    iVar6 = uVar13 * 4;
    uVar13 = uVar13 + 1 & 0xffff;
    *(undefined4 *)((uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) + iVar6 + 0xe0) = 0;
    puVar1 = DAT_020b95c4;
  } while (uVar13 < 0x44);
  uVar13 = 0;
  do {
    uVar11 = (uint)puVar1 & 3;
    uVar9 = *(uint *)((uint)puVar1 & 0xfffffffc);
    iVar6 = uVar10 * 4;
    uVar10 = uVar10 + 1 & 0xffff;
    *(undefined4 *)((uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) + iVar6 + 0x1f0) = 0;
    puVar2 = DAT_020b95c4;
  } while (uVar10 < 0xf);
  uVar10 = 0;
  do {
    uVar11 = (uint)puVar2 & 3;
    uVar9 = *(uint *)((uint)puVar2 & 0xfffffffc);
    iVar6 = uVar13 * 4;
    uVar13 = uVar13 + 1 & 0xffff;
    *(undefined4 *)((uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) + iVar6 + 0x22c) = 0;
    puVar1 = DAT_020b95c4;
  } while (uVar13 < 0xd);
  uVar13 = 0;
  do {
    uVar11 = (uint)puVar1 & 3;
    uVar9 = *(uint *)((uint)puVar1 & 0xfffffffc);
    iVar6 = uVar10 * 4;
    uVar10 = uVar10 + 1 & 0xffff;
    *(undefined4 *)((uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) + iVar6 + 0x260) = 0;
    puVar2 = DAT_020b95c4;
  } while (uVar10 < 0x16);
  uVar10 = 0;
  do {
    uVar11 = (uint)puVar2 & 3;
    uVar9 = *(uint *)((uint)puVar2 & 0xfffffffc);
    iVar6 = uVar13 * 4;
    uVar13 = uVar13 + 1 & 0xffff;
    *(undefined4 *)((uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) + iVar6 + 0x2b8) = 0;
    puVar1 = DAT_020b95c4;
  } while (uVar13 < 8);
  uVar13 = 0;
  do {
    uVar11 = (uint)puVar1 & 3;
    uVar9 = *(uint *)((uint)puVar1 & 0xfffffffc);
    iVar6 = uVar10 * 4;
    uVar10 = uVar10 + 1 & 0xffff;
    *(undefined4 *)((uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) + iVar6 + 0x2d8) = 0;
    puVar2 = DAT_020b95c4;
  } while (uVar10 < 0xc9);
  uVar10 = 0;
  do {
    uVar11 = (uint)puVar2 & 3;
    uVar9 = *(uint *)((uint)puVar2 & 0xfffffffc);
    iVar6 = uVar13 * 4;
    uVar13 = uVar13 + 1 & 0xffff;
    *(undefined4 *)((uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) + iVar6 + 0x5fc) = 0;
    puVar1 = DAT_020b95c4;
  } while (uVar13 < 0x2c);
  uVar13 = 0;
  do {
    uVar11 = (uint)puVar1 & 3;
    uVar9 = *(uint *)((uint)puVar1 & 0xfffffffc);
    iVar6 = uVar10 * 4;
    uVar10 = uVar10 + 1 & 0xffff;
    *(undefined4 *)((uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) + iVar6 + 0x6ac) = 0;
    puVar2 = DAT_020b95c4;
  } while (uVar10 < 0x28);
  uVar10 = 0;
  do {
    uVar11 = (uint)puVar2 & 3;
    uVar9 = *(uint *)((uint)puVar2 & 0xfffffffc);
    iVar6 = uVar13 * 4;
    uVar13 = uVar13 + 1 & 0xffff;
    *(undefined4 *)((uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) + iVar6 + 0x74c) = 0;
    puVar1 = DAT_020b95c4;
  } while (uVar13 < 0x21);
  do {
    uVar13 = (uint)puVar1 & 3;
    uVar11 = *(uint *)((uint)puVar1 & 0xfffffffc);
    iVar6 = uVar10 * 4;
    uVar10 = uVar10 + 1 & 0xffff;
    *(undefined4 *)((uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20) + iVar6 + 2000) = 0;
  } while (uVar10 < 3);
  uVar3 = func_020b47c0(DAT_020b95c8);
  Gfx_ReadPalette((*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
                  *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20
                  ) + DAT_020b95cc,uVar3);
  uVar3 = func_020b47c0(DAT_020b95d0);
  Gfx_ReadPalette((*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
                  *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20
                  ) + DAT_020b95d4,uVar3);
  uVar10 = (*(uint *)(DAT_020b95d8 & 0xfffffffc) >> (DAT_020b95d8 & 3) * 8 |
           *(uint *)(DAT_020b95d8 & 0xfffffffc) << (DAT_020b95d8 & 3) * -8 + 0x20) + 8;
  uVar13 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  switch(uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) {
  case 0:
    break;
  case 1:
    uVar11 = *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
             *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20;
    uVar10 = uVar11 + 0x7dc;
    uVar13 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    *(uint *)(uVar11 + 0x7fc) = uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20;
    break;
  case 2:
    uVar3 = func_020b47c0(DAT_020b95dc);
    Gfx_ReadPalette((*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
                    *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) <<
                    ((uint)DAT_020b95c4 & 3) * -8 + 0x20) + DAT_020b95e0,uVar3);
    uVar10 = (*(uint *)(DAT_020b95d8 & 0xfffffffc) >> (DAT_020b95d8 & 3) * 8 |
             *(uint *)(DAT_020b95d8 & 0xfffffffc) << (DAT_020b95d8 & 3) * -8 + 0x20) + 0xc;
    uVar13 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    if ((uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) == 4) {
      uVar3 = func_020b47c0(DAT_020b95e4);
      Gfx_ReadPalette((*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
                      *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) <<
                      ((uint)DAT_020b95c4 & 3) * -8 + 0x20) + DAT_020b95e8,uVar3);
    }
    break;
  case 3:
    break;
  case 4:
    uVar3 = func_020b47c0(DAT_020b95ec);
    Gfx_ReadPalette((*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
                    *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) <<
                    ((uint)DAT_020b95c4 & 3) * -8 + 0x20) + DAT_020b95f0,uVar3);
    uVar3 = func_020b47c0(DAT_020b95f4);
    Gfx_ReadPalette((*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
                    *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) <<
                    ((uint)DAT_020b95c4 & 3) * -8 + 0x20) + DAT_020b95f8,uVar3);
    break;
  case 5:
  }
  uVar3 = func_020b47c0(DAT_020b95fc);
  Gfx_ReadCharGraphics
            ((*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
             *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20) +
             0x7e0,uVar3);
  uVar3 = func_020b47c0(DAT_020b9600);
  Gfx_ReadCharGraphics
            ((*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
             *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20) +
             0x7f0,uVar3);
  uVar10 = (*(uint *)(DAT_020b95d8 & 0xfffffffc) >> (DAT_020b95d8 & 3) * 8 |
           *(uint *)(DAT_020b95d8 & 0xfffffffc) << (DAT_020b95d8 & 3) * -8 + 0x20) + 8;
  uVar13 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  switch(uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) {
  case 0:
    break;
  case 1:
    uVar3 = func_020b47c0(DAT_020b9604);
    Gfx_ReadCharGraphics
              ((*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
               *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20) +
               0x800,uVar3);
    break;
  case 2:
    uVar3 = func_020b47c0(DAT_020b9608);
    Gfx_ReadCharGraphics
              ((*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
               *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20) +
               0x810,uVar3);
    uVar10 = (*(uint *)(DAT_020b95d8 & 0xfffffffc) >> (DAT_020b95d8 & 3) * 8 |
             *(uint *)(DAT_020b95d8 & 0xfffffffc) << (DAT_020b95d8 & 3) * -8 + 0x20) + 0xc;
    uVar13 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    if ((uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) == 4) {
      uVar3 = func_020b47c0(DAT_020b960c);
      Gfx_ReadCharGraphics
                ((*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
                 *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20)
                 + 0x880,uVar3);
    }
    break;
  case 3:
    break;
  case 4:
    uVar3 = func_020b47c0(DAT_020b9610);
    Gfx_ReadCharGraphics
              ((*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
               *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20) +
               0x820,uVar3);
    uVar3 = func_020b47c0(DAT_020b9614);
    Gfx_ReadCharGraphics
              ((*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
               *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20) +
               0x830,uVar3);
    break;
  case 5:
  }
  local_214 = 0;
  uVar3 = func_020b47c0(DAT_020b9618);
  LoadCellBankFrom(&local_214,uVar3);
  puVar1 = DAT_020b95c4;
  uVar10 = 0;
  do {
    uVar3 = CellBank_GetMetatileEntry(local_214,uVar10);
    uVar13 = (uint)puVar1 & 3;
    uVar11 = *(uint *)((uint)puVar1 & 0xfffffffc);
    *(undefined4 *)((uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20) + uVar10 * 4) = uVar3;
    uVar10 = uVar10 + 1 & 0xffff;
  } while (uVar10 < 0x38);
  local_210 = 0;
  uVar3 = func_020b47c0(DAT_020b961c);
  LoadCellBankFrom(&local_210,uVar3);
  puVar1 = DAT_020b95c4;
  uVar10 = 0;
  do {
    uVar3 = CellBank_GetMetatileEntry(local_210,uVar10);
    uVar13 = (uint)puVar1 & 3;
    uVar11 = *(uint *)((uint)puVar1 & 0xfffffffc);
    iVar6 = uVar10 * 4;
    uVar10 = uVar10 + 1 & 0xffff;
    *(undefined4 *)((uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20) + iVar6 + 0xe0) = uVar3;
  } while (uVar10 < 0x44);
  uVar13 = *(uint *)(DAT_020b95d8 & 0xfffffffc) >> (DAT_020b95d8 & 3) * 8 |
           *(uint *)(DAT_020b95d8 & 0xfffffffc) << (DAT_020b95d8 & 3) * -8 + 0x20;
  uVar10 = uVar13 + 8;
  uVar11 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  switch(uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20) {
  case 0:
    break;
  case 1:
    uVar3 = GetLoadedFont_from_thumb(2);
    uVar10 = (*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
             *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20) +
             0x7f0;
    uVar13 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar10 = (uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) + 0x14;
    uVar13 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    G2d_Sprite_CreateFromTiles
              (auStack_1e0,uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20,0x20,0x10);
    local_1b8 = ComputeSomeInterCharacterWidth();
    local_1c0 = auStack_1e0;
    local_1b4 = 0;
    local_1bc = uVar3;
    uVar3 = func_020b47cc(DAT_020b9620);
    Bmg_GetRawStringPointer_from_thumb(uVar3,0x81);
    G2d_Text_PrintString(&local_1c0,0x80,0x38,0xe);
    uVar10 = (*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
             *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20) +
             0x7f0;
    uVar13 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar13 = uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20;
    uVar10 = uVar13 + 0x14;
    uVar11 = uVar10 & 3;
    uVar9 = *(uint *)(uVar10 & 0xfffffffc);
    uVar13 = uVar13 + 0x10;
    uVar10 = uVar13 & 3;
    uVar13 = *(uint *)(uVar13 & 0xfffffffc);
    Arm_FlushRange(uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20,
                   uVar13 >> uVar10 * 8 | uVar13 << uVar10 * -8 + 0x20);
    local_20c = 0;
    uVar3 = func_020b47c0(DAT_020b9628);
    LoadCellBankFrom(&local_20c,uVar3);
    puVar1 = DAT_020b95c4;
    uVar10 = 0;
    do {
      uVar3 = CellBank_GetMetatileEntry(local_20c,uVar10);
      uVar13 = (uint)puVar1 & 3;
      uVar11 = *(uint *)((uint)puVar1 & 0xfffffffc);
      iVar6 = uVar10 * 4;
      uVar10 = uVar10 + 1 & 0xffff;
      *(undefined4 *)((uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20) + iVar6 + 0x1f0) = uVar3
      ;
    } while (uVar10 < 0xf);
    uVar3 = GetLoadedFont_from_thumb(2);
    uVar10 = (*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
             *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20) +
             0x800;
    uVar13 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar10 = (uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) + 0x14;
    uVar13 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    G2d_Sprite_CreateFromTiles(auStack_1b0,uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20,0x20)
    ;
    local_188 = ComputeSomeInterCharacterWidth();
    local_190 = auStack_1b0;
    local_184 = 0;
    local_18c = uVar3;
    uVar3 = func_020b47cc(DAT_020b962c);
    Bmg_GetRawStringPointer_from_thumb(uVar3,0x6d);
    G2d_Text_PrintString(&local_190,0x80,0x18,0xe);
    uVar10 = (*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
             *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20) +
             0x800;
    uVar13 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar13 = uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20;
    uVar10 = uVar13 + 0x14;
    uVar11 = uVar10 & 3;
    uVar9 = *(uint *)(uVar10 & 0xfffffffc);
    uVar13 = uVar13 + 0x10;
    uVar10 = uVar13 & 3;
    uVar13 = *(uint *)(uVar13 & 0xfffffffc);
    Arm_FlushRange(uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20,
                   uVar13 >> uVar10 * 8 | uVar13 << uVar10 * -8 + 0x20);
    uVar10 = (*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
             *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20) +
             0x800;
    uVar13 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar10 = (uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) + 0x14;
    uVar13 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    func_020b46d0(uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20,0,0,0x20);
    break;
  case 2:
    uVar13 = uVar13 + 0xc;
    uVar10 = uVar13 & 3;
    uVar13 = *(uint *)(uVar13 & 0xfffffffc);
    if ((uVar13 >> uVar10 * 8 | uVar13 << uVar10 * -8 + 0x20) == 4) {
      local_204 = 0;
      uVar3 = func_020b47c0(DAT_020b9634);
      LoadCellBankFrom(&local_204,uVar3);
      puVar1 = DAT_020b95c4;
      uVar10 = 0;
      do {
        uVar3 = CellBank_GetMetatileEntry(local_204,uVar10);
        uVar13 = (uint)puVar1 & 3;
        uVar11 = *(uint *)((uint)puVar1 & 0xfffffffc);
        iVar6 = uVar10 * 4;
        uVar10 = uVar10 + 1 & 0xffff;
        *(undefined4 *)((uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20) + iVar6 + 2000) =
             uVar3;
      } while (uVar10 < 3);
      uVar3 = GetLoadedFont_from_thumb(2);
      uVar13 = *(uint *)(DAT_020b95d8 & 0xfffffffc) >> (DAT_020b95d8 & 3) * 8 |
               *(uint *)(DAT_020b95d8 & 0xfffffffc) << (DAT_020b95d8 & 3) * -8 + 0x20;
      uVar10 = uVar13 & 3;
      uVar13 = *(uint *)(uVar13 & 0xfffffffc);
      uVar4 = GetBmgIndexFromCircuitIndex_from_thumb
                        (uVar13 >> uVar10 * 8 | uVar13 << uVar10 * -8 + 0x20);
      uVar10 = (*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
               *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20) +
               0x880;
      uVar13 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      uVar10 = (uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) + 0x14;
      uVar13 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      G2d_Sprite_CreateFromTiles
                (auStack_180,uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20,0x20);
      local_158 = GetSomeInterCharacterWidth();
      local_160 = auStack_180;
      local_154 = 0;
      uVar10 = (*(uint *)(DAT_020b95d8 & 0xfffffffc) >> (DAT_020b95d8 & 3) * 8 |
               *(uint *)(DAT_020b95d8 & 0xfffffffc) << (DAT_020b95d8 & 3) * -8 + 0x20) + 0x18;
      uVar13 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      if (uVar10 >> uVar13 * 8 == 0 && uVar10 << uVar13 * -8 + 0x20 == 0) {
        uVar14 = 0x54;
      }
      else {
        uVar14 = 0x55;
      }
      local_15c = uVar3;
      uVar3 = func_020b47cc(DAT_020b9638);
      Bmg_GetRawStringPointer_from_thumb(uVar3,uVar14);
      G2d_Text_PrintString(&local_160,0,9,0xc);
      uVar10 = (*(uint *)(DAT_020b95d8 & 0xfffffffc) >> (DAT_020b95d8 & 3) * 8 |
               *(uint *)(DAT_020b95d8 & 0xfffffffc) << (DAT_020b95d8 & 3) * -8 + 0x20) + 0x18;
      uVar13 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      if (uVar10 >> uVar13 * 8 == 0 && uVar10 << uVar13 * -8 + 0x20 == 0) {
        uVar3 = 0x54;
      }
      else {
        uVar3 = 0x55;
      }
      uVar14 = func_020b47cc(DAT_020b9640);
      Bmg_GetRawStringPointer_from_thumb(uVar14,uVar3);
      G2d_Text_PrintString(&local_160,0,8,0xc);
      local_158 = GetSomeInterCharacterWidth();
      uVar3 = func_020b47cc(DAT_020b9644);
      Bmg_GetRawStringPointer_from_thumb(uVar3,uVar4);
      G2d_Text_PrintString(&local_160,0,0x19,0xe);
      uVar3 = func_020b47cc(DAT_020b9648);
      Bmg_GetRawStringPointer_from_thumb(uVar3,uVar4);
      G2d_Text_PrintString(&local_160,0,0x18,0xe);
      uVar10 = (*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
               *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20) +
               0x880;
      uVar13 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      uVar13 = uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20;
      uVar10 = uVar13 + 0x14;
      uVar11 = uVar10 & 3;
      uVar9 = *(uint *)(uVar10 & 0xfffffffc);
      uVar13 = uVar13 + 0x10;
      uVar10 = uVar13 & 3;
      uVar13 = *(uint *)(uVar13 & 0xfffffffc);
      Arm_FlushRange(uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20,
                     uVar13 >> uVar10 * 8 | uVar13 << uVar10 * -8 + 0x20);
      uVar13 = *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
               *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20;
      uVar10 = uVar13 + 0x87c;
      uVar11 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      uVar13 = uVar13 + 0x7dc;
      uVar9 = uVar13 & 3;
      uVar7 = *(uint *)(uVar13 & 0xfffffffc);
      uVar10 = (uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20) + 0xc;
      uVar13 = uVar10 & 3;
      uVar5 = *(uint *)(uVar10 & 0xfffffffc);
      uVar10 = (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) + 0xc;
      uVar11 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      CopyMemory16(uVar5 >> uVar13 * 8 | uVar5 << uVar13 * -8 + 0x20,
                   uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20,0x40);
      uVar10 = (*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
               *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20) +
               0x880;
      uVar13 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      uVar10 = (uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) + 0x14;
      uVar13 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      func_020b46d0(uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20,0,0,0x20);
    }
    else {
      local_208 = 0;
      uVar3 = func_020b47c0(DAT_020b9630);
      LoadCellBankFrom(&local_208,uVar3);
      puVar1 = DAT_020b95c4;
      uVar10 = 0;
      do {
        uVar3 = CellBank_GetMetatileEntry(local_208,uVar10);
        iVar6 = uVar10 * 4;
        uVar10 = uVar10 + 1 & 0xffff;
        *(undefined4 *)
         ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
          *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + iVar6 + 0x22c) =
             uVar3;
      } while (uVar10 < 0xd);
      uVar13 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
               *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20;
      uVar10 = uVar13 + 0x80c;
      uVar11 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      uVar13 = uVar13 + 0x7dc;
      uVar9 = uVar13 & 3;
      uVar7 = *(uint *)(uVar13 & 0xfffffffc);
      uVar10 = (uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20) + 0xc;
      uVar13 = uVar10 & 3;
      uVar5 = *(uint *)(uVar10 & 0xfffffffc);
      uVar10 = (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) + 0xc;
      uVar11 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      CopyMemory16(uVar5 >> uVar13 * 8 | uVar5 << uVar13 * -8 + 0x20,
                   uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20,0x40);
      uVar10 = (*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
               *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20) +
               0x810;
      uVar13 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      uVar10 = (uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) + 0x14;
      uVar13 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      func_020b46d0(uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20,0,0,0x20);
    }
    break;
  case 3:
    break;
  case 4:
    local_200 = 0;
    uVar3 = func_020b47c0(DAT_020b964c);
    LoadCellBankFrom(&local_200,uVar3);
    puVar1 = DAT_020b95c4;
    uVar10 = 0;
    do {
      uVar3 = CellBank_GetMetatileEntry(local_200,uVar10);
      iVar6 = uVar10 * 4;
      uVar10 = uVar10 + 1 & 0xffff;
      *(undefined4 *)
       ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
        *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + iVar6 + 0x260) =
           uVar3;
    } while (uVar10 < 0x16);
    uVar13 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
             *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20;
    uVar10 = uVar13 + 0x81c;
    uVar11 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar13 = uVar13 + 0x7dc;
    uVar9 = uVar13 & 3;
    uVar7 = *(uint *)(uVar13 & 0xfffffffc);
    uVar10 = (uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20) + 0xc;
    uVar13 = uVar10 & 3;
    uVar5 = *(uint *)(uVar10 & 0xfffffffc);
    uVar10 = (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) + 0xc;
    uVar11 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    CopyMemory16(uVar5 >> uVar13 * 8 | uVar5 << uVar13 * -8 + 0x20,
                 uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20,0x40);
    uVar10 = (*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
             *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20) +
             0x820;
    uVar13 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar10 = (uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) + 0x14;
    uVar13 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    func_020b46d0(uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20,0,0,0x20);
    local_1fc = 0;
    uVar3 = func_020b47c0(DAT_020b9650);
    LoadCellBankFrom(&local_1fc,uVar3);
    puVar1 = DAT_020b95c4;
    uVar10 = 0;
    do {
      uVar3 = CellBank_GetMetatileEntry(local_1fc,uVar10);
      iVar6 = uVar10 * 4;
      uVar10 = uVar10 + 1 & 0xffff;
      *(undefined4 *)
       ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
        *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + iVar6 + 0x2b8) =
           uVar3;
    } while (uVar10 < 8);
    uVar13 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
             *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20;
    uVar10 = uVar13 + 0x82c;
    uVar11 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar13 = uVar13 + 0x7ec;
    uVar9 = uVar13 & 3;
    uVar7 = *(uint *)(uVar13 & 0xfffffffc);
    uVar10 = (uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20) + 0xc;
    uVar13 = uVar10 & 3;
    uVar5 = *(uint *)(uVar10 & 0xfffffffc);
    uVar10 = (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) + 0xc;
    uVar11 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    CopyMemory16(uVar5 >> uVar13 * 8 | uVar5 << uVar13 * -8 + 0x20,
                 uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20,0x20);
    uVar10 = (*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
             *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20) +
             0x830;
    uVar13 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar10 = (uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) + 0x14;
    uVar13 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    func_020b46d0(uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20,0,0,0x20);
    break;
  case 5:
    local_1f8 = 0;
    uVar3 = func_020b47c0(DAT_020b9654);
    Gfx_ReadCharGraphics(&local_1f8,uVar3);
    uVar10 = local_1f8 + 0x14U & 3;
    uVar13 = *(uint *)(local_1f8 + 0x14U & 0xfffffffc);
    uVar10 = uVar13 >> uVar10 * 8 | uVar13 << uVar10 * -8 + 0x20;
    func_020b46d0(uVar10,0,0,8);
    func_020b46d0(uVar10,0,0,8);
  }
  uVar3 = func_020b47c0(DAT_020b9658);
  Gfx_ReadPalette((*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
                  *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20
                  ) + DAT_020b965c,uVar3);
  uVar3 = func_020b47c0(DAT_020b9660);
  Gfx_ReadPalette((*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
                  *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20
                  ) + DAT_020b9664,uVar3);
  uVar3 = func_020b47c0(DAT_020b9668);
  Gfx_ReadPalette((*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
                  *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20
                  ) + DAT_020b966c,uVar3);
  if (*(char *)((*(uint *)(DAT_020b95d8 & 0xfffffffc) >> (DAT_020b95d8 & 3) * 8 |
                *(uint *)(DAT_020b95d8 & 0xfffffffc) << (DAT_020b95d8 & 3) * -8 + 0x20) + 0x58) !=
      '\0') {
    local_1f4 = 0;
    iVar6 = GetCurrentPlayerRacerId();
    uVar10 = iVar6 * 0x30 +
             (*(uint *)(DAT_020b95d8 & 0xfffffffc) >> (DAT_020b95d8 & 3) * 8 |
             *(uint *)(DAT_020b95d8 & 0xfffffffc) << (DAT_020b95d8 & 3) * -8 + 0x20) + 0x74;
    uVar13 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    if (uVar10 >> uVar13 * 8 == 0 && uVar10 << uVar13 * -8 + 0x20 == 0) {
      iVar6 = 0x13;
    }
    else {
      iVar6 = 0x23;
    }
    uVar3 = func_020b47c0(DAT_020b9670);
    Gfx_ReadPalette(&local_1f4,uVar3);
    uVar10 = (*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
             *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20) +
             0x83c;
    uVar13 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar10 = (uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) + 0xc;
    uVar13 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    Arm_FlushRange(uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20,0x200);
    puVar1 = DAT_020b95c4;
    iVar15 = 0;
    do {
      uVar10 = (uint)puVar1 & 3;
      uVar13 = *(uint *)((uint)puVar1 & 0xfffffffc);
      iVar12 = iVar6 + iVar15;
      uVar10 = (uVar13 >> uVar10 * 8 | uVar13 << uVar10 * -8 + 0x20) + 0x83c;
      uVar13 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      uVar11 = local_1f4 + 0xcU & 3;
      uVar9 = *(uint *)(local_1f4 + 0xcU & 0xfffffffc);
      iVar8 = iVar15 + 0xb3;
      iVar15 = iVar15 + 1;
      uVar10 = (uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) + 0xc;
      uVar13 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      *(undefined2 *)((uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) + iVar8 * 2) =
           *(undefined2 *)((uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) + iVar12 * 2);
    } while (iVar15 < 4);
  }
  uVar3 = func_020b47c0(DAT_020b9674);
  Gfx_ReadCharGraphics
            ((*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
             *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20) +
             0x840,uVar3);
  uVar3 = func_020b47c0(DAT_020b9678);
  Gfx_ReadCharGraphics
            ((*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
             *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20) +
             0x850,uVar3);
  uVar3 = func_020b47c0(DAT_020b967c);
  Gfx_ReadCharGraphics
            ((*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
             *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20) +
             0x860,uVar3);
  uVar3 = GetLoadedFont_from_thumb(0);
  uVar10 = (*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
           *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20) +
           0x850;
  uVar13 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  uVar10 = (uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) + 0x14;
  uVar13 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  G2d_Sprite_CreateFromTiles
            (auStack_150,uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20,0x20,0x10);
  local_130 = auStack_150;
  uVar10 = 0;
  local_128 = 1;
  local_124 = 0;
  local_12c = uVar3;
  if (*(char *)((*(uint *)(DAT_020b95d8 & 0xfffffffc) >> (DAT_020b95d8 & 3) * 8 |
                *(uint *)(DAT_020b95d8 & 0xfffffffc) << (DAT_020b95d8 & 3) * -8 + 0x20) + 0x3d0) !=
      '\0') {
    do {
      uVar13 = (uint)(((int)(uVar10 * -0x80000000) >> 0x1f) * -0x680000) >> 0x10;
      uVar11 = (uVar10 >> 1) * 0x10 + 0x48 & 0xffff;
      FormatRacerNameString_from_thumb(uVar10,auStack_120,1);
      GetCurrentPlayerRacerId();
      G2d_Text_PrintString(&local_130,uVar13,uVar11 + 1);
      GetCurrentPlayerRacerId();
      G2d_Text_PrintString(&local_130,uVar13,uVar11);
      uVar10 = uVar10 + 1 & 0xffff;
    } while (uVar10 < *(byte *)((*(uint *)(DAT_020b95d8 & 0xfffffffc) >> (DAT_020b95d8 & 3) * 8 |
                                *(uint *)(DAT_020b95d8 & 0xfffffffc) <<
                                (DAT_020b95d8 & 3) * -8 + 0x20) + 0x3d0));
  }
  uVar3 = GetLoadedFont_from_thumb(2);
  uVar10 = (*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
           *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20) +
           0x850;
  uVar13 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  uVar10 = (uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) + 0x14;
  uVar13 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  G2d_Sprite_CreateFromTiles
            (auStack_f8,uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20,0x20,0x10);
  local_d8 = auStack_f8;
  local_d0 = 1;
  local_cc = 0;
  local_d4 = uVar3;
  uVar3 = func_020b47cc(DAT_020b9680);
  Bmg_GetRawStringPointer_from_thumb(uVar3,0x79);
  G2d_Text_PrintString(&local_d8,0x20,0x38,0xe);
  uVar3 = GetLoadedFont_from_thumb(0);
  uVar10 = (*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
           *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20) +
           0x860;
  uVar13 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  uVar10 = (uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) + 0x14;
  uVar13 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  G2d_Sprite_CreateFromTiles(auStack_c8,uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20,0x20,10)
  ;
  local_a0 = 1;
  local_a8 = auStack_c8;
  uVar10 = 0;
  local_9c = 0;
  local_a4 = uVar3;
  if (*(char *)((*(uint *)(DAT_020b95d8 & 0xfffffffc) >> (DAT_020b95d8 & 3) * 8 |
                *(uint *)(DAT_020b95d8 & 0xfffffffc) << (DAT_020b95d8 & 3) * -8 + 0x20) + 0x3d0) !=
      '\0') {
    local_21c = 0xe;
    local_224 = 0xc;
    do {
      uVar13 = (uVar10 & 3) * 0x380000 >> 0x10;
      uVar11 = (uVar10 >> 2) * 0x10 + 0x38 & 0xffff;
      FormatRacerNameString_from_thumb(uVar10,auStack_98,0);
      uVar9 = GetCurrentPlayerRacerId();
      uVar3 = local_21c;
      if ((uVar10 == uVar9) &&
         (uVar9 = *(uint *)(DAT_020b95d8 & 0xfffffffc) >> (DAT_020b95d8 & 3) * 8 |
                  *(uint *)(DAT_020b95d8 & 0xfffffffc) << (DAT_020b95d8 & 3) * -8 + 0x20,
         uVar3 = local_224, *(char *)(uVar9 + 0x58) != '\0')) {
        uVar9 = uVar10 * 0x30 + uVar9 + 0x74;
        uVar5 = uVar9 & 3;
        uVar9 = *(uint *)(uVar9 & 0xfffffffc);
        if (uVar9 >> uVar5 * 8 == 0 && uVar9 << uVar5 * -8 + 0x20 == 0) {
          uVar3 = 10;
        }
        else {
          uVar3 = 8;
        }
      }
      G2d_Text_PrintString(&local_a8,uVar13,uVar11 + 1);
      G2d_Text_PrintString(&local_a8,uVar13,uVar11,uVar3);
      uVar10 = uVar10 + 1 & 0xffff;
    } while (uVar10 < *(byte *)((*(uint *)(DAT_020b95d8 & 0xfffffffc) >> (DAT_020b95d8 & 3) * 8 |
                                *(uint *)(DAT_020b95d8 & 0xfffffffc) <<
                                (DAT_020b95d8 & 3) * -8 + 0x20) + 0x3d0));
  }
  local_1f0 = 0;
  uVar3 = func_020b47c0(DAT_020b9684);
  LoadCellBankFrom(&local_1f0,uVar3);
  puVar1 = DAT_020b95c4;
  uVar10 = 0;
  do {
    uVar3 = CellBank_GetMetatileEntry(local_1f0,uVar10);
    uVar13 = (uint)puVar1 & 3;
    uVar11 = *(uint *)((uint)puVar1 & 0xfffffffc);
    iVar6 = uVar10 * 4;
    uVar10 = uVar10 + 1 & 0xffff;
    *(undefined4 *)((uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20) + iVar6 + 0x2d8) = uVar3;
  } while (uVar10 < 0xc9);
  local_1ec = 0;
  uVar3 = func_020b47c0(DAT_020b997c);
  LoadCellBankFrom(&local_1ec,uVar3);
  puVar1 = DAT_020b95c4;
  uVar10 = 0;
  do {
    uVar3 = CellBank_GetMetatileEntry(local_1ec,uVar10);
    uVar13 = (uint)puVar1 & 3;
    uVar11 = *(uint *)((uint)puVar1 & 0xfffffffc);
    iVar6 = uVar10 * 4;
    uVar10 = uVar10 + 1 & 0xffff;
    *(undefined4 *)((uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20) + iVar6 + 0x5fc) = uVar3;
  } while (uVar10 < 0x2c);
  local_1e8 = 0;
  uVar3 = func_020b47c0(DAT_020b9980);
  LoadCellBankFrom(&local_1e8,uVar3);
  puVar1 = DAT_020b95c4;
  uVar10 = 0;
  do {
    uVar3 = CellBank_GetMetatileEntry(local_1e8,uVar10);
    uVar13 = (uint)puVar1 & 3;
    uVar11 = *(uint *)((uint)puVar1 & 0xfffffffc);
    iVar6 = uVar10 * 4;
    uVar10 = uVar10 + 1 & 0xffff;
    *(undefined4 *)((uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20) + iVar6 + 0x6ac) = uVar3;
  } while (uVar10 < 0x28);
  uVar10 = (*(uint *)(DAT_020b95d8 & 0xfffffffc) >> (DAT_020b95d8 & 3) * 8 |
           *(uint *)(DAT_020b95d8 & 0xfffffffc) << (DAT_020b95d8 & 3) * -8 + 0x20) + 8;
  uVar13 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  if ((uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) == 1) {
    uVar3 = func_020b47c0(DAT_020b9984);
    Gfx_ReadPalette((*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
                    *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) <<
                    ((uint)DAT_020b95c4 & 3) * -8 + 0x20) + DAT_020b9988,uVar3);
    uVar3 = func_020b47c0(DAT_020b998c);
    Gfx_ReadCharGraphics
              ((*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
               *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20) +
               0x870,uVar3);
    uVar3 = GetLoadedFont_from_thumb(0);
    uVar10 = (*(uint *)((uint)DAT_020b95c4 & 0xfffffffc) >> ((uint)DAT_020b95c4 & 3) * 8 |
             *(uint *)((uint)DAT_020b95c4 & 0xfffffffc) << ((uint)DAT_020b95c4 & 3) * -8 + 0x20) +
             0x870;
    uVar13 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar10 = (uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) + 0x14;
    uVar13 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    G2d_Sprite_CreateFromTiles
              (auStack_70,uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20,0x20,0x10);
    puStack_50 = auStack_70;
    uVar10 = 0;
    uStack_48 = 1;
    uStack_44 = 0;
    uStack_4c = uVar3;
    do {
      uVar13 = (uVar10 >> 1) * 0x10 + 0x49 & 0xffff;
      FormatTimeTrialRecordRacerNameString(uVar10,auStack_40,1);
      uVar11 = (uint)(((int)(uVar10 * -0x80000000) >> 0x1f) * -0x680000) >> 0x10;
      G2d_Text_PrintString(&puStack_50,uVar11,uVar13 + 1,0xf);
      G2d_Text_PrintString(&puStack_50,uVar11,uVar13,0xe);
      uVar10 = uVar10 + 1 & 0xffff;
    } while (uVar10 < 7);
    uStack_1e4 = 0;
    uVar3 = func_020b47c0(DAT_020b9990);
    LoadCellBankFrom(&uStack_1e4,uVar3);
    puVar1 = DAT_020b95c4;
    uVar10 = 0;
    do {
      uVar3 = CellBank_GetMetatileEntry(uStack_1e4,uVar10);
      uVar13 = (uint)puVar1 & 3;
      uVar11 = *(uint *)((uint)puVar1 & 0xfffffffc);
      iVar6 = uVar10 * 4;
      uVar10 = uVar10 + 1 & 0xffff;
      *(undefined4 *)((uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20) + iVar6 + 0x74c) = uVar3
      ;
    } while (uVar10 < 0x21);
    return;
  }
  return;
}

