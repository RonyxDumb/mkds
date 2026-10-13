/* Decompiled C draft; module arm9; ROM address 020ea514. No matching claim. */
#include "types.h"
#include "deps/020ea514_SomeAnimationLoadWrapper_from_thumb.h"

void SomeAnimationLoadWrapper_from_thumb
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  undefined4 uVar1;
  
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  Animation_CreateFrom(param_1,param_3,param_2,1,uVar1,param_4);
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  Animation_RegisterAll(param_3,param_5,uVar1);
  Animation_SetAt(param_3,0);
  return;
}

