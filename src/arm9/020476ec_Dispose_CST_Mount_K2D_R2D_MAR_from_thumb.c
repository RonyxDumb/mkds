/* Decompiled C draft; module arm9; ROM address 020476ec. No matching claim. */
#include "types.h"
#include "deps/020476ec_Dispose_CST_Mount_K2D_R2D_MAR_from_thumb.h"

void Dispose_CST_Mount_K2D_R2D_MAR_from_thumb(void)

{
  int iVar1;
  
  Arc_DisposeArchive_from_thumb(0xd);
  SetActiveExecutionContextHeapGroupId_from_thumb(0);
  iVar1 = GetCurrentSceneId();
  if (iVar1 == 2) {
    Arc_MountArchive_from_thumb(5,2);
    Arc_MountArchive_from_thumb(0xb,2);
    Arc_MountArchive_from_thumb(0,2);
  }
  SetActiveExecutionContextHeapGroupId_from_thumb(9);
  return;
}

