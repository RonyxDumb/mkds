#pragma once

#include "types.h"

typedef struct PeerAddress PeerAddress;

// Object DWCi_NNCompletedCallback reads and writes through its last parameter.
typedef struct Unk0219db18 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 pad_02[6];
    /* 08 */ u32 mUnk_08;
} Unk0219db18;

u32 DWCi_ProcessNNFailure(void);
void DWCi_NNCompletedCallback(s32 result, s32 gamesocket, PeerAddress *remoteaddr, void *userdata);
