#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_020d2dec.h"
#include "Main/Unknown/code_020f73fc.h"

#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020deb2c.h"
#include "Main/Unknown/code_020f2dac.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f7000.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0210e000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_021053d8.h"
#include "Main/Unknown/code_021053e4.h"
#include "Main/Unknown/code_02105550.h"
#include "Main/Unknown/code_021052fc.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020f813c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02147cd8.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "ITCM/code_01ffcf7c.h"

const u16 gBouncingItemBoxUntilCourseHitBit = 0x2000;

const ItemInfo gItemInfoKiller = {1, 1, 0xd, 1, 0, 0, StartItemKiller};

const ItemKind gItemKindKiller = {
    0x12c, 1, 1,    -1,  -1,   {0}, NULL, NULL,     NULL, NULL,   NULL, NULL, ComputeViewTest, NULL,   NULL,  NULL,
    0,     0, NULL, 0,   NULL, 1,   0,    0x4b0000, 2,    0x319a, 0,    0,    0x1000,          0x1b33, 0x19a, 0x11f,
    0,     1, 0,    {0}, 0,    1,   1,    1,        1,    0};

#pragma thumb on
// Allocates the map objects that the item objects with a map-object look take from the pool.
void CreatePooledMapObjects(void) {
    Vec3 buf;
    s32 i;
    switch (gRaceSetup->mMode) {
        case MODE_BATTLE:
            gPooledMapObjectCount = 0xb;
            break;
        case MODE_MISSION_RUN:
            gPooledMapObjectCount = 0x20;
            break;
        case 5:
            gPooledMapObjectCount = 6;
            break;
        default:
            gPooledMapObjectCount = 3;
            break;
    }
    gPooledMapObjects = HeapAlloc(GetHeap(GetCurrentHeapCall()), gPooledMapObjectCount * 4);
    buf = data_0215a6cc;
    gPooledMapObjectRow.mUnk_00 = buf;
    gPooledMapObjectRowDegrees = buf;
    gPooledMapObjectRowScale = gVec3Ones;
    gPooledMapObjectRow.mKind = 0x6f;
    gPooledMapObjectRow.mUnk_2e = 1;
    for (i = 0; i < gPooledMapObjectCount; i++) {
        gPooledMapObjects[i] = CreateMapObjectFromCourseMapRow(&gPooledMapObjectRow, 0x6f);
    }
    gPooledMapObjectNextIndex = 0;
}
#pragma thumb off

void StartItemKiller(ItemInUse *itemInUse, HeldItem *heldItem) {
    StartKartKiller(heldItem->mKartItems->mKart);
    RemoveHeldItemObjects(heldItem, 1);
    SetActiveItem(itemInUse->mKartItems, 0xe);
}

void ResetKartActiveItemAfterKiller(s32 kartIndex) {
    gKartItems[kartIndex].mActiveItem = 0x13;
    if (gRaceSetup->mMode != 5) {
        return;
    }
    if (kartIndex == gRaceSetup->mEntryIndex) {
        return;
    }
    func_020efd84(&gKartItems[kartIndex], 0xe);
}

// Battle only: hands item 17 to a kart with an empty hand when its timer is 0 and counts the running timers down.
void UpdateBouncingItemBoxTimers(void) {
    s32 i;
    s32 timer;
    KartItems *kartItems;
    HeldItem *heldItem;
    NNSSndSeqPlayer **sndHandle;
    u32 fadeFrame = 0;
    u32 seqArcNo = 0;
    if (gRaceSetup->mMode != MODE_BATTLE) {
        return;
    }
    for (i = 0; i < 8; i++) {
        timer = gBouncingItemBoxTimers[i];
        if (timer < 0) {
            continue;
        }
        kartItems = &gKartItems[(u16) i];
        heldItem = &kartItems->mHeldItem;
        if (heldItem->mItemInfoIndex != 0x13) {
            continue;
        }
        if (timer == 0) {
            SetHeldItem(heldItem, 0x11);
            gBouncingItemBoxTimerRunning[i] = 0;
            if (i == gRaceSetup->mEntryIndex && (data_0217c780 & 1)) {
                sndHandle = TakeSoundHandleEntry(GetSoundHandlePool(0));
                if (data_0217d084.mUnk_0c != 0) {
                    if (sndHandle[0] != NULL) {
                        NNS_SndPlayerStopSeq(sndHandle, 0);
                    }
                    if (sndHandle[0] != NULL) {
                        NNS_SndPlayerStopSeq(sndHandle, fadeFrame);
                    }
                    NNS_SndArcPlayerStartSeqArc(sndHandle, seqArcNo, 0x3f);
                }
            }
        } else if (gBouncingItemBoxTimerRunning[i] != 0 && timer > 0) {
            gBouncingItemBoxTimers[i]--;
        }
    }
}

