#include "Main/Net/buddy_changed_callback.h"
#include "00/code_021832d8.h"

void BuddyChangedCallback(void) {
    gWiFiSession->mBuddiesChanged = 1;
}
