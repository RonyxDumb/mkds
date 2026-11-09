#pragma once

#include "types.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

// The two values DrawRaceStartBattle passes to GetRaceStartBattleMNcerEntry.
enum {
    VALUE_0 = 0,
    VALUE_1 = 1,
};

void DrawRaceStartBattle(RaceHudOamBuffer *oamBuffer);
u16 *CupPictureGetBootInfoHalfwordPointer(void);
u32 CupPictureIsDownloadBoot(void);
u32 CupPictureIsDownloadBootWrapper(void);