void func_02104f84(s32 kartIndex) {
    if (gRaceSetup->mMode != MODE_BATTLE) {
        return;
    }
    if ((s32) gBouncingItemBoxTimers[kartIndex] >= 0) {
        return;
    }
    gBouncingItemBoxTimers[kartIndex] = 0;
    ReleaseKartItems(&gKartItems[kartIndex]);
}

void StartBouncingItemBox(BouncingItemBox *box) {
    if (box->mKartIsEntry != 0) {
        (box->mPooledMapObject)->mShadowMode = 1;
    }
    if ((box->mUnk_000.mItemObject.mFlags & 0x180000) == 0) {
        box->mUnk_000.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceBouncingItemBox;
    }
}

void ReleaseBouncingItemBox(BouncingItemBox *box) {
    u16 kartIndex = box->mUnk_000.mItemObject.mOwnerKartIndexAndFlags & ~0xff00;
    if ((s32) gBouncingItemBoxTimers[kartIndex] > 0) {
        gBouncingItemBoxTimerRunning[kartIndex] = 1;
    }
    ParkPooledMapObject(box->mPooledMapObject);
}

void CollideKartWithBouncingItemBox(BouncingItemBox *box, void *kart) {
    StartItemSlotAndEffects(&box->mUnk_000.mItemObject.mPos, kart, 0,
                            (box->mUnk_000.mItemObject.mFlags & 0x10000) ? 1 : 0, 0);
}

void ResetBouncingItemBox(BouncingItemBox *box) {
    box->mScaleRatio = 0x666;
    ResetPooledMapObject(box->mPooledMapObject);
    box->mKartIsEntry = (u16) (box->mUnk_000.mItemObject.mOwnerKartIndexAndFlags & ~0xff00) == gRaceSetup->mEntryIndex;
    if (box->mKartIsEntry != 0) {
        (box->mPooledMapObject)->mShadowMode = 2;
    }
    gBouncingItemBoxTimers[(u16) (box->mUnk_000.mItemObject.mOwnerKartIndexAndFlags & ~0xff00)] = 0x258;
}

void AdvanceBouncingItemBoxInUse(ItemInUse *itemInUse, BouncingItemBox *box) {
    Vec3 scale;
    ItemBox *mapObject = box->mPooledMapObject;
    s32 scaleRatio;
    if (box->mKartIsEntry != 0) {
        VEC_MultAdd(MUL_FIXED12_NO_ROUND(itemInUse->mKartScaleFactorTimesBase.z, -28877),
                    &itemInUse->mKartOrientation.mUnk_00[1], &box->mUnk_000.mItemObject.mPos, &box->mMapObjectPos);
        scaleRatio = box->mScaleRatio;
        scale.x = MUL_FIXED12_NO_ROUND(box->mUnk_000.mItemObject.mScale.x, scaleRatio);
        scale.y = MUL_FIXED12_NO_ROUND(box->mUnk_000.mItemObject.mScale.y, scaleRatio);
        scale.z = MUL_FIXED12_NO_ROUND(box->mUnk_000.mItemObject.mScale.z, scaleRatio);
        SetPooledMapObjectFromItem(mapObject, box->mUnk_000.mItemObject.mAlpha, &scale);
    } else {
        box->mMapObjectPos = box->mUnk_000.mItemObject.mPos;
        SetPooledMapObjectFromItem(mapObject, box->mUnk_000.mItemObject.mAlpha, &box->mUnk_000.mItemObject.mScale);
    }
    AdvancePooledMapObject(mapObject);
}

s32 InitBouncingItemBox(ItemInUse *itemInUse, BouncingItemBox *box) {
    StartItemObjectSoundSource(&box->mUnk_000.mItemObject);
    box->mUnk_000.mItemObject.mOwnerKartIndexAndFlags |= gBouncingItemBoxUntilCourseHitBit;
    if (box->mKartIsEntry != 0) {
        (box->mPooledMapObject)->mShadowMode = 1;
    }
    if ((itemInUse->mKartItems->mFlags & KART_ITEMS_THROW_FORWARD) != 0) {
        ThrowBouncingItem(&box->mUnk_000, itemInUse, 0, 1, 0x4000, 0x3000, 0x59a);
        StartSound(&box->mUnk_000.mItemObject.mSoundSource, 0xda, 0x7f, 0);
        box->mThrownForward = 1;
        return box->mThrownForward;
    } else {
        ThrowBouncingItem(&box->mUnk_000, itemInUse, 0, 0, 0x4000, 0x3000, 0x59a);
        if (itemInUse->mKartVelocityLength < 0x1000) {
            box->mUnk_000.mItemObject.mVelocity.x = 0;
            box->mUnk_000.mItemObject.mVelocity.y = 0;
            box->mUnk_000.mItemObject.mVelocity.z = 0;
        }
        box->mThrownForward = 0;
        return box->mThrownForward;
    }
}

