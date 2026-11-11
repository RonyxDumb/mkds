#include "Main/Unknown/code_020a2e88.h"

// Sets the balloon's kart index to -1 and starts a countdown; given a position, places the balloon there.
void StartBalloonWithoutKart(Balloon *balloon, Vec3 *position) {
    balloon->mNoKartTimer = 0x1e;
    balloon->mKartIndex = -1;
    balloon->mDrawCount = 1;
    balloon->mDrawList = NULL;
    if (position == NULL) {
        return;
    }
    balloon->mMapObject.mPos.x = position->x;
    balloon->mMapObject.mPos.y = position->y + 0xf666;
    balloon->mMapObject.mPos.z = position->z;
}

// Copies the two vectors into mTargetPos and mTargetVelocity.
void SetBalloonTargetPosAndVelocity(Balloon *balloon, Vec3 *targetPos, Vec3 *targetVelocity) {
    balloon->mTargetPos = *targetPos;
    balloon->mTargetVelocity = *targetVelocity;
}
