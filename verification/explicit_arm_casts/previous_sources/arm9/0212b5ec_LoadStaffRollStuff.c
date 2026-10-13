/* Decompiled C draft; module arm9; ROM address 0212b5ec. No matching claim. */
#include "types.h"
#include "deps/0212b5ec_LoadStaffRollStuff.h"

void LoadStaffRollStuff(undefined4 param_1)

{
  int iVar1;
  char cVar2;
  ushort uVar3;
  int *piVar4;
  uint *puVar5;
  ushort *puVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int local_14 [2];
  
  iVar7 = Mem_AllocateHeap(param_1,uRam0212b7bc);
  piVar4 = piRam0212b7c0;
  *piRam0212b7c0 = iVar7;
  *(undefined4 *)(iVar7 + 0x858) = param_1;
  *(undefined4 *)
   (*(uint *)((uint)piVar4 & 0xfffffffc) >> ((uint)piVar4 & 3) * 8 |
   *(uint *)((uint)piVar4 & 0xfffffffc) << ((uint)piVar4 & 3) * -8 + 0x20) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)piVar4 & 0xfffffffc) >> ((uint)piVar4 & 3) * 8 |
    *(uint *)((uint)piVar4 & 0xfffffffc) << ((uint)piVar4 & 3) * -8 + 0x20) + 4) = 0;
  uVar8 = Mem_AllocateHeap(param_1,0xa0);
  InitializeGlobalTEQ(uVar8,10);
  piVar4 = piRam0212b7c0;
  *(undefined4 *)
   ((*(uint *)((uint)piRam0212b7c0 & 0xfffffffc) >> ((uint)piRam0212b7c0 & 3) * 8 |
    *(uint *)((uint)piRam0212b7c0 & 0xfffffffc) << ((uint)piRam0212b7c0 & 3) * -8 + 0x20) + 8) = 0;
  uVar8 = uRam0212b7c4;
  *(undefined4 *)
   ((*(uint *)((uint)piVar4 & 0xfffffffc) >> ((uint)piVar4 & 3) * 8 |
    *(uint *)((uint)piVar4 & 0xfffffffc) << ((uint)piVar4 & 3) * -8 + 0x20) + 0x10) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)piVar4 & 0xfffffffc) >> ((uint)piVar4 & 3) * 8 |
    *(uint *)((uint)piVar4 & 0xfffffffc) << ((uint)piVar4 & 3) * -8 + 0x20) + 0x14) = 0xffffffff;
  *(undefined4 *)
   ((*(uint *)((uint)piVar4 & 0xfffffffc) >> ((uint)piVar4 & 3) * 8 |
    *(uint *)((uint)piVar4 & 0xfffffffc) << ((uint)piVar4 & 3) * -8 + 0x20) + 0xc) = uVar8;
  puVar5 = puRam0212b7c8;
  *(undefined1 *)
   ((*(uint *)((uint)piVar4 & 0xfffffffc) >> ((uint)piVar4 & 3) * 8 |
    *(uint *)((uint)piVar4 & 0xfffffffc) << ((uint)piVar4 & 3) * -8 + 0x20) + 0x1c) = 1;
  puVar6 = puRam0212b7cc;
  *(undefined1 *)
   ((*(uint *)((uint)piVar4 & 0xfffffffc) >> ((uint)piVar4 & 3) * 8 |
    *(uint *)((uint)piVar4 & 0xfffffffc) << ((uint)piVar4 & 3) * -8 + 0x20) + 0x850) = 1;
  *(undefined4 *)
   ((*(uint *)((uint)piVar4 & 0xfffffffc) >> ((uint)piVar4 & 3) * 8 |
    *(uint *)((uint)piVar4 & 0xfffffffc) << ((uint)piVar4 & 3) * -8 + 0x20) + 0x854) = 0x240;
  *puVar5 = (*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
            *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20) & 0xffffe0ff |
            0x100;
  *puVar6 = *puVar6 & 0xfffc | 1;
  *puVar6 = *puVar6 & 0x43 | 0x1000;
  uVar8 = GetVramBg0BaseOffset_Bottom();
  local_14[1] = 0;
  Mem_CpuFastMemorySet(0,uVar8,0x8000);
  iVar7 = 0;
  do {
    iVar9 = GetAnotherSubEngineBGOffset();
    uVar3 = (ushort)iVar7;
    iVar1 = iVar7 * 2;
    iVar7 = iVar7 + 1;
    *(ushort *)(iVar9 + iVar1) = uVar3 | 0xf000;
  } while (iVar7 < 0x400);
  uVar8 = find_buf_fn_from_thumb(uRam0212b7d0);
  Gfx_ReadPalette(local_14,uVar8);
  uVar11 = local_14[0] + 0xcU & 3;
  uVar10 = *(uint *)(local_14[0] + 0xcU & 0xfffffffc);
  AllocateReserveTEQSub
            (0x1f,0x1e0,(uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20) + 0x1e0,0x20);
  uVar11 = *(uint *)((uint)piRam0212b7c0 & 0xfffffffc) >> ((uint)piRam0212b7c0 & 3) * 8 |
           *(uint *)((uint)piRam0212b7c0 & 0xfffffffc) << ((uint)piRam0212b7c0 & 3) * -8 + 0x20;
  G2d_Sprite_CreateFromTiles(uVar11 + 0x20,uVar11 + 0x50,0x20,2,4);
  cVar2 = *(char *)((*(uint *)((uint)piRam0212b7c0 & 0xfffffffc) >> ((uint)piRam0212b7c0 & 3) * 8 |
                    *(uint *)((uint)piRam0212b7c0 & 0xfffffffc) <<
                    ((uint)piRam0212b7c0 & 3) * -8 + 0x20) + 0x1c);
  uVar8 = GetLoadedFont_from_thumb(2);
  piVar4 = piRam0212b7c0;
  uVar11 = *(uint *)((uint)piRam0212b7c0 & 0xfffffffc) >> ((uint)piRam0212b7c0 & 3) * 8 |
           *(uint *)((uint)piRam0212b7c0 & 0xfffffffc) << ((uint)piRam0212b7c0 & 3) * -8 + 0x20;
  *(uint *)(uVar11 + 0x40) = uVar11 + 0x20;
  *(undefined4 *)(uVar11 + 0x44) = uVar8;
  *(int *)(uVar11 + 0x48) = (int)cVar2;
  *(undefined4 *)(uVar11 + 0x4c) = 0;
  uVar11 = (uint)piVar4 & 3;
  uVar10 = *(uint *)((uint)piVar4 & 0xfffffffc);
  Mem_CpuFill8((uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20) + 0x50,0,0x800);
  uVar8 = find_buf_fn_from_thumb(uRam0212b7d4);
  uVar8 = Bmg_GetRawStringPointer_from_thumb(uVar8,0);
  *(undefined4 *)
   ((*(uint *)((uint)piRam0212b7c0 & 0xfffffffc) >> ((uint)piRam0212b7c0 & 3) * 8 |
    *(uint *)((uint)piRam0212b7c0 & 0xfffffffc) << ((uint)piRam0212b7c0 & 3) * -8 + 0x20) + 0x18) =
       uVar8;
  return;
}

