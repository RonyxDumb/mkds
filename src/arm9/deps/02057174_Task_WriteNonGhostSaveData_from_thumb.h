#pragma once
/* Function-specific inferred declarations. */
void ResetSaveDataHolderTaskPendingFlag_from_thumb(void);
void Task_WriteNonGhostSaveData_from_thumb(void);
void WriteSaveDataSection_Emblem_from_thumb(undefined4 param_1);
void WriteSaveDataSection_FriendList_from_thumb(undefined4 param_1);
void WriteSaveDataSection_GrandPrix_from_thumb(undefined4 param_1);
void WriteSaveDataSection_Header_from_thumb(undefined4 param_1);
void WriteSaveDataSection_MissionRun_from_thumb(undefined4 param_1);
void WriteSaveDataSection_TimeTrials_from_thumb(undefined4 param_1);
void func_02145d38(void);
#define piRam02057214 (*(int **)(uintptr_t)0x2057214u)
#define piRam02057218 (*(int **)(uintptr_t)0x2057218u)
