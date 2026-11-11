#include "00/code_02199614.h"
#include "00/code_0218d818.h"
#include "00/code_0219903c.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_02134398.h"
#include "00/code_02197e58.h"
#include "00/code_021985ec.h"
#include "00/code_021988e8.h"
#include "00/code_02198a8c.h"
#include "00/code_02199000.h"
#include "00/code_021997f8.h"
#include "00/code_02199a0c.h"
#include "00/code_02199f80.h"
#include "00/code_02199fa4.h"
#include "00/code_0219981c.h"
#include "00/code_0219a014.h"
#include "00/code_0219a028.h"
#include "00/code_02199ad8.h"

u32 gti2HandleReliableMessage(Gt2Connection *connection, u32 type, const u8 *message, s32 len) {
    u32 serialNumber;
    s32 bufferFull;
    u32 expectedSerialNumber;
    if (len < 7) {
        if (func_ov000_02199fa4(connection) != 0) {
            return 1;
        }
        return 0;
    }
    serialNumber = func_ov000_0219a028(message, 3);
    expectedSerialNumber = func_ov000_0219a028(message, 5);
    if (func_ov000_02199ec8(connection, expectedSerialNumber) == 0) {
        return 0;
    }
    if (serialNumber == connection->mExpectedSerialNumber) {
        gti2SetPendingAck(connection);
        if (gti2DeliverReliableMessage(connection, type, message + 7, len - 7) == 0) {
            return 0;
        }
        if (gti2DeliverHoldMessages(connection) != 0) {
            return 1;
        }
        return 0;
    }
    if (func_ov000_0219a014(serialNumber, connection->mExpectedSerialNumber) < 0) {
        gti2SetPendingAck(connection);
        return 1;
    }
    if (gti2BufferIncomingMessage(connection, type, serialNumber, message + 7, len - 7, &bufferFull) == 0) {
        return 0;
    }
    if (bufferFull != 0 && func_ov000_02199f80(connection) == 0) {
        return 0;
    }
    return 1;
}

u32 gti2HandleAck(Gt2Connection *connection, const u8 *message, s32 len) {
    if (len != 2) {
        if (func_ov000_02199fa4(connection) != 0) {
            return 1;
        }
        return 0;
    }
    if (func_ov000_02199ec8(connection, func_ov000_0219a028(message, 0)) != 0) {
        return 1;
    }
    return 0;
}

u32 gti2HandleNack(Gt2Connection *connection, const u8 *message, s32 len) {
    u32 firstNumber;
    u32 lastNumber;
    s32 num;
    s32 index;
    GTI2OutgoingBufferMessage *sentEntry;
    firstNumber = func_ov000_0219a028(message, 0);
    if (len == 2) {
        lastNumber = firstNumber;
    } else if (len == 4) {
        lastNumber = func_ov000_0219a028(message, 2);
    } else {
        if (func_ov000_02199fa4(connection) != 0) {
            return 1;
        }
        return 0;
    }
    num = DarrayGetCount(connection->mOutgoingBufferMessages);
    for (index = 0; index < num; index++) {
        sentEntry = DarrayGetElement(connection->mOutgoingBufferMessages, index);
        if (func_ov000_0219a014(sentEntry->mSerialNumber, firstNumber) >= 0 &&
            func_ov000_0219a014(sentEntry->mSerialNumber, lastNumber) <= 0) {
            if (gti2ResendMessage(connection, (Unk02198af4 *) sentEntry) == FALSE) {
                return 0;
            }
        }
    }
    return 1;
}
