#include "ITCM/dma_transfer.h"
#include "ITCM/collision_slots.h"
#include "Main/Item/item_pool.h"
#include "Main/Item/item_koura_w.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Item/code_020f9334.h"
#include "Main/Item/code_020f73fc.h"
#include "Main/Item/item_object.h"
#include "Main/MapObjects/woodbox.h"
#include "Main/Course/course_color_blend.h"
#include "Main/MapObjects/data_0217b000.h"
#include "code_0200fc8c.h"

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
    enum { K0 } itemKind;

    itemObject->mFlags &= -0x1000;
    if (itemObject->mAgeFrames == 1 && (itemObject->mFlags & 0x8000000) && !(itemObject->mFlags & 0x10000000)) {
        RoundTripItemObjectData(itemObject);
    }
    if (itemObject->mFramesSinceCourseHit <= 5) {
        itemObject->mFramesSinceCourseHit += 1;
    }
    if (itemObject->mFramesSinceReset <= 5) {
        itemObject->mFramesSinceReset += 1;
    }
    if (!(itemObject->mFlags & 0x8000)) {
        itemObject->mCollisionBits = 0;
    }
    if (!(itemObject->mFlags & 0x800000)) {
        if (itemObject->mScaleTargetOrSpeed == 0) {
            if (GrowItemObjectScale(itemObject, itemPool->mScaleLimit, 0x2e1) != 0) {
                RefreshItemObjectScale(itemObject);
            } else {
                goto L_a20;
            }
        } else {
        L_a20:
            if (itemObject->mFlags & 0xc000) {
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
    if (itemObject->mFlags & 4) {
        return TRUE;
    }
    if (!(itemObject->mFlags & 0x8000) && itemObject->mCollisionSlotIndex != -1) {
        if (skipOverlapSearch == 0) {
            FindCollisionSlotsOverlappingSlot(itemObject->mCollisionSlotIndex, 0x6000);
        }
        for (overlapIndex = 0; overlapIndex < gFoundCollisionSlotCount; overlapIndex++) {
            overlapFlags = gFoundCollisionSlotFlags[overlapIndex];
            if (overlapFlags & 0x4000) {
                if (itemObject->mCollisionSlotIndex != gFoundCollisionSlotIndices[overlapIndex]) {
                    CollideItemObjectWithItemObject(itemObject, gFoundCollisionSlotObjects[overlapIndex]);
                } else {
                    continue;
                }
            } else if (overlapFlags & 0x2000) {
                ApplyMapObjectHitToItemObject(itemObject, gFoundCollisionSlotObjects[overlapIndex]);
            }
            if (itemObject->mCollisionSlotIndex == -1) {
                break;
            }
        }
    }
    collisionBits = itemObject->mCollisionBits;
    if (itemObject->mFlags & 0x8000) {
        AdvanceCourseColorBlend(&itemObject->mColorBlend, (collisionBits & 0x3c000000) >> 26, 0x800);
    } else {
        AdvanceCourseColorBlend(&itemObject->mColorBlend, (collisionBits & 0x3c000000) >> 26, 0x5000);
    }
    if (collisionBits & 0x1e34ef) {
        itemObject->mFramesSinceCourseHit = 0;
        if (collisionBits & 0x1000000) {
            itemObject->mFramesSinceReset = 0;
        }
        if (collisionBits & 0x80400) {
            if (collisionBits & 0x400) {
                if (itemObject->mCourseReleaseTimer == 0) {
                    if (itemObject->mFlags & 0x8000) {
                        itemObject->mCourseReleaseTimer = 0xb4;
                    } else {
                        itemObject->mCourseReleaseTimer = 2;
                    }
                }
            }
            if (collisionBits & 0x80000) {
                itemObject->mFlags |= 0x40000000;
            } else {
                itemObject->mFlags &= ~0x40000000;
            }
        } else {
            itemObject->mFlags &= ~0x40000000;
        }
    }
    if (itemObject->mCourseReleaseTimer != 0 && !(itemObject->mFlags & 0x180000)) {
        itemObject->mCourseReleaseTimer -= 1;
        if (itemObject->mCourseReleaseTimer == 0) {
            StartItemObjectReleaseOnTimeout(itemObject);
        }
    }
    if (itemObject->mPos.y < 0 && itemObject->mKind != 0xb && itemObject->mKind != 0xa) {
        StartItemObjectReleaseTimerSynced(itemObject, 1);
    }
    if (itemObject->mFramesSinceCourseHit < 5) {
        itemObject->mFlags &= ~0x20000;
    } else {
        itemObject->mFlags |= 0x20000;
        if (itemObject->mNormal.y < 0xfae && !(itemObject->mFlags & 0x40000080)) {
            BlendDirectionTowardUp(&itemObject->mNormal, 0xcd);
        }
    }
    if (itemObject->mFramesSinceReset < 5) {
        itemObject->mFlags |= 0x40000;
    } else {
        itemObject->mFlags &= ~0x40000;
    }
    itemKind = itemObject->mKind;
    viewRadiusScale = gItemKinds[itemKind].mViewRadiusScale;
    itemObject->mDistanceSquaredAndFlags =
        itemPool->mViewTest(itemObject->mPosPointer, itemObject->mRadius * viewRadiusScale, itemPool->mDrawDistance,
                            itemPool->mFarDistanceSquared, 0x1f);
    if (itemObject->mDistanceSquaredAndFlags & 3) {
        itemObject->mFlags |= 0x10000;
    } else {
        itemObject->mFlags &= ~0x10000;
    }
    if (itemObject->mFlags & 0x400000) {
        UpdateItemObjectSoundSource(itemObject);
    }
    itemObject->mPrevPos = itemObject->mPos;
    itemObject->mAgeFrames += 1;
    if (itemObject->mOwnerKartIndexAndFlags & 0x4000) {
        if (itemObject->mOwnerKartIndexAndFlags & 0x2000) {
            if (itemObject->mAgeFrames > 4 && !(itemObject->mFlags & 0x20000)) {
                itemObject->mOwnerKartIndexAndFlags &= ~0x4000;
            }
        } else if (itemObject->mAgeFrames > 0x1e) {
            itemObject->mOwnerKartIndexAndFlags &= ~0x4000;
        }
    }
    return FALSE;
}
