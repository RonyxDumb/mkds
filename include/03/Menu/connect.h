#pragma once

#include "types.h"

void ConnectFreeExpHeapBlockWrapper(void *unused, void *block);
u32 ConnectAllocExpHeapBlockWrapper(u32 unused, u32 size);
void AdvanceConnectRequest(u32 entry);
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
