/* Decompiled C draft; module arm9; ROM address 0200ef38. No matching claim. */
#include "types.h"
#include "deps/0200ef38_Os_SetMemoryRegionEndAddress.h"

void Os_SetMemoryRegionEndAddress(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 * 4 + 0x27ffdc4) = param_2;
  return;
}

