#include "Main/Net/multiboot_registry.h"
#include "code_02007ec4.h"
#include "code_02008880.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Kart/kart_scale_surface_tables.h"
#include "Main/System/backup_net_camera_work.h"
#include "mb_fileinfo.h"
#include "Main/Net/game_registry_data.h"

#pragma thumb on

u32 RegisterMultiBootSegment(void) {
    u32 size;
    int succeeded;
    u32 result;
    result = 0;
    size = MB_GetSegmentLength(NULL);
    if ((0x00010000u) <= size) {
        succeeded = MB_ReadSegment(NULL, gConnectionWork->mMultiBootSegment, gConnectionWork->mMultiBootSegmentSize);
        if ((succeeded != 0) &&
            (succeeded = MB_RegisterFile(gGameRegistry, gConnectionWork->mMultiBootSegment), succeeded != 0)) {
            result = 1;
        }
    }
    return result;
}

void SetGameRegistryTexts(Bmg *bmg) {
    void **table;
    void *firstEntry;
    void *secondEntry;
    firstEntry = GetBmgEntry(bmg, 0);
    secondEntry = GetBmgEntry(bmg, 1);
    table = (void **) gGameRegistry;
    ((void **) gGameRegistry)[1] = firstEntry;
    table[2] = secondEntry;
}

#pragma thumb off
