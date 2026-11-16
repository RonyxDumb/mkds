#pragma once

#include "types.h"

typedef struct OamRange OamRange;

// K&R on purpose: message_box_create.c calls WriteWinRect with a u8 array, and the typed header of this function
// declares it with u16 *.
void WriteWinInOutBits();

void CloseMessageBox(void);
void CreateMessageBox(u32 messageIndex, s32 kind, s32 adjustBrightness, u32 column, u32 value);
u16 GetRecordValueByMacAddress(u8 *macAddress);
