#pragma once

#include "types.h"

extern u8 gJbBgStep3NcgName[];
extern u8 gYbBgStep3NclName[];
extern u8 gXb4MultiNscName[];
extern u16 gValueRecordsFrames;
extern u32 gValueRecordsRequestTask;

void StartValueRecordsCloseWithoutNext(void);
void UpdateValueRecordsFrames(void);
void UpdateValueRecordsMessageClose(void);
void UpdateValueRecordsMessageResult(void);
void UpdateValueRecordsDuringRequest(void);
void UpdateValueRecordsRelease(void);
void UpdateValueRecordsFadeOut(void);
void StartValueRecordsClose(void);
void UpdateValueRecordsResult(void);
void UpdateValueRecordsNop(void);
void UpdateValueRecordsInput(void);
void UpdateValueRecords(void);
void UpdateValueRecordsFadeIn(void);
void StartValueRecordsFadeIn(void);
void LoadValueRecordsFilesAndSetBgCnt(void);
void SetupValueRecords(void);
