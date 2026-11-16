#pragma once

#include "types.h"

u32 KBD_IsEnableTpSampling(void);
u32 GetKeyboardLastTouchY(void);
u32 GetKeyboardLastTouchX(void);
u32 GetKeyboardTouchStatus(void);
u32 GetKeyboardTouchDown(void);
u32 KBD_IsSetPadPress(u32 mask);
u32 KBD_IsSetPadTrig(u32 mask);
