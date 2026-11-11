#include "00/code_02199a0c.h"
#include "00/code_02199ad8.h"
#include "00/code_02197e58.h"

u32 gti2DeliverReliableMessage(Gt2Connection *connection, int type, const u8 *message, u32 len) {
    int result;
    connection->mExpectedSerialNumber = connection->mExpectedSerialNumber + 1;
    if (type == 0) {
        result = gti2HandleAppReliable(connection, message, len);
        if (result == 0) {
            return 0;
        }
    } else if (type == 1) {
        result = gti2HandleClientChallenge(connection, message, len);
        if (result == 0) {
            return 0;
        }
    } else if (type == 2) {
        result = gti2HandleServerChallenge(connection, message, len);
        if (result == 0) {
            return 0;
        }
    } else if (type == 3) {
        result = gti2HandleClientResponse(connection, message, len);
        if (result == 0) {
            return 0;
        }
    } else if (type == 4) {
        result = gti2HandleAccept(connection);
        if (result == 0) {
            return 0;
        }
    } else if (type == 5) {
        result = gti2HandleReject(connection, message, len);
        if (result == 0) {
            return 0;
        }
    } else if ((type == 6) && (result = gti2HandleClose(connection), result == 0)) {
        return 0;
    }
    return 1;
}
