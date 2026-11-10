#pragma once

#include "types.h"
#include "Main/Unknown/code_02125de0.h"

void PrintKeyboardButtonTexts(void);
void InitKeyboardCursorCorners(void);
void HideKeyboardFirstBufferObjects(void);
void SetKeyboardTextFromFriendKey(void);
void SetKeyboardTextFromName(void);
void SetKeyboardTextFromPlayerName(void);
void CopyKeyboardTextAsBytes(void);
void InitKeyboard(void *heap, s32 mode);
