#include "00/code_02197b34.h"
#include "00/code_0218e2dc.h"
#include "00/code_02197e58.h"
#include "00/unk_021b3000.h"
#include "string.h"
#include "code_02134398.h"
#include "code_021384cc.h"
#include "code_02139f70.h"

void AppendBufferBytes(Gt2Buffer *buffer, const u8 *data, int len) {
    if (data != NULL && len != 0) {
        if (len == -1) {
            len = strlen((const char *) data);
        }
        if (buffer->mLength + len > buffer->mSize) {
            AssertionFailed(gGt2BufferWriteDataAssert, gGt2BufferFileName, NULL, 0x40);
        }
        memcpy(buffer->mData + buffer->mLength, data, len);
        buffer->mLength = buffer->mLength + len;
    }
}

void RemoveBufferBytes(Gt2Buffer *buffer, int start, int shortenBy) {
    if (start == -1) {
        start = buffer->mLength - shortenBy;
    }
    if (start > buffer->mLength) {
        AssertionFailed(gGt2BufferShortenStartAssert, gGt2BufferFileName, NULL, 0x4f);
    }
    if (shortenBy > buffer->mLength - start) {
        AssertionFailed(gGt2BufferShortenLengthAssert, gGt2BufferFileName, NULL, 0x50);
    }
    memmove(buffer->mData + start, buffer->mData + start + shortenBy, buffer->mLength - start - shortenBy);
    buffer->mLength = buffer->mLength - shortenBy;
}

BOOL gti2VerifyChallenge(const s8 *buffer) {
    s32 b[8];
    u32 h;
    u32 g;
    s32 runningXor;
    s32 index;
    u32 firstByte;
    u32 d;
    runningXor = 0;
    index = 1;
    firstByte = (u8) buffer[0];
    b[0] = firstByte;
    b[0] &= index;
    b[2] = runningXor;
    b[1] = index;
    b[4] = runningXor;
    b[3] = index;
    b[6] = index;
    b[5] = index;
    b[7] = index;
    do {
        d = (u8) buffer[index - 1];
        if (d < firstByte) {
            g = b[1];
        } else {
            g = b[2];
        }
        if (firstByte < 0x4f) {
            h = b[3];
        } else {
            h = b[4];
        }
        runningXor ^= (index ^ d) & b[5];
        d = b[0];
        d ^= runningXor;
        d ^= h;
        runningXor = d;
        runningXor ^= g;
        if ((runningXor != 0 && ((u8) buffer[index] & b[6]) == 0) || (runningXor == 0 && ((u8) buffer[index] & b[7]) == 1)) {
            return FALSE;
        }
        index++;
    } while (index < 0x20);
    return TRUE;
}

s8 *gti2GetChallenge(s8 *buffer) {
    s32 b[9];
    u32 previousByte;
    u32 h;
    u32 d;
    s32 index;
    s32 parityFlag;
    u32 g;
    u8 *current;
    if (buffer == NULL) {
        AssertionFailed(gGt2AuthChallengeAssert, gGt2AuthFileName, NULL, 0x2b);
    }
    srand(GetElapsedMilliseconds());
    buffer[0] = (s32) rand() % 0x5d + 0x21;
    parityFlag = 0;
    index = 1;
    b[1] = parityFlag;
    b[0] = index;
    b[3] = parityFlag;
    b[2] = index;
    b[5] = index;
    b[4] = index;
    b[6] = index;
    b[7] = index;
    do {
        previousByte = (u8) buffer[index - 1];
        d = (u8) buffer[0];
        if (previousByte < d) {
            g = b[0];
        } else {
            g = b[1];
        }
        if (d < 0x4f) {
            h = b[2];
        } else {
            h = b[3];
        }
        d &= b[5];
        b[8] = index;
        b[8] ^= previousByte;
        b[8] &= b[4];
        parityFlag ^= b[8];
        d ^= parityFlag;
        d ^= h;
        parityFlag = d;
        parityFlag ^= g;
        current = (u8 *) &buffer[index];
        buffer[index] = (s32) rand() % 0x5d + 0x21;
        if ((parityFlag != 0 && (*current & b[6]) == 0) || (parityFlag == 0 && (*current & b[7]) == 1)) {
            (*current)++;
        }
        index++;
    } while (index < 0x20);
    return buffer;
}

s8 *gti2GetResponse(s8 *buffer, const s8 *challenge) {
    s32 valid;
    s32 secretLen;
    s32 index;
    s32 scaledIndex;
    s32 prevByte;
    s32 challengeIndex;
    secretLen = strlen((const char *) gGt2ChallengeKey);
    valid = gti2VerifyChallenge(challenge);
    index = 0;
    scaledIndex = 0;
    do {
        if (valid == 0 || index == 0 || index == 0xd) {
            buffer[index] = (s32) rand() % 0x5d + 0x21;
        } else {
            if (index == 1 || index == 0xe) {
                prevByte = challenge[index];
            } else {
                prevByte = challenge[index - 1];
            }
            challengeIndex =
                (gGt2ChallengeKey[(index + (u8) challenge[index]) % secretLen] + index * (u8) challenge[index]) % 0x20;
            buffer[index] =
                (s32) Abs((u8) challenge[challengeIndex] ^ gGt2ChallengeKey[(prevByte * scaledIndex) % secretLen]) % 0x5d +
                0x21;
        }
        scaledIndex += 0x4647;
        index++;
    } while (index < 0x20);
    return buffer;
}
