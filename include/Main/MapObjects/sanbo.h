#pragma once

#include "types.h"

void ShineEndCallback(void);
void ShineKartEliminatedCallback(u16 kartIndex);
BOOL ShineKartHitCallback(u16 kartIndex, u16 hitByKartIndex);
void *CreateSanboUpdateList(void);
void *CreateSanboDrawList(void);
