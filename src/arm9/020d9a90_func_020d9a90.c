/* Decompiled C draft; module arm9; ROM address 020d9a90. No matching claim. */
#include "types.h"
#include "deps/020d9a90_func_020d9a90.h"

void func_020d9a90(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  GetActiveExecutionContext();
  uVar2 = ExecutionContext_GetHeapHandle();
  iVar3 = Mem_AllocateHeap(uVar2,uRam020d9afc);
  *piRam020d9b00 = iVar3;
  func_020d9cf4(0,0,uRam020d9b14,uRam020d9b18,uRam020d9b04,uRam020d9b08,uRam020d9b0c,uRam020d9b10,
                0x78,0x1e,1,10,0x17,0x10,0);
  *(undefined4 *)(*piRam020d9b00 + 0x60) = 0;
  uVar2 = FormatFindMapObjFileBuffer_from_thumb(uRam020d9b1c);
  piVar1 = piRam020d9b00;
  *(undefined4 *)(*piRam020d9b00 + 100) = uVar2;
  func_020d4980(*piVar1);
  return;
}

