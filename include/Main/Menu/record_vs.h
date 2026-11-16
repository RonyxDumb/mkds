#pragma once

#include "types.h"

void SetRecordSceneIndex(u32 index);
void SetRecordScenePageIndex(u32 pageIndex);
u32 GetRecordSceneIndex(void);
u32 GetRecordScenePageIndex(void);

void AdvanceRecordSceneRegistersTimer(void);

void SetRecordNextScene(unsigned int scene);
unsigned int GetRecordNextScene(void);
unsigned int GetRecordPrevScene(void);
unsigned int GetRecordPrevScreen(void);

void RequestRecordScreen(s32 screen);

// Values of RecordScene.mScreen, mNextScreen and mPrevScreen: the five screens, then the two non-screen values.
enum {
    RECORD_SCREEN_TOP_MENU,
    RECORD_SCREEN_GPX,
    RECORD_SCREEN_TIME_ATTACK,
    RECORD_SCREEN_VS,
    RECORD_SCREEN_VS_ERASE,
    RECORD_SCREEN_START,
    RECORD_SCREEN_OUTSIDE,
};
#define RECORD_SCREEN_NONE (-1)

// The Record scene object: runs one of the five Record screens at a time and switches between them on request.
typedef struct RecordScreenCallbacks {
    /* 00 */ void (*mInit)(void *);
    /* 04 */ void (*mRelease)(void);
    /* 08 */ void (*mAdvance)(void);
    /* 0c */ void (*mWriteOffsets)(void);
    /* 10 */ void (*mWriteRegisters)(void);
} RecordScreenCallbacks;

// Frames after the scene starts or a screen switches before the screen's register writer runs; mRegistersTimer counts
// down from this.
#define RECORD_REGISTERS_DELAY_FRAMES 2

// The record scene: its heaps, current, next and previous screens, previous and next scenes, the running screen's
// callbacks, and the page and entry index.
typedef struct RecordScene {
    /* 00 */ void *mHeap;
    /* 04 */ void *mStateHeap;
    /* 08 */ s32 mScreen;
    /* 0c */ s32 mNextScreen;
    /* 10 */ s32 mPrevScreen;
    /* 14 */ s16 mPrevScene;
    /* 16 */ s16 mNextScene;
    /* 18 */ RecordScreenCallbacks mScreenCallbacks;
    /* 2c */ s32 mRegistersTimer;
    /* 30 */ s16 mPageIndex;
    /* 32 */ s16 mIndex;
} RecordScene;

void AdvanceRecordScene(void);

void SetRecordScreenCallbacks(const RecordScreenCallbacks *callbacks);

void WriteRecordSceneRegisters(void);

void ReleaseRecordSceneObject(void);

void InitRecordSceneObject(void *heap, s16 previousScene);

void LoadRecordSceneData(void);

void WriteRecordVSRegisters(void);
void RegisterRecordVSCallbacks(void);
void ClearRecordScreenCallbacksKeepRegisters(void);

void WriteRecordVSBgOffsets(void);

void AdvanceRecordVSBrowse(void);
void AdvanceRecordVSPageSlideOut(void);
void AdvanceRecordVSPageSlideIn(void);
void AdvanceRecordVSSubSlideOut(void);
void AdvanceRecordVSMainSlideOut(void);
void AdvanceRecordVSPressButton(void);
void AdvanceRecordVSSubSlideOutRequestScreen(void);
void AdvanceRecordVSSubSlideIn(void);
void AdvanceRecordVS(void);

void AdvanceRecordVSWaitReturnButton(void);

void AdvanceRecordVSSlideInMain(void);
void AdvanceRecordVSSlideInSub(void);

void AdvanceRecordVSWaitFade(void);

extern char *gRecordVSMTransientBnclName;
extern const u16 gRecordVSGridLabelIndices[3][3];
extern const u16 gRecordVSPageButtonIndices[2];
extern const s16 gRecordVSRectRowIndices[10];
extern const u16 gRecordVSFriendKeyLabelHeights[12];
extern const u16 gRecordVSRowLabelIndices[6];
extern const u16 gRecordVSRowLabelWidths[6];
extern char *gRecordVSMBnclName;
extern char *gRecordVSMNscrName;
extern char *gRecordVSMBNclrName;
extern char *gRecordVSSONclrName;
extern char *gRecordVSM03NscrName;
extern const u16 gRecordVSFriendKeyLabelWidths[12];
extern const u16 gRecordVSUnhighlightedObjectIndices[6];
extern const u16 gRecordVSHighlightObjectIndices[6];
extern char *gRecordVSMNcgrName;
extern const u16 gRecordVSUnflaggedObjectIndices[6];
extern char *gRecordVSSBnclName;
extern char *gRecordVSMONclrName;
extern char *gRecordVSSNcerName;
extern const u16 gRecordVSGridLabelWidths[3][3];
extern const u16 gRecordVSFriendKeyLabelIndices[12];
extern char *gRecordVSSBnblName;
extern const u16 gRecordVSPageButtonPressedIndices[2];
extern const u16 gRecordVSRowLabelHeights[6];
extern char *gRecordVSSBnllName;
extern const u16 gRecordVSGridLabelHeights[3][3];
extern const u16 gRecordVSFlaggedObjectIndices[6];
extern char *gRecordVSSNcgrName;
extern char *gRecordVSMTransientBnllName;
extern const u16 gRecordVSGridRow0MessageIndices[4];
extern char *gRecordVSM02NscrName;
extern char *gRecordVSMNcerName;
extern char *gRecordVSMBNcgrName;
extern char *gRecordVSMBnllName;
extern struct RecordScene *gRecordScene;
