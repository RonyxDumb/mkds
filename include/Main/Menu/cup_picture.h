#pragma once

#include "types.h"

BOOL IsCupPictureReady(void);
void *GetCupPictureNclrData(void);
void *GetCupPictureNcgrData(void);
void *GetCupPictureNscrData(void);
s32 CreateRaceHudSubScreenFireball2Cells(void);

extern char gCupPictureRetro[6];
extern char gCupPictureNitro[6];
extern char gCupPicturePrefix[29];
