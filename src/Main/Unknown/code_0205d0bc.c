#include "Main/Unknown/code_0205d0bc.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/unk_0217a000.h"

u32 CreateParticipantKartMap(void *heap) {
    gParticipantKartMap = HeapAlloc(heap, sizeof(ParticipantKartMap));
    return sizeof(ParticipantKartMap);
}
