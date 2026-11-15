#pragma once

#include "types.h"
#include "03/System/tasks.h"
#include "00/Lib/DWC/code_02188720.h"

void ConnectFreeExpHeapBlockWrapper(void *unused, void *block);
u32 ConnectAllocExpHeapBlockWrapper(u32 unused, u32 size);
void AdvanceConnectRequest(TaskEntry *entry, void *arg);
void UpdateConnectRelease(void);
void UpdateConnectFadeOut(void);
void StartConnectFadeOut(void);
void UpdateConnectResultNop(void);
void UpdateConnectNop(void);
void UpdateConnectInputNop(void);
void UpdateConnect(void);
void UpdateConnectFadeIn(void);
void StartConnectFadeIn(void);
void StartConnectRequest(void);
void LoadConnectFilesAndSetBgCnt(void);
void SetupConnect(void);

extern const DWCACConfig gConnectParamsTemplate;
extern u8 gConnectSucceeded;
