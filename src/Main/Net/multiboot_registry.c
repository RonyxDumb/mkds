#include "Main/Net/multiboot_registry.h"
#include "multiboot_file_register.h"
#include "multiboot_checksum.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Kart/kart_scale_surface_tables.h"
#include "Main/System/backup_net_camera_work.h"
#include "multiboot_segment_read.h"
#include "Main/Net/game_registry_data.h"

#pragma thumb on

u32 RegisterMultiBootSegment(void) {
    u32 size;
    int succeeded;
    u32 result;
    result = 0;
    size = ComputeRomBinarySize_from_thumb(NULL);
    if ((0x00010000u) <= size) {
        succeeded = FsUnk_ReadCartHeader_from_thumb(NULL, g_GlobalZE->mMultiBootSegment, g_GlobalZE->mMultiBootSegmentSize);
        if ((succeeded != 0) &&
            (succeeded = MB_RegisterFile(g_GlobalBAN, g_GlobalZE->mMultiBootSegment), succeeded != 0)) {
            result = 1;
        }
    }
    return result;
}

void SetGlobalBAN_from_thumb(Bmg *bmg) {
    void **table;
    void *firstEntry;
    void *secondEntry;
    firstEntry = Bmg_GetRawStringPointer_from_thumb(bmg, 0);
    secondEntry = Bmg_GetRawStringPointer_from_thumb(bmg, 1);
    table = (void **) g_GlobalBAN;
    ((void **) g_GlobalBAN)[1] = firstEntry;
    table[2] = secondEntry;
}

#pragma thumb off
