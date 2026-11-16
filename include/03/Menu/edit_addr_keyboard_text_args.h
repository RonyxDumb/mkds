#pragma once

#include "types.h"
#include "03/System/tasks.h"

// The text rectangle, the entry count it returns and the one-character text that CreateEditAddrKeyboard builds for each
// key of each key row.
typedef struct EditAddrKeyboardTextArgs {
    /* 00 */ u16 mTextRect[4];
    /* 08 */ u32 mEntryCount;
    /* 0c */ u16 mText[2];
} EditAddrKeyboardTextArgs;
