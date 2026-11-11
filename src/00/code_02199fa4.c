#include "00/code_02199fa4.h"
#include "00/code_02199fb0.h"

u32 gti2ConnectionCommunicationError(Gt2Connection *connection) {
    u32 result;
    u32 errorResult;
    u32 closeReason;
    u32 errorHandler;
    errorResult = 7u;
    closeReason = 2u;
    errorHandler = (u32) &gti2ConnectionError;
    result = gti2ConnectionError(connection, errorResult, closeReason);
    return result;
}
