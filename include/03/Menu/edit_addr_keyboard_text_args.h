#pragma once

#include "types.h"
#include "03/System/tasks.h"

// Stack object of CreateEditKeyboard.
typedef struct EditAddrKeyboardTextArgs {
    /* 00 */ u16 mTextRect[4];
    /* 08 */ u32 mEntryCount;
    /* 0c */ u16 mText[2];
} EditAddrKeyboardTextArgs;
