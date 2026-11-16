#include "00/Lib/GameSpy/md5_base64_encode.h"
#include "00/Lib/GameSpy/random_seed.h"
#include "00/Lib/CPS/md5_finish.h"
#include "00/Lib/CPS/md5_update.h"
#include "00/Lib/CPS/md5_begin.h"
#include "00/Lib/NitroWiFi/access_point_search_defaults.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "print_memory_multibyte_write.h"
#include "digest_stream_hash.h"

const s8 gUrlSafeEncodeing[3] = {0x2d, 0x5f, 0x3d};
const s8 gAlternateEncoding[3] = {0x5b, 0x5d, 0x5f};
const s8 gDefaultEncoding[3] = {0x2b, 0x2f, 0x3d};

s32 Util_RandInt(s32 low, s32 high) {
    s32 span = high - low;
    s32 num;
    if (span == 0) {
        return low;
    }
    num = longrand() % span;
    return num + low;
}

void TripToQuart(const s8 *trip, s8 *quart, s32 inlen) {
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
        case B64_ENCODING_ALTERNATE:
            alphabet = gAlternateEncoding;
            break;
        case B64_ENCODING_URL_SAFE:
            alphabet = gUrlSafeEncodeing;
            break;
        default:
            alphabet = gDefaultEncoding;
            break;
    }
    while (inputLeft > 0) {
        TripToQuart(inputCursor, outputCursor, inlen >= 3 ? 3 : inlen);
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
        sprintf(output + offset, "%02x", digest[count]);
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
