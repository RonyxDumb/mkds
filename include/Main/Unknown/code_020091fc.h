#pragma once

#include "types.h"
#include "Main/Unknown/code_02007ec4.h"
#include "Main/Unknown/code_02008880.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214cfe4.h"
#include "wm_etc.h"
#include "code_02003be0.h"
#include "fs_file.h"
#include "Main/Unknown/code_02008e10.h"

// Entry of the list that gGameInfoList walks (the lists are chained through field4BC). MB_GetGameInfoRecvList returns one;
// the 0xc0 bytes at 0x4c0 are moved out by MB_FakeGetParentBssDesc.
typedef struct GameInfoEntry {
    /* 000 */ u8 field0[0x220];
    /* 220 */ u8 field220[0x16];
    /* 236 */ u8 field236;
    /* 237 */ u8 field237;
    /* 238 */ u8 field238[0x60];
    /* 298 */ u8 field298[0xc0];
    /* 358 */ u8 field358;
    /* 359 */ u8 field359;
    /* 35a */ u16 field35A;
    /* 35c */ u16 field35C;
    /* 35e */ u8 field35E[0x14a];
    /* 4a8 */ u8 field4A8[8];
    /* 4b0 */ u16 field4B0;
    /* 4b2 */ u8 field4B2;
    /* 4b3 */ u8 field4B3;
    /* 4b4 */ u8 field4B4;
    /* 4b5 */ u8 field4B5;
    /* 4b6 */ u8 field4B6[2];
    /* 4b8 */ u32 field4B8;
    /* 4bc */ struct GameInfoEntry *mNext;
    /* 4c0 */ u8 field4C0[0xc0];
} GameInfoEntry;

// State of the walk over the GameInfoEntry list: the first entry, the current entry, the position in the current
// entry, and five bytes that ResetGameInfoWalk clears.
typedef struct GameInfoList {
    /* 00 */ GameInfoEntry *mFirst;
    /* 04 */ GameInfoEntry *mCurrent;
    /* 08 */ u8 *field8;
    /* 0c */ u8 mState;
    /* 0d */ u8 fieldD;
    /* 0e */ u8 fieldE;
    /* 0f */ u8 fieldF;
    /* 10 */ u8 field10;
    /* 11 */ u8 mNextSequence;
    /* 12 */ u8 field12[2];
} GameInfoList;

// 0x70-byte block that func_020092d0 and func_020094b8 fill and pass to WM_SetGameInfo. The halfword at 0xc and
// the bytes from 0xe have another layout in func_020094b8.
typedef struct GameInfoBlock {
    /* 00 */ u32 field0;
    /* 04 */ union {
        u8 field4;
        struct {
            u8 field4_0 : 2;
            u8 field4_2 : 6;
        };
    };
    /* 05 */ u8 field5;
    /* 06 */ u8 field6;
    /* 07 */ u8 mSequence;
    /* 08 */ u16 mChecksum;
    /* 0a */ u8 fieldA;
    /* 0b */ u8 fieldB;
    /* 0c */ union {
        u16 fieldC;
        u8 mUnk_0c_b;
    };
    /* 0e */ u16 fieldE;
    /* 10 */ u8 field10[0x58];
    /* 68 */ u8 field68[8];
} GameInfoBlock;

// Fields func_02009828 reads.
typedef struct Unk02009828 {
    /* 00 */ u8 field0[4];
    /* 04 */ const u16 *field4;
    /* 08 */ const u8 *field8;
    /* 0c */ const u8 *fieldC;
    /* 10 */ const u8 *field10;
    /* 14 */ u32 field14;
    /* 18 */ u8 field18;
} Unk02009828;

extern u8 data_0216fc30;
extern u32 data_0216fc44;
extern void (*data_0216fc48)(u32 a);
extern GameInfoList gGameInfoList;
extern GameInfoBlock gGameInfoBlock;
extern u8 data_0216fce0[0xc0];
extern Unk0216fc1c data_0216fd30[1];

u32 func_020091fc(ScanBlock *scanBlock);
u32 MB_RecvGameInfoBeacon(EntryCallbackFunc callback, u32 b, ScanBlock *scanBlock);
void func_020092d0(u32 ggid, u16 tgid, u32 attr);
void func_02009494(void);
void func_020094b8(u32 ggid, u16 tgid, u32 attr);
void func_020095c4(void);
u32 AdvanceGameInfoEntry(void);
void SetNextGameInfo(u32 ggid, u16 tgid, u32 attr);
void ResetGameInfoWalk(void);
void InitGameInfoList(void);
void AppendGameInfoEntry(GameInfoEntry *newEntry);
u32 GetU16StringLength(const u16 *string);
void func_0200973c(GameInfoEntry *entry, const void *records, u32 recordMask, u32 d);
u32 LoadFileIfSizeMatches(const u8 *path, u8 *buffer, u32 isLarge);
void func_02009828(GameInfoEntry *entry, Unk02009828 *params, const u8 *record);

// Declared here until the code that defines them is decompiled.
