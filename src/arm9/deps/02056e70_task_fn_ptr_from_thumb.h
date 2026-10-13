#pragma once
/* Function-specific inferred declarations. */
void ClearSaveDataSection_Emblem_from_thumb(void);
void ClearSaveDataSection_FriendList_from_thumb(void);
void ClearSaveDataSection_GrandPrix_from_thumb(void);
void ClearSaveDataSection_Header_from_thumb(int param_1);
void ClearSaveDataSection_MissionRun_from_thumb(void);
void ClearSaveDataSection_TimeTrials_from_thumb(void);
void ResetSaveDataHolderTaskPendingFlag_from_thumb(void);
void WriteSaveDataSection_Emblem_from_thumb(undefined4 param_1);
void WriteSaveDataSection_FriendList_from_thumb(undefined4 param_1);
void WriteSaveDataSection_GrandPrix_from_thumb(undefined4 param_1);
void WriteSaveDataSection_Header_from_thumb(undefined4 param_1);
void WriteSaveDataSection_MissionRun_from_thumb(undefined4 param_1);
void WriteSaveDataSection_TimeTrials_from_thumb(undefined4 param_1);
void func_02145d38(void);
void task_fn_ptr_from_thumb(void);
#define piRam02056f8c (*(int **)(uintptr_t)0x2056f8cu)
#define piRam02056f90 (*(int **)(uintptr_t)0x2056f90u)
#define psRam02056f94 (*(short **)(uintptr_t)0x2056f94u)
