/* Decompiled C draft; module arm9; ROM address 0205d0bc. No matching claim. */
#include "types.h"
#include "deps/0205d0bc_InitializeGlobalRE.h"

undefined4 InitializeGlobalRE(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = Mem_AllocateHeap(param_1,10);
  *puRam0205d0e4 = uVar1;
  return 10;
}

