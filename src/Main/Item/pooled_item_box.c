#include "Main/Item/pooled_item_box.h"
#include "Main/System/heap.h"
#include "Main/Kart/kart_participant_record.h"
#include "Main/MapObjects/map_object_create.h"
#include "Main/Item/code_020f73fc.h"

#include "Main/MapObjects/item_box.h"
#include "Main/Item/held_item.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Item/item_kinoko.h"
#include "Main/Item/item_in_use.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Item/item_object.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Item/code_020f9334.h"
#include "Main/Sound/sound_start.h"
#include "code_0212d214.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/pooled_item_box_init.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/System/heap_call.h"
#include "Main/Item/item_slot_tables.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Item/data_027e0000.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Menu/data_0217d000.h"
#include "Main/Sound/sound_system.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "code_02147cd8.h"
#include "code_0212df7c.h"
#include "ITCM/collision_slots.h"
#include "Main/Item/bouncing_item_box_timers.h"

u32 gPooledMapObjectNextIndex;
struct MapObject **gPooledMapObjects;
s32 gPooledMapObjectCount;
struct CourseMapRow gPooledMapObjectRow;

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
    s32 objectIndex;
    switch (gRaceSetup->mMode) {
        case MODE_BATTLE:
            gPooledMapObjectCount = 0xb;
            break;
        case MODE_MISSION_RUN:
            gPooledMapObjectCount = 0x20;
            break;
        case MODE_WIFI:
            gPooledMapObjectCount = 6;
            break;
        default:
            gPooledMapObjectCount = 3;
            break;
    }
    gPooledMapObjects = HeapAlloc(GetHeap(GetCurrentHeapCall()), gPooledMapObjectCount * 4);
    buf = gPooledMapObjectVec3Zero;
    gPooledMapObjectRow.mPosition = buf;
    gPooledMapObjectRow.mRotationDegrees = buf;
    gPooledMapObjectRow.mScale = gVec3Ones;
    gPooledMapObjectRow.mKind = 0x6f;
    gPooledMapObjectRow.mSettings[3] = 1;
    for (objectIndex = 0; objectIndex < gPooledMapObjectCount; objectIndex++) {
        gPooledMapObjects[objectIndex] = CreateMapObjectFromCourseMapRow(&gPooledMapObjectRow, 0x6f);
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
    if (gRaceSetup->mMode != MODE_WIFI) {
        return;
    }
    if (kartIndex == gRaceSetup->mEntryIndex) {
        return;
    }
    SetKartItemsHeldItemByInfoIndex(&gKartItems[kartIndex], 0xe);
}

// Battle only: hands item 17 to a kart with an empty hand when its timer is 0 and counts the running timers down.
void UpdateBouncingItemBoxTimers(void) {
    s32 kartIndex;
    s32 timer;
    KartItems *kartItems;
    HeldItem *heldItem;
    NNSSndSeqPlayer **sndHandle;
    u32 fadeFrame = 0;
    u32 seqArcNo = 0;
    if (gRaceSetup->mMode != MODE_BATTLE) {
        return;
    }
    for (kartIndex = 0; kartIndex < 8; kartIndex++) {
        timer = gBouncingItemBoxTimers[kartIndex];
        if (timer < 0) {
            continue;
        }
        kartItems = GetKartItems(kartIndex);
        heldItem = &kartItems->mHeldItem;
        if (heldItem->mItemInfoIndex != 0x13) {
            continue;
        }
        if (timer == 0) {
            SetHeldItem(heldItem, 0x11);
            gBouncingItemBoxTimerRunning[kartIndex] = 0;
            if (kartIndex == gRaceSetup->mEntryIndex && (gRaceSoundKind & 1)) {
                sndHandle = TakeSoundHandleEntry(GetSoundHandlePool(0));
                if (gSoundModeHolder.mSeqStartEnabled != 0) {
                    if (sndHandle[0] != NULL) {
                        NNS_SndPlayerStopSeq(sndHandle, 0);
                    }
                    if (sndHandle[0] != NULL) {
                        NNS_SndPlayerStopSeq(sndHandle, fadeFrame);
                    }
                    NNS_SndArcPlayerStartSeqArc(sndHandle, seqArcNo, 0x3f);
                }
            }
        } else if (gBouncingItemBoxTimerRunning[kartIndex] != 0 && timer > 0) {
            gBouncingItemBoxTimers[kartIndex]--;
        }
    }
}

