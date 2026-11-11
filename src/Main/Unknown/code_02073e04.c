#include "Main/Unknown/code_02073e04.h"
#include "Main/Unknown/code_02039774.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_02147cd8.h"

u32 GetCameraEntryChanged(void) {
    return gCameraEntryChanged;
}

// Distance of the point a along the forward axis of the current camera.
int GetCameraForwardDistance(const Vec3 *position) {
    Camera *currentCamera;
    Vec3 offset;
    currentCamera = GetCurrentCamera();
    VEC_Subtract(position, &currentCamera->mPos, &offset);
    return Vec3DotUnrounded(&currentCamera->mForward, &offset);
}

// Distance of the point a along mSide of the current camera, times mSideDistanceSign (-1 in mirror mode).
int GetCameraSideDistance(const Vec3 *position) {
    Camera *currentCamera;
    int sideDistance;
    Vec3 offset;
    currentCamera = GetCurrentCamera();
    VEC_Subtract(position, &currentCamera->mPos, &offset);
    sideDistance = ((u32) Vec3DotUnrounded(&currentCamera->mSide, &offset));
    return currentCamera->mSideDistanceSign * sideDistance;
}
