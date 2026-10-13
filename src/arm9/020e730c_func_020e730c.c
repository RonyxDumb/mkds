/* Decompiled C draft; module arm9; ROM address 020e730c. No matching claim. */
#include "types.h"
#include "deps/020e730c_func_020e730c.h"

void func_020e730c(void)

{
  ushort uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  uVar1 = *(ushort *)(*piRam020e737c + 4);
  GetActiveExecutionContext();
  uVar3 = ExecutionContext_GetHeapHandle();
  iVar4 = Mem_AllocateHeap(uVar3,(uint)uVar1 << 2);
  *piRam020e7380 = iVar4;
  GetActiveExecutionContext();
  uVar3 = ExecutionContext_GetHeapHandle();
  iVar4 = Mem_AllocateHeap(uVar3,(uint)uVar1 << 1);
  *piRam020e7384 = iVar4;
  piVar2 = piRam020e737c;
  iVar4 = 0;
  piVar5 = (int *)*piRam020e737c;
  if ((short)piVar5[1] != 0) {
    iVar7 = 0;
    do {
      iVar6 = *(int *)(*piVar5 + iVar7);
      uVar1 = *(ushort *)(iVar6 + 0xa0);
      *(int *)(*piRam020e7380 + (uint)uVar1 * 4) = iVar6 + 4;
      *(undefined2 *)(*piRam020e7384 + (uint)uVar1 * 2) = *(undefined2 *)(iVar6 + 0xa2);
      iVar7 = iVar7 + 4;
      iVar4 = iVar4 + 1;
      piVar5 = (int *)*piVar2;
    } while (iVar4 < (int)(uint)*(ushort *)(piVar5 + 1));
  }
  return;
}

