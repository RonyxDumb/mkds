#pragma once

#include "types.h"
#include "03/System/touch_key_input.h"

typedef struct Rect Rect;

BOOL GetTouchPoint(u16 *output);
BOOL IsTouchPressedInOriginSizeRect(const OriginSizeRect *input);
BOOL IsTouchReleasedInRect(const Rect *rect);
BOOL IsTouchPressedOrRepeatedInRect(const Rect *rect);
BOOL IsTouchPressedInRect(const Rect *rect);
BOOL IsTouchDownInRect(const Rect *rect);
BOOL AreKeysReleased(u32 keys);
BOOL AreKeysPressedOrRepeated(u32 keys);
BOOL AreKeysPressed(u32 keys);
BOOL AreKeysDown(u32 keys);
void UpdateTouchInput(void);
void UpdateKeyInput(void);
void UpdateKeyTouchInput(void);
void ReleaseKeyTouchInput(void);

extern u8 gTouchRepeatFrames;
extern struct KeyTouchInput *gKeyTouchInput;
extern u8 gKeyRepeatFrames[14];
