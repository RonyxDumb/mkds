#include "00/code_02199f80.h"
#include "00/code_02198a8c.h"
#include "00/code_02199fb0.h"

u32 gti2ConnectionMemoryError(Gt2Connection *connection) {
    int sentClosed;
    u32 result;
    sentClosed = gti2SendClosed(connection);
    if (sentClosed != 0) {
        result = gti2ConnectionError(connection, 1, 4);
        return result;
    }
    return 0;
}
