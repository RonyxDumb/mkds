/* Decompiled C draft; module arm9; ROM address 021205ac. No matching claim. */
#include "types.h"
#include "deps/021205ac_InitializeGlobalB_from_thumb.h"

void InitializeGlobalB_from_thumb(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = Mem_AllocateHeapAligned(param_1,uRam021205dc,0x20);
  *piRam021205e0 = iVar1;
  StateDualHandler_Create((undefined4 *)(uintptr_t)(iVar1 + 8),uRam021205e4,8,0);
  iVar1 = *piRam021205e0;
  *(undefined2 *)(iVar1 + 0x18) = 0;
  *(undefined2 *)(iVar1 + 0x1a) = 1;
  return;
}

