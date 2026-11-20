#pragma once

#include "types.h"

void SetupOptMenuMessageNext(void);
void UpdateOptMenuMessageRelease(void);
void UpdateOptMenuMessageFadeOut(void);
void StartOptMenuMessageClose(void);
void UpdateOptMenuMessageResult(void);
void UpdateOptMenuMessageNop(void);
void UpdateOptMenuMessageInput(void);
void UpdateOptMenuMessage(void);
void UpdateOptMenuMessageButtonsIn(void);
void UpdateOptMenuMessageFadeIn(void);
void StartOptMenuMessageFadeIn(void);
void LoadOptMenuMessageFileAndSetBgCnt(void);
void SetupOptMenuMessage(void);

extern u8 gOptMenuMessageYb5MultiNscName[19];
extern u8 gOptMenuMessageShowNext;
