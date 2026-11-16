#pragma once

#include "types.h"

u16 oam_getAffineCount(const void *oamList);
void oam_applyBuffers(void *mainOamList, void *subOamList);
