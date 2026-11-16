#include "00/Lib/GameSpy/challenge_response.h"
#include "00/Lib/GameSpy/socket_calls.h"
#include "00/Lib/GameSpy/connection_events.h"
#include "string.h"
#include "print_memory_multibyte_write.h"
#include "scan_text_random.h"
#include "narrow_string_functions.h"

s8 gGt2ChallengeKey[33] = "3b8dd8995f7c40a9a5c5b7dd5b481341";

BOOL gti2VerifyChallenge(const u8 *buffer) {
    s32 masks[8];
    u32 firstByteMask;
    u32 previousMask;
    s32 runningXor;
    s32 index;
    u32 firstByte;
    u32 workValue;
    runningXor = 0;
    index = 1;
    firstByte = buffer[0];
    masks[0] = firstByte;
    masks[0] &= index;
    masks[2] = runningXor;
    masks[1] = index;
    masks[4] = runningXor;
    masks[3] = index;
    masks[6] = index;
    masks[5] = index;
    masks[7] = index;
    do {
        workValue = buffer[index - 1];
        if (workValue < firstByte) {
            previousMask = masks[1];
        } else {
            previousMask = masks[2];
        }
        if (firstByte < 0x4f) {
            firstByteMask = masks[3];
        } else {
            firstByteMask = masks[4];
        }
        runningXor ^= (index ^ workValue) & masks[5];
        workValue = masks[0];
        workValue ^= runningXor;
        workValue ^= firstByteMask;
        runningXor = workValue;
        runningXor ^= previousMask;
        if ((runningXor != 0 && (buffer[index] & masks[6]) == 0) ||
            (runningXor == 0 && (buffer[index] & masks[7]) == 1)) {
            return FALSE;
        }
        index++;
    } while (index < 0x20);
    return TRUE;
}

u8 *gti2GetChallenge(u8 *buffer) {
    s32 masks[9];
    u32 previousByte;
    u32 firstByteMask;
    u32 workValue;
    s32 index;
    s32 parityFlag;
    u32 previousMask;
    u8 *current;
    if (buffer == NULL) {
        AssertionFailed("buffer", "gt2Auth.c", NULL, 0x2b);
    }
    srand(GetElapsedMilliseconds());
    buffer[0] = (s32) rand() % 0x5d + 0x21;
    parityFlag = 0;
    index = 1;
    masks[1] = parityFlag;
    masks[0] = index;
    masks[3] = parityFlag;
    masks[2] = index;
    masks[5] = index;
    masks[4] = index;
    masks[6] = index;
    masks[7] = index;
    do {
        previousByte = buffer[index - 1];
        workValue = buffer[0];
        if (previousByte < workValue) {
            previousMask = masks[0];
        } else {
            previousMask = masks[1];
        }
        if (workValue < 0x4f) {
            firstByteMask = masks[2];
        } else {
            firstByteMask = masks[3];
        }
        workValue &= masks[5];
        masks[8] = index;
        masks[8] ^= previousByte;
        masks[8] &= masks[4];
        parityFlag ^= masks[8];
        workValue ^= parityFlag;
        workValue ^= firstByteMask;
        parityFlag = workValue;
        parityFlag ^= previousMask;
        current = &buffer[index];
        buffer[index] = (s32) rand() % 0x5d + 0x21;
        if ((parityFlag != 0 && (*current & masks[6]) == 0) || (parityFlag == 0 && (*current & masks[7]) == 1)) {
            (*current)++;
        }
        index++;
    } while (index < 0x20);
    return buffer;
}

u8 *gti2GetResponse(u8 *buffer, const u8 *challenge) {
    s32 valid;
    s32 challengeKeyLen;
    s32 index;
    s32 scaledIndex;
    s32 selectedByte;
    s32 challengeIndex;
    challengeKeyLen = strlen((const char *) gGt2ChallengeKey);
    valid = gti2VerifyChallenge(challenge);
    index = 0;
    scaledIndex = 0;
    do {
        if (valid == 0 || index == 0 || index == 0xd) {
            buffer[index] = (s32) rand() % 0x5d + 0x21;
        } else {
            if (index == 1 || index == 0xe) {
                selectedByte = (s8) challenge[index];
            } else {
                selectedByte = (s8) challenge[index - 1];
            }
            challengeIndex =
                (gGt2ChallengeKey[(index + challenge[index]) % challengeKeyLen] + index * challenge[index]) % 0x20;
            buffer[index] =
                (s32) Abs(challenge[challengeIndex] ^ gGt2ChallengeKey[(selectedByte * scaledIndex) % challengeKeyLen]) % 0x5d +
                0x21;
        }
        scaledIndex += 0x4647;
        index++;
    } while (index < 0x20);
    return buffer;
}
