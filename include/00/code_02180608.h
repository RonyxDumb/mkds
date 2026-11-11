#pragma once

#include "types.h"

// Four callbacks of a WiFi state: mInit gets WiFiStates.mStateHeap, mAdvance runs every frame.
typedef struct WiFiStateCallbacks {
    /* 00 */ void (*mInit)(void *);
    /* 04 */ void (*mRelease)(void);
    /* 08 */ void (*mAdvance)(void);
    /* 0c */ void (*mWriteRegisters)(void);
} WiFiStateCallbacks;

typedef struct WiFiStates {
    /* 00 */ void *mHeap;
    /* 04 */ void *mStateHeap;
    /* 08 */ u32 mState;
    /* 0c */ s32 mNextState;
    /* 10 */ u32 mPrevState;
    /* 14 */ s32 mUnk_14;
    // Scene number the WiFi screens ask for (-1 = none); UpdateWiFiMenuScene copies it to SceneNumbers.mNextScene.
    /* 18 */ s16 mNextScene;
    /* 1a */ u8 pad_1a[2];
    /* 1c */ WiFiStateCallbacks mCallbacks;
    /* 2c */ void *mUnk_2c;
    /* 30 */ u32 mWiFiVSSettingIndex;
    /* 34 */ s32 mTimeLimitDisabled;
    /* 38 */ u8 pad_38[4];
} WiFiStates;

extern WiFiStates *gWiFiStates;

BOOL IsWiFiSessionOffOutsideLogin(void);
void SetWiFiVSSettingFlag(s32 flag);
s32 GetWiFiVSSettingFlag(void);
void SetWiFiVSSettingIndex(unsigned int settingIndex);
unsigned int GetWiFiVSSettingIndex(void);
u32 LookupWiFiVSSettingMessageIndex(u32 settingIndex);
u32 IsWiFiStatesCounterNotNegative(void);
void SetWiFiNextScene(unsigned int nextScene);
unsigned int GetWiFiNextScene(void);
s32 GetWiFiPrevState(void);
void RequestWiFiState(s32 nextState);
void SetWiFiStateCallbacks(const WiFiStateCallbacks *callbacks);
void WriteWiFiStatesRegisters(void);
void AdvanceWiFiStates(void);
void InitWiFiStates(void *heap, s32 sceneNumber);
void LoadWiFiMenuSceneData(void);
void ClearWiFiStateCallbacks(void);
