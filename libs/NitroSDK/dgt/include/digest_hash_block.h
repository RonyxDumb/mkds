#pragma once

#include "types.h"
#include "digest_hmac_overlay_hash.h" // DGTHash2Context

void DGTi_hash2_arm4_small(DGTHash2Context *ctx, u8 *data, int size);
