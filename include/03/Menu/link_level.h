#pragma once

#include "types.h"
#include "03/unk_021da000.h"

void UpdateLinkLevel(void);
void ReleaseLinkLevel(void);
void CreateLinkLevel(int row);

extern const u16 gLinkLevelPosition[2];
extern const u8 gLinkLevelImages[2][4];
extern struct LinkLevel *gLinkLevel;
