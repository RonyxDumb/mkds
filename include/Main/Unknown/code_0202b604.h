#pragma once

#include "types.h"

extern char aMbSelect_menu_[];
extern char aMbSelect_men_0[];
extern char aMbSelect_men_1[];
extern char aMbSelect_men_2[];
extern char aMbSelect_men_3[];
extern char aMbSelect_men_4[];
extern char aMbSelect_menu_etc_download_m_bg_01_ns[];
extern char aSelect_menu_etc_m_b_ncgr[];
extern char aSelect_menu_etc_m_nce_ncgr[];
extern char aSelect_menu_etc_title_m_nce_ncgr[];
extern char aSelect_menu_etc_m_nce_ncer[];
extern char aSelect_menu_etc_title_m_nce_ncer[];
extern char aSelect_menu_etc_m_o_nclr[];
extern char aSelect_menu_etc_m_b_nclr[];
extern char aSelect_menu_etc_m_bg_00_nscr[];
extern char aSelect_menu_etc_m_bg_01_nscr[];

void RequestPlayerEntryListSetup(void);
void func_0202b618(s32 a);
void SetEntryTeamIndex(int entryIndex, int teamIndex);
void SetPlayerEntryListUseTeams(s32 useTeams);
void func_0202b7c0(s32 kind);
u32 IsEveryPlayerKartStored(void);
u32 IsPlayerEntryListTimerZero(void);
void LoadPlayerEntryListFiles(void);
void WritePlayerEntryListRegisters(void);
void ReleasePlayerEntryList(void);
