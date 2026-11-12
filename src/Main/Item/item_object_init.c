#include "Main/Item/item_object_init.h"
#include "Main/MapObjects/collision_hit_link_create.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Sound/sound_start.h"
#include "Main/Sound/sound_source_init.h"

#pragma thumb on

void InitItemObject(ItemObject *itemObject, u32 creationNumber, int itemKind) {
    itemObject->mCreationNumber = creationNumber;
    CreateCollisionHitLink(&itemObject->mCollisionHitLink);
    InitSoundSource(&itemObject->mSoundSource, gItemKinds[itemKind].mFalloffIndex, &itemObject->mPos);
    ReleaseSoundSourceWrapper(&itemObject->mSoundSource);
}

#pragma thumb off
