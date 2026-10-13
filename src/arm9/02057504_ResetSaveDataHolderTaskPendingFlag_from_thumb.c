/* Decompiled C draft; module arm9; ROM address 02057504. No matching claim. */
#include "types.h"
#include "deps/02057504_ResetSaveDataHolderTaskPendingFlag_from_thumb.h"

void ResetSaveDataHolderTaskPendingFlag_from_thumb(void)

{
  *(undefined1 *)(*piRam02057510 + 0x28) = 0;
  return;
}

