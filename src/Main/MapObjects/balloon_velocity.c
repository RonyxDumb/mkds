#include "Main/MapObjects/balloon_velocity.h"
#include "vector_math.h"

void AddBalloonVelocity(Balloon *balloon, const Vec3 *addend) {
    VEC_Add(&balloon->mMapObject.mPosStep, addend, &balloon->mMapObject.mPosStep);
}