void AdvanceBouncingItemBox(BouncingItemBox *box) {
    u32 buf;
    Vec3 offset;
    Vec3 scale;
    u16 kartIndex;
    s32 framesLeft;
    s32 scaleRatio;
    s32 kartIsEntry;
    ItemBox *mapObject;
    if ((box->mUnk_000.mItemObject.mFlags & 0x180000) != 0) {
        if ((box->mUnk_000.mItemObject.mFlags & 0x80000) != 0) {
            AdvanceItemObjectFadeOut(&box->mUnk_000.mItemObject);
        } else if ((box->mUnk_000.mItemObject.mFlags & 0x100000) != 0) {
            AdvanceItemObjectReleaseTimer(&box->mUnk_000.mItemObject);
        }
    } else if ((box->mUnk_000.mItemObject.mFlags & 0x8000) != 0) {
        if (gRaceSetup->mMode == MODE_BATTLE) {
            kartIndex = box->mUnk_000.mItemObject.mOwnerKartIndexAndFlags & ~0xff00;
            framesLeft = gBouncingItemBoxTimers[kartIndex] - 0x3c;
            if (framesLeft < box->mUnk_000.mItemObject.mAlpha) {
                box->mUnk_000.mItemObject.mAlpha = framesLeft;
            }
            if (framesLeft < 0xa) {
                FreeItemObjectCollisionSlot(&box->mUnk_000.mItemObject);
                if (framesLeft == 0) {
                    ReleaseItemPoolObject(&gItemPools[box->mUnk_000.mItemObject.mKind], &box->mUnk_000.mItemObject);
                    return;
                }
            }
            gBouncingItemBoxTimers[kartIndex]--;
        }
        AdvanceRestingItemObject(&box->mUnk_000.mItemObject);
    } else if ((box->mUnk_000.mItemObject.mFlags & 0x4000) != 0) {
        AdvanceFallingItemObject(&box->mUnk_000.mItemObject);
    } else {
        if (box->mThrownForward != 0) {
            AdvanceBouncingItem(&box->mUnk_000, 0x1ec, 0xfec, 0, &buf);
        } else {
            AdvanceBouncingItem(&box->mUnk_000, 0x2e1, 0xf85, 0, &buf);
        }
        if ((box->mUnk_000.mItemObject.mFlags & 8) != 0 && (box->mUnk_000.mItemObject.mFlags & 3) == 0) {
            if (box->mThrownForward != 0) {
                box->mUnk_000.mItemObject.mVelocity.y <<= 1;
            }
            StopSound(&box->mUnk_000.mItemObject.mSoundSource, 0xda);
            StartRestingItemObject(&box->mUnk_000.mItemObject, &buf);
        }
    }
    kartIsEntry = box->mKartIsEntry;
    mapObject = box->mPooledMapObject;
    if (kartIsEntry != 0 && box->mScaleRatio < 0x1000) {
        box->mScaleRatio += 0xcd;
        scaleRatio = box->mScaleRatio;
        scale.x = MUL_FIXED12_NO_ROUND(box->mUnk_000.mItemObject.mScale.x, scaleRatio);
        scale.y = MUL_FIXED12_NO_ROUND(box->mUnk_000.mItemObject.mScale.y, scaleRatio);
        scale.z = MUL_FIXED12_NO_ROUND(box->mUnk_000.mItemObject.mScale.z, scaleRatio);
        VEC_Subtract(&box->mUnk_000.mItemObject.mPos, &box->mMapObjectPos, &offset);
        VEC_MultAdd(MUL_FIXED12_NO_ROUND(box->mScaleRatio, box->mScaleRatio), &offset, &box->mMapObjectPos,
                    &box->mMapObjectPos);
        SetPooledMapObjectFromItem(mapObject, box->mUnk_000.mItemObject.mAlpha, &scale);
    } else {
        box->mMapObjectPos = box->mUnk_000.mItemObject.mPos;
        SetPooledMapObjectFromItem(mapObject, box->mUnk_000.mItemObject.mAlpha, &box->mUnk_000.mItemObject.mScale);
    }
    AdvancePooledMapObject(mapObject);
}
