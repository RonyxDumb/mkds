/* Decompiled C draft; module arm9; ROM address 020d58c0. No matching claim. */
#include "types.h"
#include "deps/020d58c0_AllocateSomePointers.h"

void AllocateSomePointers(void)

{
  int iVar1;
  uint uVar2;
  undefined2 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  
  GetActiveExecutionContext();
  uVar6 = ExecutionContext_GetHeapHandle();
  puVar3 = puRam020d59d8;
  *puRam020d59d4 = 0;
  *puVar3 = 0;
  uVar7 = Mem_AllocateHeap(uVar6,0x400);
  *puRam020d59dc = uVar7;
  uVar7 = Mem_AllocateHeap(uVar6,0x400);
  *puRam020d59e0 = uVar7;
  uVar7 = Mem_AllocateHeap(uVar6,0x1c00);
  *puRam020d59e4 = uVar7;
  uVar7 = Mem_AllocateHeap(uVar6,0x200);
  *puRam020d59e8 = uVar7;
  uVar7 = Mem_AllocateHeap(uVar6,0x100);
  *puRam020d59ec = uVar7;
  uVar7 = Mem_AllocateHeap(uVar6,0x100);
  *puRam020d59f0 = uVar7;
  uVar6 = Mem_AllocateHeap(uVar6,0x200);
  *puRam020d59f4 = uVar6;
  puVar5 = puRam020d59e8;
  iVar8 = 0;
  do {
    iVar10 = (iVar8 + 1) * 0x10000;
    iVar1 = iVar10 >> 0x10;
    uVar2 = (uint)puVar5 & 3;
    uVar9 = *(uint *)((uint)puVar5 & 0xfffffffc);
    *(short *)((uVar9 >> uVar2 * 8 | uVar9 << uVar2 * -8 + 0x20) + iVar8 * 2) =
         (short)((uint)iVar10 >> 0x10);
    puVar4 = puRam020d59e4;
    iVar8 = iVar1;
  } while (iVar1 < 0x100);
  iVar8 = 0;
  iVar10 = 0;
  do {
    uVar2 = (uint)puVar4 & 3;
    uVar9 = *(uint *)((uint)puVar4 & 0xfffffffc);
    iVar8 = (iVar8 + 1) * 0x10000 >> 0x10;
    *(undefined4 *)((uVar9 >> uVar2 * 8 | uVar9 << uVar2 * -8 + 0x20) + iVar10 + 0xc) = 0;
    iVar10 = iVar10 + 0x1c;
  } while (iVar8 < 0x100);
  return;
}

