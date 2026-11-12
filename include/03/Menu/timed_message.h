#pragma once

#include "types.h"

void UpdateTimedMessageFrames(void);
void UpdateTimedMessageRelease(void);
void StartTimedMessageFadeOut(void);
void UpdateTimedMessageNop(void);
void UpdateTimedMessage(void);
void UpdateTimedMessageFadeIn(void);
void StartTimedMessageFadeIn(void);
void LoadTimedMessageFileAndSetBgCnt(void);
void SetupTimedMessage(void);

extern u8 gYb5MultiNscName5[19];
extern u8 gTimedMessageFrames;
