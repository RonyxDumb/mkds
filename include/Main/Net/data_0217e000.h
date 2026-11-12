#pragma once
#include "types.h"
#include "stream.h" // Unk0212c7f0
#include "code_0212d214.h"

typedef struct OSMutex OSMutex;

typedef struct OSMessageQueue OSMessageQueue;

struct MWiDestructorChain;

struct WMArm9Buf;

struct Unk021425e8;

// Message WmReceiveFifo builds for the port callbacks on connect and disconnect.
extern struct Unk021425e8 gPortCallbackEvent;

// The ten 0x100-byte command messages.
extern u8 data_0217ef60[10][0x100];

extern struct MWiDestructorChain *data_0217eeb0;

// Word arrays; ExitTail uses entry 0 of each, fwrite entries 3-5, printf entry 3 and
// raise entry 7.
extern u32 gLockOwnerThreadIds[];

extern u32 gLockHoldCounts[];

// 0x14-byte entries passed to OS_TryLockMutex, OS_UnlockMutex and OS_LockMutex; ExitTail uses entry 0,
// fwrite entries 3-5, printf entry 3 and raise entry 7. An OSMutex is 0x18 bytes, so OSMutex.mPrev of one entry is
// the start of the next entry.
extern u8 gLockMutexes[][0x14];

extern OSMutex data_0217e3e0;

extern NNSFndList data_0217e3f8;

extern Unk0212c7f0 data_0217e404[4];
