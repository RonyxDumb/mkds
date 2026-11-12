#include "01/code_02187eb0.h"
#include "01/code_02188158.h"
#include "01/code_02188e88.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Unknown/code_020f36d8.h"
#include "01/unk_021a7000.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_02042000.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020da000.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/code_020fd000.h"
#include "Main/Unknown/code_02042044.h"

Kart *GetEntryKartInRange(MissionRunMapObject *mapObject, s32 radius, s32 halfAngle) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    if (kart != NULL && IsPointInRange(mapObject, &kart->mPos, radius, halfAngle) != FALSE &&
        (kart->mDriveFlags & KART_DRIVE_SINKING) == 0) {
        return kart;
    }
    return NULL;
}

Kart *GetEntryKartInAngleRange(MissionRunMapObject *mapObject, s32 angleOffset, s32 radius, s32 halfAngle) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    if (kart != NULL && (kart->mDriveFlags & KART_DRIVE_SINKING) == 0 && (radius != 0 || halfAngle != 0)) {
        if (radius == 0 || IsWithinXzDistanceOfPoint(mapObject, &kart->mPos, radius) != 0) {
            if (halfAngle == 0 || IsDirectionToPointWithinAngle(mapObject, mapObject->mAngle + angleOffset, &kart->mPos,
                                                                halfAngle) != 0) {
                return kart;
            }
        }
    }
    return NULL;
}

Kart *GetEntryKartFacingObject(MissionRunMapObject *mapObject, s32 radius, s32 halfAngle) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    if (kart != NULL && (kart->mDriveFlags & KART_DRIVE_SINKING) == 0 && (radius != 0 || halfAngle != 0)) {
        if (radius == 0 || IsWithinXzDistanceOfPoint(mapObject, &kart->mPos, radius) != 0) {
            if (halfAngle == 0 ||
                IsDirectionToPointWithinAngle(mapObject, kart->mHeadingAngle + 0x8000, &kart->mPos, halfAngle) != 0) {
                return kart;
            }
        }
    }
    return NULL;
}

CourseMapGroupEntry *GetCurrentGroupEntry(MissionRunMapObject *mapObject) {
    if (mapObject->mEntryGroupIndex < gCourseMap->mEntryGroupCount) {
        return GetCourseMapGroupEntry(mapObject->mEntryGroupIndex, mapObject->mEntryIndex);
    }
    return NULL;
}

s32 GetCurrentGroupEntryValue(MissionRunMapObject *mapObject) {
    if (mapObject->mEntryGroupIndex < gCourseMap->mEntryGroupCount) {
        return GetCourseMapGroupEntry(mapObject->mEntryGroupIndex, mapObject->mEntryIndex)->mUnk_0e;
    }
    return 0;
}

s32 GetCurrentGroupEntryPercent(MissionRunMapObject *mapObject) {
    if (mapObject->mEntryGroupIndex < gCourseMap->mEntryGroupCount) {
        return GetCourseMapGroupEntry(mapObject->mEntryGroupIndex, mapObject->mEntryIndex)->mUnk_10;
    }
    return 0;
}

CourseMapGroupEntry *GetNextGroupEntry(MissionRunMapObject *mapObject) {
    CourseMap *courseMap = gCourseMap;
    s32 nextEntryIndex;

    if (mapObject->mEntryGroupIndex < courseMap->mEntryGroupCount) {
        nextEntryIndex = mapObject->mEntryIndex + 1;
        if (nextEntryIndex >= GetCourseMapEntryGroup(mapObject->mEntryGroupIndex)->mEntryCount) {
            nextEntryIndex = 0;
        }
        return GetCourseMapGroupEntry(mapObject->mEntryGroupIndex, nextEntryIndex);
    }
    return NULL;
}

void DecrementEntryIndexSkipZero(MissionRunMapObject *mapObject) {
    CourseMap *courseMap;
    CourseMapEntryGroup *entryGroup;
    s32 groupIndex;
    s32 entryIndex;

    courseMap = gCourseMap;
    groupIndex = mapObject->mEntryGroupIndex;
    if (groupIndex < courseMap->mEntryGroupCount) {
        entryGroup = &courseMap->mEntryGroups[(u16) groupIndex];
        entryIndex = mapObject->mEntryIndex - 1;
        if (entryIndex <= 0) {
            entryIndex = entryGroup->mEntryCount - 1;
        }
        mapObject->mEntryIndex = entryIndex;
    }
}
