#include "Main/Unknown/code_0204aa04.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_0211d4a8.h"

u32 SetMultiSimple(u32 flag) {
    u32 value0 = flag;
    u32 value1;
    if (gBootInfo->mBootType == 2) {
        return value0;
    }
    value0 = (value0) & (1u);
    value1 = gStartupWork->mUnk_1c;
    value1 = (value1) & ~(4u);
    value0 = (value1) | ((value0 << 2));
    gStartupWork->mUnk_1c = value0;
    return value0;
}

KeyRecordingBuffer *InitKeyRecordingBuffer(KeyRecording *record, void *heap) {
    KeyRecordingBuffer *buffer = HeapAlloc(heap, 0xdcc);
    record->mBuffer = buffer;
    return buffer;
}
