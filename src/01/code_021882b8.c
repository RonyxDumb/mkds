#include "01/code_021882b8.h"
#include "01/code_0218d520.h"
#include "01/code_0218155c.h"
#include "01/code_02188e88.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a2f30.h"
#include "Main/Unknown/code_02100000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/code_0218c000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020a3000.h"
#include "Main/Unknown/code_020f9c6c.h"

void ResetMissionRunMapObjects(void) {
    u16 i;
    MissionRunMapObject *obj;
    MissionRunMapObject *tableObj;
    MapObjectList *table;

    if (!(gRaceSetup->mMode == MODE_MISSION_RUN ? IsKartEliminated((u16) gRaceSetup->mEntryIndex) : 0)) {
        for (i = gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : (u8) 0;
             i <= (gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunMapObjectLastIndex() : (u16) 0); i++) {
            obj = gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunMapObject(i) : 0;
            table = FindMapObjectKindUpdateList(0x1ff);
            StopMapObjectState(obj);
            obj->mGravityEnabled = FALSE;
            obj->mUnk_2b8 = 3;
            obj->mSpeed = obj->mSpeedTarget = obj->mSpeedPerCall = 0;
            obj->mAngleState = 0;
            obj->mAnglePerCall = obj->mAnglePerCallTarget = obj->mAnglePerCallIncrement = 0;
            obj->mMoveAngleMode = 0;
            obj->mMoveAnglePerCall = obj->mMoveAnglePerCallTarget = obj->mMoveAnglePerCallIncrement = 0;
            obj->mVelocity.x = obj->mVelocity.y = obj->mVelocity.z = 0;
            obj->mAlphaLimit = obj->mAlphaLimitTarget = 0x1f000;
            obj->mAlphaLimitPerCall = 0;
            if (i - (gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) <
                table->mMapObjectCount) {
                tableObj =
                    table->mMapObjects[i -
                                       (gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0)];
                obj->mUnk_000.mPos = tableObj->mUnk_000.mCourseMapRow->mPosition;
                tableObj =
                    table->mMapObjects[i -
                                       (gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0)];
                obj->mAngle = DEG_TO_ANGLE(tableObj->mUnk_000.mCourseMapRow->mRotationDegrees.y);
            }
        }
    }
    ResetBalloons();
}
