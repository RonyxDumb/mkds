#include "00/code_0219210c.h"
#include "00/code_021919ac.h"
#include "00/code_021a3668.h"

void gpiFreeInfoCache(GpiProfile *profile) {
    if (profile->mUnk_0c != NULL) {
        DWCi_GsFree(profile->mUnk_0c->mUnk_00[0]);
        profile->mUnk_0c->mUnk_00[0] = NULL;
        DWCi_GsFree(profile->mUnk_0c->mUnk_00[1]);
        profile->mUnk_0c->mUnk_00[1] = NULL;
        DWCi_GsFree(profile->mUnk_0c->mUnk_00[2]);
        profile->mUnk_0c->mUnk_00[2] = NULL;
        DWCi_GsFree(profile->mUnk_0c->mUnk_00[3]);
        profile->mUnk_0c->mUnk_00[3] = NULL;
        DWCi_GsFree(profile->mUnk_0c->mUnk_00[4]);
        profile->mUnk_0c->mUnk_00[4] = NULL;
        DWCi_GsFree(profile->mUnk_0c->mUnk_00[5]);
        profile->mUnk_0c->mUnk_00[5] = NULL;
        DWCi_GsFree(profile->mUnk_0c->mAimName);
        profile->mUnk_0c->mAimName = NULL;
        DWCi_GsFree(profile->mUnk_0c);
        profile->mUnk_0c = NULL;
    }
}
