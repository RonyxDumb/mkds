#pragma once

#include "types.h"

u32 DWCi_ProcessMatchClosing(s32 error, s32 errorCode, s32 profileId);
void ReceiveMatchingPeerMessage(s32 peerIndex, s32 kind, u8 *data);
void DWCi_ClearQR2Key(void);
