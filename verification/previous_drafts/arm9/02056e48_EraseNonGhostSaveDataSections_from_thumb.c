/* Decompiled C draft; module arm9; ROM address 02056e48. No matching claim. */
#include "types.h"
#include "deps/02056e48_EraseNonGhostSaveDataSections_from_thumb.h"

void EraseNonGhostSaveDataSections_from_thumb(void)

{
  EnableMKDSSVSomeFlag_from_thumb();
  WorkerInsertTask(uRam02056e68);
  *(undefined4 *)(*piRam02056e6c + 0xf8) = 1;
  return;
}

