/* Decompiled C draft; module arm9; ROM address 02057260. No matching claim. */
#include "types.h"
#include "deps/02057260_ClearSaveDataGhosts_from_thumb.h"

void ClearSaveDataGhosts_from_thumb(void)

{
  Mem_CpuFill8((uint *)(uintptr_t)(*(undefined4 *)(*piRam02057288 + 0x14)),0,uRam0205728c);
  Mem_CpuFill8((uint *)(uintptr_t)(*(undefined4 *)(*piRam02057288 + 0x18)),0,uRam02057290);
  return;
}

