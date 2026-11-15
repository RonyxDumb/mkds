#include "Main/Item/item_kinoko.h"
#include "Main/Sound/sound_start.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Item/code_020f73fc.h"
#include "Main/Item/item_f_box.h"
#include "Main/MapObjects/data_02159000.h"
#include "Main/MapObjects/ob_pakkun_sf.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/data_027e0000.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Item/item_in_use.h"
#include "Main/Item/item_pool.h"
#include "Main/Item/code_020f6be8.h"
#include "Main/Item/item_slot_tables.h"
#include "Main/Item/item_object.h"
#include "code_02147cd8.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/MapObjects/code_020e6a74.h"
#include "Main/Course/course_color_blend.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Item/code_020f9334.h"
#include "Main/Item/held_item.h"
#include "Main/Item/pooled_item_box.h"
#include "Main/Kart/kart_participant_record.h"
#include "Main/Sound/kart_sound_callbacks.h"
#include "Main/Sound/kart_surface_sound.h"
#include "Main/Sound/data_0216c000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Item/item_object_throw.h"
#include "Main/Item/item_koura_r_kart_items.h"
#include "Main/Item/item_object_bouncing.h"
#include "Main/Sound/sound_distance_change_reset.h"
#include "Main/System/state_machine_init.h"
#include "Main/Item/item_link_following.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/rock.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Race/race.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Sound/data_0210b000.h"
#include "code_0212d214.h"
#include "Main/MapObjects/code_020e01f0.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Menu/data_0217d000.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Sound/sound_seq.h"
#include "code_0212df7c.h"
#include "Main/Race/race_clock.h"
#include "Main/Kart/karts.h"
#include "Main/Item/item_teresa_offset.h"
#include "ITCM/collision_slots.h"
#include "Main/Item/code_020f4dfc.h"
#include "Main/Item/code_020f50b4.h"

const u16 gItemKinokoNoOwnerBit = ITEM_OWNER_NO_OWNER;

const ItemInfo gItemInfoKinoko = {1, 1, 3, 1, 0, 0, StartItemKinokoBoost};

const ItemKind gItemKindKinoko = {0x138,
                                  8,
                                  0x20,
                                  -1,
                                  -1,
                                  {0},
                                  (void (*)(void *)) ResetItemKinoko,
                                  NULL,
                                  NULL,
                                  NULL,
                                  NULL,
                                  (void (*)(void *, void *, void *)) DrawItemKinoko,
                                  ComputeViewTest,
                                  NULL,
                                  NULL,
                                  NULL,
                                  0,
                                  0,
                                  NULL,
                                  0,
                                  NULL,
                                  0,
                                  0,
                                  0x4b0000,
                                  2,
                                  0x3800,
                                  0x5000,
                                  0x34cd,
                                  0x1000,
                                  0x1b33,
                                  0x19a,
                                  0x23d,
                                  1,
                                  0,
                                  1,
                                  {0},
                                  0,
                                  1,
                                  1,
                                  1,
                                  1,
                                  0};

// Item hook of the mushroom: starts the kart boost, uses up one held object, marks the use,
// and makes the event call when the mode is 5.
void StartItemKinokoBoost(ItemInUse *itemInUse, HeldItem *heldItem) {
    StartKartKinokoBoost(heldItem->mKartItems->mKart);
    RemoveHeldItemObjects(heldItem, 1);
    itemInUse->mKartItems->mKinokoBoostStarted = TRUE;
    if (gRaceSetup->mMode != MODE_WIFI) {
        return;
    }
    AddItemDataFrameOnly(3);
}

void ResetItemKinoko(ItemKinoko *kinoko) {
    kinoko->mVisible = TRUE;
}

// Runs DrawItemObjectModel with the last two parameters swapped when the 0x134 word is set.
void DrawItemKinoko(ItemKinoko *kinoko, void *viewAxis, void *model) {
    if (kinoko->mVisible == FALSE) {
        return;
    }
    DrawItemObjectModel(&kinoko->mBouncingItemObject.mItemObject, model, viewAxis);
}

