#pragma once

#include "types.h"

extern u8 gJb4ErrorFontIndices[];
extern u16 gJb4ErrorMessageRect[];
extern u16 gJb4ErrorCodeXPositions[];
extern u16 gJb4ErrorCodeYPositions[];
extern u16 gDecimalFormat[];

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
