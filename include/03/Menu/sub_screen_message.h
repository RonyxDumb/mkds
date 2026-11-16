#pragma once

#include "types.h"

typedef struct MessageFile MessageFile;

BOOL HideSubScreenMessage(void);
BOOL ShowSubScreenMessage(u32 message, s32 selection, u32 mode);
void ClearSubScreenMessageShown(void);

extern const u16 gSubScreenMessageRect[4];
extern u8 gJtNullNscName[17];
extern u8 gSubScreenMessageShown;
