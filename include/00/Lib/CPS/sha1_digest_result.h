#pragma once

#include "types.h"
#include "00/Lib/CPS/sha1_update.h"

void CPSi_sha1_result_prng(Hash20Context *context, u8 *digest);
void CPSi_sha1_result(Hash20Context *context, u8 *digest);
