/* Decompiled C draft; module arm9; ROM address 020df758. No matching claim. */
#include "types.h"
#include "deps/020df758_LoadBubbleEffectModel.h"

void LoadBubbleEffectModel(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FormatFindMapObjFileBuffer_from_thumb(uRam020df7bc);
  func_020ea588(puRam020df7c0,uVar1,0);
  Model_SetPolygonIdLightFlagsEmi(*puRam020df7c0,0x3f,2,uRam020df7c4);
  GetActiveExecutionContext();
  uVar2 = ExecutionContext_GetHeapHandle();
  uVar2 = Mem_AllocateHeap(uVar2,0x38);
  *puRam020df7c8 = uVar2;
  uVar2 = FormatFindMapObjFileBuffer_from_thumb(uRam020df7cc);
  SomeAnimationLoadWrapper_from_thumb(1,*puRam020df7c0,*puRam020df7c8,uVar1,uVar2);
  Animation_SetLoop((undefined2 *)(uintptr_t)(*puRam020df7c8),0,1);
  return;
}

