#include "00/code_02199fb0.h"
#include "00/code_021985ec.h"
#include "00/code_021988e8.h"
#include "00/code_02198a8c.h"
#include "00/code_02197e58.h"

u32 func_ov000_02199fb0(Gt2Connection *a, u32 d, u32 e) {
    s32 b = a->mState;
    if (b < 5) {
        if (a->mInitiated != FALSE) {
            gti2ConnectionClosed(a);
            if (Gt2SetResultAndCallResultCallback(a, d, NULL, 0) == FALSE) {
                return 0;
            }
        } else {
            if (b == 4) {
                a->mFreeAtAcceptReject = TRUE;
            }
            gti2ConnectionClosed(a);
        }
    } else if (b != 7) {
        gti2ConnectionClosed(a);
        if (gti2ClosedCallback(a, (void *) e) == FALSE) {
            return 0;
        }
    }
    return 1;
}
