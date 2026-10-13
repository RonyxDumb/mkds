/* Decompiled C draft; module arm9; ROM address 02056e70. No matching claim. */
#include "types.h"
#include "deps/02056e70_task_fn_ptr_from_thumb.h"

void task_fn_ptr_from_thumb(void)

{
  if ((*(ushort *)(*piRam02056f8c + 0x2a) & 2) != 0) {
    ClearSaveDataSection_Emblem_from_thumb();
    WriteSaveDataSection_Emblem_from_thumb(*(undefined4 *)(*piRam02056f8c + 4));
    if (*(int *)(*piRam02056f90 + 0xc) != 0) {
      func_02145d38();
    }
  }
  if ((*(ushort *)(*piRam02056f8c + 0x2a) & 4) != 0) {
    ClearSaveDataSection_GrandPrix_from_thumb();
    WriteSaveDataSection_GrandPrix_from_thumb(*(undefined4 *)(*piRam02056f8c + 8));
    if (*(int *)(*piRam02056f90 + 0xc) != 0) {
      func_02145d38();
    }
  }
  if ((*(ushort *)(*piRam02056f8c + 0x2a) & 8) != 0) {
    ClearSaveDataSection_TimeTrials_from_thumb();
    WriteSaveDataSection_TimeTrials_from_thumb(*(undefined4 *)(*piRam02056f8c + 0xc));
    if (*(int *)(*piRam02056f90 + 0xc) != 0) {
      func_02145d38();
    }
  }
  if ((*(ushort *)(*piRam02056f8c + 0x2a) & 0x10) != 0) {
    ClearSaveDataSection_MissionRun_from_thumb();
    WriteSaveDataSection_MissionRun_from_thumb(*(undefined4 *)(*piRam02056f8c + 0x10));
    if (*(int *)(*piRam02056f90 + 0xc) != 0) {
      func_02145d38();
    }
  }
  if ((*(ushort *)(*piRam02056f8c + 0x2a) & 0x20) != 0) {
    ClearSaveDataSection_FriendList_from_thumb();
    WriteSaveDataSection_FriendList_from_thumb(*(undefined4 *)(*piRam02056f8c + 0x20));
    if (*(int *)(*piRam02056f90 + 0xc) != 0) {
      func_02145d38();
    }
  }
  if ((*(ushort *)(*piRam02056f8c + 0x2a) & 1) != 0) {
    ClearSaveDataSection_Header_from_thumb(*psRam02056f94 == 2);
    WriteSaveDataSection_Header_from_thumb(*(undefined4 *)*piRam02056f8c);
    if (*(int *)(*piRam02056f90 + 0xc) != 0) {
      func_02145d38();
    }
  }
  *(undefined2 *)(*piRam02056f8c + 0x2a) = 0;
  ResetSaveDataHolderTaskPendingFlag_from_thumb();
  return;
}

