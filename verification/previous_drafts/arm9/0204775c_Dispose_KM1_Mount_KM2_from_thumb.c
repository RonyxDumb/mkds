/* Decompiled C draft; module arm9; ROM address 0204775c. No matching claim. */
#include "types.h"
#include "deps/0204775c_Dispose_KM1_Mount_KM2_from_thumb.h"

void Dispose_KM1_Mount_KM2_from_thumb(void)

{
  Arc_DisposeArchive_from_thumb(6);
  SetActiveExecutionContextHeapGroupId_from_thumb(0);
  Arc_MountArchive_from_thumb(7,2);
  SetActiveExecutionContextHeapGroupId_from_thumb(9);
  return;
}

