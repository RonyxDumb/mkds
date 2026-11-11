#include "Main/Unknown/code_02093fa4.h"
#include "Main/Unknown/code_020937c4.h"
#include "Main/Unknown/code_020ac524.h"
#include "Main/Unknown/code_020d7d80.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_021000d0.h"

void InitNsKiller1(NsKiller1 *nsKiller1) {
    InitGroupFollower(&nsKiller1->mFollower, nsKiller1->mMapObject.mCourseMapRow, 0);
    SetStraightSegmentLengths(&nsKiller1->mFollower);
    CreateParkedMapObjects(MAP_OBJECT_KIND_NS_KILLER2, 0x14, nsKiller1);
    nsKiller1->mMapObject.mFarDistanceSquared = gSoundFalloffs[9].mUnk_20;
}
