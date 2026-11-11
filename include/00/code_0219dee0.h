#pragma once

#include "types.h"

typedef struct QueryBuffer QueryBuffer;

void WriteMatchingKeyValue(s32 keyId, QueryBuffer *buffer, void *userdata);
BOOL FilterAndEvalMatchingServerList(s32 sort);
