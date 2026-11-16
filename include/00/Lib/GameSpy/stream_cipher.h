#pragma once

#include "types.h"

typedef struct GOACryptState {
    /* 000 */ u8 mCards[256];
    /* 100 */ u8 mRegisterBytes[5];
} GOACryptState;

u8 GOADecryptByte(GOACryptState *state, u8 byte);
void GOACryptInit(GOACryptState *state, const u8 *key, u32 keyBytesLen);
void GOAHashInit(GOACryptState *state);
u8 keyrand(GOACryptState *state, u32 limit, const u8 *key, u32 keyBytesLen, u8 *runningSum, u32 *keyReadPos);
