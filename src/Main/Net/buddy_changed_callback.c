#include "Main/Net/buddy_changed_callback.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "Main/Net/wifi_session.h"

void BuddyChangedCallback(s32 index, void *arg) {
    gWiFiSession->mBuddiesChanged = 1;
}
