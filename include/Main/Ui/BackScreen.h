#pragma once

#include "types.h"

void gmenu_vblank(void);
void gmenu_render(void);

extern const char *gBackScreenSNclrNames[1];
extern const char *gBackScreenSNcgrNames[1];
extern const char *gBackScreenSNscrNames[1];
extern const char *gBackScreenMNscrNames[2];
extern const char *gBackScreenMNcgrNames[2];
extern const char *gBackScreenMNclrNames[2];

void gmenu_unpackData(void);
void gmenu_setupHWForBackground(void);
s32 gmenu_loadBackground(s32 subCharOffset);

void gmenu_finish(void);