// Battle: the first time a removed kart gets here it sets its bouncing item box timer from -1 to 0 and releases its
// items.
void ReleaseEliminatedKartItems(s32 kartIndex) {
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
    if ((box->mBouncingItemObject.mItemObject.mFlags & 0x180000) == 0) {
        box->mBouncingItemObject.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceBouncingItemBox;
    }
}

void ReleaseBouncingItemBox(BouncingItemBox *box) {
    u16 kartIndex = box->mBouncingItemObject.mItemObject.mOwnerKartIndexAndFlags & ~0xff00;
    if ((s32) gBouncingItemBoxTimers[kartIndex] > 0) {
        gBouncingItemBoxTimerRunning[kartIndex] = 1;
    }
    ParkPooledMapObject(box->mPooledMapObject);
}

void CollideKartWithBouncingItemBox(BouncingItemBox *box, void *kart) {
    StartItemSlotAndEffects(&box->mBouncingItemObject.mItemObject.mPos, kart, 0,
                            (box->mBouncingItemObject.mItemObject.mFlags & 0x10000) ? 1 : 0, 0);
}

void ResetBouncingItemBox(BouncingItemBox *box) {
    box->mScaleRatio = 0x666;
    ResetPooledMapObject(box->mPooledMapObject);
    box->mKartIsEntry =
        (u16) (box->mBouncingItemObject.mItemObject.mOwnerKartIndexAndFlags & ~0xff00) == gRaceSetup->mEntryIndex;
    if (box->mKartIsEntry != 0) {
        (box->mPooledMapObject)->mShadowMode = 2;
    }
    SetBouncingItemBoxTimer(box->mBouncingItemObject.mItemObject.mOwnerKartIndexAndFlags & ~0xff00, 0x258);
}

void AdvanceBouncingItemBoxInUse(ItemInUse *itemInUse, BouncingItemBox *box) {
    Vec3 scale;
    ItemBox *mapObject = box->mPooledMapObject;
    s32 scaleRatio;
    if (box->mKartIsEntry != 0) {
        VEC_MultAdd(MUL_FIXED12_NO_ROUND(itemInUse->mKartScaleFactorTimesBase.z, -28877),
                    &itemInUse->mKartOrientation.mRows[1], &box->mBouncingItemObject.mItemObject.mPos,
                    &box->mMapObjectPos);
        scaleRatio = box->mScaleRatio;
        scale.x = MUL_FIXED12_NO_ROUND(box->mBouncingItemObject.mItemObject.mScale.x, scaleRatio);
        scale.y = MUL_FIXED12_NO_ROUND(box->mBouncingItemObject.mItemObject.mScale.y, scaleRatio);
        scale.z = MUL_FIXED12_NO_ROUND(box->mBouncingItemObject.mItemObject.mScale.z, scaleRatio);
        SetPooledMapObjectFromItem(mapObject, box->mBouncingItemObject.mItemObject.mAlpha, &scale);
    } else {
        box->mMapObjectPos = box->mBouncingItemObject.mItemObject.mPos;
        SetPooledMapObjectFromItem(mapObject, box->mBouncingItemObject.mItemObject.mAlpha,
                                   &box->mBouncingItemObject.mItemObject.mScale);
    }
    AdvancePooledMapObject(mapObject);
}

