#pragma once

#include "types.h"

void ResetVramOamAndPalettes(void);
void RestoreBankSettingsAndResetDisplay(void);
void SaveBankSettingsAndClearVram(void);

extern u32 gSavedBankSettings[13];
