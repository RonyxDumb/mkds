#pragma once

#include "types.h"
#include "03/System/tasks.h"

extern void *gHlScr;

void InitHlScr(void);
void UploadHlScr(TaskEntry *entry, void *arg);
void LoadHlListScr(void);
void LoadHlSetScr(void);
void LoadHlScr(int scrIndex);
void ReleaseHlScr(void);
