#pragma once

#include "types.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_02024000.h"

void EmblemChoisesInitTextCanvas(TextCanvas *textCanvas, void *charCanvas, void *font, s32 charSpacing,
                                 s32 lineSpacing);
u32 EmblemChoisesDrawTextOnCanvas(TextCanvas *textCanvas, s32 textX, s32 textY, u32 color, u32 flags, void *text);
void InitEmblemChoises(void);
