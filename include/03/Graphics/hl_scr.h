#pragma once

#include "types.h"

extern void *gHlScr;

void InitHlScr(void);
void UploadHlScr(u32 a);
void LoadHlListScr(void);
void LoadHlSetScr(void);
void LoadHlScr(int b);
void ReleaseHlScr(void);
