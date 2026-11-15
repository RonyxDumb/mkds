#pragma once

#include "types.h"

typedef struct BuddyRecordBlock BuddyRecordBlock;

void ReadBackupBuddyRecordBlock(void *block);
void WriteBackupBuddyRecordBlock(BuddyRecordBlock *block);
