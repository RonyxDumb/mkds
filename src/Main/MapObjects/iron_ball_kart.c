#include "Main/MapObjects/iron_ball_kart.h"
#include "Main/System/heap.h"
#include "Main/Unknown/code_0209b634.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020aa81c.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/System/heap_call.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/Sound/sound_source_init.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/code_020ab000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "fx_mtx33.h"
#include "code_02147cd8.h"

#pragma opt_propagation off

#pragma thumb on

void MoveKeyboardCursorToValue(u16 value) {
    KeyboardRect *foundRect;
    u16 callbackValue;

    foundRect = FindKeyboardRectByValue(value);
    if (foundRect != NULL) {
        gKeyboardKeys.mCursorRect = foundRect;
        if (gKeyboardKeys.mCursorCallback != NULL) {
            callbackValue = gKeyboardKeys.mCursorCallback(GetKeyboardRectValue(foundRect), 0);
            if (callbackValue != 0) {
                gKeyboardKeys.mCursorRect = FindKeyboardRectByValue(callbackValue);
            }
        }
    }
}

s32 GetKeyboardCursorValue(void) {
    return GetKeyboardRectValue(gKeyboardKeys.mCursorRect);
}

s32 GetKeyboardChosenKeyValue(void) {
    return GetKeyboardValueForKeyId(gKeyboardLayoutKeyIds[0]);
}

#pragma thumb off

void InitIronBall(IronBall *ironBall) {
    Vec3 scale = data_02167974;

    SetMapObjectScale(&ironBall->mMapObject, &scale);
    ironBall->mMapObject.mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x44);
    InitSoundSource(&ironBall->mMapObject.mSound->mSoundSource, 10, &ironBall->mMapObject.mPos);
    ironBall->mMapObject.mFarDistanceSquared = gSoundFalloffs[10].mFarDistanceSquared;
    ironBall->mSoundOffKind3ShapeListMask =
        DecimalNonZeroDigitsToBitMask(ironBall->mMapObject.mCourseMapRow->mSettings[6]);
}

u32 CollideKartWithIronBall(IronBall *ironBall, void *kart, u8 *firstResponse, u8 *response) {
    u32 firstResponseValue = *firstResponse;
    u32 responseValue = *response;

    if (firstResponseValue == 1) {
        ironBall->mHeightSpeed = 0xa000;
        return 0;
    }
    return (u8) responseValue;
}

void CreateIronBall(void *mapObjectList) {
    gIronBall = CreateMapObjectModelNsbmd(mapObjectList, gIronBallNsbmdName);
    SetMapObjectModelPolygonId(gIronBall, 0x3f);
}

void SetupDrawIronBall(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gIronBall);
}

void DrawIronBall(void *mapObjectList, IronBall *ironBall) {
    u32 gxParam;
    MtxFx33 rotationMatrix;

    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(&ironBall->mMapObject.mPos), 0xc);
    if (ironBall->mRotateZAngle != 0) {
        MTX_RotZ33_(&rotationMatrix, SIN_OF_ANGLE((u16) ironBall->mRotateZAngle),
                    COS_OF_ANGLE((u16) ironBall->mRotateZAngle));
        NNS_G3dGeBufferOP_N(0x1a, &rotationMatrix, 9);
    }
    NNS_G3dGeBufferOP_N(0x1b, &ironBall->mMapObject.mScale, 3);
    DrawMapObjectModel(mapObjectList, gIronBall, ironBall);
}
