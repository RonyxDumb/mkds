#pragma once

#include "types.h"

typedef struct KeyRecording KeyRecording;
typedef struct KeyRecordingBuffer KeyRecordingBuffer;

KeyRecordingBuffer *AllocateInputRecord(KeyRecording *record, void *heap);
u32 StructP_SetAFlag4_SkipBattleIntro(u32 flag);
