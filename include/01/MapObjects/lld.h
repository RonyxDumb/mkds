#pragma once

#include "types.h"
#include "01/Menu/emblem_state_and_lld.h"
#include "01/Menu/emblem_button_entries.h"
#include "01/MapObjects/mission_run_map_object.h" // MissionRunMapObject

// Data that CreateLld gets for the name it is given.
typedef struct LldRecord {
    /* 0 */ u16 mAnimIndex;
    /* 2 */ u16 mPosX;
    /* 4 */ u16 mPosY;
    /* 6 */ u16 mShowMode;
} LldRecord;

// The records of a Lld file: the entry count and one animation index, position and show mode per entry.
typedef struct LldData {
    /* 00 */ u16 mEntryCount;
    /* 02 */ LldRecord mRecords[1];
} LldData;

// Group of 0x20 bytes at OamBuffer.mOams.
typedef struct OamAffineGroup {
    /* 00 */ u8 mUnk_00[0x6];
    /* 06 */ s16 mPA;
    /* 08 */ u8 mUnk_08[0x6];
    /* 0e */ s16 mPB;
    /* 10 */ u8 mUnk_10[0x6];
    /* 16 */ s16 mPC;
    /* 18 */ u8 mUnk_18[0x6];
    /* 1e */ s16 mPD;
} OamAffineGroup;

void StartDonketuStepSoundSecond(MissionRunMapObject *mapObject);
void StartDonketuStepSoundFirst(MissionRunMapObject *mapObject);
void SetLldEntryBounds(LldEntry *entry, s32 left, s32 top, s32 right, s32 bottom);
s32 GetLldEntryScale(LldEntry *entry);
void SetLldEntryScale(LldEntry *entry, s32 scale);
s32 GetLldEntryY(LldEntry *entry);
s32 GetLldEntryX(LldEntry *entry);
void SetLldEntryPos(LldEntry *entry, s32 screenX, s32 screenY);
s32 GetLldEntryFrameIndex(LldEntry *entry);
void ApplyLldEntryFrameCommand(LldEntry *entry, s32 frameOrCommand);
void SetLldEntryCallback(LldEntry *entry, s32 (*callback)(LldEntry *));
s32 FindLldEntryAtPoint(Lld *lld, s32 startIndex, s32 pointX, s32 pointY);
LldEntry *GetLldEntry(Lld *lld, s32 index);
void AdvanceLld(Lld *lld, OamBuffer *oamBuffer);
Lld *CreateLld(const char *fileName, void *cells, void *cellAnims);

#include "01/Menu/mission_run_boss_icon.h"
