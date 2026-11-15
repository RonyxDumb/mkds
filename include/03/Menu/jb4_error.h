#pragma once

#include "types.h"

void SetJb4ErrorCode(u32 errorCode);
void UpdateJb4ErrorRelease(void);
void UpdateJb4ErrorFadeOut(void);
void StartJb4ErrorClose(void);
void UpdateJb4ErrorResult(void);
void UpdateJb4ErrorNop(void);
void UpdateJb4ErrorInput(void);
void UpdateJb4Error(void);
void UpdateJb4ErrorButtonsIn(void);
void UpdateJb4ErrorFadeIn(void);
void StartJb4ErrorFadeIn(void);
void PrintJb4Error(void);

extern const u8 gJb4ErrorFontIndices[6];
extern const u16 gJb4ErrorMessageRect[4];
extern const u16 gJb4ErrorCodePositions[12];
extern u16 gDecimalFormat[3];
extern s32 gJb4ErrorCode;
