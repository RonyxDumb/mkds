#include "01/code_021842b4.h"
#include "01/code_02184390.h"
#include "01/code_02188158.h"

s32 UpdateDonketuFall(Unk02188950 *donketu) {
    if (donketu->mVelocity.y < 0) {
        SetKartCollisionCallback(donketu, DonketuFallKartCollisionCallback);
        donketu->mUnk_150 = 7;
        donketu->mUnk_158 = NULL;
    }
    return 0;
}
