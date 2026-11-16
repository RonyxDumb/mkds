#pragma once

#include "types.h"

// 0x18-byte object whose first halfword selects what ProcessMPData does with the rest.
typedef struct MPMessage {
    /* 00 */ u16 mKind;
    /* 02 */ u8 field2[2];
    /* 04 */ s32 field4;
    /* 08 */ u8 field8[2];
    /* 0a */ u8 fieldA;
    /* 0b */ u8 fieldB[0xb];
    /* 16 */ u8 field16;
    /* 17 */ u8 field17;
} MPMessage;

typedef struct Unk02050320 {
    /* 00 */ u16 field0;
    /* 02 */ u8 field2[2];
    /* 04 */ s32 field4;
} Unk02050320;

typedef struct Unk020503cc {
    /* 00 */ u16 field0;
    /* 02 */ u8 field2[4];
    /* 06 */ u8 field6[4];
    /* 0a */ u8 fieldA;
    /* 0b */ u8 fieldB[7];
} Unk020503cc;

typedef struct Unk020504a4 {
    /* 00 */ u16 field0;
    /* 02 */ u8 field2[0x14];
    /* 16 */ u8 field16;
    /* 17 */ u8 field17;
} Unk020504a4;

#include "Main/Unknown/unk_02165000.h" // QueueMPDataToPortParams
#include "code_02142eac.h" // Unk021425e8

typedef struct Unk0217aa00_45c Unk0217aa00_45c;

u32 QueueMPDataToPortCallback(void);
BOOL QueueMPDataHalfwordAndWord(s32 kind, u16 destBitmap, s32 word);
BOOL func_020503cc(s32 playerIndex, u16 destBitmap);
BOOL sub_20504A4(s32 playerIndex, u16 destBitmap);
BOOL QueueMPDataHalfword(s32 kind, u16 destBitmap);
BOOL QueueMPDataToPort(void *data, s32 dataSize, u16 destBitmap, void *sendBuffer, QueueMPDataToPortParams *params);
void MPDataPortCallback(Unk021425e8 *event);
void ProcessMPData(u32 aid, MPMessage *message);
void RemoveChild(u32 aid);
void AddChild(u32 aid, u8 *b, Unk0217aa00_45c *playerEntry);
void sub_2050E60(s32 a);
void EndCallback(Unk021425e8 *event);
void End(void);
void SetStepAndRequestPending(s32 a);
BOOL sub_20510AC(void);
s32 sub_20510C8(void);
BOOL sub_20510E4(void);
void DisconnectCallback(Unk021425e8 *event);
void Disconnect(void);
void EndParentCallback(Unk021425e8 *event);
void EndParent(void);
void EndMPCallback(Unk021425e8 *event);
void EndMP(void);
void EndDataSharing(void);
void DisconnectChildrenCallback(Unk021425e8 *event);
void DisconnectChildren(u32 aidBitmap);
