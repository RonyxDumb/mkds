#pragma once

#include "types.h"

extern char gSelectMenuEtcDownloadMBNcgrName[];
extern char gSelectMenuEtcDownloadMNcgrName[];
extern char gSelectMenuEtcDownloadMNcerName[];
extern char gSelectMenuEtcDownloadMONclrName[];
extern char gSelectMenuEtcDownloadMBNclrName[];
extern char gSelectMenuEtcDownloadMBg00NscrName[];
extern char gSelectMenuEtcDownloadMBg01NscrName[];
extern char gSelectMenuEtcMBNcgrName[];
extern char gSelectMenuEtcMNcgrName[];
extern char gSelectMenuEtcTitleMNcgrName[];
extern char gSelectMenuEtcMNcerName[];
extern char gSelectMenuEtcTitleMNcerName[];
extern char gSelectMenuEtcMONclrName[];
extern char gSelectMenuEtcMBNclrName[];
extern char gSelectMenuEtcMBg00NscrName[];
extern char gSelectMenuEtcMBg01NscrName[];

void RequestPlayerEntryListSetup(void);
void SetPlayerEntryListShowAllEntries(s32 showAll);
void SetEntryTeamIndex(int entryIndex, int teamIndex);
void SetPlayerEntryListUseTeams(s32 useTeams);
void StartPlayerEntryListKind(s32 kind);
u32 IsEveryPlayerKartStored(void);
u32 IsPlayerEntryListTimerZero(void);
void LoadPlayerEntryListFiles(void);
void WritePlayerEntryListRegisters(void);
void ReleasePlayerEntryList(void);

void AdvancePlayerEntryList(void);

void SetupPlayerEntryList(s32 mode, s32 screenKind);

void InitPlayerEntryList(void *parentHeap, void *mainOam);

void PrintEntryName(s32 entryIndex, u16 *name);

void SetExtraEntryNames(void);

void AdvancePlayerEntryListOffsets(void);

void SetEntryTargetOuterSlot(s32 entryIndex);

void SetEntryTargetInnerSlot(s32 entryIndex);

void AdvanceEntrySlots(void);

void ResetEntrySlots(void);

void SetEntryTargetSlot(s32 entryIndex, s32 slot);

void SetEntrySlot(s32 entryIndex, s32 slot);
