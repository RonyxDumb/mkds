#pragma once

#include "types.h"
#include "Main/Menu/player_entry_layout_rows.h"

void RequestPlayerEntryListSetup(void);
void SetPlayerEntryListShowAllEntries(s32 showAll);
void SetEntryTeamIndex(int entryIndex, int teamIndex);
void SetPlayerEntryListUseTeams(s32 useTeams);
// Kinds of StartPlayerEntryListKind: the timer slides out (called after the hold wait of the screens), and every entry
// moves to its outer slot and moves back to the inner slot on the next setup (called when a screen is left).
#define PLAYER_ENTRY_LIST_KIND_TIMER_OUT 2
#define PLAYER_ENTRY_LIST_KIND_ENTRIES_OUT 3
void StartPlayerEntryListKind(s32 kind);
u32 IsEveryPlayerKartStored(void);
u32 IsPlayerEntryListTimerZero(void);
void VerifySelectMenuFiles_from_thumb(void);
void WritePlayerEntryListRegisters(void);
void ReleasePlayerEntryList(void);

void AdvancePlayerEntryList(void);

void SetupPlayerEntryList(s32 mode, s32 screenKind);

void AndAnotherAlloc_0_from_thumb(void *parentHeap, void *mainOam);

void PrintEntryName(s32 entryIndex, u16 *name);

void SetExtraEntryNames(void);

void AdvancePlayerEntryListOffsets(void);

void SetEntryTargetOuterSlot(s32 entryIndex);

void SetEntryTargetInnerSlot(s32 entryIndex);

void AdvanceEntrySlots(void);

void ResetEntrySlots(void);

void SetEntryTargetSlot(s32 entryIndex, s32 slot);

void SetEntrySlot(s32 entryIndex, s32 slot);

extern const u16 gTitleCellIndices[4];
extern const u16 gNormalTimerDigitCellIndices[10];
extern const u16 gDownloadTimerDigitCellIndices[10];
extern const u16 gDownloadCharacterCellIndices[14];
extern const u16 gNormalCharacterCellIndices[14];
extern const EntryCellIndices gNormalEntryCellIndices[8];
extern const EntryCellIndices gDownloadEntryCellIndices[8];
extern const EntryLabelTextRow gNormalEntryLabelTextRows[8];
extern const EntryLabelTextRow gDownloadEntryLabelTextRows[8];
extern const s16 gEntrySlotOffsetsX[4];
extern const struct EntryLabelTextRow *gEntryLabelTextRows;
extern const u16 *gCharacterCellIndices;
extern const u16 *gTimerDigitCellIndices;
extern const struct EntryCellIndices *gEntryCellIndices;
extern struct PlayerEntryList *gPlayerEntryList;
