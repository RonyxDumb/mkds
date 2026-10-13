/* Decompiled C draft; module arm9; ROM address 0204236c. No matching claim. */
#include "types.h"
#include "deps/0204236c_InitializeAreaType3s_from_thumb.h"

void InitializeAreaType3s_from_thumb(void)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  
  GetActiveExecutionContext();
  uVar2 = ExecutionContext_GetHeapHandle();
  piVar6 = piRam020423f8;
  uVar5 = 0;
  uVar1 = 0;
  do {
    *(undefined4 *)(*piVar6 + uVar5 * 4 + 0xd8) = 0;
    uVar5 = uVar5 + 1 & 0xffff;
  } while (uVar5 < 8);
  if (*(short *)(*piVar6 + 0x78) != 0) {
    do {
      iVar3 = GetGlobalPENkmAREAByIndex_from_thumb(uVar1);
      if (*(char *)(iVar3 + 0x44) == '\x03') {
        iVar4 = *(short *)(iVar3 + 0x3c) * 4;
        piVar6 = (int *)(*piRam020423f8 + 0xd8 + iVar4);
        for (iVar4 = *(int *)(*piRam020423f8 + 0xd8 + iVar4); iVar4 != 0;
            iVar4 = *(int *)(iVar4 + 4)) {
          piVar6 = (int *)(iVar4 + 4);
        }
        iVar4 = Mem_AllocateHeap(uVar2,8);
        *piVar6 = iVar4;
        *(int *)*piVar6 = iVar3;
        *(undefined4 *)(*piVar6 + 4) = 0;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(ushort *)(*piRam020423f8 + 0x78));
  }
  return;
}

