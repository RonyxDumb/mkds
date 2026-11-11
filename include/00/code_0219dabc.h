#pragma once

#include "types.h"

typedef struct PeerAddress PeerAddress;

u32 DWCi_ProcessNNFailure(void);
void DWCi_NNCompletedCallback(s32 result, s32 gamesocket, PeerAddress *remoteaddr, void *userdata);
