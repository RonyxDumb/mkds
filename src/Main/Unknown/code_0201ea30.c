#include "Main/Unknown/code_0201ea30.h"

void *GetCellLayoutEntry(LayoutEntryTable *a, s32 b) {
    u8 *p;
    s32 n;

    p = (u8 *) (a + 1);
    n = a->mCount;
    if (b < 0 || b >= n) {
        return 0;
    }
    return p + b * 8;
}
