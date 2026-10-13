/* Decompiled C draft; module arm9; ROM address 020d7df8. No matching claim. */
#include "types.h"
#include "deps/020d7df8_func_020d7df8.h"

void func_020d7df8(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = (uint)*(ushort *)(*piRam020d7e3c + 0xc);
  if (uVar5 != 0) {
    GetActiveExecutionContext();
    uVar2 = ExecutionContext_GetHeapHandle();
    iVar3 = Mem_AllocateHeap(uVar2,uVar5 * 0xc);
    *piRam020d7e40 = iVar3;
  }
  piVar1 = piRam020d7e40;
  iVar3 = 0;
  if (uVar5 != 0) {
    iVar4 = 0;
    do {
      *(undefined4 *)(*piVar1 + iVar4) = 0;
      iVar4 = iVar4 + 0xc;
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)uVar5);
  }
  return;
}

