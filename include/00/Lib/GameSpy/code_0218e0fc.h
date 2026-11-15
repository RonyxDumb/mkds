#pragma once

#include "types.h"

// Values of the encodingType argument of B64Encode: which alphabet table it uses.
enum {
    B64_ENCODING_DEFAULT,
    B64_ENCODING_ALTERNATE,
    B64_ENCODING_URL_SAFE,
};

void MD5Digest(const char *input, s32 len, char *output);
void MD5Print(const u8 *digest, char *output);
void B64Encode(const void *input, void *output, s32 inlen, s32 encodingType);
void TripToQuart(const s8 *trip, s8 *quart, s32 inlen);
s32 Util_RandInt(s32 low, s32 high);

extern const s8 gUrlSafeEncodeing[3];
extern const s8 gAlternateEncoding[3];
extern const s8 gDefaultEncoding[3];
