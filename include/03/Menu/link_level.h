#pragma once

#include "types.h"
#include "03/System/tasks.h"
#include "03/Menu/wifi_menu_shared.h"

void UpdateLinkLevel(TaskEntry *task, void *arg);
void ReleaseLinkLevel(void);
void CreateLinkLevel(int row);

extern const u16 gLinkLevelPosition[2];
extern const u8 gLinkLevelImages[2][4];
extern struct LinkLevel *gLinkLevel;
