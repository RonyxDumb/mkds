#pragma once

#include "types.h"

void ResetRequestId(void);
void AdvanceRequestId(void);
unsigned int GetRequestId(void);
void MBi_CommCallParentError(u32 aid, u16 errcode);
u32 IsChildIndexInRange(u32 a);
