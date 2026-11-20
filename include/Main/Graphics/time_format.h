#pragma once

#include "types.h"
#include "Main/Race/race_setup_block.h" // MinuteSecondMillisecondTime
#include "touch_panel_sampling.h"

// A date as year, month and day bytes (mYear, mMonth, mDay).
typedef struct DateBytes {
    /* 00 */ u8 mYear;
    /* 01 */ u8 mMonth;
    /* 02 */ u8 mDay;
} DateBytes;

typedef s16 IndexChangeOffsets[2][7];

extern const IndexChangeOffsets gIndexChangeOffsets;

void FormatDate(DateBytes *date, u16 *text);
void FormatTwoDigitNumber(u32 number, u16 *text);
void FormatTimeFullWidth(void *time, void *text);
void FormatTimeAscii(void *time, u16 *text);
// Values of the variant argument: digits and separators written as ASCII or as full-width characters.
#define TIME_FORMAT_ASCII 0
#define TIME_FORMAT_FULL_WIDTH 1

void FormatMinuteSecondMillisecondTime(MinuteSecondMillisecondTime *time, u16 *text, s32 variant);
void WriteZeroDigitByVariant(u16 *text, s32 variant);
void WriteColonByVariant(u16 *text, s32 variant);
void FormatNumberByVariant(s32 number, u16 *text, s32 variant);
s16 LookupIndexChangeOffset(s32 step, s32 row);
