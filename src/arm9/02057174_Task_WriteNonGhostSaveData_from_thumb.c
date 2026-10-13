/* Decompiled C draft; module arm9; ROM address 02057174. No matching claim. */
#include "types.h"
#include "deps/02057174_Task_WriteNonGhostSaveData_from_thumb.h"

void Task_WriteNonGhostSaveData_from_thumb(void)

{
  WriteSaveDataSection_Emblem_from_thumb(*(undefined4 *)(*piRam02057214 + 4));
  if (*(int *)(*piRam02057218 + 0xc) != 0) {
    func_02145d38();
  }
  WriteSaveDataSection_GrandPrix_from_thumb(*(undefined4 *)(*piRam02057214 + 8));
  if (*(int *)(*piRam02057218 + 0xc) != 0) {
    func_02145d38();
  }
  WriteSaveDataSection_TimeTrials_from_thumb(*(undefined4 *)(*piRam02057214 + 0xc));
  if (*(int *)(*piRam02057218 + 0xc) != 0) {
    func_02145d38();
  }
  WriteSaveDataSection_MissionRun_from_thumb(*(undefined4 *)(*piRam02057214 + 0x10));
  if (*(int *)(*piRam02057218 + 0xc) != 0) {
    func_02145d38();
  }
  WriteSaveDataSection_FriendList_from_thumb(*(undefined4 *)(*piRam02057214 + 0x20));
  if (*(int *)(*piRam02057218 + 0xc) != 0) {
    func_02145d38();
  }
  WriteSaveDataSection_Header_from_thumb(*(undefined4 *)*piRam02057214);
  if (*(int *)(*piRam02057218 + 0xc) != 0) {
    func_02145d38();
  }
  ResetSaveDataHolderTaskPendingFlag_from_thumb();
  return;
}

