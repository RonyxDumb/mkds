#include "00/Lib/GameSpy/code_0218e0fc.h"
#include "00/Lib/GameSpy/code_0218e2a4.h"
#include "00/Lib/CPS/code_021acee0.h"
#include "00/Lib/CPS/code_021acee8.h"
#include "00/Lib/CPS/code_021acef0.h"
#include "00/unk_021b0000.h"
#include "00/unk_021b2000.h"
#include "code_02134398.h"
#include "hash1.h"

s32 Util_RandInt(s32 low, s32 high) {
    s32 range = high - low;
    s32 num;
    if (range == 0) {
        return low;
    }
    num = longrand() % range;
    return num + low;
}

void TripToQuart(const s8 *trip, u8 *quart, s32 inlen) {
    u8 paddedTriple[3];
    s32 index = 0;
    for (; index < inlen; index++) {
        paddedTriple[index] = trip[index];
    }
    for (; index < 3; index++) {
        paddedTriple[index] = 0;
    }
    quart[0] = paddedTriple[0] >> 2;
    quart[1] = ((paddedTriple[0] & 3) << 4) | (paddedTriple[1] >> 4);
    quart[2] = ((paddedTriple[1] & 0xf) << 2) | (paddedTriple[2] >> 6);
    quart[3] = paddedTriple[2] & 0x3f;
}

void B64Encode(const void *input, void *output, s32 inlen, s32 encodingType) {
    const s8 *inputCursor = input;
    s8 *outputCursor = output;
    s8 *outputStart = outputCursor;
    const s8 *alphabet;
    s32 inputLeft = inlen;
    s8 *padStart;
    s8 value;
    switch (encodingType) {
        case 1:
            alphabet = gAlternateEncoding;
            break;
        case 2:
            alphabet = gUrlSafeEncodeing;
            break;
        default:
            alphabet = gDefaultEncoding;
            break;
    }
    while (inputLeft > 0) {
        TripToQuart(inputCursor, (u8 *) outputCursor, inlen >= 3 ? 3 : inlen);
        outputCursor += 4;
        inputCursor += 3;
        inputLeft -= 3;
    }
    padStart = outputCursor;
    if (inlen % 3 == 1) {
        padStart = outputCursor - 2;
    } else if (inlen % 3 == 2) {
        padStart = outputCursor - 1;
    }
    *outputCursor = 0;
    while (outputCursor > outputStart) {
        outputCursor--;
        if (outputCursor >= padStart) {
            *outputCursor = alphabet[2];
        } else {
            value = *outputCursor;
            if (value <= 25) {
                *outputCursor = value + 65;
            } else if (value <= 51) {
                *outputCursor = value + 71;
            } else if (value <= 61) {
                *outputCursor = value - 4;
            } else if (value == 62) {
                *outputCursor = alphabet[0];
            } else if (value == 63) {
                *outputCursor = alphabet[1];
            }
        }
    }
}

void MD5Print(const u8 *digest, char *output) {
    u32 count;
    s32 offset;
    count = 0;
    offset = 0;
    for (; count < 16; count++) {
        sprintf(output + offset, gHexByteFormat, digest[count]);
        offset += 2;
    }
}

void MD5Digest(const char *input, s32 len, char *output) {
    u8 hashBytes[16];
    DGTHash1Context context;
    MD5Init(&context);
    MD5Update(&context, (const u8 *) input, len);
    MD5Final(hashBytes, &context);
    MD5Print(hashBytes, output);
}
