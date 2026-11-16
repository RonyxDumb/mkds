#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_02042064.h"

CourseMapGroupEntry *mdat_getPathPoint(u16 groupIndex, u16 entryIndex) {
    return mdat_getPath(groupIndex)->mEntries + entryIndex;
}
