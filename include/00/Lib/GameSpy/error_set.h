#pragma once

#include "types.h"

typedef struct GPConnection GPConnection;

void gpiSetError(GPConnection *connection, u32 errorNumber, const char *errorMessage);
