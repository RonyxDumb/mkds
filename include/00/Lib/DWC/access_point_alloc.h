#pragma once

#include "types.h"

void DWCi_AC_Free(u8 name, void *ptr, u32 size);
void *DWCi_AC_Alloc(u8 name, u32 size);
void DWCi_AC_InsertApInfo(int slotIndex, void *info);
