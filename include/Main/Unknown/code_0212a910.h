#pragma once

#include "types.h"

void SetLinkLevelIconEnabled(u32 index, u32 enabled);
void InitLinkLevelIcons(void *heap, void *oamList);
void OpenMessageScreen(s32 messageKind, s32 inputEnabled);
void FormatMessageScreenErrorCode(void);
void PrintMessageScreenText(void);
void *GetMessageScreenText(void);
void ClearMessageScreenMap(void);
void *GetMessageScreenCharBuffer(void);
