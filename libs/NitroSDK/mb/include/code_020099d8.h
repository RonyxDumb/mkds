#pragma once

#include "types.h"
#include "code_02009928.h"
#include "code_0200ad00.h"
#include "mb_data.h"
#include "code_02142eac.h"

int MBi_SendMP(void *data, u32 size, u32 childMask);
s32 MBi_SetMPData(Unk021425e8Func callback, void *data, s32 dataSize, u16 unusedValue, u16 childMask);
