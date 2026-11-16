#pragma once

#include "types.h"

void UpdateExchangeSearchOutcome(void);
void UpdateExchangeSearchRelease(void);
void UpdateExchangeSearchFadeOut(void);
void StartExchangeSearchClose(void);
void UpdateExchangeSearchResult(void);
void UpdateExchangeSearchNop(void);
void UpdateExchangeSearchInput(void);
void UpdateExchangeSearch(void);
void UpdateExchangeSearchButtonsIn(void);
void UpdateExchangeSearchFadeIn(void);
void StartExchangeSearchFadeIn(void);
void LoadExchangeSearchFilesAndSetBgCnt(void);
void SetupExchangeSearch(void);

extern u8 gExchangeSearchShowNext;
