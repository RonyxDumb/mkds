#include "Main/Unknown/code_020733ec.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02066ac0.h"
#include "Main/Unknown/code_02067cb0.h"
#include "Main/Unknown/code_02067f94.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02067000.h"
#include "Main/Unknown/code_02067c70.h"
#include "Main/Unknown/code_02067f78.h"
#include "Main/Unknown/code_020681e0.h"
#include "Main/Unknown/code_020681e4.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_0207a73c.h"
#include "Main/Unknown/code_0208ae60.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020e0650.h"
#include "Main/Unknown/unk_02165000.h"
#include "code_02147cd8.h"
#include "ITCM/code_01ff9598.h"

void InitKartMapObjectResponses(void) {
    RaceSetup *raceSetup;
    u16 i;
    void **responseSlot;
    void **secondResponseSlot;

    data_0217ac14 = IsLowestOffsetFarOnHitBit;
    raceSetup = gRaceSetup;
    i = 0;
    responseSlot = gCollideKartWithMapObjectResponses;
    secondResponseSlot = gKartMapObjectSecondResponses;
    if (raceSetup->mCourseId == COURSE_ID_RAINBOW || raceSetup->mCourseId == COURSE_ID_OLD_SKY_AGB) {
        data_0217ac14 = IsLowestOffsetFarOnHitBitOrYAbove;
    }
    data_0217ac10 = 0;
    if (raceSetup->mMode == MODE_BATTLE) {
        switch (raceSetup->mCourseId) {
            case COURSE_ID_MINI_BLOCK_64:
            case COURSE_ID_MINI_DOKAN_GC:
                data_0217ac10 = 1;
                data_0217ac14 = IsLowestOffsetFarOnHitBitOrKartBit;
                break;
        }
    }
    for (; i < 15; i++, responseSlot++, secondResponseSlot++) {
        switch (i) {
            case 0:
                *responseSlot = CollideKartWithMapObjectResponse0;
                *secondResponseSlot = MapObjectResponseReturnArgument;
                break;
            case 2:
                *responseSlot = CollideKartWithMapObjectResponse2;
                *secondResponseSlot = MapObjectResponseReturnArgument;
                break;
            case 3:
                *responseSlot = CollideKartWithMapObjectResponse3;
                *secondResponseSlot = MapObjectResponseReturnArgument;
                break;
            case 4:
                *responseSlot = CollideKartWithMapObjectResponse4;
                *secondResponseSlot = MapObjectResponseReturnArgument;
                break;
            case 5:
                *responseSlot = CollideKartWithMapObjectResponse5;
                *secondResponseSlot = MapObjectResponseReturnArgument;
                break;
            case 6:
                *responseSlot = CollideKartWithMapObjectResponse6;
                *secondResponseSlot = MapObjectResponseReturnArgument;
                break;
            case 7:
                *responseSlot = CollideKartWithMapObjectResponse7;
                *secondResponseSlot = MapObjectResponseReturnArgument;
                break;
            case 9:
                *responseSlot = CollideKartWithMapObjectResponse9;
                *secondResponseSlot = StartKartPushFlipOnHitByMapObject;
                break;
            case 8:
                *responseSlot = CollideKartWithMapObjectResponse8;
                *secondResponseSlot = StartKartPushFlipOnHit;
                break;
            case 10:
                *responseSlot = CollideKartWithMapObjectResponse10;
                *secondResponseSlot = StartKartPushDoubleFlipOnHit;
                break;
            case 11:
                *responseSlot = CollideKartWithMapObjectResponse11;
                *secondResponseSlot = MapObjectResponseReturnArgument;
                break;
            case 12:
                *responseSlot = CollideKartWithMapObjectResponse12;
                *secondResponseSlot = MapObjectResponseReturnArgument;
                break;
            case 13:
                *responseSlot = CollideKartWithMapObjectResponse13;
                *secondResponseSlot = MapObjectResponseReturnArgument;
                break;
            case 14:
                *responseSlot = CollideKartWithMapObjectResponse14;
                *secondResponseSlot = MapObjectResponseReturnArgument;
                break;
            default:
                *responseSlot = CollideKartWithMapObjectNoResponse;
                *secondResponseSlot = MapObjectResponseReturnArgument;
                break;
        }
    }
    data_usa_021654ec = FX_Div(0x1000, MUL_FIXED12_NO_ROUND(GetFirstBaseSpeedLimit(), 0xd9aLL));
}

void InitKartResources(Kart *kart) {
    void *heap;
    Vec3 *collisionPos;
    u16 i;

    heap = GetHeap(GetCurrentHeapCall());
    kart->mUnk_230 = AdvanceKartOffsetCycle;
    InitKartPhysicalParams(kart);
    InitKartFlags(kart);
    if (kart->mUnk_7c & KART_7C_MODELS_ENTRY_008_SET) {
        SetKartSpeedLimitReciprocal(FX_Div(0x1000, kart->mPhysicalParam->mBaseSpeedLimit));
    }
    InitKartSound(kart);
    CreateCollisionHitLink(&kart->mCollisionHitLink);
    kart->mAi = HeapAlloc(heap, 0x158);
    if (gCourseMap->mRaceRouteCount != 0 || gCourseMap->mBattleRouteCount != 0) {
        if (gRaceSetup->mCurrentEntries[kart->mIndex].mPlayer.mKind == PLAYER_KIND_CPU) {
            kart->mUnk_7c |= 2;
            if (kart->mUnk_7c & 2) {
                for (i = 0; i < 12; i++) {
                    if (i != 0) {
                        kart->mPhysicalParam->mUnk_38[i] = kart->mPhysicalParam->mUnk_38[i] << 2;
                        if (kart->mPhysicalParam->mUnk_38[i] > kart->mPhysicalParam->mUnk_38[0]) {
                            kart->mPhysicalParam->mUnk_38[i] = kart->mPhysicalParam->mUnk_38[0];
                        }
                    }
                }
            }
        }
    }
    kart->mUnk_2ca = -1;
    kart->mCollisionSlot = kart->mUnk_2ca;
    if (gRaceSetup->mMode == 5) {
        collisionPos = &kart->mPointAlongUp;
    } else {
        collisionPos = &kart->mCollisionCenter;
    }
    if (kart->mCollisionSlot == -1) {
        kart->mCollisionSlot = CreateCollisionSlot(collisionPos, kart->mPhysicalParam->mRadius + 0xd000, 0x8000, kart);
    }
    if (kart->mUnk_2ca == -1) {
        kart->mUnk_2ca =
            CreateCollisionSlot(&kart->mUnk_1f0, ((s64) kart->mPhysicalParam->mRadius << 15) >> 12, 0x800, kart);
    }
    kart->mUnk_44 |= KART_44_ON_GROUND;
    kart->mUnk_4d0 = 0x64;
    kart->mRadius = kart->mPhysicalParam->mRadius;
    InitKartSoundParams(kart);
    if (gRaceSetup->mMode == 5) {
        kart->mUnk_514 = HeapAlloc(heap, 0xb8);
        InitParticipantKartRecordState(kart, heap);
    }
    if (IsRaceAwardOrStaffRoll() != 0) {
        kart->mUnk_44 |= 0x1000000;
    }
}
