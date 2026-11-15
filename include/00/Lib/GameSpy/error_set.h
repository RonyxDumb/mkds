#pragma once

#include "types.h"

typedef struct GpConnection GpConnection;

void GpiSetError(GpConnection *connection, u32 errorNumber, const char *errorMessage);
