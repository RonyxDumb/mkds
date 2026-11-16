#include "Main/Graphics/res_file_entries_reset.h"
#include "Main/System/backup_net_camera_work.h"
#include "linked_list_init.h"

NNSFndList g_LoadedModelTextureList;

void InitializeLoadedModelTextureList(void) {
    NNSFndList *list;
    u32 offset;
    u32 unusedScratch;
    list = &g_LoadedModelTextureList;
    offset = 0u;
    IntrusiveListWrapper_InitializeEmpty(list, offset);
}
