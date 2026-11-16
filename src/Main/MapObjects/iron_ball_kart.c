#include "Main/MapObjects/iron_ball_kart.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "Main/Menu/keyboard_keys.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/view_matrix_setters.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/Sound/sound_source_init.h"
#include "Main/Menu/keyboard_char_tables.h"
#include "Main/Sound/sound_ortho_quad_and_item_box_timer_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "matrix_3x3_basic.h"
#include "fixed_vector_math.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/MapObjects/bound.h"

MapObjectModel *gIronBall;

Vec3 gIronBallInitialScale = {0x4000, 0x4000, 0x4000};

MapObjectKindDescriptor gIronBallKindDescriptor = {0,
                                             {0, 0},
                                             0x134,
                                             InitIronBall,
                                             CreateIronBallKindData,
                                             CreateIronBallDrawList,
                                             CreateIronBallShadowDrawList,
                                             0,
                                             CreateIronBallUpdateList};
MapObjectKindDescriptor gIronBallDrawOnlyKindDescriptor = {0,
                                             {0, 0},
                                             0x134,
                                             InitIronBall,
                                             CreateEmptyMapObjectKindData,
                                             CreateIronBallDrawList};

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
    return GetKeyboardValueForKeyId(gKeyboardKeys.mChosenKeyId);
}

#pragma thumb off

void InitIronBall(IronBall *ironBall) {
    Vec3 scale = gIronBallInitialScale;

    SetMapObjectScale(&ironBall->mMapObject, &scale);
    ironBall->mMapObject.mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(SoundSource));
    InitSoundSource(&ironBall->mMapObject.mSound->mSoundSource, 10, &ironBall->mMapObject.mPos);
    ironBall->mMapObject.mFarDistanceSquared = gSoundFalloffs[10].mFarDistanceSquared;
    ironBall->mSoundOffZoneMask = DecimalNonZeroDigitsToBitMask(ironBall->mMapObject.mCourseMapRow->mSettings[6]);
}

u32 CollideKartWithIronBall(IronBall *ironBall, void *kart, u8 *firstResponse, u8 *response) {
    u32 firstResponseValue = *firstResponse;
    u32 responseValue = *response;

    if (firstResponseValue == 1) {
        ironBall->mHeightSpeed = IRON_BALL_JUMP_SPEED;
        return 0;
    }
    return (u8) responseValue;
}

void CreateIronBall(void *mapObjectList) {
    gIronBall = CreateMapObjectModelNsbmd(mapObjectList, "IronBall.nsbmd");
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
