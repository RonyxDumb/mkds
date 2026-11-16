#include "Main/Net/participant_kart_map.h"
#include "Main/System/heap.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Save/ghost_record_file.h"

u32 InitializeGlobalRE(void *heap) {
    g_GlobalRE = Mem_AllocateHeap(heap, sizeof(ParticipantKartMap));
    return sizeof(ParticipantKartMap);
}
