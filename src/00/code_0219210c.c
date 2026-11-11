#include "00/code_0219210c.h"
#include "00/code_021919ac.h"
#include "00/code_021a3668.h"

void gpiFreeInfoCache(GpiProfile *profile) {
    if (profile->mCache != NULL) {
        DWCi_GsFree(profile->mCache->mUnk_00[0]);
        profile->mCache->mUnk_00[0] = NULL;
        DWCi_GsFree(profile->mCache->mUnk_00[1]);
        profile->mCache->mUnk_00[1] = NULL;
        DWCi_GsFree(profile->mCache->mUnk_00[2]);
        profile->mCache->mUnk_00[2] = NULL;
        DWCi_GsFree(profile->mCache->mUnk_00[3]);
        profile->mCache->mUnk_00[3] = NULL;
        DWCi_GsFree(profile->mCache->mUnk_00[4]);
        profile->mCache->mUnk_00[4] = NULL;
        DWCi_GsFree(profile->mCache->mUnk_00[5]);
        profile->mCache->mUnk_00[5] = NULL;
        DWCi_GsFree(profile->mCache->mAimName);
        profile->mCache->mAimName = NULL;
        DWCi_GsFree(profile->mCache);
        profile->mCache = NULL;
    }
}
