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

void CreateNsKiller1(void *a) {
    gNsKiller1 = CreateMapObjectModelAnimated(a, gNsKiller1NsbmdName);
}

void DrawNsKiller1(void *a, NsKiller1 *nsKiller1) {
    s32 t;

    t = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &t, 1);
    NNS_G3dGeBufferOP_N(0x1b, &nsKiller1->mMapObject.mScale, 3);
    nsKiller1->mMapObject.mMatrix.mUnk_00[3].x = nsKiller1->mMapObject.mPos.x >> 4;
    nsKiller1->mMapObject.mMatrix.mUnk_00[3].y = nsKiller1->mMapObject.mPos.y >> 4;
    nsKiller1->mMapObject.mMatrix.mUnk_00[3].z = nsKiller1->mMapObject.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &nsKiller1->mMapObject.mMatrix, 12);
    DrawMapObjectModel(a, gNsKiller1, nsKiller1);
}

void InitNsKiller1Objects(MapObjectList *mapObjectList) {
    s32 i;
    NsKiller1 *nsKiller1;

    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (nsKiller1 = mapObjectList->mMapObjects[i]) != NULL; i++) {
        nsKiller1->mStateTimer = 0;
    }
}

void UpdateNsKiller1(void *a, NsKiller1 *nsKiller1) {
    SoundStartParams s;

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
                    s = data_0216676c;
                    s.mPositionSource = &nsKiller1->mMapObject.mPos;
                    s.mDistanceSquared = GetHorizontalCameraDistanceSquared(&nsKiller1->mMapObject.mPos);
                    StartSndHandleSoundEx(&s, GetSndHandleSlot(8));
                }
            } else if (nsKiller1->mStateTimer <= 0) {
                nsKiller1->mStateTimer = 0;
                nsKiller1->mState = 3;
            }
            nsKiller1->mStateTimer--;
            break;
        case 3:
            StartNsKiller2(&nsKiller1->mMapObject.mPos, &nsKiller1->mMapObject.mMatrix.mUnk_00[2], nsKiller1->mMapObject.mAngle);
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

void InitNsKiller2(NsKiller2 *nsKiller2) {
    nsKiller2->mMapObject.mFlags |= data_021564b4;
    ParkMapObject(&nsKiller2->mMapObject);
    nsKiller2->mSoundDistanceSquaredChange = CreateVehicleSoundSource(&nsKiller2->mMapObject);
    ResetSoundDistanceSquaredChange(nsKiller2->mSoundDistanceSquaredChange);
    nsKiller2->mMapObject.mSound->mSoundSource.mTrackParamsFunction =
        (void (*)(void *, void *, void *)) SetNsKiller2SoundTrackParams;
}

u8 CollideKartWithNsKiller2(NsKiller2 *nsKiller2, Kart *kart, u8 *c, u8 *d) {
    u8 x;
    u8 v;

    x = *c;
    v = *d;
    if (x == 1) {
        nsKiller2->mParkTimer = 0x78;
        nsKiller2->mMode = 1;
        nsKiller2->mMapObject.mPosStep.x = ((s64) nsKiller2->mMapObject.mPosStep.x << 10) >> 12;
        nsKiller2->mMapObject.mPosStep.y = ((s64) nsKiller2->mMapObject.mPosStep.y << 10) >> 12;
        nsKiller2->mMapObject.mPosStep.z = ((s64) nsKiller2->mMapObject.mPosStep.z << 10) >> 12;
        nsKiller2->mMapObject.mPosStep.y = 0x4000;
        nsKiller2->mMapObject.mFlags |= data_021564ac;
        if (kart->mItemEffect == 1 || kart->mItemEffect == 3) {
            nsKiller2->mMapObject.mDistanceSquaredAndFlags |= data_021564b0;
        }
        StartSoundIfKartStarOrKiller(&nsKiller2->mMapObject, kart);
    }
    return v;
}

void CreateNsKiller2AndNsKiller2S(void *a) {
    gNsKiller2 = CreateMapObjectModelAnimated(a, gNsKiller2NsbmdName);
    gNsKiller2S = CreateMapObjectModelShadow(a, gNsKiller2SNsbmdName);
    SetMapObjectModelPolygonId(gNsKiller2S, 0x3f);
}

