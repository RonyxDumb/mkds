/* Decompiled C draft; module arm9; ROM address 020ed490. No matching claim. */
#include "types.h"
#include "deps/020ed490_func_020ed490.h"

undefined4 func_020ed490(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  uVar1 = Mem_AllocateHeap(uVar1,0x6c);
  uVar2 = FindItemFileBuffer_from_thumb(param_1);
  Model_CreateFromNsbmd(uVar1,uVar2);
  Model_SetPolygonIdLightFlagsEmi(uVar1,4,2,uRam020ed4cc);
  return uVar1;
}

