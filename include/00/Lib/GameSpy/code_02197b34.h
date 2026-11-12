#pragma once

#include "types.h"

typedef struct Gt2Buffer Gt2Buffer;

extern const s8 gGt2ChallengeKey[];
extern const char gGt2AuthChallengeAssert[];
extern const char gGt2AuthFileName[];
extern const char gGt2BufferShortenStartAssert[];
extern const char gGt2BufferShortenLengthAssert[];
extern const char gGt2BufferWriteDataAssert[];

s8 *gti2GetResponse(s8 *buffer, const s8 *challenge);
s8 *gti2GetChallenge(s8 *buffer);
BOOL gti2VerifyChallenge(const s8 *buffer);
void RemoveBufferBytes(Gt2Buffer *buffer, int start, int shortenBy);
void AppendBufferBytes(Gt2Buffer *buffer, const u8 *data, int len);
