#pragma once

#include "types.h"

extern const char *g_str_back_screen_s_b_00_nclr[1];
extern const char *g_str_back_screen_s_b_00_ncgr[1];
extern const char *g_str_back_screen_s_bg_00_nscr[1];
extern const char *g_str_back_screen_m_b_00_01_nscr[2];
extern const char *g_str_back_screen_m_b_00_01_ncgr[2];
extern const char *g_str_back_screen_m_b_00_01_nclr[2];

extern char gBackScreenSNclr00Name[];
extern char gBackScreenSNcgr00Name[];
extern char gBackScreenSNscrBg00Name[];
extern char gBackScreenMNscrBg00Name[];
extern char gBackScreenMNscrBg01Name[];
extern char gBackScreenMNcgr00Name[];
extern char gBackScreenMNcgr01Name[];
extern char gBackScreenMNclr00Name[];
extern char gBackScreenMNclr01Name[];

void PrepareNavigationContextFiles_from_thumb(void);
void InitBackScreenDisplay(void);
s32 InitializeBackScreen_from_thumb(s32 subCharOffset);
