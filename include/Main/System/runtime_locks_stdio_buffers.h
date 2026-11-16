#pragma once
#include "types.h"
#include "sound_stream_control.h" // NNSSndStrmPlayer
#include "sound_archive_load.h"

typedef struct OSMutex OSMutex;

typedef struct OSMessageQueue OSMessageQueue;

struct MWiDestructorChain;

struct WMArm9Buf;

struct WMPortRecvCallback;

extern struct MWiDestructorChain *gGlobalDestructorChain;

// Word arrays; ExitTail uses entry 0 of each, fwrite entries 3-5, SomeSprintf entry 3 and
// raise entry 7.
extern u32 g_SomeThreadId[9];

extern u32 g_SomeCounter[9];

// 0x14-byte entries passed to Os_Mutex_TryLock, Os_Mutex_Unlock and Os_Mutex_Lock; ExitTail uses entry 0,
// fwrite entries 3-5, SomeSprintf entry 3 and raise entry 7. An OSMutex is 0x18 bytes, so OSMutex.mPrev of one entry is
// the start of the next entry.
extern u8 g_AnotherMutex[9][0x14];

extern u8 gStderrBuffer[0x100];
extern u8 gStdoutBuffer[0x100];
extern u8 gStdinBuffer[0x100];
