#pragma once

#include "types.h"
#include "Main/System/backup_net_camera_work.h" // DataSharing

void InitRaceConnection(void);
void ResetConnectionData(void);
void ResetDataSharing(DataSharing *dataSharing);
void FinishConnectionEnd(void);
void InitConnectionBuffers(void *heap);
void InitConnection(void *heap);
s32 GetZeroWordResult(void);
s32 StartDataSharingSync(void);
BOOL FinishDataSharingSync(void);
s32 AdvanceBlockReceive(void);
void UpdateConnectionSendTimer(void);
s32 AdvanceBlockCountRequest(void);
s32 AdvanceConnectionSetup(s32 isParent, void *ghostSource);
