#pragma once

#include "types.h"

typedef struct CellFileSet CellFileSet;
typedef struct PlayerEntryList PlayerEntryList;

// 6-byte elements of the table behind gEntryCellIndices: three indices into the arrays at member 0x18 of
// CellFileSet.
typedef struct EntryCellIndices {
    /* 00 */ u16 field0;
    /* 02 */ u16 mCharacterCellIndex;
    /* 04 */ u16 mKartCellIndex;
} EntryCellIndices;

// 8-byte elements of the table behind gEntryLabelTextRows.
typedef struct EntryLabelTextRow {
    /* 00 */ s16 field0;
    /* 02 */ u8 field2[6];
} EntryLabelTextRow;

// What the first member of PlayerEntryList points to.
typedef struct Unk02174e3c_00 {
    /* 00 */ u8 field0[0x10];
    /* 10 */ u32 field10;
    /* 14 */ void *field14;
} Unk02174e3c_00;

extern u16 gTitleCellIndices[];
extern s16 gEntrySlotOffsetsX[];
extern u16 a012345678[];
extern u16 a_01234567[];
extern u16 gDownloadCharacterCellIndices[];
extern u16 gNormalCharacterCellIndices[];
extern EntryCellIndices gNormalEntryCellIndices[];
extern EntryCellIndices gDownloadEntryCellIndices[];
extern EntryLabelTextRow gNormalEntryLabelTextRows[];
extern EntryLabelTextRow gDownloadEntryLabelTextRows[];
extern const char aMbSelect_menu_etc_download_m_b_ncgr[];
extern const char aMbSelect_menu_etc_download_m_b_nclr[];
extern const char aMbSelect_menu_etc_download_m_bg_00_ns[];
extern const char aMbSelect_menu_etc_download_m_b_ncgr_0[];
extern const char aMbSelect_menu_etc_download_m_b_nclr_0[];
extern const char aMbSelect_menu_etc_download_m_bg_01__0[];
extern const char aSelect_menu_etc_m_b_ncgr_0[];
extern const char aSelect_menu_etc_m_b_nclr_0[];
extern const char aSelect_menu_etc_m_bg_00_nscr_0[];
extern const char aSelect_menu_etc_m_b_ncgr_1[];
extern const char aSelect_menu_etc_m_b_nclr_1[];
extern const char aSelect_menu_etc_m_bg_01_nscr_0[];
extern const char aMbSelect_menu_etc_download_m_nce_ncgr[];
extern const char aMbSelect_menu_etc_download_m_nce_ncer[];
extern const char aMbSelect_menu_etc_download_m_o_nclr[];
extern const char aMbSelect_menu_etc_download_m_bncl[];
extern const char aMbSelect_menu_etc_download_m_bnll[];
extern const char aSelect_menu_etc_m_nce_ncgr_0[];
extern const char aSelect_menu_etc_m_nce_ncer_0[];
extern const char aSelect_menu_etc_m_o_nclr_0[];
extern const char aSelect_menu_etc_m_bncl[];
extern const char aSelect_menu_etc_m_bnll[];
extern const char aSelect_menu_etc_title_m_nce_ncgr_0[];
extern const char aSelect_menu_etc_title_m_nce_ncer_0[];
extern const char aSelect_menu_etc_title_m_bncl[];
extern const char aCommon_bmg_29[];
extern EntryCellIndices *gEntryCellIndices;
extern u16 *gCharacterCellIndices;
extern EntryLabelTextRow *gEntryLabelTextRows;
extern u16 *gTimerDigitCellIndices;

void AdvancePlayerEntryList(void);
void SetupPlayerEntryList(s32 mode, s32 screenKind);
void InitPlayerEntryList(void *parentHeap, void *mainOam);
void PrintEntryName(s32 entryIndex, u16 *name);
void func_0202c8dc(void);
void AdvancePlayerEntryListOffsets(void);
void func_0202cb2c(s32 entryIndex);
void func_0202cb68(s32 entryIndex);
void AdvanceEntrySlots(void);
void ResetEntrySlots(void);
void SetEntryTargetSlot(s32 entryIndex, s32 slot);
void SetEntrySlot(s32 entryIndex, s32 slot);
