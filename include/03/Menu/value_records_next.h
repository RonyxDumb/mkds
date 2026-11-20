#pragma once

#include "types.h"

void UpdateValueRecordsNextFrames(void);
void UpdateValueRecordsNextRelease(void);
void StartValueRecordsNextFadeOut(void);
void UpdateValueRecordsNextNop(void);
void UpdateValueRecordsNext(void);
void UpdateValueRecordsNextFadeIn(void);
void StartValueRecordsNextFadeIn(void);
void LoadValueRecordsNextFileAndSetBgCnt(void);
void SetupValueRecordsNext(void);
void UpdateApListMessageClose(void);
void UpdateApListMessageResult(void);

extern u8 gValueRecordsNextXb4MultiNscName[19];
extern u8 gValueRecordsNextFrames;
