#include "00/code_0219981c.h"
#include "00/code_0218d818.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/code_02197b34.h"
#include "00/code_02197ddc.h"
#include "00/code_02197e58.h"
#include "00/code_021985ec.h"
#include "00/code_021988e8.h"
#include "00/code_02198a8c.h"
#include "00/code_02199a00.h"
#include "00/code_02199a0c.h"
#include "00/code_0219a014.h"
#include "code_021382a8.h"
#include "Main/Unknown/code_02133000.h"

u32 gti2BufferIncomingMessage(Gt2Connection *connection, s32 type, u32 serialNumber, const u8 *message, s32 len,
                              s32 *overflow) {
    GTI2IncomingBufferMessage newEntry;
    s32 num;
    s32 index;
    GTI2IncomingBufferMessage *heldMessage;
    num = DarrayGetCount(connection->mIncomingBufferMessages);
    for (index = 0; index < num; index++) {
        heldMessage = DarrayGetElement(connection->mIncomingBufferMessages, index);
        if (heldMessage->mSerialNumber == serialNumber) {
            *overflow = 0;
            return 1;
        }
        if (func_ov000_0219a014(heldMessage->mSerialNumber, serialNumber) > 0) {
            break;
        }
    }
    if (GetBufferUnusedSize(&connection->mIncomingBuffer) < len) {
        *overflow = 1;
        return 1;
    }
    newEntry.mStart = connection->mIncomingBuffer.mLength;
    newEntry.mLen = len;
    newEntry.mType = type;
    newEntry.mSerialNumber = serialNumber;
    DarrayInsertSorted(connection->mIncomingBufferMessages, &newEntry, gti2IncomingBufferMessageCompare);
    if (num + 1 != DarrayGetCount(connection->mIncomingBufferMessages)) {
        *overflow = 1;
        return 1;
    }
    AppendBufferBytes(&connection->mIncomingBuffer, message, len);
    if (num == 0) {
        if (gti2SendNack(connection, connection->mExpectedSerialNumber, serialNumber - 1) == FALSE) {
            return 0;
        }
    } else {
        heldMessage = DarrayGetElement(connection->mIncomingBufferMessages, num);
        if (heldMessage->mSerialNumber == serialNumber) {
            heldMessage = DarrayGetElement(connection->mIncomingBufferMessages, num - 1);
            if ((u16) func_ov000_0219a014(serialNumber, heldMessage->mSerialNumber) > 1) {
                if (gti2SendNack(connection, heldMessage->mSerialNumber + 1, serialNumber - 1) == FALSE) {
                    return 0;
                }
            }
        }
    }
    *overflow = 0;
    return 1;
}

void gti2RemoveHoldMessage(Gt2Connection *connection, GTI2IncomingBufferMessage *message, s32 index) {
    s32 d = 0;
    s32 removedStart = message->mStart;
    s32 removedLen = message->mLen;
    s32 num;
    s32 i;
    GTI2IncomingBufferMessage *heldMessage;
    DarrayRemove(connection->mIncomingBufferMessages, index);
    num = DarrayGetCount(connection->mIncomingBufferMessages);
    for (i = 0; i < num; i++) {
        heldMessage = DarrayGetElement(connection->mIncomingBufferMessages, i);
        if (heldMessage->mStart > removedStart) {
            heldMessage->mStart -= removedLen;
            if (d <= heldMessage->mStart + heldMessage->mLen) {
                d = heldMessage->mStart + heldMessage->mLen;
            }
        }
    }
    RemoveBufferBytes(&connection->mIncomingBuffer, removedStart, removedLen);
}

u32 gti2DeliverHoldMessages(Gt2Connection *connection) {
    s32 index;
    GTI2IncomingBufferMessage *message;
top:
    for (index = DarrayGetCount(connection->mIncomingBufferMessages) - 1; index >= 0; index--) {
        message = DarrayGetElement(connection->mIncomingBufferMessages, index);
        if (message->mSerialNumber == connection->mExpectedSerialNumber) {
            if (gti2DeliverReliableMessage(connection, message->mType,
                                           connection->mIncomingBuffer.mData + message->mStart, message->mLen) == 0) {
                return 0;
            }
            gti2RemoveHoldMessage(connection, message, index);
            goto top;
        }
    }
    return 1;
}
