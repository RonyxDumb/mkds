/* Decompiled C draft; module arm9; ROM address 020c4bec. No matching claim. */
#include "types.h"
#include "deps/020c4bec_InitializeRaceIntroData.h"

/* WARNING: Removing unreachable block (ram,0x020c4d58) */

void InitializeRaceIntroData(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 local_40;
  undefined1 auStack_3c [32];
  undefined1 *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  GetActiveExecutionContext();
  uVar2 = ExecutionContext_GetHeapHandle();
  uVar2 = Mem_AllocateHeap(uVar2,uRam020c4e24);
  puVar1 = puRam020c4e28;
  iVar9 = 0;
  iVar8 = 0;
  *puRam020c4e28 = uVar2;
  do {
    iVar9 = iVar9 + 1;
    iVar7 = (*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
            *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0x18;
    uVar3 = iVar7 + iVar8;
    uVar4 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(uint *)(iVar7 + iVar8) =
         (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xfffff3ff | 0xc00;
    uVar2 = uRam020c4e2c;
    iVar8 = iVar8 + 8;
  } while (iVar9 < 0x80);
  *(undefined4 *)
   (*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
   *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) = 0;
  uVar2 = func_020b47c0(uVar2);
  Gfx_ReadPalette((*(uint *)((uint)puRam020c4e28 & 0xfffffffc) >> ((uint)puRam020c4e28 & 3) * 8 |
                  *(uint *)((uint)puRam020c4e28 & 0xfffffffc) <<
                  ((uint)puRam020c4e28 & 3) * -8 + 0x20) + 4,uVar2);
  uVar2 = func_020b47c0(uRam020c4e30);
  Gfx_ReadCharGraphics
            ((*(uint *)((uint)puRam020c4e28 & 0xfffffffc) >> ((uint)puRam020c4e28 & 3) * 8 |
             *(uint *)((uint)puRam020c4e28 & 0xfffffffc) << ((uint)puRam020c4e28 & 3) * -8 + 0x20) +
             8,uVar2);
  local_40 = 0;
  uVar2 = func_020b47c0(uRam020c4e34);
  LoadCellBankFrom(&local_40,uVar2);
  puVar1 = puRam020c4e28;
  uVar3 = 0;
  do {
    uVar2 = CellBank_GetMetatileEntry(local_40,uVar3 & 0xffff);
    uVar4 = (uint)puVar1 & 3;
    uVar6 = *(uint *)((uint)puVar1 & 0xfffffffc);
    iVar8 = uVar3 * 4;
    uVar3 = uVar3 + 1;
    *(undefined4 *)((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) + iVar8 + 0xc) = uVar2;
  } while ((int)uVar3 < 3);
  uVar2 = GetLoadedFont_from_thumb(2);
  uVar3 = (*(uint *)((uint)puRam020c4e28 & 0xfffffffc) >> ((uint)puRam020c4e28 & 3) * 8 |
          *(uint *)((uint)puRam020c4e28 & 0xfffffffc) << ((uint)puRam020c4e28 & 3) * -8 + 0x20) + 8;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x14;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  iVar8 = -1;
  G2d_Sprite_CreateFromTiles(auStack_3c,uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20,0x20,4,4);
  local_1c = auStack_3c;
  uVar6 = *(uint *)(uRam020c4e38 & 0xfffffffc) >> (uRam020c4e38 & 3) * 8 |
          *(uint *)(uRam020c4e38 & 0xfffffffc) << (uRam020c4e38 & 3) * -8 + 0x20;
  local_14 = 1;
  local_10 = 0;
  uVar3 = uVar6 + 8 & 3;
  uVar4 = *(uint *)(uVar6 + 8 & 0xfffffffc);
  uVar3 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  local_18 = uVar2;
  if (uVar3 == 0) {
    iVar8 = GetBmgIndexFromCircuitIndex_from_thumb
                      (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                       *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20);
    local_14 = GetSomeInterCharacterWidth2();
  }
  else if (uVar3 == 4) {
    iVar8 = *(char *)(uVar6 + 0x54) + 0x55;
    local_14 = GetSomeInterCharacterWidth();
  }
  uVar2 = func_020b47cc(uRam020c4e3c);
  uVar2 = Bmg_GetRawStringPointer_from_thumb(uVar2,iVar8);
  G2d_Text_PrintString(&local_1c,0,9,0xe,uRam020c4e40,uVar2);
  uVar2 = func_020b47cc(uRam020c4e44);
  uVar2 = Bmg_GetRawStringPointer_from_thumb(uVar2,iVar8);
  G2d_Text_PrintString(&local_1c,0,8,0xe,uRam020c4e40,uVar2);
  uVar3 = (*(uint *)((uint)puRam020c4e28 & 0xfffffffc) >> ((uint)puRam020c4e28 & 3) * 8 |
          *(uint *)((uint)puRam020c4e28 & 0xfffffffc) << ((uint)puRam020c4e28 & 3) * -8 + 0x20) + 8;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  uVar3 = uVar4 + 0x14;
  uVar6 = uVar3 & 3;
  uVar5 = *(uint *)(uVar3 & 0xfffffffc);
  uVar4 = uVar4 + 0x10;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  Arm_FlushRange(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,
                 uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20);
  uVar3 = (*(uint *)((uint)puRam020c4e28 & 0xfffffffc) >> ((uint)puRam020c4e28 & 3) * 8 |
          *(uint *)((uint)puRam020c4e28 & 0xfffffffc) << ((uint)puRam020c4e28 & 3) * -8 + 0x20) + 4;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  uVar3 = uVar4 + 0xc;
  uVar6 = uVar3 & 3;
  uVar5 = *(uint *)(uVar3 & 0xfffffffc);
  uVar4 = uVar4 + 8;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  CopySomePaletteData(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,0,
                      uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20);
  uVar3 = (*(uint *)((uint)puRam020c4e28 & 0xfffffffc) >> ((uint)puRam020c4e28 & 3) * 8 |
          *(uint *)((uint)puRam020c4e28 & 0xfffffffc) << ((uint)puRam020c4e28 & 3) * -8 + 0x20) + 8;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  uVar3 = uVar4 + 0x14;
  uVar6 = uVar3 & 3;
  uVar5 = *(uint *)(uVar3 & 0xfffffffc);
  uVar4 = uVar4 + 0x10;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  CopyTileDataTop_0(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,0,
                    uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20);
  return;
}

