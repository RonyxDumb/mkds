#include "01/code_0218c55c.h"
#include "01/code_02187eb0.h"
#include "01/code_02188cd8.h"
#include "Main/Unknown/code_02042044.h"

u32 UpdateKurikingFaceKartState(Unk02188950 *mapObject) {
    CourseMapGroupEntry *currentGroupEntry;
    currentGroupEntry = GetCurrentGroupEntry(mapObject);
    SetMoveAnglePoint(mapObject, &currentGroupEntry->mPos);
    currentGroupEntry = GetCurrentGroupEntry(mapObject);
    SetPointInRangePoint(mapObject, &currentGroupEntry->mPos);
    return 0;
}
