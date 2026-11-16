#pragma once

#include "types.h"

typedef struct BackupFirstBlock BackupFirstBlock;

void WriteSaveDataSection_Header_from_thumb(BackupFirstBlock *block);
