#include "Main/Net/request_pending.h"
#include "Main/MapObjects/data_0217a000.h"

void ClearRequestPending(WirelessMessage *event) {
    gConnectionWork->mRequestPending = 0;
}
