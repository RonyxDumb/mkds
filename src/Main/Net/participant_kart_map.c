#include "Main/Net/participant_kart_map.h"
#include "Main/System/heap.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Save/ghost_record_file.h"

u32 CreateParticipantKartMap(void *heap) {
    gParticipantKartMap = HeapAlloc(heap, sizeof(ParticipantKartMap));
    return sizeof(ParticipantKartMap);
}
