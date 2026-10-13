/* Decompiled C draft; module arm9; ROM address 020364e0. No matching claim. */
#include "types.h"
#include "deps/020364e0_ExecutionContext_GetHeapHandle.h"

uint ExecutionContext_GetHeapHandle(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0xcU & 3;
  uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

