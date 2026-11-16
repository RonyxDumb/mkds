#include "Main/Unknown/code_020733ec.h"
#include "Main/System/Heap.h"
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

void driver_initColResponses(void) {
    RaceSetup *raceSetup;
    u16 i;
    void **responseSlot;
    void **b;

    data_0217ac14 = func_01ffa478;
    raceSetup = gRaceMultiConfig;
    i = 0;
    responseSlot = driver_sColReactionInitTable;
    b = driver_sColReactionHandleTable;
    if (raceSetup->mCourseId == COURSE_ID_RAINBOW || raceSetup->mCourseId == COURSE_ID_OLD_SKY_AGB) {
        data_0217ac14 = func_01ffa380;
    }
    data_0217ac10 = 0;
    if (raceSetup->mMode == MODE_BATTLE) {
        switch (raceSetup->mCourseId) {
            case COURSE_ID_MINI_BLOCK_64:
            case COURSE_ID_MINI_DOKAN_GC:
                data_0217ac10 = 1;
                data_0217ac14 = func_01ffa41c;
                break;
        }
    }
    for (; i < 15; i++, responseSlot++, b++) {
        switch (i) {
            case 0:
                *responseSlot = driver_initNoReaction;
                *b = driver_defaultHandleReaction;
                break;
            case 2:
                *responseSlot = driver_initReaction2;
                *b = driver_defaultHandleReaction;
                break;
            case 3:
                *responseSlot = driver_initSingleSpinOutReaction;
                *b = driver_defaultHandleReaction;
                break;
            case 4:
                *responseSlot = driver_initDoubleSpinOutReaction;
                *b = driver_defaultHandleReaction;
                break;
            case 5:
                *responseSlot = driver_initDoubleSpinOutFireReaction;
                *b = driver_defaultHandleReaction;
                break;
            case 6:
                *responseSlot = driver_initDoubleSpinOutWaterReaction;
                *b = driver_defaultHandleReaction;
                break;
            case 7:
                *responseSlot = driver_initForwardFlipReaction;
                *b = driver_defaultHandleReaction;
                break;
            case 9:
                *responseSlot = driver_initSingleBackwardFlip2Reaction;
                *b = driver_handleSingleBackwardFlip2Reaction;
                break;
            case 8:
                *responseSlot = driver_initSingleBackwardFlip1Reaction;
                *b = driver_handleSingleBackwardFlip1Reaction;
                break;
            case 10:
                *responseSlot = driver_initDoubleBackwardFlipReaction;
                *b = driver_handleDoubleBackwardFlipReaction;
                break;
            case 11:
                *responseSlot = driver_initDossunSmashReaction;
                *b = driver_defaultHandleReaction;
                break;
            case 12:
                *responseSlot = driver_initReaction12;
                *b = driver_defaultHandleReaction;
                break;
            case 13:
                *responseSlot = driver_initReaction13;
                *b = driver_defaultHandleReaction;
                break;
            case 14:
                *responseSlot = driver_initSingleSpinElectricityReaction;
                *b = driver_defaultHandleReaction;
                break;
            default:
                *responseSlot = driver_initReaction1;
                *b = driver_defaultHandleReaction;
                break;
        }
    }
    data_021654ec = FX_Div(0x1000, ((s64) physp_getField8() * 0xd9aLL) >> 12);
}

void func_020733ec(Kart *kart) {
    void *heap;
    Vec3 *collisionPos;
    u16 i;

    heap = proc_getHeap(proc_getCurrent());
    kart->field230 = func_02071568;
    driver_initPhysicalParams(kart);
    driver_initField7C(kart);
    if (kart->field7C & KART_7C_MODELS_ENTRY_008_SET) {
        SetKartSpeedLimitReciprocal(FX_Div(0x1000, kart->mPhysicalParam->mBaseSpeedLimit));
    }
    driver_initSound(kart);
    func_020e0650((u32 *) &kart->field208);
    kart->mAi = heap_alloc(heap, 0x158);
    if (gMapData->mRaceRouteCount != 0 || gMapData->mBattleRouteCount != 0) {
        if (gRaceMultiConfig->mCurrentEntries[kart->mIndex].mPlayer.mKind == PLAYER_KIND_CPU) {
            kart->field7C |= 2;
            if (kart->field7C & 2) {
                for (i = 0; i < 12; i++) {
                    if (i != 0) {
                        kart->mPhysicalParam->field38[i] = kart->mPhysicalParam->field38[i] << 2;
                        if (kart->mPhysicalParam->field38[i] > kart->mPhysicalParam->field38[0]) {
                            kart->mPhysicalParam->field38[i] = kart->mPhysicalParam->field38[0];
                        }
                    }
                }
            }
        }
    }
    kart->field2CA = -1;
    kart->mCollisionSlot = kart->field2CA;
    if (gRaceMultiConfig->mMode == 5) {
        collisionPos = &kart->mPointAlongUp;
    } else {
        collisionPos = &kart->mCollisionCenter;
    }
    if (kart->mCollisionSlot == -1) {
        kart->mCollisionSlot = col_createColEntry(collisionPos, kart->mPhysicalParam->mRadius + 0xd000, 0x8000, kart);
    }
    if (kart->field2CA == -1) {
        kart->field2CA =
            col_createColEntry(&kart->field1F0, ((s64) kart->mPhysicalParam->mRadius << 15) >> 12, 0x800, kart);
    }
    kart->field44 |= KART_44_ON_GROUND;
    kart->field4D0 = 0x64;
    kart->mRadius = kart->mPhysicalParam->mRadius;
    driver_initField450(kart);
    if (gRaceMultiConfig->mMode == 5) {
        kart->field514 = heap_alloc(heap, 0xb8);
        driver_initField514(kart, heap);
    }
    if (race_isAwardStaffRoll() != 0) {
        kart->field44 |= 0x1000000;
    }
}
