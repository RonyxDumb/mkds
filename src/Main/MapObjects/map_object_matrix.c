#include "Main/MapObjects/map_object_matrix.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Unknown/code_020d6dc0.h"
#include "ITCM/kart_motion.h"
#include "ITCM/sphere_collision.h"

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
