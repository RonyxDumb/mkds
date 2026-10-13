/* Decompiled C draft; module arm9; ROM address 0204274c. No matching claim. */
#include "types.h"
#include "deps/0204274c_InitializePECannonTable_from_thumb.h"

void InitializePECannonTable_from_thumb(void)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = (uint)*(ushort *)(*piRam020427a8 + 0x38);
  if (uVar4 != 0) {
    GetActiveExecutionContext();
    uVar2 = ExecutionContext_GetHeapHandle();
    uVar2 = Mem_AllocateHeap(uVar2,uVar4 << 1);
    piVar1 = piRam020427a8;
    *(undefined4 *)(*piRam020427a8 + 0xfc) = uVar2;
    uVar3 = 0;
    if (uVar4 != 0) {
      do {
        *(short *)(*(int *)(*piVar1 + 0xfc) +
                  (uint)*(ushort *)(*(int *)(*piVar1 + 0x34) + uVar3 * 0x1c + 0x1a) * 2) =
             (short)uVar3;
        uVar3 = uVar3 + 1 & 0xffff;
      } while (uVar3 < uVar4);
    }
    return;
  }
  *(undefined4 *)(*piRam020427a8 + 0xfc) = 0;
  return;
}

