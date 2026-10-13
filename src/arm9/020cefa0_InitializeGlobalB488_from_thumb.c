/* Decompiled C draft; module arm9; ROM address 020cefa0. No matching claim. */
#include "types.h"
#include "deps/020cefa0_InitializeGlobalB488_from_thumb.h"

void InitializeGlobalB488_from_thumb(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = Mem_AllocateHeap(param_1,uRam020cefb8);
  *puRam020cefbc = uVar1;
  CreateGlobalB488_from_thumb();
  return;
}

