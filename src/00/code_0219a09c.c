#include "00/code_0219a09c.h"
#include "00/code_0218dd8c.h"
#include "00/code_0218e2dc.h"
#include "00/code_0219a0d0.h"

u32 func_ov000_0219a09c(Gt2Socket *a) {
    void *v1;
    u32 v2[2];
    v2[0] = GetElapsedMilliseconds();
    v1 = HashtableFindByFn(a->mConnections, (s32) &func_ov000_0219a0d0, v2);
    if (v1 == NULL) {
        return 1;
    }
    return 0;
}
