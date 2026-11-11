#include "Main/Unknown/code_020f8d9c.h"
#include "Main/Unknown/code_020e0650.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_02109110.h"

#pragma thumb on

void InitItemObject(ItemObject *itemObject, u32 creationNumber, int itemKind) {
    itemObject->mCreationNumber = creationNumber;
    CreateCollisionHitLink(&itemObject->mCollisionHitLink);
    InitSoundSource(&itemObject->mSoundSource, gItemKinds[itemKind].mFalloffIndex, &itemObject->mPos);
    ReleaseSoundSourceWrapper(&itemObject->mSoundSource);
}

#pragma thumb off
