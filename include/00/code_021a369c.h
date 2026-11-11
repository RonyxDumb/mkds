#pragma once

#include "types.h"

void *DWC_ReallocEx(u32 name, void *ptr, u32 heldSize, u32 wantedSize, u32 align);
void *DWC_Realloc(u32 name, void *ptr, u32 oldsize, u32 newsize);
void DWC_Free(unsigned int name, unsigned int ptr, unsigned int size);
void *DWC_AllocEx(unsigned int name, unsigned int size, unsigned int align);
void *DWC_Alloc(u32 name, u32 size);
u32 DWC_SetMemFunc(void *(*alloc)(u32, u32, s32), void (*free)(u32, void *));
