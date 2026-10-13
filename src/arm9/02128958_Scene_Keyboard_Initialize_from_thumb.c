/* Decompiled C draft; module arm9; ROM address 02128958. No matching claim. */
#include "types.h"
#include "deps/02128958_Scene_Keyboard_Initialize_from_thumb.h"

void Scene_Keyboard_Initialize_from_thumb(short *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  uVar2 = Mem_AllocateHeap(uVar1,uRam02128984);
  *puRam02128988 = uVar2;
  InitializeKeyboardContext_from_thumb(uVar1,(int)*param_1);
  return;
}

