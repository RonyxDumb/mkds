#include "00/code_02198584.h"
#include "00/code_02197e58.h"
#include "00/code_021985ec.h"

u32 gti2ConnectionThink(Gt2Connection *connection, u32 now) {
    int result;
    result = gti2CheckTimeout(connection, now);
    if (result == 0) {
        return 0;
    }
    result = gti2CheckKeepAlive(connection, now);
    if (result == 0) {
        return 0;
    }
    result = gti2SendRetries(connection, now);
    if (result == 0) {
        return 0;
    }
    result = gti2CheckPendingAck(connection, now);
    if (result != 0) {
        return 1;
    }
    return 0;
}
