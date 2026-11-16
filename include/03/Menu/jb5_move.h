#pragma once

#include "types.h"
#include "03/System/touch_key_input.h"

typedef struct Rect Rect;

void Jb5MoveChildWaitCallback(void);
void UpdateJb5MoveRelease(void);
void UpdateJb5MoveFadeOut(void);
void UpdateJb5MoveMessageClose(void);
void UpdateJb5MoveMessageNop(void);
void UpdateJb5MoveMessageInputNop(void);
void UpdateJb5MoveMessage(void);
void UpdateJb5MoveMessageIn(void);
void UpdateJb5MoveFadeIn(void);
void StartJb5MoveFadeIn(void);
void LoadJb5MoveFileAndSetBgCnt(void);
void SetupJb5Move(void);

extern const Rect gJb5MoveTextRect;
extern u8 gJb5MoveNscName[18];
extern u8 gJb5MoveShowNext;
extern u8 gJb5MoveChildWaitEvent;
