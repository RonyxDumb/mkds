#include "00/code_0219a09c.h"
#include "00/GameSpy/hashtable.h"
#include "00/GameSpy/nonport.h"
#include "00/code_0219a0d0.h"

u32 func_ov000_0219a09c(Gt2Socket *a) {
    void *v1;
    u32 v2[2];
    v2[0] = func_ov000_0218e8c4();
    v1 = HashtableFindByFn(a->mConnections, (s32) &func_ov000_0219a0d0, v2);
    if (v1 == NULL) {
        return 1;
    }
    return 0;
}
