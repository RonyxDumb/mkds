/* Decompiled C draft; module arm9; ROM address 020d9c54. No matching claim. */
#include "types.h"
#include "deps/020d9c54_func_020d9c54.h"

void func_020d9c54(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  GetActiveExecutionContext();
  uVar2 = ExecutionContext_GetHeapHandle();
  iVar3 = Mem_AllocateHeap(uVar2,uRam020d9cc0);
  *piRam020d9cc4 = iVar3;
  func_020d9cf4(uRam020d9cdc,uRam020d9ce0,uRam020d9ce4,uRam020d9ce8,uRam020d9cc8,uRam020d9ccc,
                uRam020d9cd0,uRam020d9cd4,uRam020d9cd8,uRam020d9cd8,1,5,10,10,1);
  uVar2 = FormatFindMapObjFileBuffer_from_thumb(uRam020d9cec);
  *(undefined4 *)(*piRam020d9cc4 + 0x60) = uVar2;
  uVar2 = FormatFindMapObjFileBuffer_from_thumb(uRam020d9cf0);
  piVar1 = piRam020d9cc4;
  *(undefined4 *)(*piRam020d9cc4 + 100) = uVar2;
  func_020d4980(*piVar1);
  return;
}

