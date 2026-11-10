#include "Main/Unknown/code_0204ea14.h"
#include "code_02007ec4.h"
#include "Main/Unknown/code_02008000.h"
#include "code_02008880.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_02008570.h"

#pragma thumb on

u32 RegisterMultiBootSegment(void) {
    u32 size;
    int succeeded;
    u32 result;
    result = 0;
    size = MB_GetSegmentLength(NULL);
    if ((0x00010000u) <= size) {
        succeeded = MB_ReadSegment(NULL, gConnectionWork->mUnk_1658, gConnectionWork->mUnk_168c);
        if ((succeeded != 0) &&
            (succeeded = MB_RegisterFile(data_0215472c, gConnectionWork->mUnk_1658), succeeded != 0)) {
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
    table = data_0215472c;
    data_0215472c[1] = firstEntry;
    table[2] = secondEntry;
}

#pragma thumb off
