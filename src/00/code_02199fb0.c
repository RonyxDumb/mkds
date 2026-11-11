#include "00/code_02199fb0.h"
#include "00/code_021985ec.h"
#include "00/code_021988e8.h"
#include "00/code_02198a8c.h"
#include "00/code_02197e58.h"

u32 gti2ConnectionError(Gt2Connection *connection, u32 result, u32 reason) {
    s32 state = connection->mState;
    if (state < 5) {
        if (connection->mInitiated != FALSE) {
            gti2ConnectionClosed(connection);
            if (Gt2SetResultAndCallResultCallback(connection, result, NULL, 0) == FALSE) {
                return 0;
            }
        } else {
            if (state == 4) {
                connection->mFreeAtAcceptReject = TRUE;
            }
            gti2ConnectionClosed(connection);
        }
    } else if (state != 7) {
        gti2ConnectionClosed(connection);
        if (gti2ClosedCallback(connection, (void *) reason) == FALSE) {
            return 0;
        }
    }
    return 1;
}
