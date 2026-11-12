#pragma once
#include "types.h"
#include "Main/Menu/data_02174000.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "code_02022aa8.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "tp.h"
#include "Main/Save/buddy_record_time.h"
#include "g2d_CellTransferManager.h"
#include "Main/MapObjects/map_object_park.h"

// Object behind gWiFiVSCourseSelect, 0x158 bytes (InitWiFiVSCourseSelect allocates it).
typedef struct WiFiVSCourseSelect {
    /* 000 */ ScreenMapFileSet mWiFiVSCourseSelectMBAndSBParts[2];
    // mWiFiVSCourseSelectMParts and mWiFiVSCourseSelectSParts are also walked as a two-element array from the M one.
    /* 048 */ CellFileSet mWiFiVSCourseSelectMParts;
    /* 064 */ CellFileSet mWiFiVSCourseSelectSParts;
    /* 080 */ void *mOamLists[2];
    /* 088 */ struct Bmg *mCommonMessages;
    /* 08c */ struct Bmg *mWiFiMessages;
    /* 090 */ void *mHeap;
    /* 094 */ RandomState64 mRandom;
    /* 0ac */ s32 mState;
    /* 0b0 */ s32 mUnk_0b0;
    /* 0b4 */ s32 mEntryIndex;
    /* 0b8 */ s32 mPlayerCount;
    /* 0bc */ s32 mShownCourseIds[4];
    /* 0cc */ Interpolation mInterpolations[3];
    /* 0fc */ Interpolation mRowInterpolations[4];
    /* 13c */ s32 mStateFrames; /* counts only in states 3, 4, 5, 6 */
    /* 140 */ s32 mTimer;
    /* 144 */ s32 mCourseId;
    /* 148 */ s32 mCourseMessageIndex;
    /* 14c */ u16 mUnk_14c[4];
    /* 154 */ s16 mSubOffsetY;
} WiFiVSCourseSelect;

// 8-byte entries of the tables at gWiFiVSCourseSelectMLabelTextRows and gWiFiVSCourseSelectSLabelTextRows.
typedef struct LabelTextRow {
    /* 00 */ s16 mLabelIndex;
    /* 02 */ s16 mWidth;
    /* 04 */ s16 mHeight;
    /* 06 */ s16 mCellIndex;
} LabelTextRow;

extern char gCommonBmgName3[];

extern char gWiFiBmgName[];

extern char gWiFiVSCourseSelectMBNcgrName[];

extern char gWiFiVSCourseSelectMBNclrName[];

extern char gWiFiVSCourseSelectMNscrName[];

extern char gWiFiVSCourseSelectMNcgrName[];

extern char gWiFiVSCourseSelectMNcerName[];

extern char gWiFiVSCourseSelectMONclrName[];

extern char gWiFiVSCourseSelectMBnclName[];

extern char gWiFiVSCourseSelectMBnllName[];

extern char gWiFiVSCourseSelectSBNcgrName[];

extern char gWiFiVSCourseSelectSBNclrName[];

extern char gWiFiVSCourseSelectSNscrName[];

extern char gWiFiVSCourseSelectSNcgrName[];

extern char gWiFiVSCourseSelectSNcerName[];

extern char gWiFiVSCourseSelectSONclrName[];

extern char gWiFiVSCourseSelectSBnclName[];

extern char gWiFiVSCourseSelectSBnllName[];

extern char gWiFiVSCourseSelectSBnblName[];

extern u16 gCourseRowCellIndices[];

extern u16 gCourseTimerDigitCellIndices[];

extern LabelTextRow gWiFiVSCourseSelectMLabelTextRows[];

extern LabelTextRow gWiFiVSCourseSelectSLabelTextRows[];

extern s32 gCourseIdTable[];
