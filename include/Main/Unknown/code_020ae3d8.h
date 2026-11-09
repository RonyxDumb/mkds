#pragma once

#include "types.h"

typedef struct RandomState64 RandomState64;

RandomState64 *GetConnectionWorkRandomState(void);
unsigned int GetConnectionKind(void);
