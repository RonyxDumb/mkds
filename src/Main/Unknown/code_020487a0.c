#include "Main/Unknown/code_020487a0.h"
#include "Main/Unknown/unk_02175000.h"
#include "code_0200eddc.h"
#include "code_0214d018.h"

#pragma thumb on

void arc_decompressLZ(const void *source, void *destination, u32 size) {
    MI_UncompressLZ8(source, destination);
    DC_StoreRange(destination, size);
}

void arc_initSomething(int bufferIndex) {
    ArchiveBuffer *buffer;
    buffer = &gArcData->mBuffers[bufferIndex];
    buffer->mHeap = NULL;
    buffer->field8 = buffer->field8 & (0xe0000000u);
    buffer->field8 = buffer->field8 | (0x20000000u);
    buffer->field8 = buffer->field8 & (0xbfffffffu);
}

#pragma thumb off
