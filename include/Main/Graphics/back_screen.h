#pragma once

#include "types.h"

extern const char *gBackScreenSNclrNames[1];
extern const char *gBackScreenSNcgrNames[1];
extern const char *gBackScreenSNscrNames[1];
extern const char *gBackScreenMNscrNames[2];
extern const char *gBackScreenMNcgrNames[2];
extern const char *gBackScreenMNclrNames[2];

extern char gBackScreenSNclr00Name[];
extern char gBackScreenSNcgr00Name[];
extern char gBackScreenSNscrBg00Name[];
extern char gBackScreenMNscrBg00Name[];
extern char gBackScreenMNscrBg01Name[];
extern char gBackScreenMNcgr00Name[];
extern char gBackScreenMNcgr01Name[];
extern char gBackScreenMNclr00Name[];
extern char gBackScreenMNclr01Name[];

void LoadTxtSystemAndSelectFiles(void);
void InitBackScreenDisplay(void);
s32 LoadBackScreen(s32 subCharOffset);
