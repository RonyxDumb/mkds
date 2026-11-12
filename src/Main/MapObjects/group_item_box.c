#include "Main/MapObjects/group_item_box.h"
#include "Main/System/heap.h"
#include "Main/System/heap_call.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020debec.h"
#include "Main/System/state_machine_init.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Graphics/model_animation_loop_mode.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_020d8c74.h"
#include "Main/MapObjects/send_obj_shadow.h"
#include "Main/Unknown/code_020e5668.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/MapObjects/model_animation_entries.h"
#include "Main/MapObjects/nsbmd_model_draw.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02147cd8.h"

#pragma thumb on
void CreateMkdEfBubble(void) {
    void *nsbmd;

    nsbmd = FindCourseMapObjFile("mkd_ef_bubble.nsbmd");
    CreateNsbmd(&gMkdEfBubble, nsbmd, NULL);
    SetNsbmdPolygonIdLightEmiAll(gMkdEfBubble, 0x3f, 2, 0x294a);
    gMkdEfBubbleNsbta = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x38);
    InitModelAnimationWithEntries(1, gMkdEfBubble, gMkdEfBubbleNsbta, nsbmd,
                                  FindCourseMapObjFile("mkd_ef_bubble.nsbta"));
    SetModelAnimationEntryLoopMode(gMkdEfBubbleNsbta, 0, 1);
}

void InitMkdEfBubble(MkdEfBubbleObject *bubble, CourseMapRow *row) {
    InitStateMachine(&bubble->mMapObject.mStateMachine, gMkdEfBubbleStateTable, 2, bubble);
    bubble->mDelayFrameCount = row->mSettings[0];
    bubble->mInitialY = bubble->mMapObject.mPos.y;
    bubble->mBottomY = bubble->mMapObject.mPos.y - 0x10000;
    bubble->mMapObject.mPosStep.x = 0;
    bubble->mMapObject.mPosStep.y = 0;
    bubble->mMapObject.mPosStep.z = 0;
    bubble->mAngleZ = 0;
    bubble->mMapObject.mStateMachine.mNextState = 0;
    bubble->mMapObject.mStateMachine.mNextStateRequested = 1;
    RefreshShadowMatrix(&bubble->mShadowMatrix, &bubble->mMapObject.mPos,
                        MUL_FIXED12_NO_ROUND(bubble->mMapObject.mScale.x, 0x18000), 0xd);
    bubble->mMapObject.mFlags |= data_02158740;
}
#pragma thumb off

MapObjectKindData *CreateGroupItemBoxKindData(void) {
    MapObjectKindData *kindData;

    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = data_02158700;
    return kindData;
}

MapObjectList *CreateGroupItemBoxUpdateList(void) {
    gGroupItemBoxUpdateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    *gGroupItemBoxUpdateList = data_021586d8;
    SetUpdateListSlot(&gGroupItemBoxUpdateList);
    return gGroupItemBoxUpdateList;
}

void UpdateGroupItemBoxHeightOffset(void) {
    s32 sine;

    sine = FX_SinIdx(gGroupItemBoxHeightAngle);
    gGroupItemBoxHeightOffset = MUL_FIXED12_NO_ROUND(sine, 0x4000);
    gGroupItemBoxHeightAngle += 0x2d8;
    gGroupItemBoxShadowScaleWord = 0xf00 - (sine >> 4);
    gGroupItemBoxShadowScale.x = 0x1666;
    gGroupItemBoxShadowScale.y = 0x1666;
    gGroupItemBoxShadowScale.z = 0x1666;
}

void UpdateGroupItemBox(void *unused, ItemBox *itemBox) {
    if (itemBox->mFollower.mGroupFollower.mGroupIndex != 0xffff) {
        if (AdvanceGroupFollowerWithSpeeds(&itemBox->mFollower) != 0) {
            if (itemBox->mFollower.mGroupFollower.mFromEntry->mUnk_10 != 0) {
                SetupGroupFollowerWithSpeeds(&itemBox->mFollower, 0, 1);
            }
        }
        GetGroupFollowerCurvePosition(&itemBox->mFollower.mGroupFollower, &itemBox->mMapObject.mPos);
        if (itemBox->mFollower.mGroupFollower.mFromEntry->mUnk_0d != 0 &&
            itemBox->mFollower.mGroupFollower.mToEntry->mUnk_0d != 0) {
            itemBox->mMapObject.mFlags |= data_021586d4;
        } else {
            itemBox->mMapObject.mFlags &= ~0x20;
        }
        itemBox->mMapObject.mPos.y += gGroupItemBoxHeightOffset;
        itemBox->mMapObject.mPos.y += 0x10000;
    }
    if (itemBox->mShadowMode == 0) {
        SetShadowPositionXZ(&itemBox->mUnk_0b4, &itemBox->mMapObject.mPos);
    }
    UpdateItemBox(unused, itemBox);
}
