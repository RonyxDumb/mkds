#include "Main/Unknown/code_02099020.h"

#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020d278c.h"
#include "Main/Unknown/unk_02156000.h"

void InitPakkunSpit(MapObject *mapObject) {
    u32 flags = mapObject->mFlags;
    u32 addedFlags = data_02156598;
    u32 newFlags = ((flags) | (addedFlags));
    mapObject->mFlags = newFlags;
    ParkMapObject(mapObject);
    CreateMapObjectSoundSourceFalloff2(mapObject);
}

u32 CollideKartWithPakkunSpit(PakkunSpit *pakkunSpit, Kart *kart, u8 *c, u8 *d) {
    u32 v1 = *c;
    u8 result = *d;
    if (v1 == 1) {
        pakkunSpit->mUnk_00.mFlags = pakkunSpit->mUnk_00.mFlags | data_usa_02156590;
        pakkunSpit->mState = 1;
        if (kart->mItemEffect == 1 || kart->mItemEffect == 3) {
            pakkunSpit->mUnk_00.mDistanceSquaredAndFlags =
                pakkunSpit->mUnk_00.mDistanceSquaredAndFlags | data_usa_02156594;
        }
        StartSoundIfKartStarOrKiller(&pakkunSpit->mUnk_00, kart);
    }
    return result;
}

void UpdatePakkunSpit(void *mapObjectList, PakkunSpit *pakkunSpit) {
    s32 falloffIndex;
    SoundStartParams soundRequest;
    Unk0209905c_d0_08 *entry;
    switch (pakkunSpit->mState) {
        case 0:
            pakkunSpit->mHeightOffset = pakkunSpit->mHeightOffset + pakkunSpit->mHeightSpeed;
            pakkunSpit->mHeightSpeed = pakkunSpit->mHeightSpeed - 0x1000;
            if (pakkunSpit->mHeightOffset <= 0) {
                pakkunSpit->mHeightOffset = 0;
                pakkunSpit->mHeightSpeed = 0x5800;
                if ((pakkunSpit->mUnk_00.mDistanceSquaredAndFlags & 4) == 0) {
                    if (pakkunSpit->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                        falloffIndex = 2;
                    } else if (pakkunSpit->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                        falloffIndex = 3;
                    } else {
                        falloffIndex = 4;
                    }
                    soundRequest.mSoundId = 0x1af;
                    soundRequest.mPositionSource = &pakkunSpit->mUnk_00.mPos;
                    soundRequest.mFalloffIndex = falloffIndex;
                    soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&pakkunSpit->mUnk_00.mPos);
                    StartSoundFromParams(&soundRequest);
                }
            }
            if (AdvanceGroupFollower(&pakkunSpit->mFollower) != FALSE && pakkunSpit->mFollower.mForward == 0) {
                pakkunSpit->mState = 1;
            } else {
                GetGroupFollowerLinearPosStep(&pakkunSpit->mFollower, &pakkunSpit->mUnk_00.mPos,
                                              &pakkunSpit->mUnk_00.mUnk_10);
                pakkunSpit->mUnk_00.mPos.y = pakkunSpit->mUnk_00.mPos.y + (pakkunSpit->mHeightOffset + 0xf000);
            }
            if (pakkunSpit->mEmitter == NULL) {
                return;
            }
            if ((pakkunSpit->mUnk_00.mFlags & 0x12) != 0) {
                pakkunSpit->mEmitter->mUnk_24 |= 2;
                return;
            }
            PlaceEffect(pakkunSpit->mEmitter, &pakkunSpit->mUnk_00.mPos);
            pakkunSpit->mEmitter->mUnk_24 &= ~2;
            return;
        case 1:
            if (pakkunSpit->mEmitter != NULL) {
                for (entry = pakkunSpit->mEmitter->mUnk_08; entry != NULL; entry = entry->mUnk_00) {
                    entry->mUnk_26 = entry->mUnk_24;
                }
                StopEffectAndClearPointer((void **) &pakkunSpit->mEmitter);
            }
            ParkMapObject(&pakkunSpit->mUnk_00);
            return;
    }
}

void CreatePakkunSpitKindData(void) {
    CreateMapObjectKindDataWithSound(&CollideKartWithPakkunSpit, NULL, NULL, 1, 1, (0x0000018du));
}
