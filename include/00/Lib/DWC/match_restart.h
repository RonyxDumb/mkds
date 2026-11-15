#pragma once

#include "types.h"

u32 DWCi_ProcessCancelMatchSynTimeout(void);
BOOL DWCi_ProcessCancelMatchSynCommand(u32 profileId, s32 command, u32 data);
u32 DWCi_ProcessMatchSynTimeout(void);
void DWCi_SendMatchSynPacket(s32 peerIndex, u16 kind);
u32 DWCi_CloseShutdownClientSC(u32 mask);
void DWCi_CloseAllConnectionsByTimeout(void);
u32 DWCi_CloseCancelHostAsync(u32 profileId);
u32 DWCi_ResumeMatching(void);
void DWCi_RestartFromTimeout(void);
void DWCi_RestartFromCancel(s32 level);
u32 DWCi_InvalidateReservation(void);
void DWCi_FinishCancelMatching(void);
void DWCi_DoCancelMatching(void);
