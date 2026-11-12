#pragma once

#include "types.h"
#include "03/code_021c6764.h"

void UpdateEditInvalidMessageClose(void);
void UpdateEditInvalidMessageResult(void);

extern const u8 gEditLineY[2];
extern const u16 gEditCharSize[2];
extern const u8 gEditColumnX[16];
extern u8 gEditSubScreenMessages[2];
extern struct Edit *gEdit;
