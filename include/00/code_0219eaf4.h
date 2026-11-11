#pragma once

#include "types.h"

u32 DWCi_ProcessCancelMatchSynTimeout(void);
BOOL DWCi_ProcessCancelMatchSynCommand(u32 profileId, s32 command, u32 data);
u32 UpdateMatchingPeerMessageTimeouts(void);
void SendMatchingPeerMessage(s32 peerIndex, u16 kind);
u32 DropParticipantsNotInMask(u32 mask);
void CloseAllMatchingConnections(void);
u32 DWCi_CloseCancelHostAsync(u32 profileId);
u32 DWCi_ResumeMatching(void);
void DWCi_RestartFromTimeout(void);
void DWCi_RestartFromCancel(s32 level);
u32 DWCi_InvalidateReservation(void);
void DWCi_FinishCancelMatching(void);
void DWCi_DoCancelMatching(void);
