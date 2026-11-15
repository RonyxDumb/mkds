#include "00/Lib/GameSpy/info_cache_free.h"
#include "00/Lib/GameSpy/login_connect.h"
#include "00/Lib/DWC/dwc_memfunc.h"

void gpiFreeInfoCache(GpiProfile *profile) {
    if (profile->mCache != NULL) {
        DWCi_GsFree(profile->mCache->mNick);
        profile->mCache->mNick = NULL;
        DWCi_GsFree(profile->mCache->mUniquenick);
        profile->mCache->mUniquenick = NULL;
        DWCi_GsFree(profile->mCache->mEmail);
        profile->mCache->mEmail = NULL;
        DWCi_GsFree(profile->mCache->mFirstname);
        profile->mCache->mFirstname = NULL;
        DWCi_GsFree(profile->mCache->mLastname);
        profile->mCache->mLastname = NULL;
        DWCi_GsFree(profile->mCache->mHomepage);
        profile->mCache->mHomepage = NULL;
        DWCi_GsFree(profile->mCache->mAimName);
        profile->mCache->mAimName = NULL;
        DWCi_GsFree(profile->mCache);
        profile->mCache = NULL;
    }
}
