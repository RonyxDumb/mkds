#pragma once

#include "types.h"

// Entries are called with their index + 1 by func_02139e20, which compares them with 0 and 1 first.
typedef void (*Unk02139e20Func)(int a);

extern Unk02139e20Func data_0217ee94[];

int func_02139e20(int a);
