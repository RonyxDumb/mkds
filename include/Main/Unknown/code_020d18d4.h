#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020cffd0.h"
#include "Main/Unknown/code_020b4000.h"

void r2d_renderRaceNumber(RaceHudOamBuffer *oamBuffer);
void r2d_20D1DE8(RaceHudOamBuffer *oamBuffer, s32 startFrames);
void r2d_renderRaceNumberDoubleDigit(RaceHudOamBuffer *oamBuffer);
void r2d_renderRaceNumberSingleDigit(RaceHudOamBuffer *oamBuffer);
