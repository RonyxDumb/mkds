#pragma once

#include "types.h"

// Build information block of the startup code (see code_02000b4c.c).
typedef struct BuildInfoLayout {
    // Start and end of the block list, the source of the copied words, then the start of the range of words to clear
    // and its end.
    void *mWords[9];
    char mBackup[24];
    char mDwc[52];
    char mWifi[40];
    char mSsl[24];
    char mCps[1028];
} BuildInfoLayout;

extern BuildInfoLayout BuildInfo;

// Defined by the linker script.
extern u8 ARM9_TEXT_START[];
