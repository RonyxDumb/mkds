#pragma once

#include "types.h"
#include "Main/Menu/data_0217d000.h"

void InitMenuNop(void);
void QueueTrophyIcon(int iconIndex, int paletteIndex, void *cells, void *cellLayout, u32 destIndex, u16 paletteSlot,
                     int queueSelector);

void ClearTrophyIconPointer(void);

void CreateTrophyIcon(void *heap);
void LoadTrophyIconData(void);

extern char *gTrophyIconNcerName;
extern char *gTrophyIconBnclName;
extern char *gTrophyIconNclrName;
extern const u16 gTrophyIconNclrStarts[4];
extern const u16 gTrophyIconBnclIndices[8];
// Objects whose layout isn't known yet.
extern char *gTrophyIconNcgrName;
extern struct TrophyIcon *gTrophyIcon;
