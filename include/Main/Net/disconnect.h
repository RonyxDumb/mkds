#pragma once

#include "types.h"

// 0x18-byte object whose first halfword selects what ProcessMPData does with the rest.
typedef struct MPMessage {
    /* 00 */ u16 mKind;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 mUnk_08[2];
    /* 0a */ u8 mUnk_0a;
    /* 0b */ u8 mUnk_0b[0xb];
    /* 16 */ u8 mUnk_16;
    /* 17 */ u8 mUnk_17;
} MPMessage;

typedef struct MPKindWordMessage {
    /* 00 */ u16 mKind;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ s32 mWord;
} MPKindWordMessage;

typedef struct MPPlayerBitsMessage {
    /* 00 */ u16 mKind;
    /* 02 */ u8 mBits[4];
    /* 06 */ u8 mUnk_06[4];
    /* 0a */ u8 mPlayerIndex;
    /* 0b */ u8 mUnk_0b[7];
} MPPlayerBitsMessage;

typedef struct MPPlayerNameMessage {
    /* 00 */ u16 mKind;
    /* 02 */ u8 mName[0x14];
    /* 16 */ u8 mPlayerIndex;
    /* 17 */ u8 mConnectedMask;
} MPPlayerNameMessage;

#include "Main/MapObjects/data_02165000.h" // QueueMPDataToPortParams
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "code_02142eac.h" // Unk021425e8

typedef struct PlayerRecord PlayerRecord;

void QueueMPDataToPortCallback(void);
BOOL QueueMPDataHalfwordAndWord(s32 kind, u16 destBitmap, s32 word);
BOOL QueueMPDataPlayerBits(s32 playerIndex, u16 destBitmap);
BOOL QueueMPDataPlayerName(s32 playerIndex, u16 destBitmap);
BOOL QueueMPDataHalfword(s32 kind, u16 destBitmap);
BOOL QueueMPDataToPort(void *data, s32 dataSize, u16 destBitmap, void *sendBuffer, QueueMPDataToPortParams *params);
void MPDataPortCallback(Unk021425e8 *event);
void ProcessMPData(u32 aid, MPMessage *message);
void RemoveChild(u32 aid);
void AddChild(u32 aid, u8 *bytes, PlayerRecord *playerEntry);
void SetRequestErrorCode(s32 errorCode);
void EndCallback(Unk021425e8 *event);
void End(void);
void SetStepAndRequestPending(s32 step);
BOOL ConnectionMB_IsMultiBootChild(void);
s32 GetConnectionMode(void);
BOOL IsMultiBootSetupStarted(void);
void DisconnectCallback(Unk021425e8 *event);
void Disconnect(void);
void EndParentCallback(Unk021425e8 *event);
void EndParent(void);
void EndMPCallback(Unk021425e8 *event);
void EndMP(void);
void EndDataSharing(void);
void DisconnectChildrenCallback(Unk021425e8 *event);
void DisconnectChildren(u32 aidBitmap);
