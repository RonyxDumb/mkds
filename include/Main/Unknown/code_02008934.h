#pragma once

#include "types.h"

// One 0x590-byte entry of the table in EntryTable.
typedef struct EntryRecord {
    /* 000 */ u8 field0[0x220];
    /* 220 */ u8 field220[0x138];
    /* 358 */ u8 field358;
    /* 359 */ u8 field359;
    /* 35a */ u16 field35A;
    /* 35c */ u16 field35C;
    /* 35e */ u8 field35E[0x14a];
    /* 4a8 */ u8 field4A8[8];
    /* 4b0 */ u8 field4B0[2];
    /* 4b2 */ u8 field4B2;
    /* 4b3 */ u8 field4B3;
    /* 4b4 */ u8 field4B4;
    /* 4b5 */ u8 field4B5;
    /* 4b6 */ u8 field4B6[2];
    /* 4b8 */ u32 field4B8;
    /* 4bc */ u8 field4BC[4];
    /* 4c0 */ u8 mScanBuffer[4];
    /* 4c4 */ u8 mBssid[6];
    /* 4ca */ u8 field4CA[0x3e];
    /* 508 */ u16 field508;
    /* 50a */ u8 field50A[0x76];
    /* 580 */ u32 field580;
    /* 584 */ u32 field584;
    /* 588 */ u16 field588;
    /* 58a */ s16 mTimer;
    /* 58c */ u16 field58C;
    /* 58e */ u8 mLastSequence;
    /* 58f */ u8 mSequenceRepeats;
} EntryRecord;

// Object behind gEntryTable: sixteen entries from 0x10 on.
typedef struct EntryTable {
    /* 00 */ u16 mUsedMask;
    /* 02 */ u16 field2;
    /* 04 */ u16 field4;
    /* 06 */ u16 field6;
    /* 08 */ s16 field8;
    /* 0a */ s16 fieldA;
    /* 0c */ u16 fieldC;
    /* 0e */ u16 fieldE;
    /* 10 */ EntryRecord mEntries[16];
} EntryTable;

// Element of the array at 0x10 in Unk0216fc1c.
typedef struct Unk0216fc1c_10 {
    /* 00 */ u8 field0 : 4;
    /* 00 */ u8 field0_4 : 4;
    /* 01 */ u8 field1[0x15];
} Unk0216fc1c_10;

// Object behind gReceivedGameInfo.
typedef struct Unk0216fc1c {
    /* 00 */ u32 field0;
    /* 04 */ u8 field4 : 2;
    /* 04 */ u8 field4_2 : 6;
    /* 05 */ u8 field5;
    /* 06 */ u8 field6;
    /* 07 */ u8 mSequence;
    /* 08 */ u8 mChecksum[2];
    /* 0a */ u8 fieldA;
    /* 0b */ u8 fieldB;
    /* 0c */ u16 fieldC;
    /* 0e */ u16 fieldE;
    /* 10 */ Unk0216fc1c_10 field10[4];
    /* 68 */ u8 field68[8];
} Unk0216fc1c;

typedef void (*EntryCallbackFunc)(u32 a, void *b, u32 c);

extern EntryTable *gEntryTable;
extern Unk0216fc1c *gReceivedGameInfo;

EntryRecord *MB_GetGameInfoRecvList();
void func_0200895c(u32 entryIndex);
void ClearEntry(u32 entryIndex);
void ClearScanBssid(void);
void SetScanBssidFromEntry(u32 entryIndex);
void func_02008aa0(u32 entryIndex);
void func_02008c08(u32 entryIndex);
void ExpireEntriesWithBssid(const u8 *bssid);
void func_02008d30(u32 entryIndex);
void func_02008d68(u32 entryIndex);
