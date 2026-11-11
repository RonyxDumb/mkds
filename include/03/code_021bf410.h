#pragma once

#include "types.h"

typedef struct MessageFile MessageFile;

extern MessageFile *gMessages;

BOOL HideSubScreenMessage(void);
BOOL ShowSubScreenMessage(u32 message, s32 selection, u32 mode);
void ClearSubScreenMessageShown(void);
