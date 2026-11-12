#pragma once

#include "types.h"

void UpdateChildWaitMessageRelease(void);
void UpdateChildWaitMessageFadeOut(void);
void StartChildWaitMessageClose(void);
void UpdateChildWaitMessageResult(void);
void UpdateChildWaitMessageNop(void);
void UpdateChildWaitMessageInput(void);
void UpdateChildWaitMessage(void);
void UpdateChildWaitMessageButtonsIn(void);
void UpdateChildWaitMessageFadeIn(void);
void StartChildWaitMessageFadeIn(void);
void LoadChildWaitMessageFileAndSetBgCnt(void);
void SetupChildWaitMessage(void);

extern u8 gYb5MultiNscName6[19];
extern u8 gChildWaitMessageShowNext;
extern u8 gChildWaitMessageSubScreenShown[1];
