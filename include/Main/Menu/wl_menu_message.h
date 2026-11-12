#pragma once

#include "types.h"
#include "Main/Unknown/types_02180728.h"

// Object behind gWLMenuMessage, 0x654 bytes: the halfwords from 0x34 are 32 per row.
typedef struct WLMenuMessage {
    /* 000 */ void *mFont;
    /* 004 */ u8 mCharCanvas[0x20];
    /* 024 */ TextCanvas mTextCanvas;
    /* 034 */ u16 mScreenMap[0x300];
    /* 634 */ void *mCommonMessages;
    /* 638 */ struct Bmg *mMBChildMessages;
    /* 63c */ u8 mUnk_63c[4];
    /* 640 */ s32 mBg3Offset;
    /* 644 */ u8 mUnk_644[8];
    /* 64c */ s32 mState;
    /* 650 */ void *mHeap;
} WLMenuMessage;

void WriteWLMenuMessageRegistersWrapper(void);
void WriteWLMenuMessageRegisters(void);
void WLMenuMessageG2S_SetBG3Offset(u32 offsetX, int offsetY);
void WLMenuMessageGXS_SetVisiblePlane(int bits);
void ReleaseWLMenuMessage(void);
s32 AdvanceWLMenuMessageToMenu(u32 sceneNumbers);
void SetNextScene(unsigned int sceneNumbers, unsigned int nextScene);
void StopSeqZeroLoopWrapper(void);
u32 HasGroupSendMask(void);
s32 AdvanceWLMenuMessageToResult(u32 sceneNumbers);
s32 AdvanceWLMenuMessageToRace(u32 sceneNumbers);
s32 AdvanceWLMenuMBChildMessage(u32 sceneNumbers);
void WLMenuSetMenuEntryKind(unsigned int value);
void WLMenuSetRaceSetupRequested(unsigned int value);
