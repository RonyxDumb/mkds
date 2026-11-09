#include "Main/Unknown/code_020d2450.h"
#include "Main/Unknown/code_020d6dc0.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffdee4.h"

void RefreshMapObjectMatrixFromHitNormal(void *mapObject) {
    int hit;
    Vec3 normal;
    u8 quaternion[20];
    hit = CollideSphereWithCourse(OFFSET_PTR(Vec3, mapObject, 4), NULL, 0, 0xa000, 8, 0xfffffffe, NULL, &normal, NULL,
                                  NULL, NULL, NULL, NULL, NULL);
    if (hit != 0) {
        QuaternionFromYAxisToVec3(&normal, quaternion);
        Matrix3x3FromQuaternion(OFFSET_PTR(MtxFx33, mapObject, 0x28), quaternion);
        return;
    }
}
