#include "Main/Unknown/code_0205afa8.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0203c240.h"
#include "Main/Unknown/code_0203c8c0.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_0219b580.h"
#include "Main/Kart/KartTimes.h"

s32 func_0205afa8(void) {
    u32 c;
    s32 kartStartRank;
    u16 kartIndex;
    s32 d;
    s32 lapBits;

    kartIndex = gStruct217AA18->mKartOfParticipant[func_ov000_0219bb50()];
    kartStartRank = rres_getPlace(kartIndex);
    c = rstat_getDriverTotalMilliseconds(kartIndex) & 0x7ffff;
    if (rstat_hasDriverFinished(kartIndex) != 0 && gRaceStatus->mUnk_000[kartIndex].mStatus != 1 &&
        gStruct217AA14->mUnk_72c == FALSE) {
        c = 0x7ffff;
    }
    if (c == 0) {
        c = kartStartRank - 1;
    }
    if (gRaceStatus->mUnk_000[kartIndex].mStatus == 1) {
        d = 0;
    } else {
        d = 6 - rstat_getDriverHighestReachedLap(kartIndex);
    }
    lapBits = (d << 19) & 0x380000;
    if (rstat_hasDriverFinished(kartIndex) == 0 && gStruct217AA14->mUnk_72c == FALSE) {
        d = 1;
    } else {
        d = 0;
    }
    return c | (((d << 22) & 0x400000) | lapBits);
}
