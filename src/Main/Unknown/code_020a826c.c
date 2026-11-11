#include "Main/Unknown/code_020a826c.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020a8ed8.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_0210b708.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_021108bc.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0212bcac.h"
#include "Main/Unknown/code_0203c25c.h"
#include "Main/Unknown/code_0203c5f8.h"

static inline void func_020a826c_inline(CourseSoundObjectPart *soundPart) {
    s32 falloffDistanceSquared;

    if (soundPart->mStartParams.mFalloffIndex == 2) {
        falloffDistanceSquared = gSoundFalloffs[2].mUnk_20;
    } else if (soundPart->mStartParams.mFalloffIndex == 3) {
        falloffDistanceSquared = gSoundFalloffs[3].mUnk_20;
    } else if (soundPart->mStartParams.mFalloffIndex == 4) {
        falloffDistanceSquared = gSoundFalloffs[4].mUnk_20;
    } else if (soundPart->mStartParams.mFalloffIndex == 5) {
        falloffDistanceSquared = gSoundFalloffs[5].mUnk_20;
    } else if (soundPart->mStartParams.mFalloffIndex == 6) {
        falloffDistanceSquared = gSoundFalloffs[6].mUnk_20;
    } else if (soundPart->mStartParams.mFalloffIndex == 8) {
        falloffDistanceSquared = gSoundFalloffs[8].mUnk_20;
    } else {
        falloffDistanceSquared = 0;
    }
    soundPart->mStartParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&soundPart->mSourcePos);
    if (soundPart->mStartParams.mDistanceSquared < falloffDistanceSquared) {
        soundPart->mInRangeUpdateCount = soundPart->mInRangeUpdateCount == 0 ? 1 : 2;
        if (GetRaceUseChainCameras() != 0) {
            StartSndHandleSoundUnchecked(&soundPart->mStartParams, soundPart->mSndHandleSlot);
        } else {
            StartSndHandleSound(&soundPart->mStartParams, soundPart->mSndHandleSlot);
        }
    } else {
        soundPart->mInRangeUpdateCount = 0;
    }
}

void UpdateCourseSoundObject(void *a, CourseSoundObject *courseSoundObject) {
    s32 soundId;

    switch (courseSoundObject->mState) {
        case 1:
            if (IsRaceStarted() == 1) {
                soundId = courseSoundObject->mSecondPart.mStartParams.mSoundId;
                NNS_SndPlayerStopSeq(courseSoundObject->mFirstPart.mSndHandleSlot, 0);
                courseSoundObject->mFirstPart.mStartParams.mSoundId = soundId;
                courseSoundObject->mState = 2;
            }
            func_020a826c_inline(&courseSoundObject->mFirstPart);
            break;
        case 2:
            PlaceCourseSoundObjectPartSource(&courseSoundObject->mFirstPart, &courseSoundObject->mMapObject.mPos);
            if (gRaceSetup->mRaceKind == RACE_KIND_NORMAL && IsKartOnLastLap(gRaceSetup->mEntryIndex) != FALSE &&
                courseSoundObject->mFirstPart.mInRangeUpdateCount == 0 &&
                courseSoundObject->mFirstPart.mUnk_20 != FALSE) {
                soundId = GetLastLapCourseSoundId();
                NNS_SndPlayerStopSeq(courseSoundObject->mFirstPart.mSndHandleSlot, 0);
                courseSoundObject->mFirstPart.mStartParams.mSoundId = soundId;
                courseSoundObject->mState = 3;
            }
            func_020a826c_inline(&courseSoundObject->mFirstPart);
            break;
        case 3:
            PlaceCourseSoundObjectPartSource(&courseSoundObject->mFirstPart, &courseSoundObject->mMapObject.mPos);
            if (IsKartEnded((u16) gRaceSetup->mEntryIndex) != 0) {
                ParkMapObject(&courseSoundObject->mMapObject);
            } else if (courseSoundObject->mFirstPart.mUnk_20 == FALSE) {
                soundId = courseSoundObject->mSecondPart.mStartParams.mSoundId;
                NNS_SndPlayerStopSeq(courseSoundObject->mFirstPart.mSndHandleSlot, 0);
                courseSoundObject->mFirstPart.mStartParams.mSoundId = soundId;
                courseSoundObject->mState = 2;
            }
            func_020a826c_inline(&courseSoundObject->mFirstPart);
            break;
        case 4:
            func_020a826c_inline(&courseSoundObject->mFirstPart);
            func_020a826c_inline(&courseSoundObject->mSecondPart);
            break;
        case 5:
            func_020a826c_inline(&courseSoundObject->mFirstPart);
            break;
        case 6:
            func_020a826c_inline(&courseSoundObject->mFirstPart);
            func_020a826c_inline(&courseSoundObject->mSecondPart);
            break;
    }
}
