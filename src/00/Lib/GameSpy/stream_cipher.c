#include "00/Lib/GameSpy/stream_cipher.h"
#include "signed_int_divide.h"

u8 keyrand(GOACryptState *state, u32 limit, const u8 *keyBytes, u32 keyBytesLen, u8 *runningSum, u32 *keyReadPos) {
    u32 mask;
    u32 value;
    u32 tryCount;
    if (limit == 0) {
        return 0;
    }
    tryCount = 0;
    for (mask = 1; mask < limit; mask = mask * 2 + 1) {
    }
    do {
        u32 position = (*keyReadPos)++;
        *runningSum = state->mCards[*runningSum] + keyBytes[position];
        if (*keyReadPos >= keyBytesLen) {
            *keyReadPos = 0;
            *runningSum = *runningSum + keyBytesLen;
        }
        value = mask & *runningSum;
        tryCount++;
        if (tryCount > 11) {
            value = value % limit;
        }
    } while (value > limit);
    return value;
}

void GOAHashInit(GOACryptState *state) {
    s32 cardIndex;
    u32 card;
    state->mRegisterBytes[0] = 1;
    state->mRegisterBytes[1] = 3;
    state->mRegisterBytes[2] = 5;
    state->mRegisterBytes[3] = 7;
    state->mRegisterBytes[4] = 11;
    cardIndex = 0;
    card = 255;
    for (; cardIndex < 256; cardIndex++, card--) {
        state->mCards[cardIndex] = card;
    }
}

void GOACryptInit(GOACryptState *state, const u8 *key, u32 keyBytesLen) {
    u8 runningSum;
    u32 keyReadPos;
    s32 cardIndex;
    u32 countdown;
    u8 heldValue;
    if (keyBytesLen < 1) {
        GOAHashInit(state);
        return;
    }
    for (cardIndex = 0; cardIndex < 256; cardIndex++) {
        state->mCards[cardIndex] = cardIndex;
    }
    keyReadPos = 0;
    runningSum = 0;
    for (countdown = 255; (s32) countdown >= 0; countdown--) {
        u8 swapPos = keyrand(state, countdown, key, keyBytesLen, &runningSum, &keyReadPos);
        heldValue = state->mCards[countdown];
        state->mCards[countdown] = state->mCards[swapPos];
        state->mCards[swapPos] = heldValue;
    }
    state->mRegisterBytes[0] = state->mCards[1];
    state->mRegisterBytes[1] = state->mCards[3];
    state->mRegisterBytes[2] = state->mCards[5];
    state->mRegisterBytes[3] = state->mCards[7];
    state->mRegisterBytes[4] = state->mCards[runningSum];
    runningSum = 0;
    keyReadPos = 0;
}

u8 GOADecryptByte(GOACryptState *state, u8 byte) {
    u8 rotor;
    u8 heldValue;
    u8 previousInputByte;
    u32 partial;
    rotor = state->mRegisterBytes[0];
    state->mRegisterBytes[0] = rotor + 1;
    state->mRegisterBytes[1] = state->mRegisterBytes[1] + state->mCards[rotor];
    previousInputByte = state->mRegisterBytes[4];
    heldValue = state->mCards[previousInputByte];
    state->mCards[previousInputByte] = state->mCards[state->mRegisterBytes[1]];
    state->mCards[state->mRegisterBytes[1]] = state->mCards[state->mRegisterBytes[3]];
    state->mCards[state->mRegisterBytes[3]] = state->mCards[state->mRegisterBytes[0]];
    state->mCards[state->mRegisterBytes[0]] = heldValue;
    state->mRegisterBytes[2] = state->mRegisterBytes[2] + state->mCards[heldValue];
    partial = byte ^
              state->mCards[(state->mCards[state->mRegisterBytes[2]] + state->mCards[state->mRegisterBytes[0]]) & 0xff];
    state->mRegisterBytes[3] = partial ^ state->mCards[state->mCards[(state->mCards[state->mRegisterBytes[1]] +
                                                                      (state->mCards[state->mRegisterBytes[3]] +
                                                                       state->mCards[state->mRegisterBytes[4]])) &
                                                                     0xff]];
    state->mRegisterBytes[4] = byte;
    return state->mRegisterBytes[3];
}
