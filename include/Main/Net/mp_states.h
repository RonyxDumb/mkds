#pragma once

#include "types.h"
#include "Main/MapObjects/data_02165000.h"

void EnterMPReadyNop(void *stateObject);
void UpdateMPSendPlayerBits(void *stateObject);
void EnterMPSendPlayerBits(void *stateObject);
void UpdateMPExchangePlayerBits(void *stateObject);
void EnterMPExchangePlayerBits(void *stateObject);
void UpdateMPStartDataSharing(void *stateObject);
void EnterMPStartDataSharing(void *stateObject);
void UpdateMPSendPlayerNames(void *stateObject);
void EnterMPSendPlayerNames(void *stateObject);
void UpdateMPSendRomArchive(void *stateObject);
void EnterMPSendRomArchive(void *stateObject);
void UpdateMPSendAllRecords(void *stateObject);
void EnterMPSendAllRecords(void *stateObject);
void UpdateMPExchangeOwnRecords(void *stateObject);
BOOL GetEntryChunk(u8 *entry, s32 chunkIndex, s32 chunkSize, u8 **outChunk, u16 *outSize);
BOOL QueueMPChunk(u8 chunkNumber, u8 *data, u16 size, u8 playerIndex, u8 destBitmap);
void QueueMPChunkCallback(void);
void EnterMPExchangeOwnRecords(void *stateObject);
void UpdateMPStartExchange(void *stateObject);
void EnterMPStartExchange(void *stateObject);
void UpdateMPLoadSoundData(void *stateObject);
void EnterMPLoadSoundData(void *stateObject);
void UpdateMPLoadOverlay(void *stateObject);
void EnterMPLoadOverlay(void *stateObject);
void UpdateMPWaitRomArchive(void *stateObject);
void UpdateMPLoadDlArchives(void *stateObject);
void EnterMPLoadDlArchives(void *stateObject);
void UpdateMPSendGroupSendMask(void *stateObject);
void UpdateMPSendParticipantMask(void *stateObject);
void RequestMPReadyAfterCombine(void);

extern QueueMPDataToPortParams gQueueMPChunkParams;
