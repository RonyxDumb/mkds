#include "00/code_02199a0c.h"
#include "00/code_02199ad8.h"
#include "00/code_02197e58.h"

u32 gti2DeliverReliableMessage(Gt2Connection *connection, int type, const u8 *message, u32 len) {
    int result;
    connection->mExpectedSerialNumber = connection->mExpectedSerialNumber + 1;
    if (type == 0) {
        result = func_ov000_02199dd0(connection, message, len);
        if (result == 0) {
            return 0;
        }
    } else if (type == 1) {
        result = func_ov000_02199d4c(connection, message, len);
        if (result == 0) {
            return 0;
        }
    } else if (type == 2) {
        result = func_ov000_02199c98(connection, message, len);
        if (result == 0) {
            return 0;
        }
    } else if (type == 3) {
        result = func_ov000_02199bb4(connection, message, len);
        if (result == 0) {
            return 0;
        }
    } else if (type == 4) {
        result = func_ov000_02199b70(connection);
        if (result == 0) {
            return 0;
        }
    } else if (type == 5) {
        result = func_ov000_02199b14(connection, message, len);
        if (result == 0) {
            return 0;
        }
    } else if ((type == 6) && (result = func_ov000_02199ad8(connection), result == 0)) {
        return 0;
    }
    return 1;
}
