/* Decompiled C draft; module arm9; ROM address 02029a70. No matching claim. */
#include "types.h"
#include "deps/02029a70_InitializeGlobalCA_from_thumb.h"

void InitializeGlobalCA_from_thumb(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = Mem_AllocateHeap(param_1,uRam02029a88);
  *puRam02029a8c = uVar1;
  DoInitializeGlobalCA_from_thumb();
  return;
}

