/* Decompiled C draft; module arm9; ROM address 0209bde8. No matching claim. */
#include "types.h"
#include "deps/0209bde8_StructMapObject_AddAnimationNsbtp_from_thumb.h"

void StructMapObject_AddAnimationNsbtp_from_thumb(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FormatFindMapObjFileBuffer_from_thumb(param_2);
  GetActiveExecutionContext();
  uVar2 = ExecutionContext_GetHeapHandle();
  uVar2 = Mem_AllocateHeap(uVar2,0x38);
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  SomeAnimationLoadWrapper_from_thumb
            (2,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x20),
             *(undefined4 *)(param_1 + 0x18),uVar1);
  return;
}

