/* Decompiled C draft; module arm9; ROM address 020365ac. No matching claim. */
#include "types.h"
#include "deps/020365ac_GetGlobalHeapHandle.h"

uint GetGlobalHeapHandle(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = iRam020365b8 + 0xcU & 3;
  uVar2 = *(uint *)(iRam020365b8 + 0xcU & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

