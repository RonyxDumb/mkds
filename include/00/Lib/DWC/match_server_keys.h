#pragma once

#include "types.h"

typedef struct QueryBuffer QueryBuffer;

void DWCi_QR2ServerKeyCallback(u8 keyId, QueryBuffer *buffer, void *userData);
BOOL DWCi_EvaluateServers(s32 sort);
