#include "Main/MapObjects/pukupuku_kind_descriptor.h"
#include "Main/MapObjects/pukupuku.h"
#include "Main/MapObjects/pukupuku_init.h"
#include "Main/System/heap.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/pushed_motion.h"
#include "Main/MapObjects/choropu.h"
#include "Main/MapObjects/map_object_draw_list_flags.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/System/heap_call.h"
#include "Main/System/state_machine_init.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/update_list_slot.h"
#include "matrix_3x3_basic.h"
#include "fixed_vector_math.h"
#include "Main/MapObjects/rotary.h"
#include "Main/MapObjects/bridge.h"

const MapObjectKindDescriptor gPukupukuKindDescriptor = {0,
                                                         {0, 0},
                                                         0x10c,
                                                         InitPukupuku,
                                                         CreatePukupukuKindData,
                                                         CreatePukupukuDrawList,
                                                         CreatePukupukuShadowDrawList,
                                                         NULL,
                                                         CreatePukupukuUpdateList,
                                                         NULL,
                                                         {NULL, NULL, NULL, NULL}};

#pragma thumb on

StateCallbacks gPukupukuStateTable[4] = {{EnterPukupukuHop, UpdatePukupukuHop},
                                         {EnterPukupukuPushed, UpdatePukupukuPushed},
                                         {EnterPukupukuWaitRespawn, UpdatePukupukuWaitRespawn},
                                         {EnterPukupukuRespawn, UpdatePukupukuRespawn}};

void InitPukupuku(Pukupuku *pukupuku, Vec3 *position) {
    StateDualHandler_Create(&pukupuku->mPushedObject.mMapObject.mStateMachine, gPukupukuStateTable, 4, pukupuku);
    pukupuku->mPushedObject.mMapObject.mPos.y =
        pukupuku->mPushedObject.mMapObject.mPos.y +
        MUL_FIXED12_NO_ROUND(pukupuku->mPushedObject.mMapObject.mScale.y, 0xa000);
    pukupuku->mInitialPos = pukupuku->mPushedObject.mMapObject.mPos;
    pukupuku->mJumpsUntilHighJump = PUKUPUKU_JUMPS_UNTIL_HIGH_JUMP;
    pukupuku->mPushedObject.mMapObject.mPosStep.x = 0;
    pukupuku->mPushedObject.mMapObject.mPosStep.y = 0;
    pukupuku->mPushedObject.mMapObject.mPosStep.z = 0;
    InitPushedMotion(&pukupuku->mPushedObject, pukupuku->mPushedObject.mMapObject.mPos.y - 0x1e000, 0x400, 0x400,
                     0x4000, 0x1800);
    pukupuku->mPushedObject.mMapObject.mStateMachine.mNextState = PUKUPUKU_STATE_HOP;
    pukupuku->mPushedObject.mMapObject.mStateMachine.mNextStateRequested = 1;
    RefreshShadowMatrix(&pukupuku->mShadowMatrix, position,
                        MUL_FIXED12_NO_ROUND(pukupuku->mPushedObject.mMapObject.mScale.x, 0x12000), 0xd);
    pukupuku->mInitialGroundY = position->y;
    {
        Vec3 *secondRow = &pukupuku->mShadowMatrix.mMatrix.mRows[1];
        pukupuku->mGroundSlopeX = -FX_Div(secondRow->x, secondRow->y);
        pukupuku->mGroundSlopeZ = -FX_Div(secondRow->z, secondRow->y);
    }
}
#pragma thumb off
