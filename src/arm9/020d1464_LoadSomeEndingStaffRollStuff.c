/* Decompiled C draft; module arm9; ROM address 020d1464. No matching claim. */
#include "types.h"
#include "deps/020d1464_LoadSomeEndingStaffRollStuff.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void LoadSomeEndingStaffRollStuff(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 local_8 [2];
  
  GetActiveExecutionContext();
  uVar3 = ExecutionContext_GetHeapHandle();
  uVar3 = Mem_AllocateHeap(uVar3,uRam020d1584);
  puVar2 = puRam020d1588;
  iVar9 = 0;
  iVar8 = 0;
  *puRam020d1588 = uVar3;
  do {
    iVar9 = iVar9 + 1;
    iVar7 = (*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
            *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x10;
    uVar4 = iVar7 + iVar8;
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(uint *)(iVar7 + iVar8) =
         (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0xfffff3ff | 0xc00;
    uVar3 = uRam020d158c;
    iVar8 = iVar8 + 8;
  } while (iVar9 < 0x80);
  *(undefined4 *)
   (*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
   *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) = 0;
  uVar3 = func_020b47c0(uVar3);
  Gfx_ReadPalette((int *)(uintptr_t)((*(uint *)((uint)puRam020d1588 & 0xfffffffc) >> ((uint)puRam020d1588 & 3) * 8 |
                  *(uint *)((uint)puRam020d1588 & 0xfffffffc) <<
                  ((uint)puRam020d1588 & 3) * -8 + 0x20) + 4),uVar3);
  uVar3 = func_020b47c0(uRam020d1590);
  Gfx_ReadCharGraphics
            ((int *)(uintptr_t)((*(uint *)((uint)puRam020d1588 & 0xfffffffc) >> ((uint)puRam020d1588 & 3) * 8 |
             *(uint *)((uint)puRam020d1588 & 0xfffffffc) << ((uint)puRam020d1588 & 3) * -8 + 0x20) +
             8),uVar3);
  local_8[0] = 0;
  uVar3 = func_020b47c0(uRam020d1594);
  LoadCellBankFrom(local_8,uVar3);
  uVar3 = CellBank_GetMetatileEntry((ushort *)(uintptr_t)(local_8[0]),0);
  puVar2 = puRam020d1588;
  *(undefined4 *)
   ((*(uint *)((uint)puRam020d1588 & 0xfffffffc) >> ((uint)puRam020d1588 & 3) * 8 |
    *(uint *)((uint)puRam020d1588 & 0xfffffffc) << ((uint)puRam020d1588 & 3) * -8 + 0x20) + 0xc) =
       uVar3;
  uVar4 = (uint)puVar2 & 3;
  uVar5 = *(uint *)((uint)puVar2 & 0xfffffffc);
  uVar4 = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + 4;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar4 = uVar5 + 0xc;
  uVar1 = uVar4 & 3;
  uVar6 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = uVar5 + 8;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  CopySomePaletteData(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20,0,
                      uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
  uVar4 = (*(uint *)((uint)puRam020d1588 & 0xfffffffc) >> ((uint)puRam020d1588 & 3) * 8 |
          *(uint *)((uint)puRam020d1588 & 0xfffffffc) << ((uint)puRam020d1588 & 3) * -8 + 0x20) + 8;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar4 = uVar5 + 0x14;
  uVar1 = uVar4 & 3;
  uVar6 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = uVar5 + 0x10;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  CopyTileDataTop_0(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20,0,
                    uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
  _DAT_04000000 = _DAT_04000000 & uRam020d1598 | 0x10;
  return;
}