// Decreases the 0x130 word by one; when it goes below zero StartItemObjectReleaseTimerSynced runs first.
void AdvanceRestingItemKinoko(ItemKinoko *kinoko) {
    kinoko->mTimer--;
    if (kinoko->mTimer < 0) {
        StartItemObjectReleaseTimerSynced(&kinoko->mBouncingItemObject.mItemObject, 0);
    }
    AdvanceRestingItemObject(&kinoko->mBouncingItemObject.mItemObject);
}

// Sets the object up through AdvanceBouncingItem when the 0x74 word allows it.
void AdvanceBouncingItemKinoko(ItemKinoko *kinoko) {
    u32 collisionHitLink;

    AdvanceBouncingItem(&kinoko->mBouncingItemObject, 0x385, 0xff8, 0x733, &collisionHitLink);
    if ((kinoko->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_LANDED) == 0) {
        return;
    }
    if ((kinoko->mBouncingItemObject.mItemObject.mFlags &
         (ITEM_OBJECT_FLAG_FADE_OUT_STARTED | ITEM_OBJECT_FLAG_RELEASE_STARTED)) != 0) {
        return;
    }
    StopSound(&kinoko->mBouncingItemObject.mItemObject.mSoundSource, 0xda);
    StartRestingItemObject(&kinoko->mBouncingItemObject.mItemObject, &collisionHitLink);
    if ((kinoko->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAGS_ENDING) == 0) {
        kinoko->mBouncingItemObject.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceRestingItemKinoko;
    }
}

// Returns what StartItemObjectOrZero gives, with its 0x134 and 0x130 words cleared.
ItemKinoko *StartItemKinokoOrZero(void) {
    ItemKinoko *kinoko;

    kinoko = StartItemObjectOrZero(ITEM_OBJECT_KIND_KINOKO, 8, &gItemKinokoVec3UnitY, &gItemKinokoVec3UnitY);
    if (kinoko == NULL) {
        return NULL;
    }
    if ((kinoko->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAGS_ENDING) == 0) {
        kinoko->mBouncingItemObject.mItemObject.mAdvance = NULL;
    }
    FreeItemObjectCollisionSlot(&kinoko->mBouncingItemObject.mItemObject);
    kinoko->mVisible = FALSE;
    kinoko->mTimer = 0;
    return kinoko;
}

// Stores the two Vec3s in the object and sets the word at 0x80.
void ShowItemKinokoAt(ItemKinoko *kinoko, Vec3 *normal, Vec3 *pos) {
    kinoko->mVisible = TRUE;
    SetCourseColorBlendColor(&kinoko->mBouncingItemObject.mItemObject.mColorBlend, 1);
    if (normal != NULL) {
        kinoko->mBouncingItemObject.mItemObject.mNormal = *normal;
        kinoko->mBouncingItemObject.mItemObject.mFlags |= ITEM_OBJECT_FLAG_KEEP_NORMAL;
    }
    if (pos == NULL) {
        return;
    }
    kinoko->mBouncingItemObject.mItemObject.mPos = *pos;
    VEC_Subtract(&kinoko->mBouncingItemObject.mItemObject.mPos, &kinoko->mBouncingItemObject.mItemObject.mPrevPos,
                 &kinoko->mBouncingItemObject.mItemObject.mVelocity);
}

// Runs the object's first word and stores the 0x120 and 0x130 words.
void StartBouncingItemKinoko(void **kinokoSlot, Vec3 *velocity, s32 timer) {
    ItemKinoko *kinoko;

    kinoko = kinokoSlot[0];
    kinoko->mBouncingItemObject.mItemObject.mOwnerKartIndexAndFlags |= gItemKinokoNoOwnerBit;
    CreateItemObjectCollisionSlot(&kinoko->mBouncingItemObject.mItemObject);
    StartItemObjectSoundSource(&kinoko->mBouncingItemObject.mItemObject);
    InitBouncingItem(&kinoko->mBouncingItemObject, 0, velocity);
    if ((kinoko->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAGS_ENDING) == 0) {
        kinoko->mBouncingItemObject.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceBouncingItemKinoko;
    }
    kinoko->mTimer = timer;
    kinokoSlot[0] = NULL;
}
