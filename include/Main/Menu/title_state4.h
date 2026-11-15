#pragma once

#include "types.h"

void TitleSetWLMenuKind(unsigned int value);
void SetConnectionKind(unsigned int value);

void TitleLeaveNop(void);
void UpdateTitleSelectPress(void);

u32 TitleSelectPressReturnArgumentWrapper(u32 value);
