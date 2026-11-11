#include "01/code_02188158.h"
#include "01/code_02188e88.h"
#include "Main/Unknown/code_020fd264.h"
#include "Main/Unknown/code_020fd83c.h"
#include "Main/Unknown/code_020fd7f0.h"

void SetKartCollisionCallback(MissionRunMapObject *mapObject, UnkFunc *kartCollisionCallback) {
    mapObject->mKartCollisionCallback = kartCollisionCallback;
}

void SetItemCollisionCallback(MissionRunMapObject *mapObject, UnkFunc *itemCollisionCallback) {
    mapObject->mItemCollisionCallback = itemCollisionCallback;
}

BOOL IsPointInRange(MissionRunMapObject *mapObject, Vec3 *point, s32 radius, s32 halfAngle) {
    if ((radius != 0 || halfAngle != 0) && (radius == 0 || IsWithinXzDistanceOfPoint(mapObject, point, radius) != 0) &&
        (halfAngle == 0 || IsDirectionToPointWithinAngle(mapObject, mapObject->mMoveAngle, point, halfAngle) != 0)) {
        return TRUE;
    }
    return FALSE;
}

ItemBomb *FindItemBombInRange(MissionRunMapObject *mapObject, u32 radius, u32 halfAngle) {
    int bombCount;
    ItemBomb *bomb;
    int inRange;
    int index;
    bombCount = GetItemBombActiveCount();
    index = 0;
    if (0 < bombCount) {
        do {
            bomb = GetRestingItemBomb(index);
            if ((bomb != NULL) &&
                (inRange = IsPointInRange(mapObject, &bomb->mBouncingItemObject.mItemObject.mPos, radius, halfAngle),
                 inRange != 0)) {
                return bomb;
            }
            index = index + 1;
        } while (index < bombCount);
    }
    return NULL;
}
