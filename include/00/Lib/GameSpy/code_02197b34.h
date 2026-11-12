#pragma once

#include "types.h"

typedef struct Gt2Buffer Gt2Buffer;

extern s8 gGt2ChallengeKey[33];

s8 *gti2GetResponse(s8 *buffer, const s8 *challenge);
s8 *gti2GetChallenge(s8 *buffer);
BOOL gti2VerifyChallenge(const s8 *buffer);
