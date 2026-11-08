#include "Main/Unknown/code_02073e04.h"
#include "Main/Unknown/code_02039774.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_02147cd8.h"

u32 GetCameraEntryChanged(void) {
    return gCameraEntryChanged;
}

// Distance of the point a along the forward axis of the current camera.
int GetCameraForwardDistance(const Vec3 *a) {
    Camera *v1;
    Vec3 v2;
    v1 = GetCurrentCamera();
    VEC_Subtract(a, &v1->mPos, &v2);
    return Vec3DotUnrounded(&v1->mForward, &v2);
}

// Distance of the point a along mSide of the current camera, times mSideDistanceSign (-1 in mirror mode).
int GetCameraSideDistance(const Vec3 *a) {
    Camera *v1;
    int v2;
    Vec3 v3;
    v1 = GetCurrentCamera();
    VEC_Subtract(a, &v1->mPos, &v3);
    v2 = ((u32) Vec3DotUnrounded(&v1->mSide, &v3));
    return v1->mSideDistanceSign * v2;
}
