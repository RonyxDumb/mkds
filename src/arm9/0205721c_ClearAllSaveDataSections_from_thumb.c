/* Decompiled C draft; module arm9; ROM address 0205721c. No matching claim. */
#include "types.h"
#include "deps/0205721c_ClearAllSaveDataSections_from_thumb.h"

void ClearAllSaveDataSections_from_thumb(undefined4 param_1)

{
  ClearSaveDataSection_Emblem_from_thumb();
  ClearSaveDataSection_GrandPrix_from_thumb();
  ClearSaveDataSection_TimeTrials_from_thumb();
  ClearSaveDataSection_MissionRun_from_thumb();
  ClearSaveDataGhosts_from_thumb();
  ClearSaveDataSection_FriendList_from_thumb();
  ClearSaveDataSection_Header_from_thumb(param_1);
  return;
}

