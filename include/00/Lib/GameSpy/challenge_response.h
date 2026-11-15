#pragma once

#include "types.h"

typedef struct Gt2Buffer Gt2Buffer;

extern s8 gGt2ChallengeKey[33];

u8 *gti2GetResponse(u8 *buffer, const u8 *challenge);
u8 *gti2GetChallenge(u8 *buffer);
BOOL gti2VerifyChallenge(const u8 *buffer);
