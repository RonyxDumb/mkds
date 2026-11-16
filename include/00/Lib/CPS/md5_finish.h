#pragma once

#include "types.h"

typedef struct DGTHash1Context DGTHash1Context;

void MD5Final(u8 *digest, DGTHash1Context *ctx);
