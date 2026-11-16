#include "ITCM/dma_transfer.h"
#include "ITCM/collision_slots.h"
#include "Main/Item/item_pool.h"
#include "Main/MapObjects/rock.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "ITCM/sphere_collision.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Item/item_object_reset_collide.h"
#include "Main/Item/item_object_release.h"
#include "Main/Item/item_object.h"
#include "Main/MapObjects/woodbox.h"
#include "Main/Course/course_color_blend.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "reset_interrupts_halt.h"

void StartDmaTransfer(u32 channelIndex, const void *source, void *destination, u32 control) {
    vu32 *channelRegs;
    u32 savedIrq = OS_DisableInterrupts();

    *(vu32 *) (0x4000000 + channelIndex * 12 + 0xb0) = (u32) source;
    channelRegs = (vu32 *) (0x40000b0 + channelIndex * 12);
    channelRegs[1] = (u32) destination;
    channelRegs[2] = control;
    OS_RestoreInterrupts(savedIrq);
}

void StartDmaTransferAndChannel0Dummy(u32 channelIndex, const void *source, void *destination, u32 control) {
    vu32 *channel0Regs = (vu32 *) 0x40000b0;
    vu32 *channelRegs;
    u32 savedIrq = OS_DisableInterrupts();

    *(vu32 *) (0x4000000 + channelIndex * 12 + 0xb0) = (u32) source;
    channelRegs = OFFSET_PTR(vu32, channel0Regs, channelIndex * 12);
    channelRegs[1] = (u32) destination;
    channelRegs[2] = control;
    *channel0Regs;
    *channel0Regs;
    if (channelIndex == 0) {
        channelRegs[0] = 0;
        channelRegs[1] = 0;
        channelRegs[2] = 0x81400001;
    }
    OS_RestoreInterrupts(savedIrq);
}

void StartDmaTransferWithoutIrqDisable(u32 channelIndex, const void *source, void *destination, u32 control) {
    u32 channelOffset = channelIndex * 12;
    vu32 *channelRegs = (vu32 *) (0x40000b0 + channelOffset);

    *(vu32 *) (0x4000000 + channelOffset + 0xb0) = (u32) source;
    channelRegs[1] = (u32) destination;
    channelRegs[2] = control;
}

void StartDmaTransferAndChannel0DummyWithoutIrqDisable(u32 channelIndex, const void *source, void *destination,
                                                       u32 control) {
    vu32 *channel0Regs = (vu32 *) 0x40000b0;
    vu32 *channelRegs;

    *(vu32 *) (0x4000000 + channelIndex * 12 + 0xb0) = (u32) source;
    channelRegs = (vu32 *) (0x40000b0 + channelIndex * 12);
    channelRegs[1] = (u32) destination;
    channelRegs[2] = control;
    *channel0Regs;
    *channel0Regs;
    if (channelIndex == 0) {
        channelRegs[0] = 0;
        channelRegs[1] = 0;
        channelRegs[2] = 0x81400001;
    }
    *channel0Regs;
    *channel0Regs;
}

