#include "00/Lib/GameSpy/code_021947e4.h"

u32 GpiIsProfileEmpty(GpiProfile *profile) {
    if (profile != NULL && profile->mCache == 0 && profile->mBuddyStatus == NULL && profile->mPeerSig == NULL &&
        profile->mAuthSig == NULL) {
        return 1;
    }
    return 0;
}
