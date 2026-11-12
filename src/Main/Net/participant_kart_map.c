#include "Main/Net/participant_kart_map.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/data_0217a000.h"

u32 CreateParticipantKartMap(void *heap) {
    gParticipantKartMap = HeapAlloc(heap, sizeof(ParticipantKartMap));
    return sizeof(ParticipantKartMap);
}
