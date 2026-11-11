#include "00/code_02194828.h"

BOOL gpiCheckForBuddy(void *unused, GpiProfile *entry, GpiProfileSearch *search) {
    if (entry->mBuddyStatus != NULL && search->mKey == entry->mBuddyStatus->mIndex) {
        search->mEntry = entry;
        return FALSE;
    }
    return TRUE;
}
