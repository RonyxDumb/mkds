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

void func_ov001_021882b8(void) {
    u16 i;
    Unk02188950 *obj;
    Unk0218d87c *table;

    if (!(gRaceMultiConfig->mMode == MODE_MISSION_RUN ? mgcnt_isDriverDead((u16) gRaceMultiConfig->mEntryIndex) : 0)) {
        for (i = gRaceMultiConfig->mMode == MODE_MISSION_RUN ? func_ov001_02181b54() : (u8) 0;
             i <= (gRaceMultiConfig->mMode == MODE_MISSION_RUN ? GetMissionRunMapObjectLastIndex() : (u16) 0); i++) {
            obj = gRaceMultiConfig->mMode == MODE_MISSION_RUN ? GetMissionRunMapObject(i) : 0;
            table = mobj_getLogicPartForObjectId(0x1ff);
            func_ov001_02188e88(obj);
            obj->mGravityEnabled = FALSE;
            obj->field2B8 = 3;
            obj->mSpeed = obj->mSpeedTarget = obj->mSpeedPerCall = 0;
            obj->mAngleState = 0;
            obj->mAnglePerCall = obj->mAnglePerCallTarget = obj->mAnglePerCallIncrement = 0;
            obj->mMoveAngleMode = 0;
            obj->mMoveAnglePerCall = obj->mMoveAnglePerCallTarget = obj->mMoveAnglePerCallIncrement = 0;
            obj->mVelocity.x = obj->mVelocity.y = obj->mVelocity.z = 0;
            obj->mAlphaLimit = obj->mAlphaLimitTarget = 0x1f000;
            obj->mAlphaLimitPerCall = 0;
            if (i - (gRaceMultiConfig->mMode == MODE_MISSION_RUN ? func_ov001_02181b54() : 0) < table->field4) {
                obj->field0.mPos =
                    table->field0[i - (gRaceMultiConfig->mMode == MODE_MISSION_RUN ? func_ov001_02181b54() : 0)]
                        ->field0.mCourseMapRow->field0;
                obj->mAngle =
                    (u16) (((s64) table
                                    ->field0[i - (gRaceMultiConfig->mMode == MODE_MISSION_RUN ? func_ov001_02181b54() : 0)]
                                    ->field0.mCourseMapRow->fieldC.y *
                                0xb60b60b60bLL +
                            0x80000000000LL) >>
                           44);
            }
        }
    }
    func_020a305c();
}
