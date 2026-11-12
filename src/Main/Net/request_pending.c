#include "Main/Net/request_pending.h"
#include "Main/Unknown/unk_0217a000.h"

void ClearRequestPending(Unk021425e8 *event) {
    gConnectionWork->mRequestPending = 0;
}
