#pragma once

#include "types.h"
#include "Main/System/backup_net_camera_work.h" // DataSharing

void InitRaceConnection(void);
void ResetConnectionData(void);
void ResetDataSharing(DataSharing *dataSharing);
void FinishConnectionEnd(void);
void InitializeSomeZEPointers(void *heap);
void InitializeGlobalZE(void *heap);
// Results of GetZeroWordResult: children are still connected, the zero word arrived with no child left, or the
// connection is not a parent or no child is left without a zero word.
#define WORD_WAIT_RESULT_WAITING 0
#define WORD_WAIT_RESULT_RECEIVED 1
#define WORD_WAIT_RESULT_NOT_RECEIVED 2
s32 GetZeroWordResult(void);
s32 StartDataSharingSync(void);
BOOL FinishDataSharingSync(void);
s32 AdvanceBlockReceive(void);
void UpdateConnectionSendTimer(void);
s32 AdvanceBlockCountRequest(void);
s32 AdvanceConnectionSetup(s32 isParent, void *ghostSource);
