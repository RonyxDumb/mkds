#pragma once

#include "types.h"

// Values of MPMessage.mKind (the first halfword of every message ProcessMPData receives).
#define MP_MESSAGE_PARTICIPANT_MASK 1
#define MP_MESSAGE_GROUP_SEND_MASK 2
#define MP_MESSAGE_SYNC_NOT_DONE 3
#define MP_MESSAGE_SYNC_DONE 4
#define MP_MESSAGE_TRANSFER_SYNC_DONE 5
#define MP_MESSAGE_PLAYER_NAME 6
#define MP_MESSAGE_REMOVE_CHILDREN 7
#define MP_MESSAGE_RACE_SEED 8
#define MP_MESSAGE_PLAYER_BITS 9

// Smallest and largest length of a message the MP data port accepts: the kind halfword alone, and a whole MPMessage.
#define MP_MESSAGE_MIN_LENGTH 2
#define MP_MESSAGE_MAX_LENGTH 0x18

// 0x18-byte object whose first halfword selects what ProcessMPData does with the rest.
typedef struct MPMessage {
    /* 00 */ u16 mKind;
    /* 02 */ u8 mBitsOrName[2];
    /* 04 */ s32 mWord;
    /* 08 */ u8 mUnk_08[2];
    /* 0a */ u8 mBitsPlayerIndex;
    /* 0b */ u8 mUnk_0b[0xb];
    /* 16 */ u8 mNamePlayerIndex;
    /* 17 */ u8 mNameConnectedMask;
} MPMessage;

// A multiplayer message with its kind and one word.
typedef struct MPKindWordMessage {
    /* 00 */ u16 mKind;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ s32 mWord;
} MPKindWordMessage;

// A multiplayer message with its kind, a bit mask and a player index.
typedef struct MPPlayerBitsMessage {
    /* 00 */ u16 mKind;
    /* 02 */ u8 mBits[4];
    /* 06 */ u8 mUnk_06[4];
    /* 0a */ u8 mPlayerIndex;
    /* 0b */ u8 mUnk_0b[7];
} MPPlayerBitsMessage;

// A multiplayer message with its kind, a player's name, player index and connected mask.
typedef struct MPPlayerNameMessage {
    /* 00 */ u16 mKind;
    /* 02 */ u8 mName[0x14];
    /* 16 */ u8 mPlayerIndex;
    /* 17 */ u8 mConnectedMask;
} MPPlayerNameMessage;

#include "Main/Kart/kart_effect_param_tables.h" // QueueMPDataToPortParams
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "wireless_link_control.h" // WirelessMessage
#include "Main/Kart/kart_effect_param_tables.h"

typedef struct PlayerRecord PlayerRecord;

void QueueMPDataToPortCallback(void);
BOOL QueueMPDataHalfwordAndWord(s32 kind, u16 destBitmap, s32 word);
BOOL QueueMPDataPlayerBits(u8 playerIndex, u16 destBitmap);
BOOL QueueMPDataPlayerName(s32 playerIndex, u16 destBitmap);
BOOL QueueMPDataHalfword(s32 kind, u16 destBitmap);
BOOL QueueMPDataToPort(void *data, s32 dataSize, u16 destBitmap, void *sendBuffer, QueueMPDataToPortParams *params);
void MPDataPortCallback(void *portMessage);
void ProcessMPData(u32 aid, MPMessage *message);
void RemoveChild(u32 aid);
void AddChild(u32 aid, u8 *bytes, PlayerRecord *playerEntry);
void SetRequestErrorCode(s32 errorCode);
void EndCallback(WirelessMessage *event);
void End(void);
void SetStepAndRequestPending(s32 step);
BOOL ConnectionMB_IsMultiBootChild(void);
s32 GetConnectionMode(void);
BOOL IsMultiBootSetupStarted(void);
void DisconnectCallback(WirelessMessage *event);
void Disconnect(void);
void EndParentCallback(WirelessMessage *event);
void EndParent(void);
void EndMPCallback(WirelessMessage *event);
void EndMP(void);
void EndDataSharing(void);
void DisconnectChildrenCallback(WirelessMessage *event);
void DisconnectChildren(u32 aidBitmap);

extern QueueMPDataToPortParams gMPDataToPortParams;
