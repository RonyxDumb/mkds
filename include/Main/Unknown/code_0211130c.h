#pragma once

#include "types.h"

// Object whose member at 0x4 recordsMenu_onDraw writes.
typedef struct Unk02111324 {
    /* 00 */ u8 field0[4];
    /* 04 */ u16 field4;
} Unk02111324;

void recordsMenu_onDraw(Unk02111324 *sceneNumbers);
void *GetRecordMainOam(void);
void *GetRecordSubOam(void);
