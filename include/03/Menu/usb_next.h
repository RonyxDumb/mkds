#pragma once

#include "types.h"

void UpdateUsbNextFrames(void);
void UpdateUsbNextRelease(void);
void StartUsbNextFadeOut(void);
void UpdateUsbNextNop(void);
void UpdateUsbNext(void);
void UpdateUsbNextFadeIn(void);
void StartUsbNextFadeIn(void);
void LoadUsbNextFileAndSetBgCnt(void);
void SetupUsbNext(void);

extern u8 gXb4MultiNscName10[19];
extern u8 gUsbNextFrames;
