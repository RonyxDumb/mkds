#pragma once

#include "types.h"

void UpdateExchangeResultFrames(void);
void UpdateExchangeResultRelease(void);
void StartExchangeResultFadeOut(void);
void UpdateExchangeResultNop(void);
void UpdateExchangeResult(void);
void UpdateExchangeResultFadeIn(void);
void StartExchangeResultFadeIn(void);
void LoadExchangeResultFileAndSetBgCnt(void);
void SetupExchangeResult(void);
void UpdateExchangeSearchMessageClose(void);
void UpdateExchangeSearchMessageResult(void);

extern u8 gXb4MultiNscName5[19];
extern u8 gExchangeResultFrames[1];
