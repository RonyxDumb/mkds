#include "00/Lib/GameSpy/code_02194808.h"
#include "00/Lib/GameSpy/gpiProfile.h"

GpiProfile *GpiFindProfileByBuddyIndex(GpConnection *gpConnection, u32 buddyIndex) {
    GpiProfileSearch lookup;

    lookup.mKey = buddyIndex;
    lookup.mEntry = NULL;
    GpiForEachProfileWhileNonZero(gpConnection, gpiCheckForBuddy, &lookup);
    return lookup.mEntry;
}
