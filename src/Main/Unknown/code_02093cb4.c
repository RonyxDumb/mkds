#include "Main/Unknown/code_020937c4.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0207a780.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020d278c.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d8654.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_02100084.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_0210a67c.h"
#include "Main/Unknown/code_0210b708.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_0210b850.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "code_0212bcac.h"

void CreateNsKiller1(void *mapObjectList) {
    gNsKiller1 = CreateMapObjectModelAnimated(mapObjectList, gNsKiller1NsbmdName);
}

void DrawNsKiller1(void *mapObjectList, NsKiller1 *nsKiller1) {
    s32 gxParam;

    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    NNS_G3dGeBufferOP_N(0x1b, &nsKiller1->mMapObject.mScale, 3);
    nsKiller1->mMapObject.mMatrix.mRows[3].x = nsKiller1->mMapObject.mPos.x >> 4;
    nsKiller1->mMapObject.mMatrix.mRows[3].y = nsKiller1->mMapObject.mPos.y >> 4;
    nsKiller1->mMapObject.mMatrix.mRows[3].z = nsKiller1->mMapObject.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &nsKiller1->mMapObject.mMatrix, 12);
    DrawMapObjectModel(mapObjectList, gNsKiller1, nsKiller1);
}

void InitNsKiller1Objects(MapObjectList *mapObjectList) {
    s32 objectIndex;
    NsKiller1 *nsKiller1;

    if (mapObjectList == NULL) {
        return;
    }
    for (objectIndex = 0;
         objectIndex < mapObjectList->mMapObjectCount && (nsKiller1 = mapObjectList->mMapObjects[objectIndex]) != NULL;
         objectIndex++) {
        nsKiller1->mStateTimer = 0;
    }
}

void UpdateNsKiller1(void *mapObjectList, NsKiller1 *nsKiller1) {
    SoundStartParams soundParams;

    switch (nsKiller1->mState) {
        case 0:
            if (nsKiller1->mStateTimer-- > 0) {
                return;
            }
            nsKiller1->mFollower.mSpeed = 0x2000;
            nsKiller1->mFollower.mProgressStep =
                ((s64) nsKiller1->mFollower.mPath->mSegments[nsKiller1->mFollower.mSegmentIndex].mInverseProgressLength
                 << 13) >>
                12;
            nsKiller1->mState = 1;
            break;
        case 1:
            if (AdvanceGroupFollower(&nsKiller1->mFollower) != FALSE) {
                nsKiller1->mStateTimer = 0x2d;
                nsKiller1->mState = 2;
            }
            GetGroupFollowerLinearXz(&nsKiller1->mFollower, &nsKiller1->mMapObject.mPos);
            break;
        case 2:
            if (nsKiller1->mStateTimer == 0x2d) {
                if ((nsKiller1->mMapObject.mDistanceSquaredAndFlags & 4) == 0) {
                    NNS_SndPlayerStopSeq(GetSndHandleSlot(8), 0);
                    soundParams = data_0216676c;
                    soundParams.mPositionSource = &nsKiller1->mMapObject.mPos;
                    soundParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&nsKiller1->mMapObject.mPos);
                    StartSndHandleSoundEx(&soundParams, GetSndHandleSlot(8));
                }
            } else if (nsKiller1->mStateTimer <= 0) {
                nsKiller1->mStateTimer = 0;
                nsKiller1->mState = 3;
            }
            nsKiller1->mStateTimer--;
            break;
        case 3:
            StartNsKiller2(&nsKiller1->mMapObject.mPos, &nsKiller1->mMapObject.mMatrix.mRows[2],
                           nsKiller1->mMapObject.mAngle);
            if ((nsKiller1->mMapObject.mFlags & 0x12) == 0) {
                StartEffect(0x4b, &nsKiller1->mMapObject.mPos);
                StartEffect(0x4c, &nsKiller1->mMapObject.mPos);
                StartEffect(0x4d, &nsKiller1->mMapObject.mPos);
            }
            nsKiller1->mStateTimer = 0x4b;
            nsKiller1->mState = 0;
            break;
    }
}

void CreateNsKiller1DrawList(void) {
    CreateMapObjectDrawList1(CreateNsKiller1, DrawNsKiller1, NULL);
}

void CreateNsKiller1UpdateList(void) {
    CreateMapObjectUpdateList(InitNsKiller1Objects, UpdateNsKiller1, NULL);
}
