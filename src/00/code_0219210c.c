#include "00/code_0219210c.h"
#include "00/code_021919ac.h"
#include "00/code_021a3668.h"

void gpiFreeInfoCache(Unk021919ac_node *profile) {
    if (profile->mUnk_0c != NULL) {
        func_ov000_021a3668(profile->mUnk_0c->mUnk_00[0]);
        profile->mUnk_0c->mUnk_00[0] = NULL;
        func_ov000_021a3668(profile->mUnk_0c->mUnk_00[1]);
        profile->mUnk_0c->mUnk_00[1] = NULL;
        func_ov000_021a3668(profile->mUnk_0c->mUnk_00[2]);
        profile->mUnk_0c->mUnk_00[2] = NULL;
        func_ov000_021a3668(profile->mUnk_0c->mUnk_00[3]);
        profile->mUnk_0c->mUnk_00[3] = NULL;
        func_ov000_021a3668(profile->mUnk_0c->mUnk_00[4]);
        profile->mUnk_0c->mUnk_00[4] = NULL;
        func_ov000_021a3668(profile->mUnk_0c->mUnk_00[5]);
        profile->mUnk_0c->mUnk_00[5] = NULL;
        func_ov000_021a3668(profile->mUnk_0c->mUnk_c8);
        profile->mUnk_0c->mUnk_c8 = NULL;
        func_ov000_021a3668(profile->mUnk_0c);
        profile->mUnk_0c = NULL;
    }
}
