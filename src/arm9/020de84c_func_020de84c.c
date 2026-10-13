/* Decompiled C draft; module arm9; ROM address 020de84c. No matching claim. */
#include "types.h"
#include "deps/020de84c_func_020de84c.h"

void func_020de84c(void)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined8 uVar11;
  
  uVar3 = FormatFindMapObjFileBuffer_0_from_thumb(uRam020de9b4);
  BillboardModel_AllocateFromNsbmdNsbtp_from_thumb(piRam020de9b8,uVar3,0,0);
  uVar3 = FormatFindMapObjFileBuffer_0_from_thumb(uRam020de9bc);
  BillboardModel_AllocateFromNsbmdNsbtp_from_thumb(piRam020de9c0,uVar3,0,0);
  BillboardModel_SomeFn(*piRam020de9b8);
  BillboardModel_SomeFn(*piRam020de9c0);
  uVar4 = uRam020de9c4;
  iVar7 = *piRam020de9b8;
  *(uint *)(iVar7 + 0x10) = *(uint *)(iVar7 + 0x10) & uRam020de9c4;
  uVar1 = uRam020de9c8;
  *(uint *)(iVar7 + 0x10) = *(uint *)(iVar7 + 0x10) | uRam020de9c8;
  iVar7 = *piRam020de9c0;
  *(uint *)(iVar7 + 0x10) = *(uint *)(iVar7 + 0x10) & uVar4;
  *(uint *)(iVar7 + 0x10) = *(uint *)(iVar7 + 0x10) | uVar1;
  GetActiveExecutionContext();
  uVar3 = ExecutionContext_GetHeapHandle();
  iVar7 = Mem_AllocateHeap(uVar3,uRam020de9cc);
  *piRam020de9d0 = iVar7;
  iVar10 = 0;
  iVar7 = 0;
  do {
    uVar4 = MaybeBoundsCheck(iVar10 << 0x10,iRam020de9d4);
    iVar5 = (int)(uVar4 & 0xffff) >> 4;
    iVar9 = (int)*(short *)(iRam020de9d8 + (iVar5 * 2 + 1) * 2);
    iVar8 = (int)*(short *)(iRam020de9d8 + iVar5 * 4);
    *(int *)(*piRam020de9d0 + iVar7) = iVar9;
    *(int *)(*piRam020de9d0 + iVar7 + 4) = iVar8;
    iVar5 = iVar9 >> 0x1f;
    uVar11 = Multiply64(iVar9,iVar5,iVar9,iVar5);
    *(uint *)(*piRam020de9d0 + iVar7 + 8) =
         (uint)uVar11 >> 0xc | (int)((ulonglong)uVar11 >> 0x20) << 0x14;
    iVar6 = iVar8 >> 0x1f;
    uVar11 = Multiply64(iVar8,iVar6,iVar8,iVar6);
    *(uint *)(*piRam020de9d0 + iVar7 + 0xc) =
         (uint)uVar11 >> 0xc | (int)((ulonglong)uVar11 >> 0x20) << 0x14;
    uVar11 = Multiply64(iVar9,iVar5,iVar8,iVar6);
    *(uint *)(*piRam020de9d0 + iVar7 + 0x10) =
         (uint)uVar11 >> 0xc | (int)((ulonglong)uVar11 >> 0x20) << 0x14;
    iVar7 = iVar7 + 0x14;
    iVar10 = iVar10 + 1;
  } while (iVar10 < iRam020de9d4);
  GetActiveExecutionContext();
  uVar3 = ExecutionContext_GetHeapHandle();
  iVar7 = Mem_AllocateHeap(uVar3,uRam020de9dc);
  piVar2 = piRam020de9e0;
  *piRam020de9e0 = iVar7;
  iVar7 = iRam020de9d8;
  iVar5 = 0;
  iVar10 = 0;
  do {
    uVar4 = MaybeBoundsCheck(iVar5 << 0x10,0x82);
    iVar6 = (int)(uVar4 & 0xffff) >> 4;
    *(int *)(*piVar2 + iVar10) = (int)*(short *)(iVar7 + (iVar6 * 2 + 1) * 2);
    *(int *)(*piVar2 + iVar10 + 4) = (int)*(short *)(iVar7 + iVar6 * 4);
    uVar4 = uRam020de9e8;
    iVar10 = iVar10 + 8;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x82);
  if (*(int *)*puRam020de9e4 == 0x1d) {
    *(uint *)(*piRam020de9b8 + 0x14) = *(uint *)(*piRam020de9b8 + 0x14) & uRam020de9e8;
    *(uint *)(*piRam020de9c0 + 0x14) = *(uint *)(*piRam020de9c0 + 0x14) & uVar4;
  }
  return;
}

