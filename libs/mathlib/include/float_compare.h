#pragma once

#include "types.h"

u32 FloatCompare3Way(u32 left, u32 right);
u32 _fls(u32 left, u32 right);
u32 _fgr(u32 left, u32 right);
u32 _fgeq(u32 left, u32 right);
u32 _dneq(u32 leftLow, u32 leftHigh, u32 rightLow, u32 rightHigh);
u32 _deq(u32 leftLow, u32 leftHigh, u32 rightLow, u32 rightHigh);
u32 _dls(u32 leftLow, u32 leftHigh, u32 rightLow, u32 rightHigh);
u32 _dleq(u32 leftLow, u32 leftHigh, u32 rightLow, u32 rightHigh);
u32 _dgr(u32 leftLow, u32 leftHigh, u32 rightLow, u32 rightHigh);
