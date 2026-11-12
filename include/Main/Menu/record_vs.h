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

// The Record scene object: runs one of the five Record screens at a time and switches between them on request.
typedef struct RecordScreenCallbacks {
    /* 00 */ void (*mInit)(void *);
    /* 04 */ void (*mRelease)(void);
    /* 08 */ void (*mAdvance)(void);
    /* 0c */ void (*mWriteOffsets)(void);
    /* 10 */ void (*mWriteRegisters)(void);
} RecordScreenCallbacks;

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

void AdvanceRecordVSState4(void);
void AdvanceRecordVSState5(void);
void AdvanceRecordVSState6(void);
void AdvanceRecordVSState7(void);
void AdvanceRecordVSState8(void);
void AdvanceRecordVSState9(void);
void AdvanceRecordVSState10(void);
void AdvanceRecordVSState11(void);
void AdvanceRecordVS(void);

void AdvanceRecordVSState3(void);

void AdvanceRecordVSState1(void);
void AdvanceRecordVSState2(void);

void AdvanceRecordVSState0(void);
