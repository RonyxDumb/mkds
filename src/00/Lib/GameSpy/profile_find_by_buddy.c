#include "00/Lib/GameSpy/profile_find_by_buddy.h"
#include "00/Lib/GameSpy/profile_walk.h"

GpiProfile *gpiFindBuddy(GpConnection *gpConnection, u32 buddyIndex) {
    GpiProfileSearch lookup;

    lookup.mKey = buddyIndex;
    lookup.mEntry = NULL;
    gpiProfileMap(gpConnection, gpiCheckForBuddy, &lookup);
    return lookup.mEntry;
}
