#pragma once

#include "types.h"

// How many keys each of the five keyboard rows has.
typedef struct EditKeyboardRowCounts {
    /* 0 */ u8 mCounts[5];
} EditKeyboardRowCounts;

extern EditKeyboardRowCounts gEditKeyboardRow4KeyCounts;
extern EditKeyboardRowCounts gEditKeyboardKeyCounts;
extern EditKeyboardRowCounts gEditKeyboardExtraKeyCounts;
extern u8 gEditKeyboardPage0Inputs[0x30];
extern u8 gEditKeyboardPage1Inputs[0x30];
extern u8 gEditKeyboardPage2Inputs[0x30];
extern u8 *gEditKeyboardPageInputs[3];
extern u32 gEditKeyboardExtraKeySoundSeqs[];
