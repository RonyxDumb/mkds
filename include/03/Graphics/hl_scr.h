#pragma once

#include "types.h"

extern void *gHlScr;

void InitHlScr(void);
void UploadHlScr(u32 entry);
void LoadHlListScr(void);
void LoadHlSetScr(void);
void LoadHlScr(int scrIndex);
void ReleaseHlScr(void);
