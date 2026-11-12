#include "00/code_02199614.h"
#include "00/code_0218d818.h"
#include "00/code_0219903c.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_02134398.h"
#include "00/code_02197e58.h"
#include "00/gt2Connection.h"
#include "00/gt2Main.h"
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
        if (gti2ConnectionCommunicationError(connection) != 0) {
            return 1;
        }
        return 0;
    }
    serialNumber = gti2UShortFromBuffer(message, 3);
    expectedSerialNumber = gti2UShortFromBuffer(message, 5);
    if (gti2HandleESN(connection, expectedSerialNumber) == 0) {
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
    if (gti2SNDiff(serialNumber, connection->mExpectedSerialNumber) < 0) {
        gti2SetPendingAck(connection);
        return 1;
    }
    if (gti2BufferIncomingMessage(connection, type, serialNumber, message + 7, len - 7, &bufferFull) == 0) {
        return 0;
    }
    if (bufferFull != 0 && gti2ConnectionMemoryError(connection) == 0) {
        return 0;
    }
    return 1;
}

u32 gti2HandleAck(Gt2Connection *connection, const u8 *message, s32 len) {
    if (len != 2) {
        if (gti2ConnectionCommunicationError(connection) != 0) {
            return 1;
        }
        return 0;
    }
    if (gti2HandleESN(connection, gti2UShortFromBuffer(message, 0)) != 0) {
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
    firstNumber = gti2UShortFromBuffer(message, 0);
    if (len == 2) {
        lastNumber = firstNumber;
    } else if (len == 4) {
        lastNumber = gti2UShortFromBuffer(message, 2);
    } else {
        if (gti2ConnectionCommunicationError(connection) != 0) {
            return 1;
        }
        return 0;
    }
    num = DarrayGetCount(connection->mOutgoingBufferMessages);
    for (index = 0; index < num; index++) {
        sentEntry = DarrayGetElement(connection->mOutgoingBufferMessages, index);
        if (gti2SNDiff(sentEntry->mSerialNumber, firstNumber) >= 0 && gti2SNDiff(sentEntry->mSerialNumber, lastNumber) <= 0) {
            if (gti2ResendMessage(connection, sentEntry) == FALSE) {
                return 0;
            }
        }
    }
    return 1;
}
