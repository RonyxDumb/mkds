/* Decompiled C draft; module arm9; ROM address 02057130. No matching claim. */
#include "types.h"
#include "deps/02057130_OverwriteEmptySaveData_from_thumb.h"

void OverwriteEmptySaveData_from_thumb(void)

{
  ClearAllSaveDataSections_from_thumb(*psRam02057168 == 2);
  if (*psRam02057168 != 2) {
    EnableMKDSSVSomeFlag_from_thumb();
    WorkerInsertTask(uRam0205716c);
    *(undefined4 *)(*piRam02057170 + 0xf8) = 1;
  }
  return;
}

