#pragma once

#include "types.h"
#include "print_memory_multibyte_write.h"

u32 fwrite(const char *data, u32 itemSize, u32 itemCount, FILE *stream);
int fflush(FILE *stream);
double LdexpViaFrexp(double value, int exponentDelta);
