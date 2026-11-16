#pragma once

#include "types.h"
#include "Main/MapObjects/wanwan_chain.h"
#include "Main/MapObjects/group_item_box.h"
#include "Main/MapObjects/segment_group_collision.h"
#include "Main/MapObjects/map_object_draw_list_flags.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/Graphics/model_animation.h"
#include "Main/MapObjects/attractor.h"

#define MKD_EF_BUBBLE_SHADOW_ALPHA_CAP 0xd

#define MKD_EF_BUBBLE_LEAP_SOUND_ID 0x18c

// KoopaBlock.mCollisionMapObject.mMapObject.mStateMachine states, in the order of gKoopaBlockStateTable. The block
// follows its path: ACCELERATE speeds up along the first part, CRUISE keeps the path speed, DECELERATE slows down
// along the last part.
enum {
    KOOPA_BLOCK_STATE_ACCELERATE,
    KOOPA_BLOCK_STATE_CRUISE,
    KOOPA_BLOCK_STATE_DECELERATE,
};

// MkdEfBubbleObject.mMapObject.mStateMachine states, in the order of gMkdEfBubbleStateTable. LEAP throws the bubble up
// from mBottomY until it falls back; WAIT keeps it hidden for mDelayFrameCount frames.
enum {
    MKD_EF_BUBBLE_STATE_LEAP,
    MKD_EF_BUBBLE_STATE_WAIT,
};

void UpdateKoopaBlockDecelerate(void *stateObject);
void DrawAllKoopaBlocks(void *viewMatrix);
BOOL IsKoopaBlockKind(u32 kind);
s32 GetKoopaBlockProgress(KoopaBlock *koopaBlock);
void CreateKoopaBlock(void);
void InitKoopaBlock(KoopaBlock *koopaBlock, CourseMapRow *courseRow);
MapObjectKindData *CreateMkdEfBubbleKindData(void);
MapObjectList *CreateMkdEfBubbleDrawList(void);
MapObjectList *CreateMkdEfBubbleUpdateList(void);
/* writes the polygon alpha cap (mAlphaCap of its mShadowMatrix), read only by draw routines */
void DrawMkdEfBubble(void *unused0, MkdEfBubbleObject *bubble, void *unused1, s32 alpha);
void AdvanceMkdEfBubbleAnimation(void);
void UpdateMkdEfBubble(void *unused,
                       MkdEfBubbleObject *bubble); /* skipped for objects with mFlags & 4 (parked pool objects) */
void EnterMkdEfBubbleLeap(void *stateObject);
void UpdateMkdEfBubbleLeap(void *stateObject);

extern StateCallbacks gKoopaBlockStateTable[3];

extern struct Nsbmd *gMkdEfBubble;
extern MkdEfBubbleUpdateList *gMkdEfBubbleUpdateList;
extern struct Nsbmd *gKoopaBlock;
extern MapObjectDrawList *gMkdEfBubbleDrawList;
extern struct ModelAnimation *gMkdEfBubbleNsbta;

extern const u16 gMkdEfBubbleWaitFlag;
extern const u16 gMkdEfBubbleWaitSecondFlag;
extern const MkdEfBubbleUpdateList gMkdEfBubbleUpdateListData;
extern const MapObjectDrawList gMkdEfBubbleDrawListData;
extern const MapObjectKindData gMkdEfBubbleKindData;
