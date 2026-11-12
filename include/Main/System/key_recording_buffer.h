#pragma once

#include "types.h"

typedef struct KeyRecording KeyRecording;
typedef struct KeyRecordingBuffer KeyRecordingBuffer;

KeyRecordingBuffer *InitKeyRecordingBuffer(KeyRecording *record, void *heap);
u32 SetMultiSimple(u32 flag);