s32 InitBouncingItemBox(ItemInUse *itemInUse, BouncingItemBox *box) {
    StartItemObjectSoundSource(&box->mBouncingItemObject.mItemObject);
    box->mBouncingItemObject.mItemObject.mOwnerKartIndexAndFlags |= gBouncingItemBoxUntilCourseHitBit;
    if (box->mKartIsEntry != 0) {
        (box->mPooledMapObject)->mShadowMode = 1;
    }
    if ((itemInUse->mKartItems->mFlags & KART_ITEMS_THROW_FORWARD) != 0) {
        ThrowBouncingItem(&box->mBouncingItemObject, itemInUse, 0, 1, 0x4000, 0x3000, 0x59a);
        StartSound(&box->mBouncingItemObject.mItemObject.mSoundSource, 0xda, 0x7f, 0);
        box->mThrownForward = 1;
        return box->mThrownForward;
    } else {
        ThrowBouncingItem(&box->mBouncingItemObject, itemInUse, 0, 0, 0x4000, 0x3000, 0x59a);
        if (itemInUse->mKartVelocityLength < 0x1000) {
            box->mBouncingItemObject.mItemObject.mVelocity.x = 0;
            box->mBouncingItemObject.mItemObject.mVelocity.y = 0;
            box->mBouncingItemObject.mItemObject.mVelocity.z = 0;
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
    if ((box->mBouncingItemObject.mItemObject.mFlags & 0x180000) != 0) {
        if ((box->mBouncingItemObject.mItemObject.mFlags & 0x80000) != 0) {
            AdvanceItemObjectFadeOut(&box->mBouncingItemObject.mItemObject);
        } else if ((box->mBouncingItemObject.mItemObject.mFlags & 0x100000) != 0) {
            AdvanceItemObjectReleaseTimer(&box->mBouncingItemObject.mItemObject);
        }
    } else if ((box->mBouncingItemObject.mItemObject.mFlags & 0x8000) != 0) {
        if (gRaceSetup->mMode == MODE_BATTLE) {
            kartIndex = box->mBouncingItemObject.mItemObject.mOwnerKartIndexAndFlags & ~0xff00;
            framesLeft = gBouncingItemBoxTimers[kartIndex] - 0x3c;
            if (framesLeft < box->mBouncingItemObject.mItemObject.mAlpha) {
                box->mBouncingItemObject.mItemObject.mAlpha = framesLeft;
            }
            if (framesLeft < 0xa) {
                FreeItemObjectCollisionSlot(&box->mBouncingItemObject.mItemObject);
                if (framesLeft == 0) {
                    ReleaseItemPoolObject(&gItemPools[box->mBouncingItemObject.mItemObject.mKind],
                                          &box->mBouncingItemObject.mItemObject);
                    return;
                }
            }
            gBouncingItemBoxTimers[kartIndex]--;
        }
        AdvanceRestingItemObject(&box->mBouncingItemObject.mItemObject);
    } else if ((box->mBouncingItemObject.mItemObject.mFlags & 0x4000) != 0) {
        AdvanceFallingItemObject(&box->mBouncingItemObject.mItemObject);
    } else {
        if (box->mThrownForward != 0) {
            AdvanceBouncingItem(&box->mBouncingItemObject, 0x1ec, 0xfec, 0, &buf);
        } else {
            AdvanceBouncingItem(&box->mBouncingItemObject, 0x2e1, 0xf85, 0, &buf);
        }
        if ((box->mBouncingItemObject.mItemObject.mFlags & 8) != 0 &&
            (box->mBouncingItemObject.mItemObject.mFlags & 3) == 0) {
            if (box->mThrownForward != 0) {
                box->mBouncingItemObject.mItemObject.mVelocity.y <<= 1;
            }
            StopSound(&box->mBouncingItemObject.mItemObject.mSoundSource, 0xda);
            StartRestingItemObject(&box->mBouncingItemObject.mItemObject, &buf);
        }
    }
    kartIsEntry = box->mKartIsEntry;
    mapObject = box->mPooledMapObject;
    if (kartIsEntry != 0 && box->mScaleRatio < 0x1000) {
        box->mScaleRatio += 0xcd;
        scaleRatio = box->mScaleRatio;
        scale.x = MUL_FIXED12_NO_ROUND(box->mBouncingItemObject.mItemObject.mScale.x, scaleRatio);
        scale.y = MUL_FIXED12_NO_ROUND(box->mBouncingItemObject.mItemObject.mScale.y, scaleRatio);
        scale.z = MUL_FIXED12_NO_ROUND(box->mBouncingItemObject.mItemObject.mScale.z, scaleRatio);
        VEC_Subtract(&box->mBouncingItemObject.mItemObject.mPos, &box->mMapObjectPos, &offset);
        VEC_MultAdd(MUL_FIXED12_NO_ROUND(box->mScaleRatio, box->mScaleRatio), &offset, &box->mMapObjectPos,
                    &box->mMapObjectPos);
        SetPooledMapObjectFromItem(mapObject, box->mBouncingItemObject.mItemObject.mAlpha, &scale);
    } else {
        box->mMapObjectPos = box->mBouncingItemObject.mItemObject.mPos;
        SetPooledMapObjectFromItem(mapObject, box->mBouncingItemObject.mItemObject.mAlpha,
                                   &box->mBouncingItemObject.mItemObject.mScale);
    }
    AdvancePooledMapObject(mapObject);
}
