#pragma once

#include "00/code_02180608.h"
#include "00/code_021acef8.h"
#include "00/code_021ad734.h"
#include "00/code_02186d04.h"
#include "00/code_02187484.h"
#include "00/code_02188008.h"
#include "00/code_021884d8.h"
#include "00/GameSpy/nonport.h"
#include "00/code_021a3a18.h"

#include "types.h"
#include "00/code_021a6fa8.h"

// Settings func_ov000_021a72c4 reads and func_ov000_021a71c0 applies.
typedef struct Unk021b49b8 {
    /* 00 */ s8 field0;
    /* 01 */ s8 field1;
    /* 02 */ u16 field2;
    /* 04 */ u16 field4;
    /* 06 */ u16 field6;
    /* 08 */ u16 field8;
    /* 0a */ u16 fieldA;
    /* 0c */ u16 fieldC;
    /* 0e */ u16 fieldE;
    /* 10 */ Unk021a72a4 field10;
    /* 14 */ Unk021a72a4 field14;
} Unk021b49b8;

// Objects whose layout isn't known yet.
extern u32 data_ov000_021b49b4;
extern Unk021b49b8 data_ov000_021b49b8;
extern Unk021b49b8 data_ov000_021b49d0;
extern char gMatchingSignature[];
extern char gUnsignedFormat[];
extern char gDwcPidKey[];
extern char gDwcEvalKey[];
extern char gDwcMtypeKey[];
extern char gDwcMresvKey[];
extern char gDwcMverKey[];
extern char gVerKey[];
extern u8 gScmKey[];
extern u8 gScnKey[];
extern char data_ov000_021b41f0[];
extern u32 data_ov000_021b49f4;
extern char data_ov000_021b4388[];
extern char data_ov000_021b4394[];
extern char data_ov000_021b43a0[];
extern char data_ov000_021b43a8[];
extern char data_ov000_021b43ac[];
extern char data_ov000_021b43b0[];
extern char data_ov000_021b43c0[];
extern char data_ov000_021b43cc[];
extern char data_ov000_021b43d8[];
extern Unk021a3eb0 data_ov000_021b4270;
extern Unk021a4a08 *data_ov000_021b426c;
extern char data_ov000_021b43f8[];
extern char data_ov000_021b4400[];
extern char data_ov000_021b4404[];
extern char data_ov000_021b440c[];
extern char data_ov000_021b4418[];
extern char data_ov000_021b4428[];
extern u8 data_ov000_021b442c[];
extern char data_ov000_021b4464[];
extern char data_ov000_021b43e4[];
extern u8 gSrvrText[];
extern u8 gClntText[];
extern u16 gOfferedValues[2];
extern const char *data_ov000_021b4a30[];
extern u8 gLabelAText[];
extern u8 gLabelBBText[];
extern u8 gLabelCCCText[];
extern u8 data_ov000_021b4be4[];
extern u8 data_ov000_021b4be5[];
extern u8 gWiFiVSCourseSelectState[];
extern Http *gHttp;
extern DWCNetcheck *gNetcheck;
extern Unk02188408 *data_ov000_021b4d00;
extern void *data_ov000_021b4d04;
extern void *data_ov000_021b4d08;
extern Unk02188114 *data_ov000_021b4d0c;
extern Unk021884e4 *data_ov000_021b4d10;
extern struct Hashtable *data_ov000_021b4d18;
extern struct SbServer *data_ov000_021b4d1c;
// Objects behind gWiFiSelectCharacterState and gWiFiSelectKartState.
typedef struct WiFiSelectHeapHolder {
    /* 0 */ void *mHeap;
} WiFiSelectHeapHolder;

extern WiFiSelectHeapHolder *gWiFiSelectCharacterState;
extern WiFiSelectHeapHolder *gWiFiSelectKartState;

// Object behind data_ov000_021b4d24; the 0x5d8 bytes at offset 0x4c of a MatchingServerList.
typedef struct SbServerList {
    /* 000 */ s32 mState;
    /* 004 */ struct Darray *field4;
    /* 008 */ struct Darray *field8;
    /* 00c */ char fieldC[0x24];
    /* 030 */ char field30[0x24];
    /* 054 */ char field54[0x20];
    /* 074 */ s8 field74[8];
    /* 07c */ u8 *mInBuffer;
    /* 080 */ s32 mInBufferLength;
    /* 084 */ char *field84[0xff];
    /* 480 */ s32 field480;
    /* 484 */ s32 field484;
    /* 488 */ UnkFunc *mCallback;
    /* 48c */ UnkFunc *field48C;
    /* 490 */ UnkFunc *field490;
    /* 494 */ void *field494;
    /* 498 */ const char *field498;
    /* 49c */ s32 field49C;
    /* 4a0 */ s32 field4A0;
    /* 4a4 */ u32 field4A4;
    /* 4a8 */ u16 field4A8;
    /* 4aa */ u8 field4AA[2];
    /* 4ac */ char *field4AC;
    /* 4b0 */ s32 field4B0;
    /* 4b4 */ u32 field4B4;
    /* 4b8 */ u32 field4B8;
    /* 4bc */ u8 field4BC[0x108];
    /* 5c4 */ u32 field5C4;
    /* 5c8 */ s32 field5C8;
    /* 5cc */ s32 field5CC;
    /* 5d0 */ int field5D0;
} SbServerList;

extern SbServerList *data_ov000_021b4d24;
extern s32 data_ov000_021b4d28;
extern const char *data_ov000_021b4d20;
extern char data_ov000_021b4d2c[];

// Object behind data_ov000_021b4dac.
typedef struct Unk021b4dac {
    /* 00 */ s32 field0;
    /* 04 */ u8 field4[2];
    /* 06 */ u16 field6;
    /* 08 */ u8 field8[4];
    /* 0c */ u8 fieldC;
    /* 0d */ u8 fieldD[0x3f];
    /* 4c */ s32 field4C;
    /* 50 */ u32 field50;
    /* 54 */ s32 field54;
} Unk021b4dac;

extern Unk021b4dac data_ov000_021b4dac;
extern u8 data_ov000_021b4db0[];
extern u8 data_ov000_021b4db4[];
extern u8 data_ov000_021b4db8[];
extern u8 data_ov000_021b4dbd[];
extern char data_ov000_021b4d6c[];
extern u8 data_ov000_021b4e50[];
extern u8 data_ov000_021b400c[];
extern u8 gEmptyString[];
extern char gFmeKey[];
extern char gMdfKey[];
extern u8 gInitStateString[];
extern u8 gServerFullString[];
extern u8 gUnexpectedConnectAttemptString[];
extern u8 gYString[];
extern u8 gNString[];
extern char gAndEmptyParensString[];
extern char data_ov000_021b3fcc[];
extern char data_ov000_021b3fec[];
extern char data_ov000_021b3ffc[];
extern char data_ov000_021b4004[];
extern char data_ov000_021b4008[];
extern char data_ov000_021b4014[];
extern char data_ov000_021b4030[];
extern char data_ov000_021b404c[];
extern char data_ov000_021b4054[];
extern char data_ov000_021b4058[];
extern char data_ov000_021b4060[];
extern u8 data_ov000_021b4064[];

extern char gGpMessagePrefixFormat[];
extern char gGpcmPrefix[];
extern char gMatTag[];
extern char gSlashUnsignedFormat[];
extern char gMatchingFilterFormat[];
extern char gAndParenFormat[];
extern char gKeyEqualsUnsignedFormat[];

#include "00/code_021a3760.h"
