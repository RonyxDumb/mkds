/* Decompiled C draft; module arm9; ROM address 0209be50. No matching claim. */
#include "types.h"
#include "deps/0209be50_StructMapObject_AddAnimationNsbca_from_thumb.h"

void StructMapObject_AddAnimationNsbca_from_thumb(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FormatFindMapObjFileBuffer_from_thumb(param_2);
  GetActiveExecutionContext();
  uVar2 = ExecutionContext_GetHeapHandle();
  uVar2 = Mem_AllocateHeap(uVar2,0x38);
  *(undefined4 *)(param_1 + 0x1c) = uVar2;
  SomeAnimationLoadWrapper_from_thumb
            (0,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x1c),
             *(undefined4 *)(param_1 + 0x18),uVar1);
  return;
}

