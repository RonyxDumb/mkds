#include "Main/Unknown/code_0205d0bc.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/unk_0217a000.h"

u32 CreateParticipantKartMap(void *heap) {
    u32 value0 = (u32) heap;
    u32 value1;
    value1 = 0xau;
    value0 = (u32) heap_alloc((void *) value0, value1);
    value1 = (u32) &gStruct217AA18;
    *(u32 *) ((value1) + (0)) = value0;
    value0 = 0xau;
    return value0;
}
