#include "Main/Unknown/code_020d2450.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_020d6dc0.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffdee4.h"

void RefreshMapObjectMatrixFromHitNormal(MapObject *mapObject) {
    int hit;
    Vec3 normal;
    Quaternion quaternion;
    hit = CollideSphereWithCourse(&mapObject->mPos, NULL, 0, 0xa000, 8, 0xfffffffe, NULL, &normal, NULL, NULL, NULL,
                                  NULL, NULL, NULL);
    if (hit != 0) {
        QuaternionFromYAxisToVec3(&normal, &quaternion);
        Matrix3x3FromQuaternion(&mapObject->mMatrix.mAxes, &quaternion);
        return;
    }
}
