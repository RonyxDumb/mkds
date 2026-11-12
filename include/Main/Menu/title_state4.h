#pragma once

#include "types.h"

void TitleSetWLMenuKind(unsigned int value);
void SetConnectionKind(unsigned int value);

void TitleState5Nop(void);
void UpdateTitleState4(void);

u32 TitleState4ReturnArgumentWrapper(u32 value);
