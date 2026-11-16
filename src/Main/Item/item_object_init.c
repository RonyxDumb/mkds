#include "Main/Item/item_object_init.h"
#include "Main/MapObjects/collision_hit_link_create.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Sound/sound_start.h"
#include "Main/Sound/sound_source_init.h"
#include "Main/Item/item_pool.h"

#pragma thumb on

void InitItemObject(ItemObject *itemObject, u32 creationNumber, int itemKind) {
    itemObject->mCreationNumber = creationNumber;
    CreateCollisionHitLink(&itemObject->mCollisionHitLink);
    StructMQRacerEntry_SomeFn_45(&itemObject->mSoundSource, gItemKinds[itemKind].mFalloffIndex, &itemObject->mPos);
    ReleaseSoundSourceWrapper(&itemObject->mSoundSource);
}

#pragma thumb off
