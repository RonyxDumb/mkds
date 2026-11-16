#pragma once

#include "types.h"

typedef struct OamRange OamRange;

// K&R on purpose: this declaration is deliberately not the typed one in 03/Graphics/dispcnt_window.h.
void WriteWinInOutBits();

void CloseMessageBox(void);
void CreateMessageBox(u32 messageIndex, s32 kind, s32 adjustBrightness, u32 column, u32 value);
u16 GetRecordValueByMacAddress(u8 *macAddress);
