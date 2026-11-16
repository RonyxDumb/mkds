#pragma once

#include "types.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_02024000.h"

void echoi_NNS_G2dTextCanvasInit(TextCanvas *textCanvas, void *charCanvas, void *c, s32 d, s32 e);
u32 echoi_NNS_G2dTextCanvasDrawText(TextCanvas *textCanvas, s32 x, s32 y, u32 d, u32 e, void *text);
void echoi_init(void);
