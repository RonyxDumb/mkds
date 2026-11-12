#pragma once

#include "types.h"
#include "03/code_021c2530.h"

typedef struct MessageFile {
    /* 00 */ u32 *mOffsets;
    /* 04 */ u8 *mData;
    /* 08 */ u8 *mFile;
} MessageFile;

void *GetMessageEntryAndWriteDigit(MessageFile *table, u32 index, s32 column, s32 value);

extern struct MessagesPool *gMessagesPool;
