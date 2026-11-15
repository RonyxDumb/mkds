#pragma once

#include "types.h"

void UpdateConnectDoneFrames(void);
void UpdateConnectDoneRelease(void);
void StartConnectDoneFadeOut(void);
void UpdateConnectDoneNop(void);
void UpdateConnectDone(void);
void UpdateConnectDoneFadeIn(void);
void StartConnectDoneFadeIn(void);
void LoadConnectDoneFileAndSetBgCnt(void);
void SetupConnectDone(void);
void UpdateConnectMessageFadeOut(void);
void UpdateConnectMessageClose(void);
void UpdateConnectMessageNop(void);
void UpdateConnectMessageInputNop(void);
void UpdateConnectMessage(void);

extern u8 gXb4MultiNscName9[19];
extern u8 gConnectDoneFrames;
