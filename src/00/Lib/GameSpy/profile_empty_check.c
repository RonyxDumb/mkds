#include "00/Lib/GameSpy/profile_empty_check.h"

u32 gpiCanFreeProfile(GpiProfile *profile) {
    if (profile != NULL && profile->mCache == 0 && profile->mBuddyStatus == NULL && profile->mPeerSig == NULL &&
        profile->mAuthSig == NULL) {
        return 1;
    }
    return 0;
}
