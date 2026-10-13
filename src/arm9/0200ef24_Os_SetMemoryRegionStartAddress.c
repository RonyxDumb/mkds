/* Decompiled C draft; module arm9; ROM address 0200ef24. No matching claim. */
#include "types.h"
#include "deps/0200ef24_Os_SetMemoryRegionStartAddress.h"

void Os_SetMemoryRegionStartAddress(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 * 4 + 0x27ffda0) = param_2;
  return;
}

