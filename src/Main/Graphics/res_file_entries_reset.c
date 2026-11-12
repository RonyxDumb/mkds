#include "Main/Graphics/res_file_entries_reset.h"
#include "Main/MapObjects/data_0217a000.h"
#include "code_0201750c.h"

void ResetResFileEntries(void) {
    NNSFndList *list;
    u32 offset;
    u32 value12;
    list = &gResFileEntries;
    offset = 0u;
    NNS_FndInitList(list, offset);
}
