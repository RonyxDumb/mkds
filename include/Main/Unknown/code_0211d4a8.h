#pragma once

#include "types.h"
#include "code_0200fc8c.h"

typedef struct SelectRaceRuleRowEntries {
    /* 00 */ u16 mEntryIndices[2];
} SelectRaceRuleRowEntries;

extern SelectRaceRuleRowEntries gSelectRaceRuleRowEntries[];

#define gBootInfo HW_WM_BOOT_BUF

void MoveSelectRaceRuleRowPrevious(void);
void MoveSelectRaceRuleRowNext(void);
