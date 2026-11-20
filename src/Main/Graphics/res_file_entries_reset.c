#include "Main/Graphics/res_file_entries_reset.h"
#include "Main/System/backup_net_camera_work.h"
#include "linked_list_init.h"

NNSFndList gResFileEntries;

void ResetResFileEntries(void) {
    NNSFndList *list;
    u32 offset;
    u32 unusedValue;
    list = &gResFileEntries;
    offset = 0u;
    NNS_FndInitList(list, offset);
}
