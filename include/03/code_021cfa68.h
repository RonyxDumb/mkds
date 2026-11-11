#pragma once

#include "types.h"
#include "code_02142eac.h"
#include "code_021445e0.h"

typedef struct WhWork {
    /* 0000 */ void *mUnk_00;
    /* 0004 */ u16 mUnk_04;
    /* 0006 */ u8 pad_06[2];
    /* 0008 */ u32 mUnk_08;
    /* 000c */ u16 mUnk_0c;
    /* 000e */ u16 mUnk_0e;
    /* 0010 */ u16 mUnk_10;
    /* 0012 */ u16 mUnk_12;
    /* 0014 */ u16 mUnk_14;
    /* 0016 */ u16 mUnk_16;
    /* 0018 */ u16 mUnk_18;
    /* 001a */ u8 pad_1a[0x18];
    /* 0032 */ u16 mUnk_32;
    /* 0034 */ u16 mUnk_34;
    /* 0036 */ u16 mUnk_36;
    /* 0038 */ u8 pad_38[8];
    /* 0040 */ s32 mUnk_40;
    /* 0044 */ u32 mUnk_44;
    /* 0048 */ u32 mUnk_48;
    /* 004c */ s32 (*mUnk_4c)(Unk021425e8 *);
    /* 0050 */ u16 mUnk_50;
    /* 0052 */ u16 mUnk_52;
    /* 0054 */ s32 mUnk_54;
    /* 0058 */ u32 mUnk_58;
    /* 005c */ u16 mUnk_5c;
    /* 005e */ u16 mUnk_5e;
    /* 0060 */ u16 mUnk_60;
    /* 0062 */ u8 pad_62[0x1e];
    /* 0080 */ u8 mUnk_80[0xf00];
    /* 0f80 */ u8 mUnk_f80[0xe0];
    /* 1060 */ u8 mUnk_1060[0x240];
    /* 12a0 */ u32 mUnk_12a0;
    /* 12a4 */ u32 mUnk_12a4;
    /* 12a8 */ u8 pad_12a8[0x100];
    /* 13a8 */ u32 mUnk_13a8;
    /* 13ac */ u32 (*mUnk_13ac)(void *, struct WhWork *);
    /* 13b0 */ u32 mUnk_13b0;
    /* 13b4 */ u8 pad_13b4[0xc];
    /* 13c0 */ u8 mUnk_13c0[0x20];
    /* 13e0 */ WMDataSharingInfo mUnk_13e0;
    /* 1c00 */ WMDataSet mUnk_1c00;
    /* 1e00 */ WMDataSharingInfo mUnk_1e00;
} WhWork;

extern WhWork *gWhWork;

BOOL EndWh(void);
void FinalizeWh(void);
void StartWhResetOrFail(void);
BOOL StepWhDataSharing(void *sendData);
u8 *GetWhSharedDataAddress(u32 aid);
void SetWhConnectCallback(u32 callback);
BOOL StartWhParentConnect(u32 mode, u16 tgid, u16 channel);
void StartWhInitializeCallback(Unk021425e8 *event);
BOOL StartWhInitialize(void);
void WhIndicationCallback(Unk021425e8 *event);
BOOL ClearWhAndInitialize(void);
int PickWhChannel(u16 channelMask);
u16 DecideWhChannel(void);
int StartWhMeasureChannel(Unk021425e8Func callback, u16 channel);
void StartWhMeasureChannelCallback(Unk021425e8 *event);
u32 MeasureNextWhChannel(u16 channel);
BOOL StartWhChannelSearch(void);
u32 GetWhState(void);
u16 GetWhConnectedMask(void);
void SetWhGgid(u32 ggid);
void EndWhCallback(Unk021425e8 *event);
void StartWhResetCallback(Unk021425e8 *event);
BOOL StartWhReset(void);
void DisconnectWhCallback(Unk021425e8 *event);
BOOL DisconnectWh(void);
void EndWhMPBeforeDisconnectCallback(Unk021425e8 *event);
BOOL EndWhMPBeforeDisconnect(void);
BOOL EndActiveWhKeySharing(void);
void EndWhParentCallback(Unk021425e8 *event);
BOOL EndWhParent(void);
void EndWhMPCallback(Unk021425e8 *event);
BOOL EndWhMP(void);
BOOL EndWhKeySharing(void);
BOOL StartWhKeySharing(void);
void StartWhMPCallback(Unk021425e8 *event);
BOOL StartWhMP(void);
void StartWhParentCallback(Unk021425e8 *event);
BOOL StartWhParent(void);
void SetWhWepKeyCallback(Unk021425e8 *event);
BOOL SetWhWepKey(void);
void SetWhParentParameterCallback(Unk021425e8 *event);
BOOL SetWhParentParameter(void);
void SetWhErrorCode(s32 errorCode);
void SetWhState(u32 value);
void InitWhWork(WhWork *work);
