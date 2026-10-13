/* Decompiled C draft; module arm9; ROM address 02047728. No matching claim. */
#include "types.h"
#include "deps/02047728_Dispose_KM2_KSB_Mount_CRS_from_thumb.h"

void Dispose_KM2_KSB_Mount_CRS_from_thumb(void)

{
  int iVar1;
  
  Arc_DisposeArchive_from_thumb(7);
  Arc_DisposeArchive_from_thumb(8);
  SetActiveExecutionContextHeapGroupId_from_thumb(0);
  iVar1 = GetCurrentSceneId();
  if (iVar1 == 2) {
    Arc_MountArchive_from_thumb(3,2);
  }
  SetActiveExecutionContextHeapGroupId_from_thumb(9);
  return;
}

