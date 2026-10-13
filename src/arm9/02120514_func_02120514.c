/* Decompiled C draft; module arm9; ROM address 02120514. No matching claim. */
#include "types.h"
#include "deps/02120514_func_02120514.h"

void func_02120514(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(int *)*piRam02120554 != 0) {
    Mem_Exp_Finalize();
    GetActiveExecutionContext();
    uVar2 = ExecutionContext_GetHeapHandle();
    Mem_FreeHeap(uVar2,*(undefined4 *)(*piRam02120554 + 4));
  }
  piVar1 = piRam02120554;
  *(undefined4 *)(*piRam02120554 + iRam02120558) = 0;
  iVar3 = *piVar1;
  *(undefined2 *)(iVar3 + 0x18) = 0;
  *(undefined2 *)(iVar3 + 0x1a) = 1;
  return;
}

