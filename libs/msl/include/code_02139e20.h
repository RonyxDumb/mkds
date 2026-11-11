#pragma once

#include "types.h"

// Entries are called with their index + 1 by raise, which compares them with 0 and 1 first.
typedef void (*RaiseHandlerFunc)(int a);

extern RaiseHandlerFunc gRaiseHandlers[];

int raise(int signalNumber);
