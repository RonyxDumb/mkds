#include "01/code_02184390.h"
#include "01/code_021843b0.h"
#include "01/code_02188950.h"

void DonketuFallKartCollisionCallback(Unk02188950 *donketu) {
    SetKartCollisionCallback(donketu, DonketuKartCollisionCallback);
    donketu->mUnk_2d8 = 0xb;
}
