/* Decompiled C draft; module arm9; ROM address 0205dc54. No matching claim. */
#include "types.h"
#include "deps/0205dc54_InitializeGlobalLU.h"

void InitializeGlobalLU(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = Mem_AllocateHeap(param_1,0x168);
  *puRam0205dc78 = uVar1;
  return;
}

