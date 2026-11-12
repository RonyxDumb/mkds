#include "00/code_02194808.h"
#include "00/gpiProfile.h"

GpiProfile *GpiFindProfileByBuddyIndex(GpConnection *a, u32 b) {
    GpiProfileSearch s;

    s.mKey = b;
    s.mEntry = NULL;
    GpiForEachProfileWhileNonZero(a, gpiCheckForBuddy, &s);
    return s.mEntry;
}
