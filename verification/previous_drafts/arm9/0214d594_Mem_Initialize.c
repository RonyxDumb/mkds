/* Decompiled C draft; module arm9; ROM address 0214d594. No matching claim. */
#include "types.h"
#include "deps/0214d594_Mem_Initialize.h"

void Mem_Initialize(void)

{
  Mem_SetWramcnt(3);
  Mem_DmaStop(0);
  return;
}

