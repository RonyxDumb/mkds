#pragma once

#include "types.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_020d22c0.h"

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
    /* 0b0 */ s32 fieldB0;
    /* 0b4 */ s32 mEntryIndex;
    /* 0b8 */ s32 mPlayerCount;
    /* 0bc */ s32 mShownCourseIds[4];
    /* 0cc */ Interpolation mInterpolations[3];
    /* 0fc */ Interpolation mRowInterpolations[4];
    /* 13c */ s32 mStateFrames; /* counts only in states 3, 4, 5, 6 */
    /* 140 */ s32 mTimer;
    /* 144 */ s32 mCourseId;
    /* 148 */ s32 mCourseMessageIndex;
    /* 14c */ u16 field14C[4];
    /* 154 */ s16 mSubOffsetY;
} WiFiVSCourseSelect;

// 8-byte entries of the tables at gWiFiVSCourseSelectMLabelTextRows and gWiFiVSCourseSelectSLabelTextRows.
typedef struct LabelTextRow {
    /* 00 */ s16 mLabelIndex;
    /* 02 */ s16 mWidth;
    /* 04 */ s16 mHeight;
    /* 06 */ s16 mCellIndex;
} LabelTextRow;

extern char aCommon_bmg_15[];
extern char aWifi_bmg[];
extern char aWifi_vs_cou_11[];
extern char aWifi_vs_cou_12[];
extern char aWifi_vs_cou_13[];
extern char aWifi_vs_cou_15[];
extern char aWifi_vs_cou_14[];
extern char aWifi_vs_cou_16[];
extern char aWifi_vs_cou_17[];
extern char aWifi_vs_cou_18[];
extern char aWifi_vs_cou_19[];
extern char aWifi_vs_cou_20[];
extern char aWifi_vs_cou_21[];
extern char aWifi_vs_cou_22[];
extern char aWifi_vs_cou_23[];
extern char aWifi_vs_cou_24[];
extern char aWifi_vs_cou_25[];
extern char aWifi_vs_cou_26[];
extern char aWifi_vs_cou_27[];

s32 AdvanceWiFiVSCourseSelect(void);
void InitWiFiVSCourseSelect(void *parentHeap, void *mainOam, void *subOam);

extern u16 gCourseRowCellIndices[];
extern u16 gCourseTimerDigitCellIndices[];
extern LabelTextRow gWiFiVSCourseSelectMLabelTextRows[];
extern LabelTextRow gWiFiVSCourseSelectSLabelTextRows[];
extern s32 WifiCourseOrder[];

void WriteWiFiVSCourseSelectRegisters(void);
void ReleaseWiFiVSCourseSelect(void);
s32 PickRandomCourseIndexNotRaced(void);
void AdvanceWiFiVSCourseSelectTimer(void);
void AdvancePickedCourseRows(void);
void AdvanceSubCellsOffsetY(void);
void ShowWiFiSessionCourse(void);
void func_0202b3f4(void);
void RefreshCourseListRows(s32 action, s32 slot, s32 row, s32 selectedSlot);
void WriteKartPositionAndCount(s32 position, s32 kartCount);
