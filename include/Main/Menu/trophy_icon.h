#pragma once

#include "types.h"
#include "Main/Menu/menu_screens_work.h"

void nullsub_20_from_thumb(void);
void QueueTrophyIcon(int iconIndex, int paletteIndex, void *cells, void *cellLayout, u32 destIndex, u16 paletteSlot,
                     int queueSelector);

void ClearTrophyIconPointer(void);

void CreateTrophyIcon(void *heap);
void VerifySelectTrophyIconFiles_from_thumb(void);

extern char *gTrophyIconNcerName;
extern char *gTrophyIconBnclName;
extern char *gTrophyIconNclrName;
extern const u16 gTrophyIconNclrStarts[4];
extern const u16 gTrophyIconBnclIndices[8];
extern char *gTrophyIconNcgrName;
extern struct TrophyIcon *gTrophyIcon;
