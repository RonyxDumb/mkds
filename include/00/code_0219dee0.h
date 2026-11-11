#pragma once

#include "types.h"

typedef struct QueryBuffer QueryBuffer;

void DWCi_QR2ServerKeyCallback(s32 keyId, QueryBuffer *buffer, void *userdata);
BOOL DWCi_EvaluateServers(s32 sort);