BOOL UpdateItemObject(ItemPool *itemPool, ItemObject *itemObject, s32 skipOverlapSearch) {
    s32 overlapIndex;
    u32 collisionBits;
    u32 overlapFlags;
    s32 grewScale;
    s32 viewRadiusScale;
    enum { ITEM_KIND_FIRST } itemKind;

    itemObject->mFlags &= -0x1000;
    if (itemObject->mAgeFrames == 1 && (itemObject->mFlags & ITEM_OBJECT_FLAG_WIFI_RACE) &&
        !(itemObject->mFlags & ITEM_OBJECT_FLAG_FROM_DATA)) {
        RoundTripItemObjectData(itemObject);
    }
    if (itemObject->mFramesSinceCourseHit <= ITEM_OBJECT_RECENT_HIT_FRAMES) {
        itemObject->mFramesSinceCourseHit += 1;
    }
    if (itemObject->mFramesSinceReset <= ITEM_OBJECT_RECENT_HIT_FRAMES) {
        itemObject->mFramesSinceReset += 1;
    }
    if (!(itemObject->mFlags & ITEM_OBJECT_FLAG_RESTING)) {
        itemObject->mCollisionBits = 0;
    }
    if (!(itemObject->mFlags & ITEM_OBJECT_FLAG_FIXED_SCALE)) {
        if (itemObject->mScaleTargetOrSpeed == 0) {
            if (GrowItemObjectScale(itemObject, itemPool->mScaleLimit, 0x2e1) != 0) {
                RefreshItemObjectScale(itemObject);
            } else {
                goto L_a20;
            }
        } else {
        L_a20:
            if (itemObject->mFlags & (ITEM_OBJECT_FLAG_LAUNCHED | ITEM_OBJECT_FLAG_RESTING)) {
                grewScale = GrowItemObjectScale(itemObject, itemPool->mTargetScale, 0x19a);
                if (SwingItemObjectScale(itemObject) == 0 && grewScale != 0) {
                    RefreshItemObjectScale(itemObject);
                }
            } else if (GrowItemObjectScale(itemObject, itemPool->mTargetScale, itemPool->mScaleStep) != 0) {
                RefreshItemObjectScale(itemObject);
            }
        }
    }
    if (itemObject->mAdvance != NULL) {
        itemObject->mAdvance(itemObject);
    }
    if (itemObject->mFlags & ITEM_OBJECT_FLAG_RELEASED) {
        return TRUE;
    }
    if (!(itemObject->mFlags & ITEM_OBJECT_FLAG_RESTING) && itemObject->mCollisionSlotIndex != -1) {
        if (skipOverlapSearch == 0) {
            FindCollisionSlotsOverlappingSlot(itemObject->mCollisionSlotIndex, 0x6000);
        }
        for (overlapIndex = 0; overlapIndex < gFoundCollisionSlotCount; overlapIndex++) {
            overlapFlags = gFoundCollisionSlotFlags[overlapIndex];
            if (overlapFlags & COLLISION_SLOT_FLAG_ITEM_OBJECT) {
                if (itemObject->mCollisionSlotIndex != gFoundCollisionSlotIndices[overlapIndex]) {
                    CollideItemObjectWithItemObject(itemObject, gFoundCollisionSlotObjects[overlapIndex]);
                } else {
                    continue;
                }
            } else if (overlapFlags & COLLISION_SLOT_FLAG_MAP_OBJECT) {
                ApplyMapObjectHitToItemObject(itemObject, gFoundCollisionSlotObjects[overlapIndex]);
            }
            if (itemObject->mCollisionSlotIndex == -1) {
                break;
            }
        }
    }
    collisionBits = itemObject->mCollisionBits;
    if (itemObject->mFlags & ITEM_OBJECT_FLAG_RESTING) {
        AdvanceCourseColorBlend(&itemObject->mColorBlend, (collisionBits & 0x3c000000) >> 26, 0x800);
    } else {
        AdvanceCourseColorBlend(&itemObject->mColorBlend, (collisionBits & 0x3c000000) >> 26, 0x5000);
    }
    if (collisionBits & COURSE_HIT_GROUND) {
        itemObject->mFramesSinceCourseHit = 0;
        if (collisionBits & 0x1000000) {
            itemObject->mFramesSinceReset = 0;
        }
        if (collisionBits & 0x80400) {
            if (collisionBits & 0x400) {
                if (itemObject->mCourseReleaseTimer == 0) {
                    if (itemObject->mFlags & ITEM_OBJECT_FLAG_RESTING) {
                        itemObject->mCourseReleaseTimer = ITEM_OBJECT_COURSE_RELEASE_RESTING_FRAMES;
                    } else {
                        itemObject->mCourseReleaseTimer = ITEM_OBJECT_COURSE_RELEASE_NOT_RESTING_FRAMES;
                    }
                }
            }
            if (collisionBits & COURSE_HIT_BOOST_SURFACE) {
                itemObject->mFlags |= ITEM_OBJECT_FLAG_ON_BOOST_SURFACE;
            } else {
                itemObject->mFlags &= ~ITEM_OBJECT_FLAG_ON_BOOST_SURFACE;
            }
        } else {
            itemObject->mFlags &= ~ITEM_OBJECT_FLAG_ON_BOOST_SURFACE;
        }
    }
    if (itemObject->mCourseReleaseTimer != 0 && !(itemObject->mFlags & ITEM_OBJECT_FLAGS_ENDING)) {
        itemObject->mCourseReleaseTimer -= 1;
        if (itemObject->mCourseReleaseTimer == 0) {
            StartItemObjectReleaseOnTimeout(itemObject);
        }
    }
    if (itemObject->mPos.y < 0 && itemObject->mKind != ITEM_OBJECT_KIND_TERESA &&
        itemObject->mKind != ITEM_OBJECT_KIND_GESSO) {
        StartItemObjectReleaseTimerSynced(itemObject, 1);
    }
    if (itemObject->mFramesSinceCourseHit < ITEM_OBJECT_RECENT_HIT_FRAMES) {
        itemObject->mFlags &= ~ITEM_OBJECT_FLAG_NO_RECENT_COURSE_HIT;
    } else {
        itemObject->mFlags |= ITEM_OBJECT_FLAG_NO_RECENT_COURSE_HIT;
        if (itemObject->mNormal.y < 0xfae &&
            !(itemObject->mFlags & (ITEM_OBJECT_FLAG_ON_BOOST_SURFACE | ITEM_OBJECT_FLAG_KEEP_NORMAL))) {
            BlendDirectionTowardUp(&itemObject->mNormal, 0xcd);
        }
    }
    if (itemObject->mFramesSinceReset < ITEM_OBJECT_RECENT_HIT_FRAMES) {
        itemObject->mFlags |= ITEM_OBJECT_FLAG_COURSE_HIT_ATTRIBUTE;
    } else {
        itemObject->mFlags &= ~ITEM_OBJECT_FLAG_COURSE_HIT_ATTRIBUTE;
    }
    itemKind = itemObject->mKind;
    viewRadiusScale = gItemKinds[itemKind].mViewRadiusScale;
    itemObject->mDistanceSquaredAndFlags =
        itemPool->mViewTest(itemObject->mPosPointer, itemObject->mRadius * viewRadiusScale, itemPool->mDrawDistance,
                            itemPool->mFarDistanceSquared, 0x1f);
    if (itemObject->mDistanceSquaredAndFlags & ITEM_OBJECT_VIEW_TEST_OUTSIDE_BITS) {
        itemObject->mFlags |= ITEM_OBJECT_FLAG_OUT_OF_VIEW;
    } else {
        itemObject->mFlags &= ~ITEM_OBJECT_FLAG_OUT_OF_VIEW;
    }
    if (itemObject->mFlags & ITEM_OBJECT_FLAG_HAS_SOUND_SOURCE) {
        UpdateItemObjectSoundSource(itemObject);
    }
    itemObject->mPrevPos = itemObject->mPos;
    itemObject->mAgeFrames += 1;
    if (itemObject->mOwnerKartIndexAndFlags & ITEM_OWNER_EXCLUDED) {
        if (itemObject->mOwnerKartIndexAndFlags & ITEM_OWNER_EXCLUDED_UNTIL_COURSE_HIT) {
            if (itemObject->mAgeFrames > ITEM_OBJECT_EXCLUDED_UNTIL_COURSE_HIT_AGE_FRAMES &&
                !(itemObject->mFlags & ITEM_OBJECT_FLAG_NO_RECENT_COURSE_HIT)) {
                itemObject->mOwnerKartIndexAndFlags &= ~ITEM_OWNER_EXCLUDED;
            }
        } else if (itemObject->mAgeFrames > ITEM_OBJECT_EXCLUDED_AGE_FRAMES) {
            itemObject->mOwnerKartIndexAndFlags &= ~ITEM_OWNER_EXCLUDED;
        }
    }
    return FALSE;
}