void DrawNsKiller2(void *a, NsKiller2 *nsKiller2) {
    s32 t;
    MtxFx33 rotationMatrix;
    s32 angleIndex;

    if (nsKiller2->mParkTimer <= 0) {
        return;
    }
    t = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &t, 1);
    NNS_G3dGeBufferOP_N(0x19, SetTranslationMatrixPos(&nsKiller2->mMapObject.mPos), 12);
    angleIndex = nsKiller2->mMapObject.mAngle >> 4;
    MTX_RotY33_(&rotationMatrix, gPairsByAngle[angleIndex * 2], gPairsByAngle[angleIndex * 2 + 1]);
    NNS_G3dGeBufferOP_N(0x1a, &rotationMatrix, 9);
    NNS_G3dGeBufferOP_N(0x1b, &nsKiller2->mMapObject.mScale, 3);
    DrawMapObjectModel(a, gNsKiller2S, nsKiller2);
    DrawMapObjectModel(a, gNsKiller2, nsKiller2);
}

void UpdateNsKiller2(void *a, NsKiller2 *nsKiller2) {
    if ((GetKartKind3ShapeListMask() & nsKiller2->mMapObject.mDigitMask) != 0) {
        nsKiller2->mMapObject.mFlags |= data_021564a8;
    } else {
        nsKiller2->mMapObject.mFlags &= ~2;
    }
    switch (nsKiller2->mMode) {
        case 0:
            if (nsKiller2->mParkTimer-- > 0) {
                if ((nsKiller2->mMapObject.mFlags & 2) == 0 && (nsKiller2->mMapObject.mDistanceSquaredAndFlags & 8) != 0) {
                    AdvanceSoundDistanceSquaredChange(nsKiller2->mSoundDistanceSquaredChange,
                                                      nsKiller2->mMapObject.mDistanceSquaredAndFlags & ~0xc000001f);
                } else {
                    AdvanceSoundDistanceSquaredChange(nsKiller2->mSoundDistanceSquaredChange,
                                                      GetHorizontalCameraDistanceSquared(&nsKiller2->mMapObject.mPos));
                }
                VEC_Add(&nsKiller2->mMapObject.mPos, &nsKiller2->mMapObject.mPosStep, &nsKiller2->mMapObject.mPos);
                if (nsKiller2->mParkTimer < 0x24e) {
                    StartMapObjectSoundWhileRequested(&nsKiller2->mMapObject, 0x17d);
                }
            } else {
                ParkMapObject(&nsKiller2->mMapObject);
            }
            break;
        case 1:
            if (nsKiller2->mParkTimer-- > 0) {
                nsKiller2->mMapObject.mPosStep.y -= 0x400;
                VEC_Add(&nsKiller2->mMapObject.mPos, &nsKiller2->mMapObject.mPosStep, &nsKiller2->mMapObject.mPos);
            } else {
                ParkMapObject(&nsKiller2->mMapObject);
            }
            break;
    }
}

void CreateNsKiller2KindData(void) {
    MapObjectKindData *o;

    o = CreateMapObjectKindDataWithSound(CollideKartWithNsKiller2, NULL, NULL, 1, 1, 0x17b);
    o->mUnk_38 = 0x32000;
    o->mUnk_3c = -0x64000;
}

void CreateNsKiller2DrawList(void) {
    CreateMapObjectDrawList1(CreateNsKiller2AndNsKiller2S, DrawNsKiller2, NULL);
}

void CreateNsKiller2UpdateList(void) {
    CreateMapObjectUpdateList(NULL, UpdateNsKiller2, NULL);
}

// Starts a parked NsKiller2 at a (raised), flying along b with angle c.
void StartNsKiller2(Vec3 *startPos, Vec3 *b, u16 angle) {
    NsKiller2 *nsKiller2;

    nsKiller2 = UnparkFirstParkedMapObject(FindMapObjectKindUpdateList(MAP_OBJECT_KIND_NS_KILLER2));
    if (nsKiller2 == NULL) {
        return;
    }
    nsKiller2->mParkTimer = 600;
    nsKiller2->mMapObject.mPos.x = startPos->x;
    nsKiller2->mMapObject.mPos.y = startPos->y + 0x2a000;
    nsKiller2->mMapObject.mPos.z = startPos->z;
    nsKiller2->mMapObject.mMatrix.mUnk_00[2].x = b->x;
    nsKiller2->mMapObject.mMatrix.mUnk_00[2].y = 0;
    nsKiller2->mMapObject.mMatrix.mUnk_00[2].z = b->z;
    nsKiller2->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(b->x, 0x6000);
    nsKiller2->mMapObject.mPosStep.y = 0;
    nsKiller2->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(b->z, 0x6000);
    nsKiller2->mMapObject.mAngle = angle;
    nsKiller2->mMode = 0;
}
