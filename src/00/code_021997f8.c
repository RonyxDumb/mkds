#include "00/code_021997f8.h"
#include "00/code_0218e2dc.h"
#include "00/code_02197e58.h"

void gti2SetPendingAck(Gt2Connection *connection) {
    u32 now;
    if (connection->mPendingAck == 0) {
        connection->mPendingAck = 1;
        now = GetElapsedMilliseconds();
        connection->mPendingAckTime = now;
    }
}
