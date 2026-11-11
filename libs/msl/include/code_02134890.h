#pragma once

#include "types.h"
#include "code_02134398.h"

u32 fwrite(const char *data, u32 itemSize, u32 itemCount, FILE *stream);
int fflush(FILE *stream);
double LdexpViaFrexp(double value, int exponentDelta);
