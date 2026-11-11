#include "00/code_021947e4.h"

u32 GpiIsProfileEmpty(GpiProfile *a) {
    if (a != NULL && a->mCache == 0 && a->mBuddyStatus == NULL && a->mPeerSig == NULL && a->mAuthSig == NULL) {
        return 1;
    }
    return 0;
}
