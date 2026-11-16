#pragma once

#include "types.h"

u32 DWCi_BACKUPlWriteAll(int data);
u32 DWCi_BACKUPlWritePage(int data, int *flags, void *verifyBuffer);
u32 DWCi_BACKUPlRead(void *buffer);
u32 DWCi_BACKUPlInit(u16 *buffer);
